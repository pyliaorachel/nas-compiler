#include <stdio.h>
#include <stdarg.h>
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

static int lbl;
static int globalSymIdx;
static int funcSymIdx;
static int funcCallLevel;
static localSymTab* currentFrameSymTab;

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

    SB = FP = IN = SP = 0;
}

void programEnds() {
    sm_delete(globalSymTab);
    sm_delete(funcSymTab);
    free(localSymTabs);
}

void moveRegPointer(int regIdx, int offset) {
    printf("\tpush\t%s\n", regNames[regIdx]);
    printf("\tpush\t%d\n", offset);
    printf("\tadd\n");
    printf("\tpop\t%s\n", regNames[regIdx]);
    reg[regIdx] += offset;
}

void createCallFrame(nodeType* paramList) {
    funcCallLevel++;

    localSymTab* symTab = (localSymTab*) malloc(sizeof(localSymTab));
    symTab->symTab = sm_new(LOCAL_SIZE);
    symTab->prev = currentFrameSymTab;
    currentFrameSymTab = symTab;

    int numOfParams = 0;
    char regName[100];
    while (paramList->type == typeOpr && paramList->opr.oper == ',') {
        sprintf(regName, "fp[%d]", -4 - numOfParams++);
        sm_put(currentFrameSymTab->symTab, paramList->opr.op[1]->id.varName, regName);
        paramList = paramList->opr.op[0];
    }
    if (paramList != NULL) {
        sprintf(regName, "fp[%d]", -4 - numOfParams++);
        sm_put(currentFrameSymTab->symTab, paramList->id.varName, regName);
    }

    currentFrameSymTab->numOfParams = numOfParams;
}

void tearDownCallFram() {
    funcCallLevel--;
    
    localSymTab* prevFrameSymTab = currentFrameSymTab->prev;
    sm_delete(currentFrameSymTab->symTab);
    free(currentFrameSymTab);
    currentFrameSymTab = prevFrameSymTab;
}

// return 1 for var already declared; 0 for new
int getGlobalRegName(char* regName, char* name, int offset) {
    if (sm_exists(globalSymTab, name)) {
        sm_get(globalSymTab, name, regName, 100);
        return 1;
    } else {
        sprintf(regName, "sb[%d]", globalSymIdx++);
        sm_put(globalSymTab, name, regName);
        return 0;
    }
}

void getLocalRegName(char* regName, char* name, int offset) {

}

int getRegName(char* regName, char* name, int offset) {
    if (funcCallLevel == 0) {
        return getGlobalRegName(regName, name, offset);
    } else {
        return 0;
    }
}

int ex(nodeType *p, int nops, ...) {
    int lblx, lbly, lblz, lbl1, lbl2, lbl_init = lbl, lbl_kept;
    char regName[100];
    int isDeclared;

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
                    printf("\tpush\t%d\n", p->con.value); 
                    break;
                case conTypeChar:
                    printf("\tpush\t\'%c\'\n", (char) p->con.value); 
                    break;
                case conTypeStr:
                    printf("\tpush\t\"%s\"\n", p->con.strValue); 
                    break;
            }
            break;
        case typeId:      
            getGlobalRegName(regName, p->id.varName, 0);
            printf("\tpush\t%s\n", regName); 
            break;
        case typeArr:
            ex(p->array.offset, 1, lbl_kept);
            printf("\tpushi\t%s\n", p->array.baseName); 
            break;
        case typeFunc:
            createCallFrame(p->func.paramList);
            tearDownCallFram();
            break;
        case typeOpr:
            switch(p->opr.oper) {
                case FOR:
                    lblz = lbl++;
                    lbly = lbl++;
                    lblx = lbl++;
                    ex(p->opr.op[0], 1, lbl_kept);
                    printf("L%03d:\n", lblx);
                    ex(p->opr.op[1], 1, lbl_kept);
                    printf("\tj0\tL%03d\n", lbly);
                    ex(p->opr.op[3], 1, lbl_init);
                    printf("L%03d:\n", lblz); // for continue
                    ex(p->opr.op[2], 1, lbl_kept);
                    printf("\tjmp\tL%03d\n", lblx);
                    printf("L%03d:\n", lbly);
                    break;
                case WHILE:
                    lbl1 = lbl++;
                    lbl2 = lbl++; // consistent order continue_target -> break target, as with FOR
                    printf("L%03d:\n", lbl1);
                    ex(p->opr.op[0], 1, lbl_kept);
                    printf("\tj0\tL%03d\n", lbl2);
                    ex(p->opr.op[1], 1, lbl_init);
                    printf("\tjmp\tL%03d\n", lbl1);
                    printf("L%03d:\n", lbl2);
                    break;
                case IF:
                    lbl1 = lbl++;
                    ex(p->opr.op[0], 1, lbl_kept);
                    if (p->opr.nops > 2) {
                        lbl2 = lbl++;
                        /* if else */
                        printf("\tj0\tL%03d\n", lbl1);
                        ex(p->opr.op[1], 1, lbl_kept);
                        printf("\tjmp\tL%03d\n", lbl2);
                        printf("L%03d:\n", lbl1);
                        ex(p->opr.op[2], 1, lbl_kept);
                        printf("L%03d:\n", lbl2);
                    } else {
                        /* if */
                        printf("\tj0\tL%03d\n", lbl1);
                        ex(p->opr.op[1], 1, lbl_kept);
                        printf("L%03d:\n", lbl1);
                    }
                    break;
                case BREAK:
                    printf("\tjmp\tL%03d\n", lbl_kept + 1);
                    break;
                case CONTINUE:
                    printf("\tjmp\tL%03d\n", lbl_kept);
                    break;
                case GETI:
                    printf("\tgeti\n"); 
                    isDeclared = getRegName(regName, p->opr.op[0]->id.varName, 1);
                    if (isDeclared) printf("\tpop\t%s\n", regName); 
                    break;
                case GETC: 
                    printf("\tgetc\n"); 
                    isDeclared = getRegName(regName, p->opr.op[0]->id.varName, 1);
                    if (isDeclared) printf("\tpop\t%s\n", regName); 
                    break;
                case GETS: 
                    printf("\tgets\n"); 
                    isDeclared = getRegName(regName, p->opr.op[0]->id.varName, 1);
                    if (isDeclared) printf("\tpop\t%s\n", regName); 
                    break;
                case PUTI: case PUTI_:
                    ex(p->opr.op[0], 1, lbl_kept);
                    if (p->opr.oper == PUTI) printf("\tputi\n"); else printf("\tputi_\n");
                    break;
                case PUTC: case PUTC_:
                    ex(p->opr.op[0], 1, lbl_kept);
                    if (p->opr.oper == PUTC) printf("\tputc\n"); else printf("\tputc_\n");
                    break;
                case PUTS: case PUTS_:
                    ex(p->opr.op[0], 1, lbl_kept);
                    if (p->opr.oper == PUTS) printf("\tputs\n"); else printf("\tputs_\n");
                    break;
                case '=':  
                    isDeclared = getRegName(regName, p->opr.op[0]->id.varName, 1);
                    ex(p->opr.op[1], 1, lbl_kept);
                    if (p->opr.op[0]->type == typeId) {
                        if (isDeclared) printf("\tpop\t%s\n", regName);
                    } else if (p->opr.op[0]->type == typeArr) {
                        ex(p->opr.op[0]->array.offset, 1, lbl_kept);
                        if (isDeclared) printf("\tpopi\t%s\n", p->opr.op[0]->array.baseName);
                    }
                    break;
                case UMINUS:    
                    ex(p->opr.op[0], 1, lbl_kept);
                    printf("\tneg\n");
                    break;
                default:
                    ex(p->opr.op[0], 1, lbl_kept);
                    ex(p->opr.op[1], 1, lbl_kept);
                    switch(p->opr.oper) {
                        case '+':   printf("\tadd\n"); break;
                        case '-':   printf("\tsub\n"); break; 
                        case '*':   printf("\tmul\n"); break;
                        case '/':   printf("\tdiv\n"); break;
                        case '%':   printf("\tmod\n"); break;
                        case '<':   printf("\tcompLT\n"); break;
                        case '>':   printf("\tcompGT\n"); break;
                        case GE:    printf("\tcompGE\n"); break;
                        case LE:    printf("\tcompLE\n"); break;
                        case NE:    printf("\tcompNE\n"); break;
                        case EQ:    printf("\tcompEQ\n"); break;
                        case AND:   printf("\tand\n"); break;
                        case OR:    printf("\tor\n"); break;
                    }
                }
    }
    return 0;
}
