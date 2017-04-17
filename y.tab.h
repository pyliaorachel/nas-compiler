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
     FOR = 262,
     WHILE = 263,
     IF = 264,
     BREAK = 265,
     CONTINUE = 266,
     GETI = 267,
     GETS = 268,
     GETC = 269,
     PUTI = 270,
     PUTS = 271,
     PUTC = 272,
     PUTI_ = 273,
     PUTS_ = 274,
     PUTC_ = 275,
     IFX = 276,
     ELSE = 277,
     OR = 278,
     AND = 279,
     NE = 280,
     EQ = 281,
     LE = 282,
     GE = 283,
     UMINUS = 284
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define CHAR 259
#define STRING 260
#define VARIABLE 261
#define FOR 262
#define WHILE 263
#define IF 264
#define BREAK 265
#define CONTINUE 266
#define GETI 267
#define GETS 268
#define GETC 269
#define PUTI 270
#define PUTS 271
#define PUTC 272
#define PUTI_ 273
#define PUTS_ 274
#define PUTC_ 275
#define IFX 276
#define ELSE 277
#define OR 278
#define AND 279
#define NE 280
#define EQ 281
#define LE 282
#define GE 283
#define UMINUS 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "c6.y"
{
    int conValue;               /* const value for int and char */
    char conStrValue[500];      /* const value for string */
    char sKey[14];              /* symbol table key (var name) */
    nodeType *nPtr;             /* node pointer */
}
/* Line 1529 of yacc.c.  */
#line 114 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

