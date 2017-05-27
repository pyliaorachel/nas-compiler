%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include "calc3.h"
#include "strmap.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(char* varName);
nodeType *array(nodeType* idNode, nodeType *offset);
nodeType *extendArray(nodeType *p, nodeType *offset);
nodeType *con(long value, conTypeEnum type);
nodeType *func(char* funcName, nodeType *paramList, nodeType *stmt);
nodeType *sct(char* structName, nodeType *memberList);
nodeType *strConcat(nodeType* s1, nodeType* s2);
void appendToList(nodeListType* nodeList, nodeType* node);
void freeNode(nodeType *p);
void freeNodeList(nodeListType* nodeList);
void programStarts(void);
void programEnds(void);
int ex(nodeType *p, int nops, ...);
void preProcess();
void exStmtList(); 
void exFuncList(); 
int yylex(void);
void wrapUp(void);

void yyerror(char *s);
symTab* globalSymTab;
symTab* funcSymTab;
symTab* structSymTab;
localSymTab* localSymTabs;
nodeListType* funcList;
nodeListType* stmtList;
nodeListType* structList;
%}

%union {
    int conValue;               /* const value for int and char */
    char conStrValue[500];      /* const value for string */
    char sKey[14];              /* symbol table key (var name) */
    nodeType *nPtr;             /* node pointer */
};

%token <conValue> INTEGER CHAR
%token <conStrValue> STRING
%token <sKey> VARIABLE DECL_VARIABLE
%token FOR WHILE IF BREAK CONTINUE RETURN DECL_ARRAY DEF_STRUCT_TYPE DECL_STRUCT
%token GETI GETS GETC PUTI PUTS PUTC PUTI_ PUTS_ PUTC_ CALL
%nonassoc IFX
%nonassoc ELSE

%left AND OR

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS REF DEREF DOT

%type <nPtr> func_decl struct_def stmt expr stmt_list assignment assignment_list array_decl_list struct_decl_list lvalue variable array array_list struct value_list

%%

program:
        main                { 
                                preProcess();
                                exStmtList(); 
                                exFuncList(); 
                                wrapUp(); 
                            }
        ;

main:
          main stmt         { appendToList(stmtList, $2); }
        | main func_decl    { appendToList(funcList, $2); }
        | main struct_def  { appendToList(structList, $2); }
        | /* NULL */
        ;

func_decl:
          DECL_VARIABLE '(' value_list ')' '{' stmt_list '}'    { $$ = func($1, $3, $6); }
        ;

struct_def:
          DEF_STRUCT_TYPE VARIABLE '{' value_list '}'               { $$ = sct($2, $4); }
        ;

stmt:
          ';'                                                   { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                                              { $$ = $1; }
        | GETI '(' lvalue ')' ';'                               { $$ = opr(GETI, 1, $3); }
        | GETC '(' lvalue ')' ';'                               { $$ = opr(GETC, 1, $3); }
        | GETS '(' lvalue ')' ';'                               { $$ = opr(GETS, 1, $3); }
        | PUTI '(' expr ')' ';'                                 { $$ = opr(PUTI, 1, $3); }
        | PUTC '(' expr ')' ';'                                 { $$ = opr(PUTC, 1, $3); }
        | PUTS '(' expr ')' ';'                                 { $$ = opr(PUTS, 1, $3); }
        | PUTI_ '(' expr ')' ';'                                { $$ = opr(PUTI_, 1, $3); }
        | PUTC_ '(' expr ')' ';'                                { $$ = opr(PUTC_, 1, $3); }
        | PUTS_ '(' expr ')' ';'                                { $$ = opr(PUTS_, 1, $3); }
        | assignment_list ';'                                   { $$ = $1; }
        | FOR '(' stmt stmt stmt ')' stmt                       { $$ = opr(FOR, 4, $3, $4, $5, $7); }
        | WHILE '(' expr ')' stmt                               { $$ = opr(WHILE, 2, $3, $5); }
        | IF '(' expr ')' stmt %prec IFX                        { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt                        { $$ = opr(IF, 3, $3, $5, $7); }
        | BREAK ';'                                             { $$ = opr(BREAK, 2, NULL, NULL); }
        | CONTINUE ';'                                          { $$ = opr(CONTINUE, 2, NULL, NULL); }
        | RETURN expr ';'                                       { $$ = opr(RETURN, 1, $2); }
        | '{' stmt_list '}'                                     { $$ = $2; }
        | DECL_VARIABLE '(' value_list ')' ';'                  { $$ = opr(CALL, 2, id($1), $3); }
        | array_decl_list ';'                                   { $$ = $1; }
        | struct_decl_list ';'                                  { $$ = $1; }
        ;

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

assignment:
          lvalue '=' expr                           { $$ = opr('=', 2, $1, $3); }
        ;

assignment_list:
          assignment                                { $$ = $1; }
        | assignment_list ',' assignment            { $$ = opr(',', 2, $1, $3); }
        ;

array_decl_list:
          DECL_ARRAY array                          { $$ = opr(DECL_ARRAY, 1, $2); }
        | DECL_ARRAY array '=' expr                 { $$ = opr('=', 2, opr(DECL_ARRAY, 1, $2), $4); }
        | array_decl_list ',' array                 { $$ = opr(',', 2, $1, opr(DECL_ARRAY, 1, $3)); }
        | array_decl_list ',' array '=' expr        { $$ = opr(',', 2, $1, opr('=', 2, opr(DECL_ARRAY, 1, $3), $5)); }
        ;

value_list:   
          expr                              { $$ = $1; }
        | value_list ',' expr               { $$ = opr(',', 2, $1, $3); }
        | /* NULL */                        { $$ = NULL; }
        ;

lvalue:
          variable                          { $$ = $1; }
        | array                             { $$ = $1; }
        | '*' expr %prec DEREF              { $$ = opr(DEREF, 1, $2); }
        ;

variable:
          VARIABLE                          { $$ = id($1); }
        | DECL_VARIABLE                     { $$ = id($1); }
        ;

array:
          array_list ']'                    { $$ = $1; }
        ;

array_list:
          variable '[' expr                 { $$ = array($1, $3); }
        | array_list ']' '[' expr           { $$ = extendArray($1, $4); }
        ;

struct_decl_list:
          '<' variable '>' variable         { $$ = opr(DECL_STRUCT, 2, $2, $4); }
        | struct_decl_list ',' variable     { 
                                                if ($1->opr.op[0]->type == typeId) {
                                                    // the second element
                                                    $$ = opr(',', 2, $1, opr(DECL_STRUCT, 2, id($1->opr.op[0]->id.varName), $3)); 
                                                } else {
                                                    $$ = opr(',', 2, $1, opr(DECL_STRUCT, 2, id($1->opr.op[1]->opr.op[0]->id.varName), $3)); 
                                                }
                                            }
        ;

struct:
          variable '.' variable             { $$ = opr(DOT, 2, $1, $3); }
        ;

expr:
          INTEGER               { $$ = con($1, conTypeInt); }
        | CHAR                  { $$ = con($1, conTypeChar); }
        | STRING                { $$ = con((long) $1, conTypeStr); }
        | array                 { $$ = $1; }
        | variable              { $$ = $1; }
        | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
        | '&' expr %prec REF    { $$ = opr(REF, 1, $2); }
        | '*' expr %prec DEREF  { $$ = opr(DEREF, 1, $2); }
        | expr '+' expr         { 
                                    if ($1->type == typeCon && $1->con.type == conTypeStr &&
                                        $3->type == typeCon && $3->con.type == conTypeStr) {
                                        $$ = strConcat($1, $3);
                                    } else {
                                        $$ = opr('+', 2, $1, $3); 
                                    }
                                }
        | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
        | expr '%' expr         { $$ = opr('%', 2, $1, $3); }
        | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
        | expr '<' expr         { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
        | expr GE expr          { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr          { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr          { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr          { $$ = opr(EQ, 2, $1, $3); }
        | expr AND expr         { $$ = opr(AND, 2, $1, $3); }
        | expr OR expr          { $$ = opr(OR, 2, $1, $3); }
        | '(' expr ')'          { $$ = $2; }
        | VARIABLE '(' value_list ')' { $$ = opr(CALL, 2, id($1), $3); }
        ;

%%

#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)

nodeType *con(long value, conTypeEnum type) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.type = type;
    if (type == conTypeStr) {
        strcpy(p->con.strValue, (char*) value);
    } else {
        p->con.value = (int) value;
    }

    return p;
}

nodeType *id(char* varName) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    strcpy(p->id.varName, varName);
    p->id.type = conTypeNull;

    return p;
}

nodeType *array(nodeType *idNode, nodeType *offset) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(arrayNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeArr;
    strcpy(p->array.baseName, idNode->id.varName);
    p->array.offsetListHead = (arrayOffsetNodeType*) malloc(sizeof(arrayOffsetNodeType));
    p->array.offsetListHead->offset = offset;
    p->array.offsetListHead->next = NULL;
    p->array.offsetListTail = p->array.offsetListHead;
    p->array.dim = 1;

    /* dump id node */
    freeNode(idNode);

    return p;
}

nodeType *extendArray(nodeType *p, nodeType *offset) {
    arrayOffsetNodeType* n = (arrayOffsetNodeType*) malloc(sizeof(arrayOffsetNodeType));
    n->offset = offset;
    n->next = NULL;

    // append
    p->array.offsetListTail->next = n;
    p->array.offsetListTail = n;

    p->array.dim += 1;
    return p;
}

nodeType *func(char* funcName, nodeType *paramList, nodeType *stmt) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(funcNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeFunc;
    strcpy(p->func.funcName, funcName);
    p->func.paramList = paramList;
    p->func.stmt = stmt;
    p->func.numOfLocalVars = 0;
    p->func.numOfParams = 0;

    return p;
}

nodeType *sct(char* structName, nodeType *memberList) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(structNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeStruct;
    strcpy(p->sct.structName, structName);
    p->sct.memberList = memberList;
    p->sct.numOfMembers = 0;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    size_t nodeSize;
    int i;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(oprNodeType) +
        (nops - 1) * sizeof(nodeType*);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

nodeType* strConcat(nodeType* s1, nodeType* s2) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.type = conTypeStr;
    strcpy(p->con.strValue, strcat(s1->con.strValue, s2->con.strValue));

    /* free 2 nodes */
    freeNode(s1);
    freeNode(s2);

    return p;
}

void appendToList(nodeListType* nodeList, nodeType* node) {
    nodeListNodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeListNodeType))) == NULL)
        yyerror("out of memory");

    p->node = node;
    p->next = NULL;
    if (nodeList->tail) {
        nodeList->tail->next = p;
        nodeList->tail = p;
    } else {
        nodeList->head = p;
        nodeList->tail = p;
    }
    nodeList->nops++;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    } else if (p->type == typeArr) {
        arrayOffsetNodeType* n = p->array.offsetListHead;
        while (n) {
            p->array.offsetListHead = n->next;
            free(n);
            n = p->array.offsetListHead;
        }
    }
    free (p);
}

void freeNodeList(nodeListType* nodeList) {
    nodeListNodeType *p = nodeList->head;

    while (p) {
        nodeList->head = p->next;
        freeNode(p->node);
        free(p);
        p = nodeList->head;
    }

    free(nodeList);
}

void wrapUp() {
    programEnds();
    exit(0);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(int argc, char **argv) {
    extern FILE* yyin;
    yyin = fopen(argv[1], "r");
    programStarts();
    yyparse();
    return 0;
}




