%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "calc3.h"
#include "strmap.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(char* varName);
nodeType *array(char* baseName, nodeType *offset);
nodeType *con(long value, conTypeEnum type);
nodeType *func(char* funcName, nodeType *paramList, nodeType *stmt);
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
StrMap* globalSymTab;
StrMap* funcSymTab;
localSymTab* localSymTabs;
nodeListType* funcList;
nodeListType* stmtList;
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
%token FOR WHILE IF BREAK CONTINUE RETURN
%token GETI GETS GETC PUTI PUTS PUTC PUTI_ PUTS_ PUTC_
%nonassoc IFX
%nonassoc ELSE

%left AND OR

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%type <nPtr> func_decl stmt expr stmt_list variable array param param_list arg arg_list

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
        | /* NULL */
        ;

func_decl:
          DECL_VARIABLE '(' param_list ')' '{' stmt_list '}'    { $$ = func($1, $3, $6); }
        ;

stmt:
          ';'                                                   { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                                              { $$ = $1; }
        | GETI '(' variable ')' ';'                             { $$ = opr(GETI, 1, $3); }
        | GETC '(' variable ')' ';'                             { $$ = opr(GETC, 1, $3); }
        | GETS '(' variable ')' ';'                             { $$ = opr(GETS, 1, $3); }
        | PUTI '(' arg ')' ';'                                  { $$ = opr(PUTI, 1, $3); }
        | PUTC '(' arg ')' ';'                                  { $$ = opr(PUTC, 1, $3); }
        | PUTS '(' arg ')' ';'                                  { $$ = opr(PUTS, 1, $3); }
        | PUTI_ '(' arg ')' ';'                                 { $$ = opr(PUTI_, 1, $3); }
        | PUTC_ '(' arg ')' ';'                                 { $$ = opr(PUTC_, 1, $3); }
        | PUTS_ '(' arg ')' ';'                                 { $$ = opr(PUTS_, 1, $3); }
        | variable '=' expr ';'                                 { $$ = opr('=', 2, $1, $3); }
        | array '=' expr ';'                                    { $$ = opr('=', 2, $1, $3); }
        | FOR '(' stmt stmt stmt ')' stmt                       { $$ = opr(FOR, 4, $3, $4, $5, $7); }
        | WHILE '(' expr ')' stmt                               { $$ = opr(WHILE, 2, $3, $5); }
        | IF '(' expr ')' stmt %prec IFX                        { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt                        { $$ = opr(IF, 3, $3, $5, $7); }
        | BREAK ';'                                             { $$ = opr(BREAK, 2, NULL, NULL); }
        | CONTINUE ';'                                          { $$ = opr(CONTINUE, 2, NULL, NULL); }
        | RETURN expr ';'                                       { $$ = opr(RETURN, 1, $2); }
        | '{' stmt_list '}'                                     { $$ = $2; }
        ;

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

param:
          variable              { $$ = $1; }
        | /* NULL */            { $$ = NULL; }
        ;

param_list:
          param                 { $$ = $1; }
        | param_list ',' param  { $$ = opr(',', 2, $1, $3); }
        ;

arg:
          expr                  { $$ = $1; }
        | /* NULL */            { $$ = NULL; }
        ;

arg_list:   
          arg                   { $$ = $1; }
        | arg_list ',' arg      { $$ = opr(',', 2, $1, $3); }
        ;

variable:
          VARIABLE              { $$ = id($1); }
        | DECL_VARIABLE         { $$ = id($1); }
        ;

array:
          VARIABLE '[' expr ']' { $$ = array($1, $3); }
        ;

expr:
          INTEGER               { $$ = con($1, conTypeInt); }
        | CHAR                  { $$ = con($1, conTypeChar); }
        | STRING                { $$ = con((long) $1, conTypeStr); }
        | variable              { $$ = $1; }
        | array                 { $$ = $1; }
        | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
        | expr '+' expr         { $$ = opr('+', 2, $1, $3); }
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
        | VARIABLE '(' arg_list ')' { $$ = opr('c', 2, id($1), $3); }
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

nodeType *array(char* baseName, nodeType *offset) {
    nodeType *p;
    size_t nodeSize;

    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(arrayNodeType);
    if ((p = malloc(nodeSize)) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeArr;
    strcpy(p->array.baseName, baseName);
    p->array.offset = offset;

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




