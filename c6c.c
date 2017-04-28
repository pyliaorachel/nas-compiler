/*
 * TODO: 
 * 1. return value
 * 2. arrays
 * 3. what to do with in/ac
*/
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include "calc3.h"
#include "y.tab.h"
#include "strmap.h"

#define SB_I 0
#define FP_I 1
#define IN_I 2
#define SP_I 3

#define SB reg[SB_I]
#define FP reg[FP_I]
#define IN reg[IN_I]
#define SP reg[SP_I]

void programStarts();
void programEnds();
void moveRegPointer(int regIdx, int offset);
void createCallFrame(funcNodeType* func);
void tearDownCallFrame(funcNodeType* func);
int pushArgs(nodeType* argList, int lbl_kept);
int getGlobalRegName(char* regName, char* name);
int getLocalRegName(char* regName, char* name);
int getRegName(char* regName, char* name);
int getFuncLabel(char* labelName, char* name);
int ex(nodeType *p, int nops, ...);
void preScan(nodeListType *list);
void preProcess();
void makeRoomGlobalVariables();
void makeRoomLocalVariables(funcNodeType* func);
void exStmtList();
void exFuncList();
void freeNodeList();

static int lbl;
static int globalSymIdx;
static int funcSymIdx;
static int funcCallLevel;
static localSymTab* currentFrameSymTab;
static int isScan;

static int reg[4];
static char regNames[4][3] = {"sb", "fp", "in", "sp"};

void programStarts() {
    globalSymTab = sm_new(GLOBAL_SIZE);
    funcSymTab = sm_new(FUNC_SIZE);
    globalSymIdx = funcSymIdx = funcCallLevel = 0;
    localSymTabs = (localSymTab*) malloc(sizeof(localSymTab));
    localSymTabs->prev = NULL;
    localSymTabs->symTab = NULL;
    currentFrameSymTab = localSymTabs;

    funcList = malloc(sizeof(nodeListType)); funcList->type = listTypeFunc; funcList->nops = 0; funcList->head = funcList->tail = NULL;
    stmtList = malloc(sizeof(nodeListType)); stmtList->type = listTypeStmt; stmtList->nops = 0; stmtList->head = stmtList->tail = NULL;

    SB = FP = IN = SP = 0;
}

void programEnds() {
    sm_delete(globalSymTab);
    sm_delete(funcSymTab);
    free(localSymTabs);
    freeNodeList(funcList);
    freeNodeList(stmtList);
}

void moveRegPointer(int regIdx, int offset) {
    printf("\tpush\t%s\n", regNames[regIdx]);
    printf("\tpush\t%d\n", offset);
    printf("\tadd\n");
    printf("\tpop\t%s\n", regNames[regIdx]);
    reg[regIdx] += offset;
}

void createCallFrame(funcNodeType* func) {
    // deepen function call level
    funcCallLevel++;

    // create symbol table
    localSymTab* symTab = (localSymTab*) malloc(sizeof(localSymTab));
    symTab->symTab = sm_new(LOCAL_SIZE);
    symTab->prev = currentFrameSymTab;
    currentFrameSymTab = symTab;

    // insert parameters into stack
    nodeType* paramList = func->paramList;
    int numOfParams = 0;
    char regName[REG_NAME_L];
    while (paramList != NULL && paramList->type == typeOpr && paramList->opr.oper == ',') {
        sprintf(regName, "fp[%d]", -4 - numOfParams++);
        sm_put(currentFrameSymTab->symTab, paramList->opr.op[1]->id.varName, regName);
        paramList = paramList->opr.op[0];
    }
    if (paramList != NULL) {
        sprintf(regName, "fp[%d]", -4 - numOfParams++);
        sm_put(currentFrameSymTab->symTab, paramList->id.varName, regName);
    }

    if (!isScan) assert(numOfParams == func->numOfParams);
    else func->numOfParams = numOfParams;
    currentFrameSymTab->numOfParams = numOfParams;
    currentFrameSymTab->numOfLocalVars = 0;

    if (!isScan) makeRoomLocalVariables(func);
}

void tearDownCallFrame(funcNodeType* func) {
    // keep variable information
    int numOfLocalVars = currentFrameSymTab->numOfLocalVars;
    if (!isScan) assert(numOfLocalVars == func->numOfLocalVars);
    else func->numOfLocalVars = numOfLocalVars;

    // clean up
    funcCallLevel--;

    localSymTab* prevFrameSymTab = currentFrameSymTab->prev;
    sm_delete(currentFrameSymTab->symTab);
    free(currentFrameSymTab);
    currentFrameSymTab = prevFrameSymTab;
}

void makeRoomGlobalVariables() {
    moveRegPointer(SP_I, sm_get_count(globalSymTab));
}

void makeRoomLocalVariables(funcNodeType* func) {
    moveRegPointer(SP_I, func->numOfLocalVars);
}

// return number of arguments; recursion to be consistent with param list
int pushArgs(nodeType* argList, int lbl_kept) {
    if (argList == NULL) return 0;

    if (argList->type != typeOpr || argList->opr.oper != ',') {
        ex(argList, 1, lbl_kept);       
        return 1;
    }

    int numOfArgs = pushArgs(argList->opr.op[0], lbl_kept);
    ex(argList->opr.op[1], 1, lbl_kept);
    return 1 + numOfArgs;
}

// return 1 for var already declared; 0 for new
int getGlobalRegName(char* regName, char* name) {
    if (sm_exists(globalSymTab, name)) {
        sm_get(globalSymTab, name, regName, REG_NAME_L);
        return 1;
    } else {
        sprintf(regName, "sb[%d]", globalSymIdx++);
        sm_put(globalSymTab, name, regName);
        return 0;
    }
}

int getLocalRegName(char* regName, char* name) {
    if (sm_exists(currentFrameSymTab->symTab, name)) {
        sm_get(currentFrameSymTab->symTab, name, regName, REG_NAME_L);
        return 1;
    } else {
        sprintf(regName, "fp[%d]", currentFrameSymTab->numOfLocalVars++);
        sm_put(currentFrameSymTab->symTab, name, regName);
        return 0;
    }
}

int getRegName(char* regName, char* name) {
    if (funcCallLevel == 0) {
        return getGlobalRegName(regName, name);
    } else if (name[0] == '@') {
        return getGlobalRegName(regName, name+1);
    } else {
        return getLocalRegName(regName, name);
    }
}

int getFuncLabel(char* labelName, char* name) {
    if (sm_exists(funcSymTab, name)) {
        sm_get(funcSymTab, name, labelName, LABEL_NAME_L);
        return 1;
    } else {
        sprintf(labelName, "L%03d", lbl++);
        sm_put(funcSymTab, name, labelName);
        return 0;
    }
}

/* conditional print assembly code depending on whether at the scanning stage */
#define PRINTF(args...) if (!isScan) printf(args)

int ex(nodeType *p, int nops, ...) {
    int lblx, lbly, lblz, lbl1, lbl2, lbl_init = lbl, lbl_kept;
    char regName[REG_NAME_L];
    char labelName[LABEL_NAME_L];
    char jmpLabelName[LABEL_NAME_L];
    int numOfArgs;

    // retrieve lbl_kept
    va_list ap;
    va_start(ap, nops);
    for (int i = 0; i < nops; i++)
        lbl_kept = va_arg(ap, int);

    if (!p) return 0;
    switch(p->type) {
        case typeCon:       
            switch(p->con.type){
                case conTypeNull:
                case conTypeInt:
                    PRINTF("\tpush\t%d\n", p->con.value); 
                    break;
                case conTypeChar:
                    PRINTF("\tpush\t\'%c\'\n", (char) p->con.value); 
                    break;
                case conTypeStr:
                    PRINTF("\tpush\t\"%s\"\n", p->con.strValue); 
                    break;
            }
            break;
        case typeId:      
            getRegName(regName, p->id.varName);
            PRINTF("\tpush\t%s\n", regName); 
            break;
        case typeArr:
            ex(p->array.offset, 1, lbl_kept);
            PRINTF("\tpushi\t%s\n", p->array.baseName); 
            break;
        case typeFunc:
            createCallFrame(&p->func);
            ex(p->func.stmt, 1, lbl_kept);
            tearDownCallFrame(&p->func);
            PRINTF("\tret\n"); // in case 'return' is not specified
            break;
        case typeOpr:
            switch(p->opr.oper) {
                case FOR:
                    lblz = lbl++;
                    lbly = lbl++;
                    lblx = lbl++;
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("L%03d:\n", lblx);
                    ex(p->opr.op[1], 1, lbl_kept);
                    PRINTF("\tj0\tL%03d\n", lbly);
                    ex(p->opr.op[3], 1, lbl_init);
                    PRINTF("L%03d:\n", lblz); // for continue
                    ex(p->opr.op[2], 1, lbl_kept);
                    PRINTF("\tjmp\tL%03d\n", lblx);
                    PRINTF("L%03d:\n", lbly);
                    break;
                case WHILE:
                    lbl1 = lbl++;
                    lbl2 = lbl++; // consistent order continue_target -> break target, as with FOR
                    PRINTF("L%03d:\n", lbl1);
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("\tj0\tL%03d\n", lbl2);
                    ex(p->opr.op[1], 1, lbl_init);
                    PRINTF("\tjmp\tL%03d\n", lbl1);
                    PRINTF("L%03d:\n", lbl2);
                    break;
                case IF:
                    lbl1 = lbl++;
                    ex(p->opr.op[0], 1, lbl_kept);
                    if (p->opr.nops > 2) {
                        lbl2 = lbl++;
                        /* if else */
                        PRINTF("\tj0\tL%03d\n", lbl1);
                        ex(p->opr.op[1], 1, lbl_kept);
                        PRINTF("\tjmp\tL%03d\n", lbl2);
                        PRINTF("L%03d:\n", lbl1);
                        ex(p->opr.op[2], 1, lbl_kept);
                        PRINTF("L%03d:\n", lbl2);
                    } else {
                        /* if */
                        PRINTF("\tj0\tL%03d\n", lbl1);
                        ex(p->opr.op[1], 1, lbl_kept);
                        PRINTF("L%03d:\n", lbl1);
                    }
                    break;
                case BREAK:
                    PRINTF("\tjmp\tL%03d\n", lbl_kept + 1);
                    break;
                case CONTINUE:
                    PRINTF("\tjmp\tL%03d\n", lbl_kept);
                    break;
                case GETI:
                    PRINTF("\tgeti\n"); 
                    getRegName(regName, p->opr.op[0]->id.varName);
                    PRINTF("\tpop\t%s\n", regName); 
                    break;
                case GETC: 
                    PRINTF("\tgetc\n"); 
                    getRegName(regName, p->opr.op[0]->id.varName);
                    PRINTF("\tpop\t%s\n", regName); 
                    break;
                case GETS: 
                    PRINTF("\tgets\n"); 
                    getRegName(regName, p->opr.op[0]->id.varName);
                    PRINTF("\tpop\t%s\n", regName); 
                    break;
                case PUTI: case PUTI_:
                    ex(p->opr.op[0], 1, lbl_kept);
                    if (p->opr.oper == PUTI) { PRINTF("\tputi\n"); } else { PRINTF("\tputi_\n"); }
                    break;
                case PUTC: case PUTC_:
                    ex(p->opr.op[0], 1, lbl_kept);
                    if (p->opr.oper == PUTC) { PRINTF("\tputc\n"); } else { PRINTF("\tputc_\n"); }
                    break;
                case PUTS: case PUTS_:
                    ex(p->opr.op[0], 1, lbl_kept);
                    if (p->opr.oper == PUTS) { PRINTF("\tputs\n"); } else { PRINTF("\tputs_\n"); }
                    break;
                case '=':  
                    getRegName(regName, p->opr.op[0]->id.varName);
                    ex(p->opr.op[1], 1, lbl_kept);
                    if (p->opr.op[0]->type == typeId) {
                        PRINTF("\tpop\t%s\n", regName);
                    } else if (p->opr.op[0]->type == typeArr) {
                        ex(p->opr.op[0]->array.offset, 1, lbl_kept);
                        PRINTF("\tpopi\t%s\n", p->opr.op[0]->array.baseName);
                    }
                    break;
                case UMINUS:    
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("\tneg\n");
                    break;
                case 'c':
                    numOfArgs = pushArgs(p->opr.op[1], lbl_kept);
                    getFuncLabel(labelName, p->opr.op[0]->id.varName);
                    PRINTF("\tcall\t%s, %d\n", labelName, numOfArgs);
                    break;
                case RETURN:
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("\tret\n");
                    break;
                default:
                    ex(p->opr.op[0], 1, lbl_kept);
                    ex(p->opr.op[1], 1, lbl_kept);
                    switch(p->opr.oper) {
                        case '+':   PRINTF("\tadd\n"); break;
                        case '-':   PRINTF("\tsub\n"); break; 
                        case '*':   PRINTF("\tmul\n"); break;
                        case '/':   PRINTF("\tdiv\n"); break;
                        case '%':   PRINTF("\tmod\n"); break;
                        case '<':   PRINTF("\tcompLT\n"); break;
                        case '>':   PRINTF("\tcompGT\n"); break;
                        case GE:    PRINTF("\tcompGE\n"); break;
                        case LE:    PRINTF("\tcompLE\n"); break;
                        case NE:    PRINTF("\tcompNE\n"); break;
                        case EQ:    PRINTF("\tcompEQ\n"); break;
                        case AND:   PRINTF("\tand\n"); break;
                        case OR:    PRINTF("\tor\n"); break;
                    }
                }
    }
    return 0;
}

void preScan(nodeListType *list) {
    isScan = 1;

    nodeListNodeType *p = list->head;

    while(p) {
        nodeType *n = p->node;
        ex(n, 0);
        p = p->next; 
    }

    isScan = 0;
}

void preProcess() {
    preScan(stmtList);
    preScan(funcList);
    makeRoomGlobalVariables();
}

void exStmtList() {
    nodeListNodeType *p = stmtList->head;

    while(p) {
        nodeType *n = p->node;
        ex(n, 0);
        p = p->next; 
    }

    printf("\tend\n");
}

void exFuncList() {
    nodeListNodeType *p = funcList->head;

    while(p) {
        nodeType *n = p->node;

        // label function & register function name
        char funcLabelName[LABEL_NAME_L];
        int isDeclared = getFuncLabel(funcLabelName, n->func.funcName);
        printf("%s:\n", funcLabelName);

        ex(n, 0);
        p = p->next; 
    }
}













