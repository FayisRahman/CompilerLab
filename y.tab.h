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
    TYPE = 270,
    ENDTYPE = 271,
    TUPLE = 272,
    PLUS = 273,
    MINUS = 274,
    DIV = 275,
    MUL = 276,
    ARROW = 277,
    IF = 278,
    THEN = 279,
    ELSE = 280,
    ENDIF = 281,
    WHILE = 282,
    DO = 283,
    ENDWHILE = 284,
    REPEAT = 285,
    UNTIL = 286,
    CONTINUE = 287,
    BREAK = 288,
    RETURN = 289,
    BREAKPOINT = 290,
    GT = 291,
    GE = 292,
    LT = 293,
    LE = 294,
    NE = 295,
    EQ = 296,
    AND = 297,
    OR = 298,
    MOD = 299
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
#define TYPE 270
#define ENDTYPE 271
#define TUPLE 272
#define PLUS 273
#define MINUS 274
#define DIV 275
#define MUL 276
#define ARROW 277
#define IF 278
#define THEN 279
#define ELSE 280
#define ENDIF 281
#define WHILE 282
#define DO 283
#define ENDWHILE 284
#define REPEAT 285
#define UNTIL 286
#define CONTINUE 287
#define BREAK 288
#define RETURN 289
#define BREAKPOINT 290
#define GT 291
#define GE 292
#define LT 293
#define LE 294
#define NE 295
#define EQ 296
#define AND 297
#define OR 298
#define MOD 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "exptree.y"

    struct tnode* node;
    char* string;
    int integer;
    struct Gsymbol* gsymbol;
    struct Lsymbol* lsymbol;
    struct DimNode* DimList;
    struct ParamList* plist;
    struct TypeTable* type;

#line 156 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
