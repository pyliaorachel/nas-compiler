#include "strmap.h"

typedef enum { typeCon, typeId, typeArr, typeOpr } nodeEnum;
typedef enum { conTypeInt, conTypeChar, conTypeStr } conTypeEnum;

/* constants */
typedef struct {
    conTypeEnum type;
    int value;                  /* value of constant */
    char strValue[500];
} conNodeType;

/* identifiers */
typedef struct {
    char varName[14];                /* subscript to sym array */
} idNodeType;

/* arrays */
typedef struct {
    char baseName[14];
    struct nodeTypeTag *offset;
} arrayNodeType;

/* operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    struct nodeTypeTag *op[1];  /* operands (expandable) */
} oprNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    /* union must be last entry in nodeType */
    /* because operNodeType may dynamically increase */
    union {
        conNodeType con;        /* constants */
        idNodeType id;          /* identifiers */
        arrayNodeType array;
        oprNodeType opr;        /* operators */
    };
} nodeType;

#define GLOBAL_SIZE 100
#define LOCAL_SIZE 100
#define FUNC_SIZE 100

extern StrMap* globalSymTab;
extern StrMap* funcSymTab;