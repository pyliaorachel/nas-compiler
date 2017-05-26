/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     CHAR = 259,
     STRING = 260,
     VARIABLE = 261,
     DECL_VARIABLE = 262,
     FOR = 263,
     WHILE = 264,
     IF = 265,
     BREAK = 266,
     CONTINUE = 267,
     RETURN = 268,
     DECL_ARRAY = 269,
     GETI = 270,
     GETS = 271,
     GETC = 272,
     PUTI = 273,
     PUTS = 274,
     PUTC = 275,
     PUTI_ = 276,
     PUTS_ = 277,
     PUTC_ = 278,
     CALL = 279,
     IFX = 280,
     ELSE = 281,
     OR = 282,
     AND = 283,
     NE = 284,
     EQ = 285,
     LE = 286,
     GE = 287,
     DEREF = 288,
     REF = 289,
     UMINUS = 290
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define CHAR 259
#define STRING 260
#define VARIABLE 261
#define DECL_VARIABLE 262
#define FOR 263
#define WHILE 264
#define IF 265
#define BREAK 266
#define CONTINUE 267
#define RETURN 268
#define DECL_ARRAY 269
#define GETI 270
#define GETS 271
#define GETC 272
#define PUTI 273
#define PUTS 274
#define PUTC 275
#define PUTI_ 276
#define PUTS_ 277
#define PUTC_ 278
#define CALL 279
#define IFX 280
#define ELSE 281
#define OR 282
#define AND 283
#define NE 284
#define EQ 285
#define LE 286
#define GE 287
#define DEREF 288
#define REF 289
#define UMINUS 290




/* Copy the first part of user declarations.  */
#line 1 "c6.y"

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
localSymTab* localSymTabs;
nodeListType* funcList;
nodeListType* stmtList;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "c6.y"
{
    int conValue;               /* const value for int and char */
    char conStrValue[500];      /* const value for string */
    char sKey[14];              /* symbol table key (var name) */
    nodeType *nPtr;             /* node pointer */
}
/* Line 193 of yacc.c.  */
#line 209 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 222 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   639

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    39,    52,     2,
      43,    44,    37,    35,    49,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      30,    48,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    50,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    31,    32,    33,    34,    40,    41,
      42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    12,    20,    22,    25,
      31,    37,    43,    49,    55,    61,    67,    73,    79,    82,
      90,    96,   102,   110,   113,   116,   120,   124,   130,   133,
     135,   138,   142,   144,   148,   151,   156,   160,   166,   168,
     172,   173,   175,   177,   180,   182,   184,   187,   191,   196,
     198,   200,   202,   204,   206,   209,   212,   215,   219,   223,
     227,   231,   235,   239,   243,   247,   251,   255,   259,   263,
     267,   271
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    -1,    55,    57,    -1,    55,    56,
      -1,    -1,     7,    43,    62,    44,    45,    58,    46,    -1,
      47,    -1,    67,    47,    -1,    15,    43,    63,    44,    47,
      -1,    17,    43,    63,    44,    47,    -1,    16,    43,    63,
      44,    47,    -1,    18,    43,    67,    44,    47,    -1,    20,
      43,    67,    44,    47,    -1,    19,    43,    67,    44,    47,
      -1,    21,    43,    67,    44,    47,    -1,    23,    43,    67,
      44,    47,    -1,    22,    43,    67,    44,    47,    -1,    60,
      47,    -1,     8,    43,    57,    57,    57,    44,    57,    -1,
       9,    43,    67,    44,    57,    -1,    10,    43,    67,    44,
      57,    -1,    10,    43,    67,    44,    57,    26,    57,    -1,
      11,    47,    -1,    12,    47,    -1,    13,    67,    47,    -1,
      45,    58,    46,    -1,     7,    43,    62,    44,    47,    -1,
      61,    47,    -1,    57,    -1,    58,    57,    -1,    63,    48,
      67,    -1,    59,    -1,    60,    49,    59,    -1,    14,    65,
      -1,    14,    65,    48,    67,    -1,    61,    49,    65,    -1,
      61,    49,    65,    48,    67,    -1,    67,    -1,    62,    49,
      67,    -1,    -1,    64,    -1,    65,    -1,    37,    67,    -1,
       6,    -1,     7,    -1,    66,    50,    -1,    64,    51,    67,
      -1,    66,    50,    51,    67,    -1,     3,    -1,     4,    -1,
       5,    -1,    65,    -1,    64,    -1,    36,    67,    -1,    52,
      67,    -1,    37,    67,    -1,    67,    35,    67,    -1,    67,
      36,    67,    -1,    67,    37,    67,    -1,    67,    39,    67,
      -1,    67,    38,    67,    -1,    67,    30,    67,    -1,    67,
      29,    67,    -1,    67,    34,    67,    -1,    67,    33,    67,
      -1,    67,    31,    67,    -1,    67,    32,    67,    -1,    67,
      28,    67,    -1,    67,    27,    67,    -1,    43,    67,    44,
      -1,     6,    43,    62,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    73,    74,    75,    79,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   108,
     109,   113,   117,   118,   122,   123,   124,   125,   129,   130,
     131,   135,   136,   137,   141,   142,   146,   150,   151,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "CHAR", "STRING", "VARIABLE",
  "DECL_VARIABLE", "FOR", "WHILE", "IF", "BREAK", "CONTINUE", "RETURN",
  "DECL_ARRAY", "GETI", "GETS", "GETC", "PUTI", "PUTS", "PUTC", "PUTI_",
  "PUTS_", "PUTC_", "CALL", "IFX", "ELSE", "OR", "AND", "'>'", "'<'", "NE",
  "EQ", "LE", "GE", "'+'", "'-'", "'*'", "'/'", "'%'", "DEREF", "REF",
  "UMINUS", "'('", "')'", "'{'", "'}'", "';'", "'='", "','", "']'", "'['",
  "'&'", "$accept", "program", "main", "func_decl", "stmt", "stmt_list",
  "assignment", "assignment_list", "array_decl_list", "param_arg_list",
  "lvalue", "variable", "array", "array_list", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    62,
      60,   284,   285,   286,   287,    43,    45,    42,    47,    37,
     288,   289,   290,    40,    41,   123,   125,    59,    61,    44,
      93,    91,    38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    60,    60,    61,    61,    61,    61,    62,    62,
      62,    63,    63,    63,    64,    64,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     7,     1,     2,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     2,     7,
       5,     5,     7,     2,     2,     3,     3,     5,     2,     1,
       2,     3,     1,     3,     2,     4,     3,     5,     1,     3,
       0,     1,     1,     2,     1,     1,     2,     3,     4,     1,
       1,     1,     1,     1,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     2,     1,    49,    50,    51,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     4,     3,    32,     0,     0,     0,    53,    52,     0,
       0,    40,    40,     0,     0,     0,    23,    24,    45,     0,
      53,    52,     0,    44,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,    56,     0,    45,    29,
       0,    55,    18,     0,    28,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,    38,     0,     0,     0,     0,    56,
      25,     0,     0,     0,    41,    42,     0,     0,     0,     0,
       0,     0,     0,     0,    70,    40,    26,    30,    33,    36,
      31,    47,     0,    69,    68,    63,    62,    66,    67,    65,
      64,    57,    58,    59,    61,    60,    71,     0,     0,     0,
       0,     0,    35,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    39,     0,    27,     0,
      20,    21,     9,    11,    10,    12,    14,    13,    15,    17,
      16,     0,    37,     0,     0,     0,     6,    19,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    31,    69,    70,    33,    34,    35,    93,
      36,    50,    51,    39,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int16 yypact[] =
{
     -49,     9,   113,   -49,   -49,   -49,   -49,   -20,   -15,   -11,
       1,     3,     0,     4,    60,    36,     5,     7,    10,    14,
      18,    19,    26,    27,    35,    60,    60,    60,   412,   -49,
      60,   -49,   -49,   -49,   -18,   -10,    44,   -24,    45,   -25,
      52,    60,    60,   412,    60,    60,   -49,   -49,   -49,    60,
      49,   -49,   256,   -49,    49,    47,    -4,    -4,    -4,    60,
      60,    60,    60,    60,    60,   -49,    53,   438,    61,   -49,
     312,   -49,   -49,    -4,   -49,    36,    60,    60,    54,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,   -49,   -39,   600,   -38,   412,   456,   474,   -49,
     -49,    60,    60,     8,    49,   -49,    62,    63,   492,   510,
     528,   546,   564,   582,   -49,    60,   -49,   -49,   -49,    65,
     600,   600,    60,   196,   196,   -17,   -17,   -17,   -17,   -17,
     -17,   -23,   -23,   -49,   -49,   -49,   -49,    60,    -7,   412,
     412,   412,   600,   600,    64,    67,    68,    93,    97,   101,
     104,   105,   106,   -37,    60,   600,   600,   412,   -49,    66,
     -49,    82,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   107,   600,   362,   412,   412,   -49,   -49,   -49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -49,   -49,   -49,   -49,     6,   -48,    84,   -49,   -49,   -41,
     -22,    -2,     2,   -49,   160
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -44
static const yytype_int16 yytable[] =
{
      37,    95,    53,    48,    38,   136,   138,   171,    32,     3,
     137,   137,   137,    54,    89,    90,    91,    55,    87,    88,
      89,    90,    91,    41,   -41,    78,    37,    77,    42,    72,
      38,    73,    43,   102,   103,   106,   107,    74,   157,    75,
     158,    37,    53,    48,    44,    38,    45,    46,    56,    96,
      57,    47,   144,    58,   104,   104,   104,    59,   105,   105,
     105,    60,    61,     4,     5,     6,     7,    48,    37,    62,
      63,   104,    38,    54,   153,   105,   117,   119,    64,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    76,   -42,    37,   101,    25,    49,    38,    92,
      77,   -43,   139,    27,   115,   122,   145,   146,   175,   173,
     174,   162,    30,   154,   163,   164,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    37,    37,    37,
     165,    38,    38,    38,   166,   159,   160,   161,   167,    25,
      26,   168,   169,   170,   158,    37,    27,   118,    28,    38,
      29,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,    37,    37,    37,    52,    38,    38,    38,     0,   117,
     177,   178,     0,     0,     0,    65,    66,    67,     0,     0,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    94,     0,    97,    98,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   120,   121,     0,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,   155,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,   156,     0,     0,
       0,     0,     0,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   172,     4,     5,     6,     7,    68,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,     0,    27,     0,    28,   116,    29,
       0,     0,     0,     0,    30,     4,     5,     6,     7,    68,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,     0,    27,     0,    28,   176,    29,
       0,     0,     0,     0,    30,     4,     5,     6,     7,    68,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
       0,     0,     0,     0,     0,    27,     0,    28,     0,    29,
       0,     0,     0,     0,    30,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,     0,   114,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
     140,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,   141,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,   147,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,     0,   148,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,     0,   149,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
     150,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,   151,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,   152,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
       2,    42,     6,     7,     2,    44,    44,    44,     2,     0,
      49,    49,    49,    15,    37,    38,    39,    15,    35,    36,
      37,    38,    39,    43,    48,    50,    28,    51,    43,    47,
      28,    49,    43,    37,    56,    57,    58,    47,    45,    49,
      47,    43,     6,     7,    43,    43,    43,    47,    43,    43,
      43,    47,    44,    43,    56,    57,    58,    43,    56,    57,
      58,    43,    43,     3,     4,     5,     6,     7,    70,    43,
      43,    73,    70,    75,   115,    73,    70,    75,    43,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    48,    48,    96,    48,    36,    37,    96,    47,
      51,    48,    96,    43,    43,    51,    44,    44,    26,   157,
      44,    47,    52,    48,    47,    47,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   139,   140,   141,
      47,   139,   140,   141,    47,   139,   140,   141,    47,    36,
      37,    47,    47,    47,    47,   157,    43,    73,    45,   157,
      47,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      -1,   173,   174,   175,    14,   173,   174,   175,    -1,   173,
     174,   175,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    -1,    44,    45,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    76,    77,    -1,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   154,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    -1,    47,
      -1,    -1,    -1,    -1,    52,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    44,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    44,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    44,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    44,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    44,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    44,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,    55,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    36,    37,    43,    45,    47,
      52,    56,    57,    59,    60,    61,    63,    64,    65,    66,
      67,    43,    43,    43,    43,    43,    47,    47,     7,    37,
      64,    65,    67,     6,    64,    65,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    67,    67,    67,     7,    57,
      58,    67,    47,    49,    47,    49,    48,    51,    50,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    47,    62,    67,    62,    57,    67,    67,    67,
      47,    48,    37,    63,    64,    65,    63,    63,    67,    67,
      67,    67,    67,    67,    44,    43,    46,    57,    59,    65,
      67,    67,    51,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    44,    49,    44,    57,
      44,    44,    67,    67,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    62,    48,    67,    67,    45,    47,    57,
      57,    57,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    44,    67,    58,    44,    26,    46,    57,    57
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 64 "c6.y"
    { 
                                preProcess();
                                exStmtList(); 
                                exFuncList(); 
                                wrapUp(); 
                            }
    break;

  case 3:
#line 73 "c6.y"
    { appendToList(stmtList, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 4:
#line 74 "c6.y"
    { appendToList(funcList, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 6:
#line 79 "c6.y"
    { (yyval.nPtr) = func((yyvsp[(1) - (7)].sKey), (yyvsp[(3) - (7)].nPtr), (yyvsp[(6) - (7)].nPtr)); }
    break;

  case 7:
#line 83 "c6.y"
    { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
    break;

  case 8:
#line 84 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 9:
#line 85 "c6.y"
    { (yyval.nPtr) = opr(GETI, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 10:
#line 86 "c6.y"
    { (yyval.nPtr) = opr(GETC, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 11:
#line 87 "c6.y"
    { (yyval.nPtr) = opr(GETS, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 12:
#line 88 "c6.y"
    { (yyval.nPtr) = opr(PUTI, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 13:
#line 89 "c6.y"
    { (yyval.nPtr) = opr(PUTC, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 14:
#line 90 "c6.y"
    { (yyval.nPtr) = opr(PUTS, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 15:
#line 91 "c6.y"
    { (yyval.nPtr) = opr(PUTI_, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 16:
#line 92 "c6.y"
    { (yyval.nPtr) = opr(PUTC_, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 17:
#line 93 "c6.y"
    { (yyval.nPtr) = opr(PUTS_, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 18:
#line 94 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 19:
#line 95 "c6.y"
    { (yyval.nPtr) = opr(FOR, 4, (yyvsp[(3) - (7)].nPtr), (yyvsp[(4) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr)); }
    break;

  case 20:
#line 96 "c6.y"
    { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 21:
#line 97 "c6.y"
    { (yyval.nPtr) = opr(IF, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 22:
#line 98 "c6.y"
    { (yyval.nPtr) = opr(IF, 3, (yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr)); }
    break;

  case 23:
#line 99 "c6.y"
    { (yyval.nPtr) = opr(BREAK, 2, NULL, NULL); }
    break;

  case 24:
#line 100 "c6.y"
    { (yyval.nPtr) = opr(CONTINUE, 2, NULL, NULL); }
    break;

  case 25:
#line 101 "c6.y"
    { (yyval.nPtr) = opr(RETURN, 1, (yyvsp[(2) - (3)].nPtr)); }
    break;

  case 26:
#line 102 "c6.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 27:
#line 103 "c6.y"
    { (yyval.nPtr) = opr(CALL, 2, id((yyvsp[(1) - (5)].sKey)), (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 28:
#line 104 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 29:
#line 108 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 30:
#line 109 "c6.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 31:
#line 113 "c6.y"
    { (yyval.nPtr) = opr('=', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 32:
#line 117 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 33:
#line 118 "c6.y"
    { (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 34:
#line 122 "c6.y"
    { (yyval.nPtr) = opr(DECL_ARRAY, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 35:
#line 123 "c6.y"
    { (yyval.nPtr) = opr('=', 2, opr(DECL_ARRAY, 1, (yyvsp[(2) - (4)].nPtr)), (yyvsp[(4) - (4)].nPtr)); }
    break;

  case 36:
#line 124 "c6.y"
    { (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), opr(DECL_ARRAY, 1, (yyvsp[(3) - (3)].nPtr))); }
    break;

  case 37:
#line 125 "c6.y"
    { (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (5)].nPtr), opr('=', 2, opr(DECL_ARRAY, 1, (yyvsp[(3) - (5)].nPtr)), (yyvsp[(5) - (5)].nPtr))); }
    break;

  case 38:
#line 129 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 39:
#line 130 "c6.y"
    { (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 40:
#line 131 "c6.y"
    { (yyval.nPtr) = NULL; }
    break;

  case 41:
#line 135 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 42:
#line 136 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 43:
#line 137 "c6.y"
    { (yyval.nPtr) = opr(DEREF, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 44:
#line 141 "c6.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (1)].sKey)); }
    break;

  case 45:
#line 142 "c6.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (1)].sKey)); }
    break;

  case 46:
#line 146 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 47:
#line 150 "c6.y"
    { (yyval.nPtr) = array((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 48:
#line 151 "c6.y"
    { (yyval.nPtr) = extendArray((yyvsp[(1) - (4)].nPtr), (yyvsp[(4) - (4)].nPtr)); }
    break;

  case 49:
#line 155 "c6.y"
    { (yyval.nPtr) = con((yyvsp[(1) - (1)].conValue), conTypeInt); }
    break;

  case 50:
#line 156 "c6.y"
    { (yyval.nPtr) = con((yyvsp[(1) - (1)].conValue), conTypeChar); }
    break;

  case 51:
#line 157 "c6.y"
    { (yyval.nPtr) = con((long) (yyvsp[(1) - (1)].conStrValue), conTypeStr); }
    break;

  case 52:
#line 158 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 53:
#line 159 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 54:
#line 160 "c6.y"
    { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 55:
#line 161 "c6.y"
    { (yyval.nPtr) = opr(REF, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 56:
#line 162 "c6.y"
    { (yyval.nPtr) = opr(DEREF, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 57:
#line 163 "c6.y"
    { 
                                    if ((yyvsp[(1) - (3)].nPtr)->type == typeCon && (yyvsp[(1) - (3)].nPtr)->con.type == conTypeStr &&
                                        (yyvsp[(3) - (3)].nPtr)->type == typeCon && (yyvsp[(3) - (3)].nPtr)->con.type == conTypeStr) {
                                        (yyval.nPtr) = strConcat((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
                                    } else {
                                        (yyval.nPtr) = opr('+', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); 
                                    }
                                }
    break;

  case 58:
#line 171 "c6.y"
    { (yyval.nPtr) = opr('-', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 59:
#line 172 "c6.y"
    { (yyval.nPtr) = opr('*', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 60:
#line 173 "c6.y"
    { (yyval.nPtr) = opr('%', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 61:
#line 174 "c6.y"
    { (yyval.nPtr) = opr('/', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 62:
#line 175 "c6.y"
    { (yyval.nPtr) = opr('<', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 63:
#line 176 "c6.y"
    { (yyval.nPtr) = opr('>', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 64:
#line 177 "c6.y"
    { (yyval.nPtr) = opr(GE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 65:
#line 178 "c6.y"
    { (yyval.nPtr) = opr(LE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 66:
#line 179 "c6.y"
    { (yyval.nPtr) = opr(NE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 67:
#line 180 "c6.y"
    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 68:
#line 181 "c6.y"
    { (yyval.nPtr) = opr(AND, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 69:
#line 182 "c6.y"
    { (yyval.nPtr) = opr(OR, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 70:
#line 183 "c6.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 71:
#line 184 "c6.y"
    { (yyval.nPtr) = opr(CALL, 2, id((yyvsp[(1) - (4)].sKey)), (yyvsp[(3) - (4)].nPtr)); }
    break;


/* Line 1267 of yacc.c.  */
#line 2008 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 187 "c6.y"


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





