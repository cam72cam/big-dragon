/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 2053 of yacc.c  */
#line 2 "bigd.y"

#include "tree.h"


/* Line 2053 of yacc.c  */
#line 51 "y.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RPAREN = 258,
     LPAREN = 259,
     ASSIGNOP = 260,
     IDENTIFIER = 261,
     ENDSTMT = 262,
     PROGRAM = 263,
     VAR = 264,
     FUNCTION = 265,
     PROCEDURE = 266,
     BEGIN_SEC = 267,
     END_SEC = 268,
     COLON = 269,
     ARRAY = 270,
     ARRAY_SEPERATOR = 271,
     ARRAY_TYPE = 272,
     ARRAY_START = 273,
     ARRAY_END = 274,
     IF = 275,
     THEN = 276,
     ELSE = 277,
     WHILE = 278,
     DO = 279,
     INTEGER = 280,
     REAL = 281,
     PERIOD = 282,
     COMMA = 283,
     INTEGER_TYPE = 284,
     REAL_TYPE = 285,
     ADDOP = 286,
     MULOP = 287,
     RELOP = 288,
     SIGN = 289,
     NOT = 290
   };
#endif
/* Tokens.  */
#define RPAREN 258
#define LPAREN 259
#define ASSIGNOP 260
#define IDENTIFIER 261
#define ENDSTMT 262
#define PROGRAM 263
#define VAR 264
#define FUNCTION 265
#define PROCEDURE 266
#define BEGIN_SEC 267
#define END_SEC 268
#define COLON 269
#define ARRAY 270
#define ARRAY_SEPERATOR 271
#define ARRAY_TYPE 272
#define ARRAY_START 273
#define ARRAY_END 274
#define IF 275
#define THEN 276
#define ELSE 277
#define WHILE 278
#define DO 279
#define INTEGER 280
#define REAL 281
#define PERIOD 282
#define COMMA 283
#define INTEGER_TYPE 284
#define REAL_TYPE 285
#define ADDOP 286
#define MULOP 287
#define RELOP 288
#define SIGN 289
#define NOT 290



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
