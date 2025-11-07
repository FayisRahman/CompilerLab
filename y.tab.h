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
    CLASS = 275,
    ENDCLASS = 276,
    EXTENDS = 277,
    PLUS = 278,
    MINUS = 279,
    DIV = 280,
    MUL = 281,
    ARROW = 282,
    IF = 283,
    THEN = 284,
    ELSE = 285,
    ENDIF = 286,
    WHILE = 287,
    DO = 288,
    ENDWHILE = 289,
    REPEAT = 290,
    UNTIL = 291,
    CONTINUE = 292,
    BREAK = 293,
    RETURN = 294,
    BREAKPOINT = 295,
    FREE = 296,
    ALLOC = 297,
    INITIALIZE = 298,
    GT = 299,
    GE = 300,
    LT = 301,
    LE = 302,
    NE = 303,
    EQ = 304,
    AND = 305,
    OR = 306,
    MOD = 307
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
#define CLASS 275
#define ENDCLASS 276
#define EXTENDS 277
#define PLUS 278
#define MINUS 279
#define DIV 280
#define MUL 281
#define ARROW 282
#define IF 283
#define THEN 284
#define ELSE 285
#define ENDIF 286
#define WHILE 287
#define DO 288
#define ENDWHILE 289
#define REPEAT 290
#define UNTIL 291
#define CONTINUE 292
#define BREAK 293
#define RETURN 294
#define BREAKPOINT 295
#define FREE 296
#define ALLOC 297
#define INITIALIZE 298
#define GT 299
#define GE 300
#define LT 301
#define LE 302
#define NE 303
#define EQ 304
#define AND 305
#define OR 306
#define MOD 307

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

#line 172 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
