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
    SELF = 265,
    STRING = 266,
    begin = 267,
    end = 268,
    MAIN = 269,
    DECL = 270,
    ENDDECL = 271,
    TYPE = 272,
    ENDTYPE = 273,
    TUPLE = 274,
    STRUCT = 275,
    CLASS = 276,
    ENDCLASS = 277,
    EXTENDS = 278,
    NEW = 279,
    DELETE = 280,
    PLUS = 281,
    MINUS = 282,
    DIV = 283,
    MUL = 284,
    ARROW = 285,
    IF = 286,
    THEN = 287,
    ELSE = 288,
    ENDIF = 289,
    WHILE = 290,
    DO = 291,
    ENDWHILE = 292,
    REPEAT = 293,
    UNTIL = 294,
    CONTINUE = 295,
    BREAK = 296,
    RETURN = 297,
    BREAKPOINT = 298,
    FREE = 299,
    ALLOC = 300,
    INITIALIZE = 301,
    GT = 302,
    GE = 303,
    LT = 304,
    LE = 305,
    NE = 306,
    EQ = 307,
    AND = 308,
    OR = 309,
    MOD = 310
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
#define SELF 265
#define STRING 266
#define begin 267
#define end 268
#define MAIN 269
#define DECL 270
#define ENDDECL 271
#define TYPE 272
#define ENDTYPE 273
#define TUPLE 274
#define STRUCT 275
#define CLASS 276
#define ENDCLASS 277
#define EXTENDS 278
#define NEW 279
#define DELETE 280
#define PLUS 281
#define MINUS 282
#define DIV 283
#define MUL 284
#define ARROW 285
#define IF 286
#define THEN 287
#define ELSE 288
#define ENDIF 289
#define WHILE 290
#define DO 291
#define ENDWHILE 292
#define REPEAT 293
#define UNTIL 294
#define CONTINUE 295
#define BREAK 296
#define RETURN 297
#define BREAKPOINT 298
#define FREE 299
#define ALLOC 300
#define INITIALIZE 301
#define GT 302
#define GE 303
#define LT 304
#define LE 305
#define NE 306
#define EQ 307
#define AND 308
#define OR 309
#define MOD 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 33 "exptree.y"

    struct tnode* node;
    char* string;
    int integer;
    struct Gsymbol* gsymbol;
    struct Lsymbol* lsymbol;
    struct DimNode* DimList;
    struct ParamList* plist;
    struct Fieldlist* type;

#line 178 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
