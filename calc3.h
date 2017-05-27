#include "strmap.h"

typedef enum { typeCon, typeId, typeArr, typeOpr, typeFunc, typeStruct } nodeEnum;
typedef enum { listTypeFunc, listTypeStmt, listTypeStruct } nodeListEnum;
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
typedef struct arrayOffsetNodeType {
    struct nodeTypeTag *offset;
    struct arrayOffsetNodeType *next;
} arrayOffsetNodeType;

typedef struct {
    struct arrayOffsetNodeType *offsetListHead;
    struct arrayOffsetNodeType *offsetListTail;
    int dim;
    int size;
    char baseName[14];
} arrayNodeType ;

/* functions */
typedef struct {
    struct nodeTypeTag *paramList;
    struct nodeTypeTag *stmt;
    int numOfParams;
    int numOfLocalVars;
    char funcName[14];
} funcNodeType;

/* struct */
typedef struct {
    struct nodeTypeTag *memberList;
    int numOfMembers;
    char structName[14];
} structNodeType;

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
        structNodeType sct;
        oprNodeType opr;        /* operators */
    };
} nodeType;

/* symbol tables */
typedef struct symTab {
    StrMap* symTab;
    StrMap* arrayDimTab;
    int size;
} symTab;

typedef struct localSymTab {
    StrMap* symTab;
    StrMap* arrayDimTab;
    int size;
    int numOfParams;
    int numOfLocalVars;
    struct localSymTab* prev;
} localSymTab;

#define GLOBAL_SIZE 500
#define LOCAL_SIZE 200
#define FUNC_SIZE 200
#define STRUCT_SIZE 200

#define LABEL_NAME_L 6
#define REG_NAME_L 100
#define VAR_NAME_L 20
#define CONST_STRING_L 500
#define DIM_STR_L 100
#define LOG_NUM_OF_MEMBERS 3 // max 999 members in struct

extern symTab* globalSymTab;
extern symTab* funcSymTab;
extern symTab* structSymTab;
extern localSymTab* localSymTabs;
extern nodeListType* funcList;
extern nodeListType* stmtList;
extern nodeListType* structList;



