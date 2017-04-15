typedef enum { typeCon, typeId, typeArr, typeOpr } nodeEnum;
typedef enum { conTypeInt, conTypeChar, conTypeStr } conTypeEnum;

/* constants */
typedef struct {
    conTypeEnum type;
    long value;                  /* value of constant */
} conNodeType;

/* identifiers */
typedef struct {
    int i;                      /* subscript to sym array */
} idNodeType;

/* arrays */
typedef struct {
    int base;
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
