#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include "calc3.h"
#include "y.tab.h"
#include "strmap.h"

/*****************************************************************************
                    Macro, Function & Variable Declarations
 *****************************************************************************/

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
void createCallFrame(funcNodeType* func);
void tearDownCallFrame(funcNodeType* func);
void moveRegPointer(int regIdx, int offset);
void makeRoomGlobalVariables();
void makeRoomLocalVariables(funcNodeType* func);
int pushArgs(nodeType* argList, int lbl_kept);
void declareArray(char* regName, arrayNodeType* array, int unitSize, int lbl_kept);
void declareStruct(char* regName, nodeType* p, int lbl_kept);
int pushStructMembers(nodeType* memberList, char* structName);
void defineStructType(structNodeType* sct);
void assignArray(nodeType* p, int lbl_kept);
void assignToStruct(nodeType* p, int lbl_kept);
int isArrayPtr(nodeType* p);
int isStructType(nodeType* p);
void pushBasePtr(nodeType* p);
void pushPtr(nodeType* p, int lbl_kept);
void pushPtrValue(nodeType* p, int lbl_kept);
void pushStructOffset(nodeType* p, char* memberName);
void putCharArray(nodeType* p, int hasNewLine, int lbl_kept);
void getCharArray(nodeType* p, int lbl_kept);
void popToPointer(nodeType* p, int lbl_kept);
void assignCharArray(nodeType* p, char* str, int lbl_kept);
int getGlobalRegName(char* regName, char* name, int size);
int getLocalRegName(char* regName, char* name, int size);
int getRegName(char* regName, char* name, int size);
char* getSimpleVarName(nodeType* p);
char* getFullVarName(nodeType* p);
StrMap* getArrayDimSymTab(char* varName);
int getFuncLabel(char* labelName, char* name);
int ex(nodeType *p, int nops, ...);
void preScan(nodeListType *list);
void preProcess();
void exStmtList();
void exFuncList();
void freeNodeList();

static int lbl;                                 // label
static int funcCallLevel;                       // level of function calls
static localSymTab* currentFrameSymTab;         // symbol table for current frame
static int isScan;                              // 1: scanning; 0: execution

static int reg[4];
static char regNames[4][3] = {"sb", "fp", "in", "sp"};

/* conditionally print assembly code depending on whether at the scanning stage */
#define PRINTF(args...) if (!isScan) printf(args)

/*****************************************************************************
                            Program Init & End
 *****************************************************************************/

void programStarts() {
    // init symbol tables
    globalSymTab = (symTab*) malloc(sizeof(symTab));
    globalSymTab->symTab = sm_new(GLOBAL_SIZE);
    globalSymTab->arrayDimTab = sm_new(GLOBAL_SIZE);
    globalSymTab->size = 0;
    funcSymTab = (symTab*) malloc(sizeof(symTab));
    funcSymTab->symTab = sm_new(FUNC_SIZE);
    funcSymTab->arrayDimTab = sm_new(FUNC_SIZE);
    funcSymTab->size = 0;
    structSymTab = (symTab*) malloc(sizeof(symTab));
    structSymTab->symTab = sm_new(STRUCT_SIZE);
    structSymTab->size = 0;
    localSymTabs = (localSymTab*) malloc(sizeof(localSymTab));
    localSymTabs->prev = NULL;
    localSymTabs->symTab = NULL;
    localSymTabs->arrayDimTab = NULL;
    currentFrameSymTab = localSymTabs;

    // init function & statement lists
    funcList = malloc(sizeof(nodeListType)); funcList->type = listTypeFunc; funcList->nops = 0; funcList->head = funcList->tail = NULL;
    stmtList = malloc(sizeof(nodeListType)); stmtList->type = listTypeStmt; stmtList->nops = 0; stmtList->head = stmtList->tail = NULL;
    structList = malloc(sizeof(nodeListType)); structList->type = listTypeStruct; structList->nops = 0; structList->head = structList->tail = NULL;

    // init pointer values
    SB = FP = IN = SP = 0;
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
    preScan(structList);
    preScan(stmtList);
    preScan(funcList);
    makeRoomGlobalVariables();
    freeNodeList(structList);
}

void programEnds() {
    sm_delete(globalSymTab->symTab);
    sm_delete(globalSymTab->arrayDimTab);
    sm_delete(funcSymTab->symTab);
    sm_delete(funcSymTab->arrayDimTab);
    sm_delete(structSymTab->symTab);
    free(globalSymTab);
    free(funcSymTab);
    free(structSymTab);
    free(localSymTabs);
    freeNodeList(funcList);
    freeNodeList(stmtList);
}

/*****************************************************************************
                            Function Init & End
 *****************************************************************************/

void createCallFrame(funcNodeType* func) {
    // deepen function call level
    funcCallLevel++;

    // create local symbol table
    localSymTab* symTab = (localSymTab*) malloc(sizeof(localSymTab));
    symTab->symTab = sm_new(LOCAL_SIZE);
    symTab->prev = currentFrameSymTab;
    currentFrameSymTab = symTab;

    // insert parameters into stack
    nodeType* paramList = func->paramList;
    int numOfParams = 0;
    char regName[REG_NAME_L];
    while (paramList != NULL && paramList->type == typeOpr && paramList->opr.oper == ',') {
        assert(paramList->opr.op[1]->type == typeId); // param list must consist of variables
        sprintf(regName, "fp[%d]", -4 - numOfParams++);
        sm_put(currentFrameSymTab->symTab, paramList->opr.op[1]->id.varName, regName);
        paramList = paramList->opr.op[0];
    }
    if (paramList != NULL) {
        assert(paramList->type == typeId); // param list must consist of variables
        sprintf(regName, "fp[%d]", -4 - numOfParams++);
        sm_put(currentFrameSymTab->symTab, paramList->id.varName, regName);
    }

    // store meta data
    if (!isScan) assert(numOfParams == func->numOfParams);
    else func->numOfParams = numOfParams;
    currentFrameSymTab->numOfParams = numOfParams;
    currentFrameSymTab->numOfLocalVars = 0;
    currentFrameSymTab->arrayDimTab = sm_new(LOCAL_SIZE);

    // push space onto stack for local variables
    if (!isScan) makeRoomLocalVariables(func);
}

void tearDownCallFrame(funcNodeType* func) {
    // keep variable information if scanning
    int numOfLocalVars = currentFrameSymTab->numOfLocalVars;
    if (!isScan) assert(numOfLocalVars == func->numOfLocalVars);
    else func->numOfLocalVars = numOfLocalVars;

    // clean up
    funcCallLevel--;

    localSymTab* prevFrameSymTab = currentFrameSymTab->prev;
    sm_delete(currentFrameSymTab->symTab);
    sm_delete(currentFrameSymTab->arrayDimTab);
    free(currentFrameSymTab);
    currentFrameSymTab = prevFrameSymTab;
}

/*****************************************************************************
                            Utility Functions
 *****************************************************************************/

void moveRegPointer(int regIdx, int offset) {
    printf("\tpush\t%s\n", regNames[regIdx]);
    printf("\tpush\t%d\n", offset);
    printf("\tadd\n");
    printf("\tpop\t%s\n", regNames[regIdx]);
    reg[regIdx] += offset;
}

void makeRoomGlobalVariables() {
    if (globalSymTab->size) moveRegPointer(SP_I, globalSymTab->size);
}

void makeRoomLocalVariables(funcNodeType* func) {
    if (func->numOfLocalVars) moveRegPointer(SP_I, func->numOfLocalVars);
}

// return number of arguments; use recursion for being consistent with param list's order
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

void declareArray(char* regName, arrayNodeType* array, int unitSize, int lbl_kept) {
    StrMap* arrayDimTab = getArrayDimSymTab(array->baseName);
    char dimStr[DIM_STR_L], buffer[DIM_STR_L];

    // calculate offset
    assert(array->dim >= 1);
    arrayOffsetNodeType *n = array->offsetListHead;
    int offset = n->offset->con.value;
    sprintf(dimStr, "%d|%d|%d", unitSize, array->dim, offset); // prepend count -> count|unitSize|dim1,dim2,...|unitsize
    n = n->next;

    while (n) {
        // not supporting VLA, always assert static declaration
        assert(n->offset->type == typeCon); 
        assert(n->offset->con.type != conTypeStr && n->offset->con.type != conTypeNull); 

        offset *= n->offset->con.value;
        sprintf(buffer, "%s,%d", dimStr, n->offset->con.value);
        strcpy(dimStr, buffer);
        n = n->next;
    }

    // declare
    getRegName(regName, array->baseName, offset * unitSize);
    if (isScan || funcCallLevel != 0) {
        // global table already have things stored, but not local table
        assert(!sm_exists(arrayDimTab, array->baseName));
        sm_put(arrayDimTab, array->baseName, dimStr);
    }

    array->size = offset * unitSize;
}

void declareStruct(char* regName, nodeType* p, int lbl_kept) {
    // get struct size
    char sizeBuffer[LOG_NUM_OF_MEMBERS];
    sm_get(structSymTab->symTab, p->opr.op[0]->id.varName, sizeBuffer, LOG_NUM_OF_MEMBERS);
    int size = atoi(sizeBuffer);

    // declare
    if (p->opr.op[1]->type == typeId) {
        getRegName(regName, p->opr.op[1]->id.varName, size);
        // key: var name, value: struct type name
        sm_put(structSymTab->symTab, p->opr.op[1]->id.varName, p->opr.op[0]->id.varName);
    } else if (p->opr.op[1]->type == typeArr) {
        declareArray(regName, &p->opr.op[1]->array, size, lbl_kept);
        // key: array name, value: struct type name
        sm_put(structSymTab->symTab, p->opr.op[1]->array.baseName, p->opr.op[0]->id.varName);
    } else {
        assert(0);
    }

    structSymTab->size++;
}

// return number of members; use recursion for in-order declaration
int pushStructMembers(nodeType* memberList, char* structName) {
    if (memberList == NULL) return 0;

    if (memberList->type != typeOpr || memberList->opr.oper != ',') {
        // store to symbol table
        char keyName[strlen(structName) + strlen(memberList->id.varName) + 2];
        sprintf(keyName, "%s.%s", structName, memberList->id.varName);
        sm_put(structSymTab->symTab, keyName, "0");
        return 1;
    }

    int numOfMembers = pushStructMembers(memberList->opr.op[0], structName);

    // store to symbol table
    char keyName[strlen(structName) + strlen(memberList->opr.op[1]->id.varName) + 2];
    char value[LOG_NUM_OF_MEMBERS];
    sprintf(keyName, "%s.%s", structName, memberList->opr.op[1]->id.varName);
    sprintf(value, "%d", numOfMembers); 
    sm_put(structSymTab->symTab, keyName, value);  

    return 1 + numOfMembers;
}

void defineStructType(structNodeType* sct) {
    // insert struct member info into symbol table
    nodeType* memberList = sct->memberList;
    int numOfMembers = pushStructMembers(sct->memberList, sct->structName);

    // store number of members info into symbol table
    char value[LOG_NUM_OF_MEMBERS];
    sprintf(value, "%d", numOfMembers); 
    sm_put(structSymTab->symTab, sct->structName, value);

    // store meta data
    sct->numOfMembers = numOfMembers;
    structSymTab->size += numOfMembers + 1; // +1 for num of member info
    assert(sm_get_count(structSymTab->symTab) == structSymTab->size);
}

void assignArray(nodeType* p, int lbl_kept) {
    char regName[REG_NAME_L], baseRegName[3] = {0}, baseRegOffset[REG_NAME_L] = {0};

    PRINTF("\n\t// array size %d\n", p->array.size); 

    // push base register address
    pushBasePtr(p);
    PRINTF("\tadd\n");  

    PRINTF("\tpop\tac\n");
    PRINTF("\tpop\tac[0]\n");

    // pop to elements
    for (int i = 1; i < p->array.size; i++) {
        PRINTF("\tpush\tac[%d]\n", i-1);
        PRINTF("\tpop\tac[%d]\n", i);
    }
}

void assignToStruct(nodeType* p, int lbl_kept) {
    // push struct variable pointer
    pushPtr(p->opr.op[0], lbl_kept);
    pushStructOffset(p->opr.op[0], p->opr.op[1]->id.varName);

    PRINTF("\tadd\n"); 
    PRINTF("\n\tpop\tac\n"); 
    PRINTF("\tpop\tac[0]\n");
}

int isArrayPtr(nodeType* p) {
    if (p->type != typeId && p->type != typeArr) return 0;

    StrMap* arrayDimTab = getArrayDimSymTab(getFullVarName(p));
    char dimStr[DIM_STR_L];
    int arrayDim;

    if (p->type == typeId && sm_exists(arrayDimTab, p->id.varName)) {
        return 1;
    } else if (p->type == typeArr) {
        if (sm_exists(arrayDimTab, p->array.baseName)) {
            // check dimension count
            sm_get(arrayDimTab, p->array.baseName, dimStr, DIM_STR_L);
            arrayDim = atoi(strtok(dimStr, "|")); // dummy, unitsize
            arrayDim = atoi(strtok(NULL, "|"));

            return p->array.dim < arrayDim;
        } else if (sm_exists(currentFrameSymTab->symTab, p->array.baseName)) {
            // array pointer in param
            return 0;
        }
    }
    
    return 0;
}

int isStructType(nodeType* p) {
    if (p->type == typeId) {
        if (sm_exists(currentFrameSymTab->symTab, p->id.varName) && sm_exists(structSymTab->symTab, p->id.varName)) {
            return 1;
        }
    } else if (p->type == typeArr) {
        if (sm_exists(currentFrameSymTab->symTab, p->array.baseName) && sm_exists(structSymTab->symTab, p->array.baseName)) {
            return 1;
        }
    } else {
        assert(0);
    }

    return 0;
}

void pushBasePtr(nodeType* p) {
    char regName[REG_NAME_L], baseRegName[3] = {0}, baseRegOffset[REG_NAME_L] = {0};

    switch(p->type) {
        case typeArr:
            getRegName(regName, p->array.baseName, -1);
            break;
        case typeId:
            getRegName(regName, p->id.varName, -1);
            break;
        default:
            return;
    }
    strncpy(baseRegName, regName, 2);
    strncpy(baseRegOffset, regName + 3, strlen(regName) - 4);

    PRINTF("\tpush\t%s\n", baseRegName);
    PRINTF("\tpush\t%s\n", baseRegOffset);
}

void pushPtr(nodeType* p, int lbl_kept) {
    StrMap* arrayDimTab = getArrayDimSymTab(getFullVarName(p));
    char dimStr[DIM_STR_L];
    int dim, unitSize; char* tempDim;
    char regName[REG_NAME_L];
    char* varName = getSimpleVarName(p);

    if (p->type == typeArr) {
        if (sm_exists(currentFrameSymTab->symTab, varName)) {
            // param is array pointer
            getRegName(regName, p->array.baseName, -1);

            PRINTF("\tpush\t%s\n", regName);

            // calculate offset
            PRINTF("\tpush\t0\n"); 
            arrayOffsetNodeType *n = p->array.offsetListHead;
            ex(n->offset, 1, lbl_kept);
            PRINTF("\tadd\n");
        } else {
            pushBasePtr(p);

            // calculate offset
            PRINTF("\tpush\t0\n"); 
            arrayOffsetNodeType *n = p->array.offsetListHead;
            ex(n->offset, 1, lbl_kept);
            PRINTF("\tadd\n"); 

            n = n->next;
            if (sm_exists(arrayDimTab, varName)) {
                sm_get(arrayDimTab, varName, dimStr, DIM_STR_L);
                unitSize = atoi(strtok(dimStr, "|")); // unitsize
                dim = atoi(strtok(NULL, "|")); // dummy, dim count
                dim = atoi(strtok(NULL, ",")); // dummy, first dimension

                while (n) {
                    dim = atoi(strtok(NULL, ","));
                    PRINTF("\tpush\t%d\n", dim); 
                    PRINTF("\tmul\n"); 
                    ex(n->offset, 1, lbl_kept);
                    PRINTF("\tadd\n"); 

                    n = n->next;
                }

                tempDim = strtok(NULL, ",");
                while (tempDim) {
                    dim = atoi(tempDim);
                    PRINTF("\tpush\t%d\n", dim); 
                    PRINTF("\tmul\n"); 
                    tempDim = strtok(NULL, ",");
                }

                PRINTF("\tpush\t%d\n", unitSize); 
                PRINTF("\tmul\n"); 

                PRINTF("\tadd\n");
            }
        }
    } else if (p->type == typeId) {
        pushBasePtr(p);
    }

    PRINTF("\tadd\n");    
}

void pushPtrValue(nodeType* p, int lbl_kept) {
    pushPtr(p, lbl_kept);
    PRINTF("\n\tpop\tac\n"); 
    PRINTF("\tpush\tac[0]\n");  
}

void pushStructOffset(nodeType* p, char* memberName) {
    char structType[VAR_NAME_L], structMemberRep[2 * VAR_NAME_L], memberOffset[LOG_NUM_OF_MEMBERS];
    char* varName = getSimpleVarName(p);

    sm_get(structSymTab->symTab, varName, structType, VAR_NAME_L);
    sprintf(structMemberRep, "%s.%s", structType, memberName);
    sm_get(structSymTab->symTab, structMemberRep, memberOffset, LOG_NUM_OF_MEMBERS);

    // push offset
    PRINTF("\tpush\t%s\n", memberOffset);  
}

void putCharArray(nodeType* p, int hasNewLine, int lbl_kept) {
    int lbl1, lbl2;

    pushPtr(p, lbl_kept);
    PRINTF("\tpop\tac\n"); 

    // start push char with loop
    lbl1 = lbl++;
    lbl2 = lbl++;
    PRINTF("L%03d:\n", lbl1);

        // jump on value <= 0
    PRINTF("\tpush\tac[0]\n");  
    PRINTF("\tpush\t0\n");  
    PRINTF("\tcompLE\n");

    PRINTF("\tj1\tL%03d\n", lbl2);

        // put char
    PRINTF("\tpush\tac[0]\n");
    PRINTF("\tputc_\n");

        // increment index
    PRINTF("\tpush\tac\n");
    PRINTF("\tpush\t1\n");
    PRINTF("\tadd\n");
    PRINTF("\tpop\tac\n"); 

    PRINTF("\tjmp\tL%03d\n", lbl1);
    PRINTF("L%03d:\n", lbl2);

    if (hasNewLine) {
        PRINTF("\tpush\t0\n");
        PRINTF("\tputc\n");
    }
}

void getCharArray(nodeType* p, int lbl_kept) {
    int lbl1, lbl2;

    pushPtr(p, lbl_kept);
    PRINTF("\tpop\tac\n"); 

    // start push char with loop
    lbl1 = lbl++;
    lbl2 = lbl++;
    PRINTF("L%03d:\n", lbl1);

        // get char
    PRINTF("\tgetc\n");
    PRINTF("\tpop\tac[0]\n");  

        // jump on value == \n
    PRINTF("\tpush\tac[0]\n");  
    PRINTF("\tpush\t%d\n", '\n');  
    PRINTF("\tcompEQ\n");

    PRINTF("\tj1\tL%03d\n", lbl2);

        // increment index
    PRINTF("\tpush\tac\n");
    PRINTF("\tpush\t1\n");
    PRINTF("\tadd\n");
    PRINTF("\tpop\tac\n"); 

    PRINTF("\tjmp\tL%03d\n", lbl1);
    PRINTF("L%03d:\n", lbl2);

    // mark the last char as \0
    PRINTF("\tpush\t0\n");
    PRINTF("\tpop\tac[0]\n");  
}

void popToPointer(nodeType* p, int lbl_kept) {
    char regName[REG_NAME_L];

    if (p->type == typeId) {
        PRINTF("\n\t// get to variable %s\n", p->id.varName); 
        getRegName(regName, p->id.varName, 1);
        PRINTF("\tpop\t%s\n", regName);
    } else if (p->type == typeArr) {
        PRINTF("\n\t// get to array %s\n", p->array.baseName); 
        pushPtr(p, lbl_kept);
        PRINTF("\n\tpop\tac\n");
        PRINTF("\tpop\tac[0]\n");
    } else if (p->type == typeOpr) {
        switch (p->opr.oper) {
            case DOT:
                PRINTF("\n\t// get to struct\n"); 
                assignToStruct(p, lbl_kept);
                break;
            default:
                break;
        }
    }
}

void assignCharArray(nodeType* p, char* str, int lbl_kept) {
    int l = strlen(str);

    pushPtr(p, lbl_kept);
    PRINTF("\tpop\tac\n"); 

    // start push char by going through each char in string
    for (int i = 0; i < l; i++) {
        PRINTF("\tpush\t\'%c\'\n", str[i]);
        PRINTF("\tpop\tac[%d]\n", i);
    }

    // mark the last char as \0
    PRINTF("\tpush\t0\n");
    PRINTF("\tpop\tac[%d]\n", l);  
}

/*****************************************************************************
                        Naming Related Utility Functions
 *****************************************************************************/

// return 1 for var already declared; 0 for newly declared ones
// size < 0 -> needs to be already declared
int getGlobalRegName(char* regName, char* name, int size) {
    if (sm_exists(globalSymTab->symTab, name)) {
        sm_get(globalSymTab->symTab, name, regName, REG_NAME_L);
        return 1;
    } else {
        assert(size > 0);
        sprintf(regName, "sb[%d]", globalSymTab->size);
        sm_put(globalSymTab->symTab, name, regName);
        globalSymTab->size += size;
        return 0;
    }
}

int getLocalRegName(char* regName, char* name, int size) {
    if (sm_exists(currentFrameSymTab->symTab, name)) {
        sm_get(currentFrameSymTab->symTab, name, regName, REG_NAME_L);
        return 1;
    } else {
        assert(size > 0);
        sprintf(regName, "fp[%d]", currentFrameSymTab->numOfLocalVars);
        sm_put(currentFrameSymTab->symTab, name, regName);
        currentFrameSymTab->numOfLocalVars += size;
        return 0;
    }
}

int getRegName(char* regName, char* name, int size) {
    if (funcCallLevel == 0) {
        return getGlobalRegName(regName, name, size);
    } else if (name[0] == '@') {
        return getGlobalRegName(regName, name+1, size);
    } else {
        return getLocalRegName(regName, name, size);
    }
}

char* getSimpleVarName(nodeType* p) {
    if (p->type == typeId) {
        if (p->id.varName[0] == '@') return p->id.varName + 1;
        else return p->id.varName;
    } else if (p->type == typeArr)  {
        if (p->array.baseName[0] == '@') return p->array.baseName + 1;
        else return p->array.baseName;
    }
    return NULL;
}

char* getFullVarName(nodeType* p) {
    if (p->type == typeId) {
        return p->id.varName;
    } else if (p->type == typeArr)  {
        return p->array.baseName;
    }
    return NULL;
}

StrMap* getArrayDimSymTab(char* varName) {
    if (funcCallLevel == 0) {
        return globalSymTab->arrayDimTab;
    } else if (varName[0] == '@') {
        return globalSymTab->arrayDimTab;
    } else {
        return currentFrameSymTab->arrayDimTab;
    }
}

int getFuncLabel(char* labelName, char* name) {
    if (sm_exists(funcSymTab->symTab, name)) {
        sm_get(funcSymTab->symTab, name, labelName, LABEL_NAME_L);
        return 1;
    } else {
        sprintf(labelName, "L%03d", lbl++);
        sm_put(funcSymTab->symTab, name, labelName);
        funcSymTab->size++;
        return 0;
    }
}

/*****************************************************************************
                            Main Execution Functions
 *****************************************************************************/

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
            PRINTF("\n\t// push constant\n"); 
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
            if (!isArrayPtr(p)) {
                PRINTF("\n\t// push variable %s\n", p->id.varName);      
                getRegName(regName, p->id.varName, 1);
                PRINTF("\tpush\t%s\n", regName); 
            } else {
                PRINTF("\n\t// push pointer %s\n", p->id.varName);      
                pushPtr(p, lbl_kept);        
            }
            break;
        case typeArr:
            if (!isArrayPtr(p)) {
                PRINTF("\n\t// push array %s\n", p->array.baseName); 
                pushPtrValue(p, lbl_kept);
            } else {
                PRINTF("\n\t// push pointer %s\n", p->array.baseName);      
                pushPtr(p, lbl_kept);    
            }
            break;
        case typeFunc:
            PRINTF("\n\t// declare function\n"); 
            createCallFrame(&p->func);
            ex(p->func.stmt, 1, lbl_kept);
            tearDownCallFrame(&p->func);
            PRINTF("\tret\n"); // in case 'return' is not specified; 'ret' may be duplicated, but doesn't matter
            break;
        case typeStruct:
            if (isScan) defineStructType(&p->sct);
            break;
        case typeOpr:
            switch(p->opr.oper) {
                case FOR:
                    PRINTF("\n\t// for loop\n"); 
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
                    PRINTF("\n\t// while loop\n"); 
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
                    PRINTF("\n\t// if statement\n"); 
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
                    PRINTF("\n\t// Input\n"); 
                    PRINTF("\tgeti\n"); 
                    popToPointer(p->opr.op[0], lbl_kept);
                    break;
                case GETC: 
                    PRINTF("\n\t// Input\n"); 
                    PRINTF("\tgetc\n"); 
                    popToPointer(p->opr.op[0], lbl_kept);
                    break;
                case GETS: 
                    PRINTF("\n\t// Input\n"); 
                    if (!isArrayPtr(p->opr.op[0])) {
                        PRINTF("\tgets\n"); 
                        popToPointer(p->opr.op[0], lbl_kept);
                    } else {
                        PRINTF("\n\t// get to char array\n");
                        getCharArray(p->opr.op[0], lbl_kept);
                    }
                    break;
                case PUTI: 
                    PRINTF("\n\t// Output\n"); 
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("\tputi\n");
                    break;
                case PUTI_:
                    PRINTF("\n\t// Output\n"); 
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("\tputi_\n");
                    break;
                case PUTC: 
                    PRINTF("\n\t// Output\n"); 
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("\tputc\n");
                    break;
                case PUTC_:
                    PRINTF("\n\t// Output\n"); 
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("\tputc_\n");
                    break;
                case PUTS: 
                    PRINTF("\n\t// Output\n"); 
                    if (!isArrayPtr(p->opr.op[0])) {
                        PRINTF("\n\t// push normal string\n");
                        ex(p->opr.op[0], 1, lbl_kept);
                        PRINTF("\tputs\n"); 
                    } else {
                        PRINTF("\n\t// push char array\n");
                        putCharArray(p->opr.op[0], 1, lbl_kept);
                    }
                    break;
                case PUTS_:
                    PRINTF("\n\t// Output\n"); 
                    if (!isArrayPtr(p->opr.op[0])) {
                        PRINTF("\n\t// push normal string\n");
                        ex(p->opr.op[0], 1, lbl_kept);
                        PRINTF("\tputs_\n"); 
                    } else {
                        PRINTF("\n\t// push char array\n");
                        putCharArray(p->opr.op[0], 0, lbl_kept);
                    }
                    break;
                case '=':  
                    if (p->opr.op[0]->type != typeOpr) {
                        if (!isArrayPtr(p->opr.op[0]) || p->opr.op[1]->type != typeCon || p->opr.op[1]->con.type != conTypeStr) {
                            if (p->opr.op[0]->type == typeId) {
                                PRINTF("\n\t// variable assignment %s\n", p->opr.op[0]->id.varName); 
                                getRegName(regName, p->opr.op[0]->id.varName, 1);
                                ex(p->opr.op[1], 1, lbl_kept);
                                PRINTF("\n\tpop\t%s\n", regName);
                            } else if (p->opr.op[0]->type == typeArr) {
                                PRINTF("\n\t// array assignment %s\n", p->opr.op[0]->array.baseName); 
                                ex(p->opr.op[1], 1, lbl_kept);
                                PRINTF("\n");
                                pushPtr(p->opr.op[0], lbl_kept);
                                PRINTF("\n\tpop\tac\n");
                                PRINTF("\tpop\tac[0]\n");
                            }
                        } else {
                            PRINTF("\n\t// char array assignment\n");
                            assignCharArray(p->opr.op[0], p->opr.op[1]->con.strValue, lbl_kept);
                        }
                    } else {
                        switch (p->opr.op[0]->opr.oper) {
                            case DECL_ARRAY:
                                PRINTF("\n\t// array declaration & assignment %s\n", p->opr.op[0]->opr.op[0]->array.baseName);
                                
                                // declare
                                ex(p->opr.op[0], 1, lbl_kept);
                                PRINTF("\n");
                                // calculate expression
                                ex(p->opr.op[1], 1, lbl_kept);
                                PRINTF("\n");

                                if (!isScan) assignArray(p->opr.op[0]->opr.op[0], lbl_kept);
                                break;
                            case DEREF:
                                PRINTF("\n\t// dereference assignment\n");

                                // calculate expression
                                ex(p->opr.op[1], 1, lbl_kept);
                                PRINTF("\n");
                                // calculate dereference expression
                                ex(p->opr.op[0]->opr.op[0], 1, lbl_kept);

                                PRINTF("\n\tpop\tac\n"); 
                                PRINTF("\tpop\tac[0]\n");  
                                break;
                            case DOT:
                                PRINTF("\n\t// struct member assignment\n");

                                // calculate expression
                                ex(p->opr.op[1], 1, lbl_kept);
                                PRINTF("\n");
                                // assign
                                assignToStruct(p->opr.op[0], lbl_kept);

                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case UMINUS:    
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("\tneg\n");
                    break;
                case REF:
                    PRINTF("\n\t// variable/array element reference\n");
                    assert((p->opr.op[0]->type == typeId || p->opr.op[0]->type == typeArr) && !isArrayPtr(p->opr.op[0]));
                    pushPtr(p->opr.op[0],lbl_kept);
                    break;
                case DEREF:    
                    // rvalue here, assignment cases handled in '=' case
                    PRINTF("\n\t// variable/array element dereference\n");
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("\n\tpop\tac\n"); 
                    PRINTF("\tpush\tac[0]\n");  
                    break;
                case DOT:
                    PRINTF("\n\t// access struct member .%s\n", p->opr.op[1]->id.varName); 

                    pushPtr(p->opr.op[0], lbl_kept);
                    pushStructOffset(p->opr.op[0], p->opr.op[1]->id.varName);

                    PRINTF("\tadd\n"); 
                    PRINTF("\n\tpop\tac\n"); 
                    PRINTF("\tpush\tac[0]\n");
                    break;
                case CALL:
                    PRINTF("\n\t// function call %s\n", p->opr.op[0]->id.varName); 
                    numOfArgs = pushArgs(p->opr.op[1], lbl_kept);
                    getFuncLabel(labelName, p->opr.op[0]->id.varName);
                    PRINTF("\tcall\t%s, %d\n", labelName, numOfArgs);
                    break;
                case RETURN:
                    ex(p->opr.op[0], 1, lbl_kept);
                    PRINTF("\tret\n");
                    break;
                case DECL_ARRAY:
                    declareArray(regName, &p->opr.op[0]->array, 1, lbl_kept);
                    break;
                case DECL_STRUCT:
                    declareStruct(regName, p, lbl_kept);
                    break;
                case ',':
                    ex(p->opr.op[0], 1, lbl_kept);
                    ex(p->opr.op[1], 1, lbl_kept);
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
                        case SLA:   PRINTF("\tsla\n"); break;
                        case SRA:   PRINTF("\tsra\n"); break;
                        case '&':   PRINTF("\tbitand\n"); break;
                        case '^':   PRINTF("\tbitxor\n"); break;
                        case '|':   PRINTF("\tbitor\n"); break;
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












