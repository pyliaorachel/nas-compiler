/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 40 "c6.y"
{
    int conValue;               /* const value for int and char */
    char conStrValue[500];      /* const value for string */
    char sKey[14];              /* symbol table key (var name) */
    nodeType *nPtr;             /* node pointer */
}
/* Line 1529 of yacc.c.  */
#line 132 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

