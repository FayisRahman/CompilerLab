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
    NILL = 264,
    STRING = 265,
    begin = 266,
    end = 267,
    MAIN = 268,
    DECL = 269,
    ENDDECL = 270,
    TYPE = 271,
    ENDTYPE = 272,
    TUPLE = 273,
    STRUCT = 274,
    PLUS = 275,
    MINUS = 276,
    DIV = 277,
    MUL = 278,
    ARROW = 279,
    IF = 280,
    THEN = 281,
    ELSE = 282,
    ENDIF = 283,
    WHILE = 284,
    DO = 285,
    ENDWHILE = 286,
    REPEAT = 287,
    UNTIL = 288,
    CONTINUE = 289,
    BREAK = 290,
    RETURN = 291,
    BREAKPOINT = 292,
    FREE = 293,
    ALLOC = 294,
    INITIALIZE = 295,
    GT = 296,
    GE = 297,
    LT = 298,
    LE = 299,
    NE = 300,
    EQ = 301,
    AND = 302,
    OR = 303,
    MOD = 304
  };
#endif
/* Tokens.  */
#define WRITE 258
#define READ 259
#define INT 260
#define STR 261
#define ID 262
#define NUM 263
#define NILL 264
#define STRING 265
#define begin 266
#define end 267
#define MAIN 268
#define DECL 269
#define ENDDECL 270
#define TYPE 271
#define ENDTYPE 272
#define TUPLE 273
#define STRUCT 274
#define PLUS 275
#define MINUS 276
#define DIV 277
#define MUL 278
#define ARROW 279
#define IF 280
#define THEN 281
#define ELSE 282
#define ENDIF 283
#define WHILE 284
#define DO 285
#define ENDWHILE 286
#define REPEAT 287
#define UNTIL 288
#define CONTINUE 289
#define BREAK 290
#define RETURN 291
#define BREAKPOINT 292
#define FREE 293
#define ALLOC 294
#define INITIALIZE 295
#define GT 296
#define GE 297
#define LT 298
#define LE 299
#define NE 300
#define EQ 301
#define AND 302
#define OR 303
#define MOD 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "exptree.y"

    struct tnode* node;
    char* string;
    int integer;
    struct Gsymbol* gsymbol;
    struct Lsymbol* lsymbol;
    struct DimNode* DimList;
    struct ParamList* plist;
    struct TypeTable* type;

#line 166 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
