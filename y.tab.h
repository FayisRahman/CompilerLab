/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    WRITE = 258,
    READ = 259,
    INT = 260,
    STR = 261,
    ID = 262,
    NUM = 263,
    STRING = 264,
    begin = 265,
    end = 266,
    MAIN = 267,
    DECL = 268,
    ENDDECL = 269,
    PLUS = 270,
    MINUS = 271,
    DIV = 272,
    MUL = 273,
    IF = 274,
    THEN = 275,
    ELSE = 276,
    ENDIF = 277,
    WHILE = 278,
    DO = 279,
    ENDWHILE = 280,
    REPEAT = 281,
    UNTIL = 282,
    CONTINUE = 283,
    BREAK = 284,
    RETURN = 285,
    BREAKPOINT = 286,
    GT = 287,
    GE = 288,
    LT = 289,
    LE = 290,
    NE = 291,
    EQ = 292,
    AND = 293,
    OR = 294,
    MOD = 295
  };
#endif
/* Tokens.  */
#define WRITE 258
#define READ 259
#define INT 260
#define STR 261
#define ID 262
#define NUM 263
#define STRING 264
#define begin 265
#define end 266
#define MAIN 267
#define DECL 268
#define ENDDECL 269
#define PLUS 270
#define MINUS 271
#define DIV 272
#define MUL 273
#define IF 274
#define THEN 275
#define ELSE 276
#define ENDIF 277
#define WHILE 278
#define DO 279
#define ENDWHILE 280
#define REPEAT 281
#define UNTIL 282
#define CONTINUE 283
#define BREAK 284
#define RETURN 285
#define BREAKPOINT 286
#define GT 287
#define GE 288
#define LT 289
#define LE 290
#define NE 291
#define EQ 292
#define AND 293
#define OR 294
#define MOD 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "exptree.y"

    struct tnode* node;
    char* string;
    int integer;
    struct Gsymbol* gsymbol;
    struct Lsymbol* lsymbol;
    struct DimNode* DimList;
    struct ParamList* plist;

#line 147 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
