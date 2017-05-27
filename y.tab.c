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
     DEF_STRUCT_TYPE = 270,
     DECL_STRUCT = 271,
     GETI = 272,
     GETS = 273,
     GETC = 274,
     PUTI = 275,
     PUTS = 276,
     PUTC = 277,
     PUTI_ = 278,
     PUTS_ = 279,
     PUTC_ = 280,
     CALL = 281,
     IFX = 282,
     ELSE = 283,
     OR = 284,
     AND = 285,
     NE = 286,
     EQ = 287,
     LE = 288,
     GE = 289,
     DOT = 290,
     DEREF = 291,
     REF = 292,
     UMINUS = 293
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
#define DEF_STRUCT_TYPE 270
#define DECL_STRUCT 271
#define GETI 272
#define GETS 273
#define GETC 274
#define PUTI 275
#define PUTS 276
#define PUTC 277
#define PUTI_ 278
#define PUTS_ 279
#define PUTC_ 280
#define CALL 281
#define IFX 282
#define ELSE 283
#define OR 284
#define AND 285
#define NE 286
#define EQ 287
#define LE 288
#define GE 289
#define DOT 290
#define DEREF 291
#define REF 292
#define UMINUS 293




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
#line 40 "c6.y"
{
    int conValue;               /* const value for int and char */
    char conStrValue[500];      /* const value for string */
    char sKey[14];              /* symbol table key (var name) */
    nodeType *nPtr;             /* node pointer */
}
/* Line 193 of yacc.c.  */
#line 218 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 231 "y.tab.c"

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
#define YYLAST   710

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    41,    56,     2,
      46,    47,    39,    37,    52,    38,    55,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
      32,    51,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    33,    34,    35,    36,
      42,    43,    44,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    15,    23,    29,
      31,    34,    40,    46,    52,    58,    64,    70,    76,    82,
      88,    91,    99,   105,   111,   119,   122,   125,   129,   133,
     139,   142,   145,   147,   150,   154,   156,   160,   163,   168,
     172,   178,   180,   184,   185,   187,   189,   192,   194,   196,
     198,   201,   205,   210,   215,   220,   224,   228,   232,   236,
     238,   240,   242,   244,   246,   248,   251,   254,   257,   261,
     265,   269,   273,   277,   281,   285,   289,   293,   297,   301,
     305,   309,   313
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    59,    62,    -1,    59,    60,
      -1,    59,    61,    -1,    -1,     7,    46,    67,    47,    48,
      63,    49,    -1,    15,     6,    48,    67,    49,    -1,    50,
      -1,    74,    50,    -1,    17,    46,    68,    47,    50,    -1,
      19,    46,    68,    47,    50,    -1,    18,    46,    68,    47,
      50,    -1,    20,    46,    74,    47,    50,    -1,    22,    46,
      74,    47,    50,    -1,    21,    46,    74,    47,    50,    -1,
      23,    46,    74,    47,    50,    -1,    25,    46,    74,    47,
      50,    -1,    24,    46,    74,    47,    50,    -1,    65,    50,
      -1,     8,    46,    62,    62,    62,    47,    62,    -1,     9,
      46,    74,    47,    62,    -1,    10,    46,    74,    47,    62,
      -1,    10,    46,    74,    47,    62,    28,    62,    -1,    11,
      50,    -1,    12,    50,    -1,    13,    74,    50,    -1,    48,
      63,    49,    -1,     7,    46,    67,    47,    50,    -1,    66,
      50,    -1,    72,    50,    -1,    62,    -1,    63,    62,    -1,
      68,    51,    74,    -1,    64,    -1,    65,    52,    64,    -1,
      14,    70,    -1,    14,    70,    51,    74,    -1,    66,    52,
      70,    -1,    66,    52,    70,    51,    74,    -1,    74,    -1,
      67,    52,    74,    -1,    -1,    69,    -1,    70,    -1,    39,
      74,    -1,    73,    -1,     6,    -1,     7,    -1,    71,    53,
      -1,    69,    54,    74,    -1,    71,    53,    54,    74,    -1,
      32,    69,    31,    69,    -1,    32,    69,    31,    70,    -1,
      72,    52,    69,    -1,    72,    52,    70,    -1,    69,    55,
      69,    -1,    70,    55,    69,    -1,     3,    -1,     4,    -1,
       5,    -1,    70,    -1,    69,    -1,    73,    -1,    38,    74,
      -1,    56,    74,    -1,    39,    74,    -1,    74,    37,    74,
      -1,    74,    38,    74,    -1,    74,    39,    74,    -1,    74,
      41,    74,    -1,    74,    40,    74,    -1,    74,    32,    74,
      -1,    74,    31,    74,    -1,    74,    36,    74,    -1,    74,
      35,    74,    -1,    74,    33,    74,    -1,    74,    34,    74,
      -1,    74,    30,    74,    -1,    74,    29,    74,    -1,    46,
      74,    47,    -1,     6,    46,    67,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    76,    77,    78,    79,    83,    87,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   117,   118,   122,   126,   127,   131,   132,   133,
     134,   138,   139,   140,   144,   145,   146,   147,   151,   152,
     156,   160,   161,   165,   166,   167,   175,   186,   187,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "CHAR", "STRING", "VARIABLE",
  "DECL_VARIABLE", "FOR", "WHILE", "IF", "BREAK", "CONTINUE", "RETURN",
  "DECL_ARRAY", "DEF_STRUCT_TYPE", "DECL_STRUCT", "GETI", "GETS", "GETC",
  "PUTI", "PUTS", "PUTC", "PUTI_", "PUTS_", "PUTC_", "CALL", "IFX", "ELSE",
  "OR", "AND", "'>'", "'<'", "NE", "EQ", "LE", "GE", "'+'", "'-'", "'*'",
  "'/'", "'%'", "DOT", "DEREF", "REF", "UMINUS", "'('", "')'", "'{'",
  "'}'", "';'", "'='", "','", "']'", "'['", "'.'", "'&'", "$accept",
  "program", "main", "func_decl", "struct_def", "stmt", "stmt_list",
  "assignment", "assignment_list", "array_decl_list", "value_list",
  "lvalue", "variable", "array", "array_list", "struct_decl_list",
  "struct", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    62,    60,   286,   287,   288,   289,    43,    45,    42,
      47,    37,   290,   291,   292,   293,    40,    41,   123,   125,
      59,    61,    44,    93,    91,    46,    38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    59,    60,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    65,    65,    66,    66,    66,
      66,    67,    67,    67,    68,    68,    68,    68,    69,    69,
      70,    71,    71,    72,    72,    72,    72,    73,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     7,     5,     1,
       2,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       2,     7,     5,     5,     7,     2,     2,     3,     3,     5,
       2,     2,     1,     2,     3,     1,     3,     2,     4,     3,
       5,     1,     3,     0,     1,     1,     2,     1,     1,     1,
       2,     3,     4,     4,     4,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     1,    59,    60,    61,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     4,     5,     3,    35,     0,     0,     0,
      63,    62,     0,     0,    64,     0,    43,    43,     0,     0,
       0,    25,    26,    49,     0,    63,    62,    64,     0,    48,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    67,     0,    49,    32,     0,    66,
      20,     0,    30,     0,     0,     0,     0,     0,    50,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,    41,     0,     0,     0,
       0,    67,    27,     0,    43,     0,     0,    44,    45,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
      43,    28,    33,    36,    39,    34,    51,    57,    58,     0,
      55,    56,    80,    79,    74,    73,    77,    78,    76,    75,
      68,    69,    70,    72,    71,    82,     0,     0,     0,     0,
       0,    38,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,     0,     0,    52,    42,     0,
      29,     0,    22,    23,     8,    11,    13,    12,    14,    16,
      15,    17,    19,    18,     0,    40,     0,     0,     0,     7,
      21,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    33,    34,    77,    78,    36,    37,    38,
     105,    39,    55,    56,    42,    43,    57,    45
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -72
static const yytype_int16 yypact[] =
{
     -72,     6,   327,   -72,   -72,   -72,   -72,   -31,   -17,   -13,
      -7,    -1,    14,    24,    13,    47,    52,    36,    41,    46,
      53,    54,    55,    56,    57,    58,    47,    13,    13,    13,
     489,   -72,    13,   -72,   -72,   -72,   -72,     5,    18,    60,
     -24,   -46,    59,    25,    62,   109,    13,    13,   489,    13,
      13,   -72,   -72,   -72,    13,    42,    50,   -72,   274,   -72,
      61,    63,    69,    -5,    -5,    -5,    13,    13,    13,    13,
      13,    13,    76,   -72,    67,   191,    73,   -72,   381,   -72,
     -72,    -5,   -72,    47,    13,    13,    47,    47,    68,   -72,
      47,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    13,   -72,   -44,   669,   -40,   489,   517,
     536,   -72,   -72,    13,    13,    13,    74,    42,    50,   -72,
      77,    78,   555,   574,   593,   612,   631,   650,    47,   -72,
      13,   -72,   -72,   -72,    72,   669,   669,   -72,   -72,    13,
      61,   -72,   211,   211,     3,     3,     3,     3,     3,     3,
      -4,    -4,   -72,   -72,   -72,   -72,    13,    45,   489,   489,
     489,   669,   -27,   669,    79,    80,    81,    82,    83,    84,
      85,    87,   101,    61,   -72,   -26,    13,   669,   669,   489,
     -72,   105,   -72,    99,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   103,   669,   435,   489,   489,   -72,
     -72,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   -72,   -72,    12,   -71,    28,   -72,   -72,
     -36,   -16,    -2,     8,   -72,   -72,     2,   187
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -48
static const yytype_int16 yytable[] =
{
      40,    59,    53,   155,    44,   -45,     3,   157,   156,    87,
      41,   107,   156,    60,    35,    46,     4,     5,     6,     7,
      53,   194,   184,    61,    72,   156,   156,   -44,    40,    47,
      85,    86,    44,    48,   115,   101,   102,   103,    41,    49,
      99,   100,   101,   102,   103,    50,    40,   116,   120,   121,
      44,    27,    54,    59,    53,    80,    41,    81,    62,    29,
     108,   117,   117,   117,    51,   119,   119,   119,    82,    32,
      83,   118,   118,   118,    52,    89,    40,    90,   162,   117,
      44,    60,    63,   119,   137,   138,    41,    64,   140,   118,
     132,   134,    65,   179,   175,   180,    85,    86,   141,    66,
      67,    68,    69,    70,    71,    87,    40,   128,   196,   133,
      44,    84,    88,   -47,   113,    85,    41,   114,   -46,   130,
     158,   164,   139,   176,   165,   166,   173,   198,     0,   185,
     186,   187,   188,   189,   190,   191,   174,   192,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   193,   197,   180,     0,     0,    40,    40,    40,   104,
      44,    44,    44,     0,     0,     0,    41,    41,    41,     0,
     181,   182,   183,     0,     0,     0,     0,    40,     0,     0,
       0,    44,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,    40,    40,    40,     0,    44,    44,
      44,    58,     0,     0,    41,    41,    41,     0,   132,   200,
     201,     0,     0,     0,    73,    74,    75,     0,     0,    79,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   106,   106,     0,   109,   110,   129,     0,
       0,   111,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   122,   123,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,   136,     0,     0,     0,     0,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     161,   106,   163,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   106,     0,     0,
       0,     0,     0,     0,   112,     0,   177,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   178,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,   195,     0,    27,    28,     0,     0,     0,
       0,     0,     0,    29,     0,    30,     0,    31,     0,     0,
       0,     0,     0,    32,     4,     5,     6,     7,    76,     9,
      10,    11,    12,    13,    14,    15,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,    27,
      28,     0,     0,     0,     0,     0,     0,    29,     0,    30,
     131,    31,     0,     0,     0,     0,     0,    32,     4,     5,
       6,     7,    76,     9,    10,    11,    12,    13,    14,    15,
       0,     0,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,    26,     0,     0,
       0,     0,     0,    27,    28,     0,     0,     0,     0,     0,
       0,    29,     0,    30,   199,    31,     0,     0,     0,     0,
       0,    32,     4,     5,     6,     7,    76,     9,    10,    11,
      12,    13,    14,    15,     0,     0,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,    27,    28,     0,
       0,     0,     0,     0,     0,    29,     0,    30,     0,    31,
       0,     0,     0,     0,     0,    32,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,     0,
       0,     0,     0,     0,   159,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,   160,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,   167,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,   168,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
     169,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,   170,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     0,     0,     0,     0,     0,   171,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,   172,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103
};

static const yytype_int16 yycheck[] =
{
       2,     6,     7,    47,     2,    51,     0,    47,    52,    55,
       2,    47,    52,    15,     2,    46,     3,     4,     5,     6,
       7,    47,    49,    15,    26,    52,    52,    51,    30,    46,
      54,    55,    30,    46,    39,    39,    40,    41,    30,    46,
      37,    38,    39,    40,    41,    46,    48,    63,    64,    65,
      48,    38,    39,     6,     7,    50,    48,    52,     6,    46,
      48,    63,    64,    65,    50,    63,    64,    65,    50,    56,
      52,    63,    64,    65,    50,    50,    78,    52,   114,    81,
      78,    83,    46,    81,    86,    87,    78,    46,    90,    81,
      78,    83,    46,    48,   130,    50,    54,    55,    90,    46,
      46,    46,    46,    46,    46,    55,   108,    31,   179,    81,
     108,    51,    53,    51,    51,    54,   108,    48,    51,    46,
     108,    47,    54,    51,    47,    47,   128,    28,    -1,    50,
      50,    50,    50,    50,    50,    50,   128,    50,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    50,    47,    50,    -1,    -1,   158,   159,   160,    50,
     158,   159,   160,    -1,    -1,    -1,   158,   159,   160,    -1,
     158,   159,   160,    -1,    -1,    -1,    -1,   179,    -1,    -1,
      -1,   179,    -1,    -1,    -1,    -1,    -1,   179,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,   198,    -1,   196,   197,
     198,    14,    -1,    -1,   196,   197,   198,    -1,   196,   197,
     198,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    32,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    46,    47,    -1,    49,    50,    47,    -1,
      -1,    54,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,   139,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,   156,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,   176,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    56,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    48,
      49,    50,    -1,    -1,    -1,    -1,    -1,    56,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    56,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    56,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    47,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    47,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    47,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      47,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    59,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    32,    38,    39,    46,
      48,    50,    56,    60,    61,    62,    64,    65,    66,    68,
      69,    70,    71,    72,    73,    74,    46,    46,    46,    46,
      46,    50,    50,     7,    39,    69,    70,    73,    74,     6,
      69,    70,     6,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    69,    74,    74,    74,     7,    62,    63,    74,
      50,    52,    50,    52,    51,    54,    55,    55,    53,    50,
      52,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    50,    67,    74,    67,    62,    74,
      74,    74,    50,    51,    48,    39,    68,    69,    70,    73,
      68,    68,    74,    74,    74,    74,    74,    74,    31,    47,
      46,    49,    62,    64,    70,    74,    74,    69,    69,    54,
      69,    70,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    47,    52,    47,    62,    47,
      47,    74,    67,    74,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    69,    70,    67,    51,    74,    74,    48,
      50,    62,    62,    62,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    47,    74,    63,    47,    28,    49,
      62,    62
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
#line 67 "c6.y"
    { 
                                preProcess();
                                exStmtList(); 
                                exFuncList(); 
                                wrapUp(); 
                            }
    break;

  case 3:
#line 76 "c6.y"
    { appendToList(stmtList, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 4:
#line 77 "c6.y"
    { appendToList(funcList, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 5:
#line 78 "c6.y"
    { appendToList(structList, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 7:
#line 83 "c6.y"
    { (yyval.nPtr) = func((yyvsp[(1) - (7)].sKey), (yyvsp[(3) - (7)].nPtr), (yyvsp[(6) - (7)].nPtr)); }
    break;

  case 8:
#line 87 "c6.y"
    { (yyval.nPtr) = sct((yyvsp[(2) - (5)].sKey), (yyvsp[(4) - (5)].nPtr)); }
    break;

  case 9:
#line 91 "c6.y"
    { (yyval.nPtr) = opr(';', 2, NULL, NULL); }
    break;

  case 10:
#line 92 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 11:
#line 93 "c6.y"
    { (yyval.nPtr) = opr(GETI, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 12:
#line 94 "c6.y"
    { (yyval.nPtr) = opr(GETC, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 13:
#line 95 "c6.y"
    { (yyval.nPtr) = opr(GETS, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 14:
#line 96 "c6.y"
    { (yyval.nPtr) = opr(PUTI, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 15:
#line 97 "c6.y"
    { (yyval.nPtr) = opr(PUTC, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 16:
#line 98 "c6.y"
    { (yyval.nPtr) = opr(PUTS, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 17:
#line 99 "c6.y"
    { (yyval.nPtr) = opr(PUTI_, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 18:
#line 100 "c6.y"
    { (yyval.nPtr) = opr(PUTC_, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 19:
#line 101 "c6.y"
    { (yyval.nPtr) = opr(PUTS_, 1, (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 20:
#line 102 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 21:
#line 103 "c6.y"
    { (yyval.nPtr) = opr(FOR, 4, (yyvsp[(3) - (7)].nPtr), (yyvsp[(4) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr)); }
    break;

  case 22:
#line 104 "c6.y"
    { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 23:
#line 105 "c6.y"
    { (yyval.nPtr) = opr(IF, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); }
    break;

  case 24:
#line 106 "c6.y"
    { (yyval.nPtr) = opr(IF, 3, (yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr)); }
    break;

  case 25:
#line 107 "c6.y"
    { (yyval.nPtr) = opr(BREAK, 2, NULL, NULL); }
    break;

  case 26:
#line 108 "c6.y"
    { (yyval.nPtr) = opr(CONTINUE, 2, NULL, NULL); }
    break;

  case 27:
#line 109 "c6.y"
    { (yyval.nPtr) = opr(RETURN, 1, (yyvsp[(2) - (3)].nPtr)); }
    break;

  case 28:
#line 110 "c6.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 29:
#line 111 "c6.y"
    { (yyval.nPtr) = opr(CALL, 2, id((yyvsp[(1) - (5)].sKey)), (yyvsp[(3) - (5)].nPtr)); }
    break;

  case 30:
#line 112 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 31:
#line 113 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 32:
#line 117 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 33:
#line 118 "c6.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 34:
#line 122 "c6.y"
    { (yyval.nPtr) = opr('=', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 35:
#line 126 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 36:
#line 127 "c6.y"
    { (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 37:
#line 131 "c6.y"
    { (yyval.nPtr) = opr(DECL_ARRAY, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 38:
#line 132 "c6.y"
    { (yyval.nPtr) = opr('=', 2, opr(DECL_ARRAY, 1, (yyvsp[(2) - (4)].nPtr)), (yyvsp[(4) - (4)].nPtr)); }
    break;

  case 39:
#line 133 "c6.y"
    { (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), opr(DECL_ARRAY, 1, (yyvsp[(3) - (3)].nPtr))); }
    break;

  case 40:
#line 134 "c6.y"
    { (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (5)].nPtr), opr('=', 2, opr(DECL_ARRAY, 1, (yyvsp[(3) - (5)].nPtr)), (yyvsp[(5) - (5)].nPtr))); }
    break;

  case 41:
#line 138 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 42:
#line 139 "c6.y"
    { (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 43:
#line 140 "c6.y"
    { (yyval.nPtr) = NULL; }
    break;

  case 44:
#line 144 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 45:
#line 145 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 46:
#line 146 "c6.y"
    { (yyval.nPtr) = opr(DEREF, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 47:
#line 147 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 48:
#line 151 "c6.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (1)].sKey)); }
    break;

  case 49:
#line 152 "c6.y"
    { (yyval.nPtr) = id((yyvsp[(1) - (1)].sKey)); }
    break;

  case 50:
#line 156 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (2)].nPtr); }
    break;

  case 51:
#line 160 "c6.y"
    { (yyval.nPtr) = array((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 52:
#line 161 "c6.y"
    { (yyval.nPtr) = extendArray((yyvsp[(1) - (4)].nPtr), (yyvsp[(4) - (4)].nPtr)); }
    break;

  case 53:
#line 165 "c6.y"
    { (yyval.nPtr) = opr(DECL_STRUCT, 2, (yyvsp[(2) - (4)].nPtr), (yyvsp[(4) - (4)].nPtr)); }
    break;

  case 54:
#line 166 "c6.y"
    { (yyval.nPtr) = opr(DECL_STRUCT, 2, (yyvsp[(2) - (4)].nPtr), (yyvsp[(4) - (4)].nPtr)); }
    break;

  case 55:
#line 167 "c6.y"
    { 
                                                if ((yyvsp[(1) - (3)].nPtr)->opr.op[0]->type == typeId) {
                                                    // the second element
                                                    (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), opr(DECL_STRUCT, 2, id((yyvsp[(1) - (3)].nPtr)->opr.op[0]->id.varName), (yyvsp[(3) - (3)].nPtr))); 
                                                } else {
                                                    (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), opr(DECL_STRUCT, 2, id((yyvsp[(1) - (3)].nPtr)->opr.op[1]->opr.op[0]->id.varName), (yyvsp[(3) - (3)].nPtr))); 
                                                }
                                            }
    break;

  case 56:
#line 175 "c6.y"
    { 
                                                if ((yyvsp[(1) - (3)].nPtr)->opr.op[0]->type == typeId) {
                                                    // the second element
                                                    (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), opr(DECL_STRUCT, 2, id((yyvsp[(1) - (3)].nPtr)->opr.op[0]->id.varName), (yyvsp[(3) - (3)].nPtr))); 
                                                } else {
                                                    (yyval.nPtr) = opr(',', 2, (yyvsp[(1) - (3)].nPtr), opr(DECL_STRUCT, 2, id((yyvsp[(1) - (3)].nPtr)->opr.op[1]->opr.op[0]->id.varName), (yyvsp[(3) - (3)].nPtr))); 
                                                }
                                            }
    break;

  case 57:
#line 186 "c6.y"
    { (yyval.nPtr) = opr(DOT, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 58:
#line 187 "c6.y"
    { (yyval.nPtr) = opr(DOT, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 59:
#line 191 "c6.y"
    { (yyval.nPtr) = con((yyvsp[(1) - (1)].conValue), conTypeInt); }
    break;

  case 60:
#line 192 "c6.y"
    { (yyval.nPtr) = con((yyvsp[(1) - (1)].conValue), conTypeChar); }
    break;

  case 61:
#line 193 "c6.y"
    { (yyval.nPtr) = con((long) (yyvsp[(1) - (1)].conStrValue), conTypeStr); }
    break;

  case 62:
#line 194 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 63:
#line 195 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 64:
#line 196 "c6.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); }
    break;

  case 65:
#line 197 "c6.y"
    { (yyval.nPtr) = opr(UMINUS, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 66:
#line 198 "c6.y"
    { (yyval.nPtr) = opr(REF, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 67:
#line 199 "c6.y"
    { (yyval.nPtr) = opr(DEREF, 1, (yyvsp[(2) - (2)].nPtr)); }
    break;

  case 68:
#line 200 "c6.y"
    { 
                                    if ((yyvsp[(1) - (3)].nPtr)->type == typeCon && (yyvsp[(1) - (3)].nPtr)->con.type == conTypeStr &&
                                        (yyvsp[(3) - (3)].nPtr)->type == typeCon && (yyvsp[(3) - (3)].nPtr)->con.type == conTypeStr) {
                                        (yyval.nPtr) = strConcat((yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr));
                                    } else {
                                        (yyval.nPtr) = opr('+', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); 
                                    }
                                }
    break;

  case 69:
#line 208 "c6.y"
    { (yyval.nPtr) = opr('-', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 70:
#line 209 "c6.y"
    { (yyval.nPtr) = opr('*', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 71:
#line 210 "c6.y"
    { (yyval.nPtr) = opr('%', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 72:
#line 211 "c6.y"
    { (yyval.nPtr) = opr('/', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 73:
#line 212 "c6.y"
    { (yyval.nPtr) = opr('<', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 74:
#line 213 "c6.y"
    { (yyval.nPtr) = opr('>', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 75:
#line 214 "c6.y"
    { (yyval.nPtr) = opr(GE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 76:
#line 215 "c6.y"
    { (yyval.nPtr) = opr(LE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 77:
#line 216 "c6.y"
    { (yyval.nPtr) = opr(NE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 78:
#line 217 "c6.y"
    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 79:
#line 218 "c6.y"
    { (yyval.nPtr) = opr(AND, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 80:
#line 219 "c6.y"
    { (yyval.nPtr) = opr(OR, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); }
    break;

  case 81:
#line 220 "c6.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); }
    break;

  case 82:
#line 221 "c6.y"
    { (yyval.nPtr) = opr(CALL, 2, id((yyvsp[(1) - (4)].sKey)), (yyvsp[(3) - (4)].nPtr)); }
    break;


/* Line 1267 of yacc.c.  */
#line 2121 "y.tab.c"
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


#line 224 "c6.y"


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





