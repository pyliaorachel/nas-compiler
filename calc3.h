#include "strmap.h"

typedef enum { typeCon, typeId, typeArr, typeOpr, typeFunc } nodeEnum;
typedef enum { listTypeFunc, listTypeStmt } nodeListEnum;
typedef enum { conTypeInt, conTypeChar, conTypeStr, conTypeNull } conTypeEnum;

/* constants */
typedef struct {
    conTypeEnum type;
    int value;                  /* value of constant */
    char strValue[500];
    /* TODO: union */
} conNodeType;

/* identifiers */
typedef struct {
    conTypeEnum type;
    char varName[14];                /* subscript to sym array */
} idNodeType;

/* arrays */
typedef struct {
    char baseName[14];
    struct nodeTypeTag *offset;
} arrayNodeType;

/* functions */
typedef struct {
    char funcName[14];
    struct nodeTypeTag *paramList;
    struct nodeTypeTag *stmt;
} funcNodeType;

/* operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag *op[1];  /* operands (expandable) */
} oprNodeType;

/* node linked list (global funcitons & statements) */
typedef struct nodeListNodeType {
    struct nodeTypeTag *node;            /* type of node list */
    struct nodeListNodeType *next;
} nodeListNodeType;

typedef struct {
    nodeListEnum type;                   /* type of node list */
    int nops;                            /* number of operands */
    struct nodeListNodeType *head;
    struct nodeListNodeType *tail;
} nodeListType;

/* node type */
typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    /* union must be last entry in nodeType */
    /* because operNodeType may dynamically increase */
    union {
        conNodeType con;        /* constants */
        idNodeType id;          /* identifiers */
        arrayNodeType array;
        funcNodeType func;
        oprNodeType opr;        /* operators */
    };
} nodeType;

typedef struct localSymTab {
    StrMap* symTab;
    int numOfParams;
    int numOfLocalVars;
    struct localSymTab* prev;
} localSymTab;

#define GLOBAL_SIZE 100
#define LOCAL_SIZE 100
#define FUNC_SIZE 100

extern StrMap* globalSymTab;
extern StrMap* funcSymTab;
extern localSymTab* localSymTabs;
extern nodeListType* funcList;
extern nodeListType* stmtList;



