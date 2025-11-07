/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "exptree.y"

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "reghandling.h"
    #include "AST.h"
    #include "evaluator.h"
    #include "global_symbol_table.h"
    #include "local_symbol_table.h"
    #include "dim_node.h"
    #include "param_list.h"
    #include "tree_visualization.h"
    #include "type_table.h"
    #include "exptree.h"
    #include "./TreeViz/tree_viz.h"

    extern int yylex();
    extern FILE *yyin;
    void yyerror(char* s);
    struct tnode* head = NULL;
    FILE* fptr = NULL;
    void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType);
    

#line 95 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 262 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   770

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  324

#define YYUNDEFTOK  2
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,     2,
      55,    56,     2,     2,    54,     2,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,    61,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    62,    63,    66,    74,    81,    82,    85,
     107,   110,   113,   125,   131,   139,   150,   153,   156,   157,
     160,   164,   170,   177,   180,   182,   189,   190,   192,   193,
     196,   199,   200,   203,   204,   207,   210,   211,   214,   218,
     219,   228,   229,   232,   237,   244,   253,   263,   266,   275,
     280,   289,   299,   302,   315,   320,   335,   339,   344,   347,
     355,   364,   370,   405,   407,   411,   416,   417,   418,   428,
     431,   434,   441,   449,   454,   459,   476,   482,   515,   527,
     546,   560,   593,   607,   618,   632,   643,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   662,   665,   670,
     675,   680,   685,   688,   691,   697,   702,   708,   714,   720,
     726,   732,   735,   739,   743,   747,   751,   759,   767,   771,
     775,   778,   781,   795,   806,   824,   838,   854,   867,   881,
     886,   891,   897,   901,   907,   918
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WRITE", "READ", "INT", "STR", "ID",
  "NUM", "NILL", "STRING", "begin", "end", "MAIN", "DECL", "ENDDECL",
  "TYPE", "ENDTYPE", "TUPLE", "STRUCT", "CLASS", "ENDCLASS", "EXTENDS",
  "PLUS", "MINUS", "DIV", "MUL", "ARROW", "IF", "THEN", "ELSE", "ENDIF",
  "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "CONTINUE", "BREAK",
  "RETURN", "BREAKPOINT", "FREE", "ALLOC", "INITIALIZE", "GT", "GE", "LT",
  "LE", "NE", "EQ", "AND", "OR", "MOD", "';'", "','", "'('", "')'", "'{'",
  "'}'", "'['", "']'", "'='", "'&'", "'.'", "$accept", "Program",
  "GDeclBlock", "GDeclList", "GDecl", "GidList", "Gid", "TDeclBlock",
  "TDeclList", "TDeclStart", "TDecl", "TIdList", "TIdDecl",
  "ClassDefBlock", "ClassDefList", "Classdef", "Cname", "Fieldlists",
  "Fld", "MethodDecl", "MDecl", "MethodDefns", "FDefBlock", "Fdef",
  "Paramlist", "ParamDecl", "Param", "LdeclBlock", "LDecList", "LDecl",
  "IdList", "IdDecl", "ArgList", "MainBlock", "body", "Slist", "Type",
  "DimList", "InputStmt", "OutputStmt", "AsgStmt", "Allocstmnt", "Stmt",
  "Ifstmt", "Whilestmt", "DoWhilestmt", "RepeatUntiltstmt", "Jumpstmt",
  "Debugstmt", "E", "DimAccess", "Field", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,    59,    44,    40,    41,   123,   125,    91,
      93,    61,    38,    46
};
# endif

#define YYPACT_NINF (-155)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   131,    23,   241,    68,    77,   184,    42,  -155,  -155,
    -155,  -155,  -155,   141,     4,   298,    98,  -155,   117,  -155,
    -155,  -155,  -155,   298,  -155,   185,  -155,    17,   115,  -155,
      47,  -155,    87,  -155,   298,   128,   134,  -155,   189,  -155,
    -155,   177,   229,   114,  -155,   234,  -155,  -155,   235,   298,
    -155,    34,   209,     0,  -155,   298,   186,   212,  -155,    17,
    -155,  -155,  -155,  -155,    19,   221,   282,   238,   239,  -155,
     124,  -155,    76,   283,   298,  -155,   289,   298,   243,   285,
    -155,   298,  -155,  -155,   294,  -155,   250,   150,   312,  -155,
     118,  -155,   163,   298,   298,   309,  -155,  -155,  -155,  -155,
     154,   317,   298,  -155,   269,   170,   334,  -155,   108,   331,
     278,  -155,   298,   277,     9,  -155,   285,   280,  -155,  -155,
    -155,   335,   199,  -155,   288,   291,    -8,   337,   292,   293,
     331,   331,   299,   300,   153,   302,   301,   303,   231,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
     176,  -155,   202,  -155,  -155,   309,   285,  -155,  -155,   108,
     153,   109,   338,   153,    56,   353,   183,   304,   153,   153,
     347,   247,  -155,  -155,    54,  -155,  -155,  -155,   354,   360,
     153,   369,   556,   314,  -155,   371,   305,  -155,  -155,    96,
     374,   330,   339,   309,  -155,   415,    73,   382,    14,   340,
     368,   341,   566,  -155,   153,   153,   153,   428,   462,   343,
     344,   388,   133,   345,  -155,  -155,   475,  -155,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,  -155,    45,    65,   349,   348,   597,  -155,  -155,  -155,
     342,   352,   399,   370,   113,   351,   372,   153,  -155,   365,
    -155,   385,   607,   638,   393,   391,   153,   153,  -155,  -155,
     206,   679,  -155,   -13,   -13,  -155,  -155,   188,   188,   188,
     188,   129,   129,   718,   688,  -155,   373,   389,  -155,   387,
    -155,  -155,  -155,   390,  -155,   394,   395,  -155,   648,   396,
    -155,  -155,  -155,   331,   331,   509,   522,   153,  -155,  -155,
    -155,   397,   402,  -155,  -155,  -155,  -155,   190,   274,   -16,
     403,   679,  -155,  -155,   331,   404,   405,  -155,  -155,   290,
    -155,  -155,   416,  -155
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      17,     0,     0,     0,     0,     0,     0,     0,    19,     1,
      66,    67,    68,     0,     0,     0,     0,     4,     0,    20,
      21,    16,    18,     0,     6,     0,     8,     0,    31,    27,
       0,    29,     0,     3,     0,     0,     0,    24,     0,     5,
       7,    70,     0,     0,    11,     0,    26,    28,     0,     0,
      42,     0,     0,     0,    25,    47,    12,    13,     9,     0,
      32,    34,    41,     2,     0,     0,     0,     0,     0,    23,
       0,    46,     0,     0,    47,    10,     0,    47,     0,    52,
      22,     0,    14,    49,     0,    48,     0,     0,     0,    33,
       0,    37,     0,    47,     0,     0,    45,    50,    69,    15,
       0,     0,     0,    36,     0,     0,     0,    54,     0,     0,
       0,    35,    47,     0,     0,    40,    52,     0,    51,    53,
      58,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
      88,    89,    96,    65,    90,    91,    92,    93,    94,    95,
       0,    62,     0,    30,    39,     0,    52,    59,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   125,   130,   120,   129,     0,     0,
       0,     0,     0,   121,   105,     0,     0,    63,    64,     0,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,   131,   127,     0,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,     0,     0,     0,   134,    38,    43,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
      77,     0,     0,     0,     0,     0,     0,     0,   122,   123,
       0,    61,   111,   106,   107,   108,   109,   112,   114,   113,
     115,   116,   117,   118,   119,   110,     0,     0,    86,     0,
      80,    44,    76,     0,    71,     0,     0,    74,     0,     0,
     132,    78,    79,     0,     0,     0,     0,     0,   124,    84,
      85,     0,     0,    72,    73,    81,    82,     0,     0,     0,
       0,    60,    83,    75,     0,     0,     0,   100,   101,     0,
      98,    99,     0,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,   411,  -155,   419,  -155,   409,  -155,  -155,  -155,
     464,  -155,   429,  -155,  -155,   451,  -155,  -155,  -155,  -155,
     400,  -155,  -155,   -45,    33,   408,  -155,  -107,  -155,   377,
    -155,   332,  -155,    -5,  -147,  -128,    25,  -155,  -155,  -155,
    -155,  -155,  -137,  -155,  -155,  -155,  -155,  -155,  -155,  -133,
    -154,  -109
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    15,    25,    26,    43,    44,     3,     6,     7,
       8,    36,    37,    16,    30,    31,    32,    76,    89,    90,
      91,   114,    49,    50,    70,    71,    85,    95,   106,   107,
     122,   123,   260,    17,   110,   138,    72,    56,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   182,
     166,   183
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     150,   188,   170,   171,    62,    10,    11,    12,   192,   155,
      33,    28,   220,   221,    10,    11,    12,   294,     1,   162,
     213,   150,   150,     9,    41,    29,    65,   195,    18,   150,
     200,   202,    35,   188,   188,   207,   208,   317,    27,   230,
      18,    65,   244,    42,    63,    66,   240,   216,    38,   193,
      27,   163,   198,   164,    28,   165,   236,   115,    68,    51,
      66,   150,   150,   174,   175,   176,   177,   153,    46,   154,
     246,   251,   252,   253,    64,    19,   233,   190,    38,   261,
     178,   211,   179,    83,    20,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   201,    23,
     242,   276,    84,   174,   175,   176,   177,    87,   165,   212,
      92,   180,    13,   163,   288,   120,   196,   165,   181,   108,
     178,   277,   179,   295,   296,   101,   105,    51,   190,   243,
      35,   108,   163,   102,   121,   197,   165,    45,   235,    51,
     174,   175,   176,   177,    48,   152,    10,    11,    12,     4,
       5,   180,   218,   219,   220,   221,    24,   178,   181,   179,
     174,   175,   176,   177,   311,   307,   308,    58,    59,   285,
     188,   188,   204,   222,   223,   224,   225,   178,    81,   179,
      82,   230,   188,    52,   150,   150,   319,    53,   180,   259,
      10,    11,    12,   124,   125,   181,    54,   126,   150,   150,
      39,    21,     4,     5,    81,   150,    99,   111,   180,   112,
     150,   218,   219,   220,   221,   181,   127,    81,   128,   104,
     314,   315,   129,   130,    81,   131,   117,   132,   133,   134,
     135,   136,    55,   137,   124,   125,    57,   189,   126,   190,
     230,    60,   204,   187,   205,    73,    10,    11,    12,    61,
     124,   125,   158,   159,   126,    13,    81,   127,   191,   128,
     297,    14,   298,   129,   130,    67,   131,    74,   132,   133,
     134,   135,   136,   127,   137,   128,    77,   124,   125,   129,
     130,   126,   131,   210,   132,   133,   134,   135,   136,    78,
     137,    86,    80,   124,   125,    79,    88,   126,    93,    94,
     127,    97,   128,    10,    11,    12,   129,   130,   316,   131,
      98,   132,   133,   134,   135,   136,   127,   137,   128,   100,
     109,   322,   129,   130,   113,   131,   116,   132,   133,   134,
     135,   136,   112,   137,   124,   125,   151,   156,   126,    10,
      11,    12,   157,   160,   167,   199,   161,   168,   169,   118,
     124,   125,   172,   173,   126,   184,   185,   127,   186,   128,
     203,   234,   214,   129,   130,   206,   131,   215,   132,   133,
     134,   135,   136,   127,   137,   128,   217,   190,   232,   209,
     130,   237,   131,   238,   132,   133,   134,   135,   136,   245,
     137,   218,   219,   220,   221,   258,   249,   239,   256,   257,
     281,   247,   278,   279,   204,   282,   283,   286,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   289,   293,   284,   294,   287,   299,    34,   248,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   218,   219,
     220,   221,   300,   301,    40,   290,   302,   303,   304,   306,
     312,   218,   219,   220,   221,   313,   318,   320,   321,   222,
     223,   224,   225,   226,   227,   228,   229,   230,    75,   323,
      22,   241,   222,   223,   224,   225,   226,   227,   228,   229,
     230,    47,    69,   119,   254,   218,   219,   220,   221,    96,
     103,   194,     0,     0,     0,     0,     0,     0,   218,   219,
     220,   221,     0,     0,     0,     0,   222,   223,   224,   225,
     226,   227,   228,   229,   230,     0,     0,     0,   255,   222,
     223,   224,   225,   226,   227,   228,   229,   230,     0,     0,
       0,   262,   218,   219,   220,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,   219,   220,   221,     0,
       0,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,     0,     0,     0,   309,   222,   223,   224,   225,
     226,   227,   228,   229,   230,     0,     0,     0,   310,   218,
     219,   220,   221,     0,     0,     0,     0,     0,     0,   218,
     219,   220,   221,     0,     0,     0,     0,     0,     0,     0,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   250,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
     218,   219,   220,   221,     0,     0,     0,     0,     0,     0,
       0,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     280,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     291,   218,   219,   220,   221,     0,     0,     0,     0,     0,
       0,   218,   219,   220,   221,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   292,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   305,   218,   219,   220,   221,     0,     0,     0,     0,
       0,   218,   219,   220,   221,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   222,   223,   224,   225,   226,   227,   228,     0,
     230,   218,   219,   220,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,   223,   224,   225,   226,   227,     0,     0,
     230
};

static const yytype_int16 yycheck[] =
{
     109,   138,   130,   131,    49,     5,     6,     7,   155,   116,
      15,     7,    25,    26,     5,     6,     7,    33,    16,    27,
     174,   130,   131,     0,     7,    21,     7,   160,     3,   138,
     163,   164,    13,   170,   171,   168,   169,    53,    13,    52,
      15,     7,   196,    26,    49,    26,   193,   180,    23,   156,
      25,    59,   161,    61,     7,    63,   189,   102,    58,    34,
      26,   170,   171,     7,     8,     9,    10,    58,    21,   114,
      56,   204,   205,   206,    49,     7,   185,    63,    53,   212,
      24,    27,    26,     7,     7,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,    42,    57,
      27,    56,    26,     7,     8,     9,    10,    74,    63,    55,
      77,    55,    14,    59,   247,     7,     7,    63,    62,    94,
      24,    56,    26,   256,   257,     7,    93,   102,    63,    56,
      13,   106,    59,    15,    26,    26,    63,    22,    42,   114,
       7,     8,     9,    10,    57,   112,     5,     6,     7,    18,
      19,    55,    23,    24,    25,    26,    15,    24,    62,    26,
       7,     8,     9,    10,   297,   293,   294,    53,    54,    56,
     307,   308,    59,    44,    45,    46,    47,    24,    54,    26,
      56,    52,   319,    55,   293,   294,   314,    53,    55,    56,
       5,     6,     7,     3,     4,    62,     7,     7,   307,   308,
      15,    17,    18,    19,    54,   314,    56,    53,    55,    55,
     319,    23,    24,    25,    26,    62,    26,    54,    28,    56,
      30,    31,    32,    33,    54,    35,    56,    37,    38,    39,
      40,    41,    55,    43,     3,     4,     7,    61,     7,    63,
      52,     7,    59,    12,    61,    59,     5,     6,     7,    14,
       3,     4,    53,    54,     7,    14,    54,    26,    56,    28,
      54,    20,    56,    32,    33,    56,    35,    55,    37,    38,
      39,    40,    41,    26,    43,    28,    55,     3,     4,    32,
      33,     7,    35,    36,    37,    38,    39,    40,    41,     7,
      43,     8,    53,     3,     4,    57,     7,     7,    55,    14,
      26,     7,    28,     5,     6,     7,    32,    33,    34,    35,
      60,    37,    38,    39,    40,    41,    26,    43,    28,     7,
      11,    31,    32,    33,     7,    35,    57,    37,    38,    39,
      40,    41,    55,    43,     3,     4,    58,    57,     7,     5,
       6,     7,     7,    55,     7,     7,    55,    55,    55,    15,
       3,     4,    53,    53,     7,    53,    55,    26,    55,    28,
       7,    56,     8,    32,    33,    61,    35,     7,    37,    38,
      39,    40,    41,    26,    43,    28,     7,    63,     7,    32,
      33,     7,    35,    53,    37,    38,    39,    40,    41,     7,
      43,    23,    24,    25,    26,     7,    55,    58,    55,    55,
      58,    61,    53,    55,    59,    53,     7,    56,    23,    24,
      25,    26,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    56,    29,    53,    33,    53,    53,    16,    60,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    23,    24,
      25,    26,    53,    56,    25,    60,    56,    53,    53,    53,
      53,    23,    24,    25,    26,    53,    53,    53,    53,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    59,    53,
       6,    56,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    30,    53,   106,    56,    23,    24,    25,    26,    81,
      90,   159,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    56,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    -1,
      -1,    56,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    -1,    56,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    56,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    44,    45,    46,    47,    48,    49,    50,    -1,
      52,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    -1,    -1,
      52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    65,    71,    18,    19,    72,    73,    74,     0,
       5,     6,     7,    14,    20,    66,    77,    97,   100,     7,
       7,    17,    74,    57,    15,    67,    68,   100,     7,    21,
      78,    79,    80,    97,    66,    13,    75,    76,   100,    15,
      68,     7,    26,    69,    70,    22,    21,    79,    57,    86,
      87,   100,    55,    53,     7,    55,   101,     7,    53,    54,
       7,    14,    87,    97,   100,     7,    26,    56,    58,    76,
      88,    89,   100,    59,    55,    70,    81,    55,     7,    57,
      53,    54,    56,     7,    26,    90,     8,    88,     7,    82,
      83,    84,    88,    55,    14,    91,    89,     7,    60,    56,
       7,     7,    15,    84,    56,    88,    92,    93,   100,    11,
      98,    53,    55,     7,    85,    87,    57,    56,    15,    93,
       7,    26,    94,    95,     3,     4,     7,    26,    28,    32,
      33,    35,    37,    38,    39,    40,    41,    43,    99,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     115,    58,    88,    58,    87,    91,    57,     7,    53,    54,
      55,    55,    27,    59,    61,    63,   114,     7,    55,    55,
      99,    99,    53,    53,     7,     8,     9,    10,    24,    26,
      55,    62,   113,   115,    53,    55,    55,    12,   106,    61,
      63,    56,    98,    91,    95,   113,     7,    26,   115,     7,
     113,    42,   113,     7,    59,    61,    61,   113,   113,    32,
      36,    27,    55,   114,     8,     7,   113,     7,    23,    24,
      25,    26,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     7,   115,    56,    42,   113,     7,    53,    58,
      98,    56,    27,    56,   114,     7,    56,    61,    60,    55,
      53,   113,   113,   113,    56,    56,    55,    55,     7,    56,
      96,   113,    56,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,    56,    56,    53,    55,
      53,    58,    53,     7,    53,    56,    56,    53,   113,    56,
      60,    53,    53,    29,    33,   113,   113,    54,    56,    53,
      53,    56,    56,    53,    53,    53,    53,    99,    99,    56,
      56,   113,    53,    53,    30,    31,    34,    53,    53,    99,
      53,    53,    31,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    65,    66,    66,    67,    67,    68,
      69,    69,    70,    70,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    75,    75,    76,    77,    77,    78,    78,
      79,    80,    80,    81,    81,    82,    83,    83,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    88,    89,    90,
      90,    91,    91,    92,    92,    93,    94,    94,    95,    95,
      96,    96,    97,    98,    99,    99,   100,   100,   100,   101,
     101,   102,   102,   102,   102,   102,   103,   104,   104,   104,
     104,   104,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   108,
     109,   110,   111,   111,   111,   112,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     3,     2,     2,     1,     3,
       3,     1,     2,     2,     4,     5,     3,     0,     2,     1,
       2,     2,     6,     3,     1,     2,     3,     2,     2,     1,
       8,     1,     3,     2,     0,     3,     2,     1,     6,     2,
       1,     2,     1,     9,    10,     3,     1,     0,     2,     1,
       2,     3,     0,     2,     1,     3,     3,     1,     1,     2,
       3,     1,     8,     3,     2,     1,     1,     1,     1,     4,
       0,     5,     6,     6,     5,     7,     5,     4,     5,     5,
       4,     6,     6,     6,     5,     5,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,    10,     8,     8,
       7,     7,     2,     2,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     4,     1,     2,     2,     2,     1,
       1,     2,     4,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 61 "exptree.y"
                                                                  {}
#line 1749 "y.tab.c"
    break;

  case 3:
#line 62 "exptree.y"
                                          {}
#line 1755 "y.tab.c"
    break;

  case 4:
#line 63 "exptree.y"
                               {}
#line 1761 "y.tab.c"
    break;

  case 5:
#line 66 "exptree.y"
                                     {
                stack_address = curr_stack_address;
                setup_pointers_codegen(fptr,top,NULL);
                is_global_vars_declared = 1;
                print_gsymbol_table();
                printf("------Global Variables Declared-----\n");
                driver_codegen(fptr);
            }
#line 1774 "y.tab.c"
    break;

  case 6:
#line 74 "exptree.y"
                           {
                stack_address = curr_stack_address;
                is_global_vars_declared = 1;
                driver_codegen(fptr);
            }
#line 1784 "y.tab.c"
    break;

  case 7:
#line 81 "exptree.y"
                              {}
#line 1790 "y.tab.c"
    break;

  case 8:
#line 82 "exptree.y"
                   {}
#line 1796 "y.tab.c"
    break;

  case 9:
#line 85 "exptree.y"
                           {
            Gsymbol* temp = (yyvsp[-1].gsymbol);
            Gsymbol* temp1 = (yyvsp[-1].gsymbol);
            while(temp){
                temp1 = temp->next;
                temp->next = NULL;
                if((yyvsp[-2].type)->type == TYPE_TUPLE && temp->varType != TYPE_ARR){
                    temp->size = (yyvsp[-2].type)->size;
                }
                if(temp->varType == TYPE_FUNCT_PTR)temp->size = 1;
                if((yyvsp[-2].type)->type == TYPE_TUPLE && temp->varType == TYPE_PTR){
                    temp->size++;
                }
                temp->typeEntry = (yyvsp[-2].type);
                add_gsymbol(temp,(yyvsp[-2].type)->type);
                
                temp->type = (yyvsp[-2].type)->type;
                temp = temp1;
            }
        }
#line 1821 "y.tab.c"
    break;

  case 10:
#line 107 "exptree.y"
                         {
            (yyval.gsymbol) = append_gsymbol_id_list((yyvsp[-2].gsymbol),(yyvsp[0].gsymbol));    
        }
#line 1829 "y.tab.c"
    break;

  case 11:
#line 110 "exptree.y"
              { (yyval.gsymbol) = (yyvsp[0].gsymbol);}
#line 1835 "y.tab.c"
    break;

  case 12:
#line 113 "exptree.y"
                     {
            Gsymbol* temp = create_symbol_id_with_dims((yyvsp[-1].node)->varname, (yyvsp[0].DimList));
            (yyvsp[-1].node)->Gentry = temp;
            if((yyvsp[0].DimList)){
                (yyvsp[-1].node)->type = TYPE_ARR;
                (yyvsp[-1].node)->Gentry->varType = TYPE_ARR;
            }else{
                (yyvsp[-1].node)->Gentry->varType = TYPE_VAR;
            }

            (yyval.gsymbol) = temp;
        }
#line 1852 "y.tab.c"
    break;

  case 13:
#line 125 "exptree.y"
                 {
            Gsymbol* temp = create_gsymbol_id((yyvsp[0].node)->varname, 2);
            (yyvsp[0].node)->Gentry = temp;
            temp->varType = TYPE_PTR;
            (yyval.gsymbol) = temp;
        }
#line 1863 "y.tab.c"
    break;

  case 14:
#line 131 "exptree.y"
                               {
            int size = get_paramlist_length((yyvsp[-1].plist));
            Gsymbol* temp = create_gsymbol_id((yyvsp[-3].node)->varname, 1);
            temp->plist = paramlist_deepcopy((yyvsp[-1].plist));
            temp->varType = TYPE_FUNCT;
            temp->flabel = flabel_count++;
            (yyval.gsymbol) = temp;
        }
#line 1876 "y.tab.c"
    break;

  case 15:
#line 139 "exptree.y"
                                   {
            int size = get_paramlist_length((yyvsp[-1].plist));
            Gsymbol* temp = create_gsymbol_id((yyvsp[-3].node)->varname, 1);
            temp->plist = paramlist_deepcopy((yyvsp[-1].plist));;
            temp->varType = TYPE_FUNCT_PTR;
            temp->flabel = flabel_count++;
            (yyval.gsymbol) = temp;
        }
#line 1889 "y.tab.c"
    break;

  case 16:
#line 150 "exptree.y"
                                      {
                // typetable_print(type_table);
            }
#line 1897 "y.tab.c"
    break;

  case 17:
#line 153 "exptree.y"
                {}
#line 1903 "y.tab.c"
    break;

  case 18:
#line 156 "exptree.y"
                              {}
#line 1909 "y.tab.c"
    break;

  case 19:
#line 157 "exptree.y"
                    {}
#line 1915 "y.tab.c"
    break;

  case 20:
#line 160 "exptree.y"
                       {
                typetable_create((yyvsp[0].node)->varname,TYPE_TUPLE,NULL);
                (yyval.string) = (yyvsp[0].node)->varname;
            }
#line 1924 "y.tab.c"
    break;

  case 21:
#line 164 "exptree.y"
                        {
                typetable_create((yyvsp[0].node)->varname,TYPE_TUPLE,NULL);
                (yyval.string) = (yyvsp[0].node)->varname;
            }
#line 1933 "y.tab.c"
    break;

  case 22:
#line 170 "exptree.y"
                                                 {
                typetable_append_plist((char*) (yyvsp[-5].string), (yyvsp[-3].plist));
                ParamList* temp = (yyvsp[-3].plist);
                
                
            }
#line 1944 "y.tab.c"
    break;

  case 23:
#line 177 "exptree.y"
                                  {
                (yyval.plist) = append_param_to_list((yyvsp[-2].plist),(yyvsp[0].plist));
            }
#line 1952 "y.tab.c"
    break;

  case 24:
#line 180 "exptree.y"
                      { (yyval.plist) = (yyvsp[0].plist); }
#line 1958 "y.tab.c"
    break;

  case 25:
#line 182 "exptree.y"
                      {
                (yyval.plist) = create_param((yyvsp[0].node)->varname, (yyvsp[-1].type)->type);
                (yyval.plist)->typeEntry = (yyvsp[-1].type);
            }
#line 1967 "y.tab.c"
    break;

  case 26:
#line 189 "exptree.y"
                                              {}
#line 1973 "y.tab.c"
    break;

  case 27:
#line 190 "exptree.y"
                                 {}
#line 1979 "y.tab.c"
    break;

  case 31:
#line 199 "exptree.y"
                            {Cptr = Cinstall((yyvsp[0].node)->Name,NULL);}
#line 1985 "y.tab.c"
    break;

  case 32:
#line 200 "exptree.y"
                                {Cptr = Cinstall((yyvsp[-2].node)->Name,(yyvsp[0].node)->Name);}
#line 1991 "y.tab.c"
    break;

  case 35:
#line 207 "exptree.y"
                             {Class_Finstall(Cptr,(yyvsp[-2].node)->Name,(yyvsp[-1].node)->Name);}
#line 1997 "y.tab.c"
    break;

  case 38:
#line 214 "exptree.y"
                                              {Class_Minstall(Cptr,(yyvsp[-4].node)->Name,Tlookup((yyvsp[-5].node)->Name),(yyvsp[-2].plist));}
#line 2003 "y.tab.c"
    break;

  case 41:
#line 228 "exptree.y"
                             {}
#line 2009 "y.tab.c"
    break;

  case 42:
#line 229 "exptree.y"
                   {}
#line 2015 "y.tab.c"
    break;

  case 43:
#line 232 "exptree.y"
                                                                  {    
                
                function_block((yyvsp[-8].type)->type,(yyvsp[-7].node),paramlist_deepcopy((yyvsp[-5].plist)),(yyvsp[-1].node),TYPE_FUNCT);

            }
#line 2025 "y.tab.c"
    break;

  case 44:
#line 237 "exptree.y"
                                                                      {
                
                function_block((yyvsp[-9].type)->type, (yyvsp[-7].node),paramlist_deepcopy((yyvsp[-5].plist)),(yyvsp[-1].node), TYPE_FUNCT_PTR);

            }
#line 2035 "y.tab.c"
    break;

  case 45:
#line 244 "exptree.y"
                                      {
                (yyval.plist) = append_param_to_list((yyvsp[-2].plist),(yyvsp[0].plist));
                if(is_global_vars_declared == 1){
                    Lsymbol* t1 = create_lsymbol_id((yyvsp[0].plist)->name, (yyvsp[0].plist)->varType == TYPE_PTR ? 1 : (yyvsp[0].plist)->size, (yyvsp[0].plist)->varType);
                    t1->type = (yyvsp[0].plist)->type;
                    t1->typeEntry = (yyvsp[0].plist)->typeEntry;
                    curr_lsymbol_table = append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
            }
#line 2049 "y.tab.c"
    break;

  case 46:
#line 253 "exptree.y"
                        {
                (yyval.plist) = (yyvsp[0].plist);
                if(is_global_vars_declared == 1){
                    Lsymbol* t1 = create_lsymbol_id((yyvsp[0].plist)->name, (yyvsp[0].plist)->size, (yyvsp[0].plist)->varType);
                    t1->type = (yyvsp[0].plist)->type;
                    t1->typeEntry = (yyvsp[0].plist)->typeEntry;
                    curr_lsymbol_table =  append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
                
            }
#line 2064 "y.tab.c"
    break;

  case 47:
#line 263 "exptree.y"
                                            {(yyval.plist) = NULL;curr_lsymbol_table= NULL;}
#line 2070 "y.tab.c"
    break;

  case 48:
#line 266 "exptree.y"
                         {
                (yyvsp[0].plist)->type = (yyvsp[-1].type)->type;
                (yyvsp[0].plist)->typeEntry = (yyvsp[-1].type);
                (yyvsp[0].plist)->size = (yyvsp[-1].type)->size;
                (yyval.plist) = (yyvsp[0].plist);
                
            }
#line 2082 "y.tab.c"
    break;

  case 49:
#line 275 "exptree.y"
                 {
                (yyval.plist) = create_param((yyvsp[0].node)->varname,TYPE_NULL);
                (yyval.plist)->size = 1;
                (yyval.plist)->varType = TYPE_VAR;
            }
#line 2092 "y.tab.c"
    break;

  case 50:
#line 280 "exptree.y"
                     {
                (yyval.plist) = create_param((yyvsp[0].node)->varname,TYPE_NULL);
                (yyval.plist)->size = 1;
                (yyval.plist)->varType = TYPE_PTR;
                
            }
#line 2103 "y.tab.c"
    break;

  case 51:
#line 289 "exptree.y"
                                    {
                Lsymbol* temp = curr_lsymbol_table;
                while(temp && temp->next){
                    temp = temp->next;
                }
                if(temp) temp->next = (yyvsp[-1].lsymbol);
                else curr_lsymbol_table = (yyvsp[-1].lsymbol);
                lst_set_bindings(curr_lsymbol_table);
                (yyval.lsymbol) = curr_lsymbol_table;
            }
#line 2118 "y.tab.c"
    break;

  case 52:
#line 299 "exptree.y"
               {(yyval.lsymbol) = NULL;lst_set_bindings(curr_lsymbol_table);}
#line 2124 "y.tab.c"
    break;

  case 53:
#line 302 "exptree.y"
                             {
                Lsymbol* temp = (yyvsp[0].lsymbol);
                while(temp){
                    check_lpresent((yyvsp[-1].lsymbol),temp->name);
                    temp = temp->next;
                }
                temp = (yyvsp[-1].lsymbol);
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = (yyvsp[0].lsymbol);
                (yyval.lsymbol) = (yyvsp[-1].lsymbol);
            }
#line 2142 "y.tab.c"
    break;

  case 54:
#line 315 "exptree.y"
                    {
                (yyval.lsymbol) = (yyvsp[0].lsymbol);   
            }
#line 2150 "y.tab.c"
    break;

  case 55:
#line 320 "exptree.y"
                              {
                Lsymbol* temp = (yyvsp[-1].lsymbol);
                while(temp){
                    temp->type = (yyvsp[-2].type)->type;
                    temp->typeEntry = (yyvsp[-2].type);
                    if(temp->typeEntry->type == TYPE_TUPLE){
                        temp->type = TYPE_TUPLE;
                    }
                    temp = temp->next;
                }
                print_lsymbol_table();
                (yyval.lsymbol) = (yyvsp[-1].lsymbol);
            }
#line 2168 "y.tab.c"
    break;

  case 56:
#line 335 "exptree.y"
                                 {
                check_lpresent((yyvsp[-2].lsymbol),(yyvsp[0].lsymbol)->name);
                (yyval.lsymbol) = append_lsymbol_id_list((yyvsp[-2].lsymbol), (yyvsp[0].lsymbol));
            }
#line 2177 "y.tab.c"
    break;

  case 57:
#line 339 "exptree.y"
                     {
                (yyval.lsymbol) = (yyvsp[0].lsymbol);
            }
#line 2185 "y.tab.c"
    break;

  case 58:
#line 344 "exptree.y"
                 {
                (yyval.lsymbol) = create_lsymbol_id((yyvsp[0].node)->varname, curr_type->size, TYPE_VAR);
            }
#line 2193 "y.tab.c"
    break;

  case 59:
#line 347 "exptree.y"
                    {
                int size = 2;
                if(curr_type->type == TYPE_TUPLE){
                    size = 1 + curr_type->size;
                }
                (yyval.lsymbol) = create_lsymbol_id((yyvsp[0].node)->varname, size, TYPE_PTR);
                printf("ptr name: %s\n",(yyvsp[0].node)->varname);
            }
#line 2206 "y.tab.c"
    break;

  case 60:
#line 355 "exptree.y"
                            {

                tnode* temp = (yyvsp[-2].node);
                while(temp->middle){
                    temp = temp->middle;
                }
                temp->middle = (yyvsp[0].node);
                (yyval.node) = (yyvsp[-2].node);
            }
#line 2220 "y.tab.c"
    break;

  case 61:
#line 364 "exptree.y"
                { (yyval.node) = (yyvsp[0].node);}
#line 2226 "y.tab.c"
    break;

  case 62:
#line 370 "exptree.y"
                                                      {

        //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome
        print_lsymbol_table();

        curr_function_type = (yyvsp[-7].type);

        tree_visual_printTree((yyvsp[-1].node));
        export_ast_to_graphviz((yyvsp[-1].node),"Main");

        fprintf(fptr, "MAIN:");

        int p = getReg();

        fprintf(fptr, "MOV R%d, BP\n", p);
        fprintf(fptr, "PUSH R%d\n", p);
        fprintf(fptr, "MOV BP, SP\n");

        int curr_offset = get_ltable_length(curr_lsymbol_table);

        if(curr_offset!=0)fprintf(fptr, "ADD SP, %d\n", curr_offset);

        freeReg();

        setup_pointers_codegen(fptr,NULL,curr_lsymbol_table);

        codeGen((yyvsp[-1].node),0,0,fptr);

        // lst_destroy($6);

        curr_lsymbol_table = NULL;
}
#line 2263 "y.tab.c"
    break;

  case 63:
#line 405 "exptree.y"
                       {(yyval.node) = (yyvsp[-1].node);}
#line 2269 "y.tab.c"
    break;

  case 64:
#line 407 "exptree.y"
                     {
            struct tnode* temp = createTree(0,TYPE_NULL,NULL,CONNECTOR,NULL,(yyvsp[-1].node), NULL, (yyvsp[0].node));
            (yyval.node) = temp;
        }
#line 2278 "y.tab.c"
    break;

  case 65:
#line 411 "exptree.y"
               {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2286 "y.tab.c"
    break;

  case 66:
#line 416 "exptree.y"
                  { (yyval.type) = typetable_lookup("int"); curr_type = (yyval.type);}
#line 2292 "y.tab.c"
    break;

  case 67:
#line 417 "exptree.y"
                  { (yyval.type) = typetable_lookup("str"); curr_type = (yyval.type);}
#line 2298 "y.tab.c"
    break;

  case 68:
#line 418 "exptree.y"
                 {
                curr_type = typetable_lookup((yyvsp[0].node)->varname);
                if(curr_type == NULL){
                    printf("Error: No UserDefined struct %s exists\n", (yyvsp[0].node)->varname);
                    exit(0); 
                }
                (yyval.type) = curr_type;
            }
#line 2311 "y.tab.c"
    break;

  case 69:
#line 428 "exptree.y"
                              {
            (yyval.DimList) = append_dim((yyvsp[-3].DimList), (yyvsp[-1].node)->val);
        }
#line 2319 "y.tab.c"
    break;

  case 70:
#line 431 "exptree.y"
                        { (yyval.DimList) = create_dimlist(NULL); }
#line 2325 "y.tab.c"
    break;

  case 71:
#line 434 "exptree.y"
                                   {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);
                int varType = get_var_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 2337 "y.tab.c"
    break;

  case 72:
#line 441 "exptree.y"
                                            {
                Gsymbol* temp = find_gsymbol((yyvsp[-3].node)->varname);
                (yyvsp[-3].node)->Gentry = temp;
                check_not_out_of_bounds((yyvsp[-2].DimList),(yyvsp[-3].node)->Gentry->dimlist);
                (yyvsp[-5].node)->left = (yyvsp[-3].node);
                (yyvsp[-3].node)->dimlist = (yyvsp[-2].DimList);
                (yyval.node) = createTree(0,TYPE_NULL, "Read", READNODE,NULL,(yyvsp[-3].node), NULL, NULL);
            }
#line 2350 "y.tab.c"
    break;

  case 73:
#line 449 "exptree.y"
                                      {
                Gsymbol* entry = find_gsymbol((yyvsp[-2].node)->varname);
                tnode* temp = createTree(0, TYPE_PTR, "*", PTRNODE, entry,(yyvsp[-2].node), NULL,NULL);
                (yyval.node) = createTree(0, TYPE_NULL, "Read", READNODE,NULL,temp, NULL, NULL);
            }
#line 2360 "y.tab.c"
    break;

  case 74:
#line 454 "exptree.y"
                                     {
                int type = (yyvsp[-2].node)->type;
                TypeTable* typet = (yyvsp[-2].node)->typeEntry;
                (yyval.node) = createTree(0,(yyvsp[-2].node)->type,"Read",READNODE,NULL,(yyvsp[-2].node),NULL,NULL);
            }
#line 2370 "y.tab.c"
    break;

  case 75:
#line 459 "exptree.y"
                                           {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-4].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-4].node)->varname);
                int type = get_type(ptr1,ptr2,(yyvsp[-4].node)->varname);
                check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,649);
                int varType = get_var_type(ptr1,ptr2,(yyvsp[-4].node)->varname);
                if(varType != TYPE_PTR){
                    printf("Error: %s is not of pointer type, use . operator to access its attributes\n", (yyvsp[-4].node)->varname);
                    exit(0);
                }
                TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[-4].node)->varname);
                tnode* arrow = createTree(0,typetable_lookup_id_type(typet,(yyvsp[-2].node)->varname),"->",ARROWNODE,NULL,(yyvsp[-4].node),NULL,(yyvsp[-2].node));
                (yyval.node) = createTree(0,typetable_lookup_id_type(typet,(yyvsp[-2].node)->varname),"Read",READNODE,NULL,arrow,NULL,NULL);
                arrow->typeEntry = typet;
            }
#line 2390 "y.tab.c"
    break;

  case 76:
#line 476 "exptree.y"
                                  {
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 2399 "y.tab.c"
    break;

  case 77:
#line 482 "exptree.y"
                       {

            if((yyvsp[-1].node)->nodetype != NULLNODE){
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-3].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-3].node)->varname);
                int varType = get_var_type(ptr1,ptr2,(yyvsp[-3].node)->varname);
                if(varType != TYPE_VAR && varType != TYPE_PTR){
                    printf("Error: %s is not of variable type\n",(yyvsp[-3].node)->varname);
                    printf("%s\n",type_to_string(varType));
                    exit(1);
                }
                TypeTable* type = NULL;
                if(ptr2){
                    check_data_types(ptr2->type,(yyvsp[-1].node)->type,ptr2->type,409);
                    type = ptr2->typeEntry;
                }else if(ptr1){
                    check_data_types(ptr1->type,(yyvsp[-1].node)->type,ptr1->type,412);
                    type = ptr1->typeEntry;
                }else{
                    printf("Error: Variable %s Not Declared 462\n", (yyvsp[-3].node)->varname);
                    exit(0);
                }
                if(type->type != (yyvsp[-1].node)->type && type != (yyvsp[-1].node)->typeEntry){
                    char* returnType = (yyvsp[-1].node)->typeEntry->name;
                    char* returningType = type->name;
                    printf("Error: Assignment with different data types, LHS => %s and RHS => %s\n", returningType, returnType);
                    exit(1);
                }
                (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL,(yyvsp[-3].node), NULL, (yyvsp[-1].node));
            }else{
                (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL, (yyvsp[-3].node), NULL, (yyvsp[-1].node));
            }
        }
#line 2437 "y.tab.c"
    break;

  case 78:
#line 515 "exptree.y"
                                {
            Gsymbol* temp = find_gsymbol((yyvsp[-4].node)->varname);
            if(temp->varType != TYPE_ARR){
                printf("Error: %s is not of array type\n",(yyvsp[-4].node)->varname);
                exit(1);
            }
            check_data_types(temp->type,(yyvsp[-1].node)->type,temp->type,432);
            (yyvsp[-4].node)->Gentry = temp;
            (yyvsp[-4].node)->dimlist = (yyvsp[-3].DimList);
            check_not_out_of_bounds((yyvsp[-3].DimList),(yyvsp[-4].node)->Gentry->dimlist);
            (yyval.node) = createTree(0,TYPE_ARR, "=", ASSIGNMENT,(yyvsp[-4].node)->Gentry,(yyvsp[-4].node), NULL, (yyvsp[-1].node));
        }
#line 2454 "y.tab.c"
    break;

  case 79:
#line 527 "exptree.y"
                           {  //here i used MUL because lex returnes MUL when the it captures '*'
            Gsymbol* ptr1 = find_gsymbol((yyvsp[-3].node)->varname);
            Lsymbol* ptr2 = find_lsymbol((yyvsp[-3].node)->varname);
            int varType = get_var_type(ptr1,ptr2,(yyvsp[-3].node)->varname);
            if(varType != TYPE_PTR){
                printf("Error: %s is not of pointer type\n",(yyvsp[-3].node)->varname);
                exit(1);
            }
            if(ptr2){
                check_data_types(ptr2->type,(yyvsp[-1].node)->type,ptr2->type,447);
            }else if(ptr1){
                check_data_types(ptr1->type,(yyvsp[-1].node)->type,ptr1->type,449);
            }else{
                printf("Error: Variable %s Not Declared 498\n", (yyvsp[-3].node)->varname);
                exit(0);
            }
            tnode* t = createTree(0,TYPE_PTR, "*", PTRNODE, NULL,(yyvsp[-3].node), NULL, NULL);
            (yyval.node) = createTree(0,TYPE_PTR, "=", ASSIGNMENT,NULL,t, NULL, (yyvsp[-1].node));
        }
#line 2478 "y.tab.c"
    break;

  case 80:
#line 546 "exptree.y"
                          {
            if((yyvsp[-1].node)->nodetype != NULLNODE){
                if((yyvsp[-3].node)->type != (yyvsp[-1].node)->type){
                    printf("Error: Assignment with different data types %s and %s\n", type_to_string((yyvsp[-3].node)->type), type_to_string((yyvsp[-1].node)->type));
                    exit(0);
                    
                }
                (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL,(yyvsp[-3].node), NULL, (yyvsp[-1].node));
                (yyval.node)->typeEntry = (yyvsp[-3].node)->typeEntry;
            }else {
                (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL,(yyvsp[-3].node), NULL, (yyvsp[-1].node));
                (yyval.node)->typeEntry = (yyvsp[-3].node)->typeEntry;
            }
        }
#line 2497 "y.tab.c"
    break;

  case 81:
#line 560 "exptree.y"
                                {
            Gsymbol* ptr1 = find_gsymbol((yyvsp[-5].node)->varname);
            Lsymbol* ptr2 = find_lsymbol((yyvsp[-5].node)->varname);
            TypeTable* type = NULL;
            if(ptr2){
                type = ptr2->typeEntry;
            }else if(ptr1){
                type = ptr1->typeEntry;
            }else{
                printf("Error: Variable %s Not Declared 539\n", (yyvsp[-5].node)->varname);
                exit(0);
            }
            if(type->type != TYPE_TUPLE){
                printf("Error: Variable %s is not of tuple type\n", (yyvsp[-5].node)->varname);
                exit(0);
            }

            if(typetable_lookup_id_type(type,(yyvsp[-3].node)->varname) != (yyvsp[-1].node)->type){
                printf("Error: Variable %s Not Declared in the tuple definition\n", (yyvsp[-3].node)->varname);
                exit(0);
                
            }
            if(get_var_type(ptr1,ptr2,(yyvsp[-3].node)->varname) != TYPE_PTR){
                printf("Error: %s is not of pointer type, use . operator\n", (yyvsp[-3].node)->varname);
                exit(0);
            }
            tnode* arrow = createTree(0,typetable_lookup_id_type(type,(yyvsp[-3].node)->varname),"->",ARROWNODE,NULL,(yyvsp[-5].node),NULL,(yyvsp[-3].node));
            (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,ptr1,arrow, NULL, (yyvsp[-1].node));
            (yyval.node)->typeEntry = type;
        }
#line 2532 "y.tab.c"
    break;

  case 82:
#line 593 "exptree.y"
                                     {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-5].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-5].node)->varname);

                TypeTable* type = get_typetable(ptr1,ptr2,(yyvsp[-5].node)->varname);

                check_data_types(type->type,type->type,TYPE_TUPLE,559);

                tnode* temp = createTree(type->size, TYPE_NULL, "Alloc", ALLOCNODE,NULL,(yyvsp[-5].node), NULL, NULL);

                temp->typeEntry = type;

                (yyval.node) = temp;
            }
#line 2551 "y.tab.c"
    break;

  case 83:
#line 607 "exptree.y"
                                       {

                if((yyvsp[-5].node)->typeEntry->type != TYPE_TUPLE){
                    printf("Error: Piecewise allocation not possible %s\n", (yyvsp[-5].node)->right->varname);
                    exit(0);
                }

                tnode* temp = createTree((yyvsp[-5].node)->typeEntry->size, TYPE_NULL, "Alloc", ALLOCNODE,NULL,(yyvsp[-5].node), NULL, NULL);

                (yyval.node) = temp;
          }
#line 2567 "y.tab.c"
    break;

  case 84:
#line 618 "exptree.y"
                                {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);

                TypeTable* type = get_typetable(ptr1,ptr2,(yyvsp[-2].node)->varname);

                check_data_types(type->type,type->type,TYPE_TUPLE,559);

                tnode* temp = createTree(type->size, TYPE_NULL, "free", FREENODE,NULL,(yyvsp[-2].node), NULL, NULL);

                temp->typeEntry = type;

                (yyval.node) = temp;
          }
#line 2586 "y.tab.c"
    break;

  case 85:
#line 632 "exptree.y"
                                   {

                if((yyvsp[-2].node)->typeEntry->type != TYPE_TUPLE){
                    printf("Error: Piecewise deallocation not possible %s\n", (yyvsp[-2].node)->right->varname);
                    exit(0);
                }

                tnode* temp = createTree((yyvsp[-2].node)->typeEntry->size, TYPE_NULL, "free", FREENODE,NULL,(yyvsp[-2].node), NULL, NULL);

                (yyval.node) = temp;
          }
#line 2602 "y.tab.c"
    break;

  case 86:
#line 643 "exptree.y"
                                 {
            tnode* temp = createTree(0, TYPE_NULL, "initalize", INITIALIZENODE,NULL,NULL, NULL, NULL);
            (yyval.node) = temp;
          }
#line 2611 "y.tab.c"
    break;

  case 87:
#line 650 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2617 "y.tab.c"
    break;

  case 88:
#line 651 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2623 "y.tab.c"
    break;

  case 89:
#line 652 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2629 "y.tab.c"
    break;

  case 90:
#line 653 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2635 "y.tab.c"
    break;

  case 91:
#line 654 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2641 "y.tab.c"
    break;

  case 92:
#line 655 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2647 "y.tab.c"
    break;

  case 93:
#line 656 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2653 "y.tab.c"
    break;

  case 94:
#line 657 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2659 "y.tab.c"
    break;

  case 95:
#line 658 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2665 "y.tab.c"
    break;

  case 96:
#line 659 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2671 "y.tab.c"
    break;

  case 97:
#line 662 "exptree.y"
                                                       {
            (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-7].node),(yyvsp[-2].node));
        }
#line 2679 "y.tab.c"
    break;

  case 98:
#line 665 "exptree.y"
                                            {
            (yyval.node) = createIfNode((yyvsp[-2].node),(yyvsp[-5].node),NULL);
        }
#line 2687 "y.tab.c"
    break;

  case 99:
#line 670 "exptree.y"
                                                    {
                (yyval.node) = createWhileNode((yyvsp[-2].node),(yyvsp[-5].node));
            }
#line 2695 "y.tab.c"
    break;

  case 100:
#line 675 "exptree.y"
                                           {
                (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
            }
#line 2703 "y.tab.c"
    break;

  case 101:
#line 680 "exptree.y"
                                                      {
                        (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
                    }
#line 2711 "y.tab.c"
    break;

  case 102:
#line 685 "exptree.y"
                           {
                (yyval.node) = createJumpNode(CONTINUENODE);
            }
#line 2719 "y.tab.c"
    break;

  case 103:
#line 688 "exptree.y"
                        {
                (yyval.node) = createJumpNode(BREAKNODE);
            }
#line 2727 "y.tab.c"
    break;

  case 104:
#line 691 "exptree.y"
                           { 
                (yyval.node) = createTree(0, (yyvsp[-1].node)->type, NULL, RETURNNODE, NULL,(yyvsp[-1].node), NULL,NULL);
                (yyval.node)->typeEntry = (yyvsp[-1].node)->typeEntry;
            }
#line 2736 "y.tab.c"
    break;

  case 105:
#line 697 "exptree.y"
                           {
                (yyval.node) = createTree(0,TYPE_NULL,"BRKP", BREAKPOINTNODE,NULL,NULL, NULL, NULL);
            }
#line 2744 "y.tab.c"
    break;

  case 106:
#line 702 "exptree.y"
               {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,567);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "+", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2755 "y.tab.c"
    break;

  case 107:
#line 708 "exptree.y"
                {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,573);
        (yyval.node) =  createTree(0, (yyvsp[-2].node)->type , "-", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2766 "y.tab.c"
    break;

  case 108:
#line 714 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,579);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "/", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2777 "y.tab.c"
    break;

  case 109:
#line 720 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,585);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "*", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2788 "y.tab.c"
    break;

  case 110:
#line 726 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,591);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "%", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2799 "y.tab.c"
    break;

  case 111:
#line 732 "exptree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2807 "y.tab.c"
    break;

  case 112:
#line 735 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,600);
        (yyval.node) = createTree(0,TYPE_BOOL,">",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2816 "y.tab.c"
    break;

  case 113:
#line 739 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,604);
        (yyval.node) = createTree(0,TYPE_BOOL,"<",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2825 "y.tab.c"
    break;

  case 114:
#line 743 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,608);
        (yyval.node) = createTree(0,TYPE_BOOL,">=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2834 "y.tab.c"
    break;

  case 115:
#line 747 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,612);
        (yyval.node) = createTree(0,TYPE_BOOL,"<=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2843 "y.tab.c"
    break;

  case 116:
#line 751 "exptree.y"
             {
        if((yyvsp[-2].node)->type == TYPE_TUPLE && (yyvsp[0].node)->nodetype == NULLNODE){

        }else{
            check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,616);
        }
        (yyval.node) = createTree(0,TYPE_BOOL,"!=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2856 "y.tab.c"
    break;

  case 117:
#line 759 "exptree.y"
             {
        if((yyvsp[-2].node)->type == TYPE_TUPLE && (yyvsp[0].node)->nodetype == NULLNODE){
                
        }else{
            check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,616);
        }
        (yyval.node) = createTree(0,TYPE_BOOL,"==",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2869 "y.tab.c"
    break;

  case 118:
#line 767 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_BOOL,624);
        (yyval.node) = createTree(0,TYPE_BOOL,"&&",OPERATOR,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2878 "y.tab.c"
    break;

  case 119:
#line 771 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_BOOL,628);
        (yyval.node) = createTree(0,TYPE_BOOL,"||",OPERATOR,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2887 "y.tab.c"
    break;

  case 120:
#line 775 "exptree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2895 "y.tab.c"
    break;

  case 121:
#line 778 "exptree.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2903 "y.tab.c"
    break;

  case 122:
#line 781 "exptree.y"
                  {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);
        int type = get_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
        check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,649);
        int varType = get_var_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
        if(varType != TYPE_PTR){
            printf("Error: %s is not of pointer type, use . operator to access its attributes\n", (yyvsp[-2].node)->varname);
            exit(0);
        }
        TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[-2].node)->varname);
        (yyval.node) = createTree(0,typetable_lookup_id_type(typet,(yyvsp[0].node)->varname),"->",ARROWNODE,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
        (yyval.node)->typeEntry = typet;
    }
#line 2922 "y.tab.c"
    break;

  case 123:
#line 795 "exptree.y"
                 {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
        if(!ptr1 || ptr1->varType != TYPE_FUNCT || ptr1->varType != TYPE_FUNCT_PTR){
            printf("Error: No function with name %s declared\n",(yyvsp[-2].node)->varname);
            exit(0);
        }
        paramlist_is_input_args_correct(ptr1->plist, NULL);
        TypeTable* typet = get_typetable(ptr1,NULL,(yyvsp[-2].node)->varname);
        (yyval.node) = createTree(0,ptr1->type,"funtion()",FUNCTIONNODE,NULL,(yyvsp[-2].node),NULL,NULL);
        (yyval.node)->typeEntry = typet;
    }
#line 2938 "y.tab.c"
    break;

  case 124:
#line 806 "exptree.y"
                         {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[-3].node)->varname);

        print_gsymbol_list(ptr1);
        if(!ptr1 || (ptr1->varType != TYPE_FUNCT && ptr1->varType != TYPE_FUNCT_PTR)){
            printf("Error: No function with name %s declared\n",(yyvsp[-3].node)->varname);
            exit(0);
        }
        tnode* temp = (yyvsp[-1].node);
        // while(temp){
        //     print_ast_node(temp);
        //     temp = temp->middle;
        // }
        paramlist_is_input_args_correct(ptr1->plist, (yyvsp[-1].node));
        TypeTable* typet = get_typetable(ptr1,NULL,(yyvsp[-3].node)->varname);
        (yyval.node) = createTree(0,ptr1->type,"funtion()",FUNCTIONNODE,NULL,(yyvsp[-3].node),NULL,(yyvsp[-1].node));
        (yyval.node)->typeEntry = typet;
    }
#line 2961 "y.tab.c"
    break;

  case 125:
#line 824 "exptree.y"
         {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[0].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[0].node)->varname);
        
        int varType = get_var_type(ptr1,ptr2,(yyvsp[0].node)->varname);
        // printf("%s is of %s\n",$1->varname, type_to_string(varType));
        if(varType != TYPE_VAR && varType != TYPE_PTR){
            printf("Error: %s is not of variable type\n",(yyvsp[0].node)->varname);
            exit(1);
        }
        TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[0].node)->varname);
        (yyval.node) = createTree(0, get_type(ptr1,ptr2,(yyvsp[0].node)->varname), (yyvsp[0].node)->varname, LEAFNODE, ptr1,NULL, NULL,NULL);
        (yyval.node)->typeEntry = typet;
    }
#line 2980 "y.tab.c"
    break;

  case 126:
#line 838 "exptree.y"
                   {
        Gsymbol* temp = find_gsymbol((yyvsp[-1].node)->varname);
        if(!(yyvsp[0].DimList)){
            if(temp->varType != TYPE_ARR){
                printf("Error: %s is of array type but using it as variable type here\n",(yyvsp[-1].node)->varname);
                exit(1);
            }
        }
        (yyvsp[-1].node)->Gentry = temp;
        check_not_out_of_bounds((yyvsp[0].DimList),(yyvsp[-1].node)->Gentry->dimlist);
        int val = get_pos((yyvsp[0].DimList),(yyvsp[-1].node)->Gentry->dimlist);
        (yyval.node) = createTree(val, temp->type, (yyvsp[-1].node)->varname, LEAFNODE, temp,NULL, NULL,NULL);
        TypeTable* typet = get_typetable(temp,NULL,(yyvsp[-1].node)->varname);
        (yyval.node)->typeEntry = typet;
        (yyval.node)->dimlist = (yyvsp[0].DimList);
    }
#line 3001 "y.tab.c"
    break;

  case 127:
#line 854 "exptree.y"
             { //here i used MUL because lex returnes MUL when the it captures '*'
        Gsymbol* ptr1 = find_gsymbol((yyvsp[0].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[0].node)->varname);

        if(!ptr1 && !ptr2){
            printf("Error: pointer %s is not declared\n", (yyvsp[0].node)->varname);
        }
        (yyvsp[0].node)->Gentry = ptr1;
        (yyval.node) = createTree(0, TYPE_INT, "*", PTRNODE, ptr1,(yyvsp[0].node), NULL,NULL);
        TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[0].node)->varname);
        (yyval.node)->typeEntry = typet;
        (yyvsp[0].node)->typeEntry = typet;
    }
#line 3019 "y.tab.c"
    break;

  case 128:
#line 867 "exptree.y"
             {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[0].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[0].node)->varname);

        if(!ptr1 && !ptr2){
            printf("Error: pointer %s is not declared\n", (yyvsp[0].node)->varname);
        }
        (yyvsp[0].node)->Gentry = ptr1;

        (yyval.node) = createTree(0, TYPE_INT, "&", ADDRNODE, NULL,(yyvsp[0].node), NULL,NULL);
        TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[0].node)->varname);
        (yyval.node)->typeEntry = typet;
        (yyvsp[0].node)->typeEntry = typet;
    }
#line 3038 "y.tab.c"
    break;

  case 129:
#line 881 "exptree.y"
             {
        (yyval.node) = createTree(-10, TYPE_STRING, (yyvsp[0].string), LEAFNODE,NULL, NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("str");
        (yyval.node)->typeEntry = typet;
    }
#line 3048 "y.tab.c"
    break;

  case 130:
#line 886 "exptree.y"
          {
        (yyval.node) = createTree((yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 3058 "y.tab.c"
    break;

  case 131:
#line 891 "exptree.y"
                {
        (yyval.node) = createTree(-(yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 3068 "y.tab.c"
    break;

  case 132:
#line 897 "exptree.y"
                                  {
                check_data_types((yyvsp[-1].node)->type,TYPE_INT,TYPE_INT,756);
                (yyval.DimList) = append_dim_with_id((yyvsp[-3].DimList),(yyvsp[-1].node));
            }
#line 3077 "y.tab.c"
    break;

  case 133:
#line 901 "exptree.y"
                        {
                check_data_types((yyvsp[-1].node)->type,TYPE_INT,TYPE_INT,760);
                (yyval.DimList) = append_dim_with_id(NULL,(yyvsp[-1].node));
            }
#line 3086 "y.tab.c"
    break;

  case 134:
#line 907 "exptree.y"
                       {
            int type = (yyvsp[-2].node)->type;
            check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,803);
            TypeTable* typet = (yyvsp[-2].node)->typeEntry;
            typetable_print(typet);
            TypeTable* typet2 = typetable_lookup_id_typetable(typet,(yyvsp[0].node)->varname);
            (yyval.node) = createTree(0,typetable_lookup_id_type(typet,(yyvsp[0].node)->varname),".",DOTNODE,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
            (yyval.node)->typeEntry = typet2;
            (yyvsp[0].node)->typeEntry = typet2;
            // printf("typeEntry %s 806\n", typet->name);
        }
#line 3102 "y.tab.c"
    break;

  case 135:
#line 918 "exptree.y"
                    {
            Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
            Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);
            int type = get_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
            check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,803);
            int varType = get_var_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
            if(varType == TYPE_PTR){
                printf("Error: %s is of pointer type, use -> operator to access its attributes\n", (yyvsp[-2].node)->varname);
                exit(0);
            }
            TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[-2].node)->varname);
            TypeTable* typet2 = typetable_lookup_id_typetable(typet,(yyvsp[0].node)->varname);
            (yyval.node) = createTree(0,typetable_lookup_id_type(typet,(yyvsp[0].node)->varname),"dot",DOTNODE,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
            (yyval.node)->typeEntry = typet2;
            (yyvsp[-2].node)->typeEntry = typet;
         }
#line 3123 "y.tab.c"
    break;


#line 3127 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 938 "exptree.y"



void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType){
    Gsymbol* temp = find_gsymbol($2->varname);
    if($1 != temp->type || functionType != temp->varType){
        printf("Error: Incorrect return type for the Function %s\n", $2->varname);
        printf("%d---%d\n",$1,temp->type);
        exit(0);
    }
    curr_function_type = temp->typeEntry;
    is_paramlist_correct(temp->plist,$4);

    print_lsymbol_table();

    curr_funct_return_type = functionType;
    
    //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome 
    // curr_lsymbol_table = $7;

    ParamList* t = $4;
    int p = getReg();
    fprintf(fptr,"F%d:", temp->flabel);
    fprintf(fptr, "MOV R%d, BP\n", p);
    fprintf(fptr, "PUSH R%d\n", p);
    fprintf(fptr, "MOV BP, SP\n");
    
    int param_list_size = get_paramlist_length($4);

    //setting up the argument values into the respective addresses in the from the local symbol table
    int count = param_list_size;
    int returnSize = 1;
    if(functionType == TYPE_FUNCT_PTR){
        returnSize = 1;
    }
    /* fprintf(fptr, "BRKP\n");
    fprintf(fptr, "BRKP\n"); */
    while(count--){
        fprintf(fptr, "MOV R%d, SP\n", p);
        fprintf(fptr, "SUB R%d, %d\n", p, param_list_size + 2 + returnSize - 1); //here the 3 is the RETURN VALUE, RETURN ADDRESS, OLD BP and the -1 for preventing the overreduction as subtracting curr_offset u reach the OLD BP 
                                                                    // and from there to reach the return value part u just need to subtract 2 and to reach the 1st arg u just need to subtract the whole paramlist
        fprintf(fptr, "MOV R%d, [R%d]\n", p, p);
        fprintf(fptr, "PUSH R%d\n", p);
    }

    /* fprintf(fptr, "BRKP\n"); */

    // This is to set up space for the locally declared variables in the function
    int curr_offset = get_ltable_length(curr_lsymbol_table) - param_list_size;

    fprintf(fptr, "MOV R%d, \"SPACE\"\n", p);
    for(int i=0;i<curr_offset;i++){
        fprintf(fptr,"PUSH R%d\n",p);
    }

    freeReg();

    export_ast_to_graphviz($8,$2->varname);

    tree_visual_printTree($8);

    Lsymbol* temp1 = curr_lsymbol_table;

    int param_list_length = get_paramlist_length($4);
    while(param_list_length-- > 0){
        temp1 = temp1->next;
    }

    setup_pointers_codegen(fptr,NULL,temp1);

    codeGen($8,0,0,fptr);
    Lsymbol* a = curr_lsymbol_table;
    // lst_destroy(a);
    curr_lsymbol_table = NULL;
    // ast_destroy($8);
}


void yyerror(char* s){
    printf("Error encountered: %s\n", s);
    exit(1);
}





int main(int argc, char *argv[]) {
    

    yyin = fopen(argv[1], "r");
    fptr = fopen("machinecode.xsm", "w");
    typetable_create("int", TYPE_INT,  NULL);
    typetable_create("str", TYPE_STRING, NULL);
    typetable_create("bool", TYPE_BOOL, NULL);
    typetable_create("void", TYPE_VOID, NULL);
    make_header(fptr);
    yyparse();
    
    print_gsymbol_table();
    exit_footer(fptr);
    create_label_with_message(fptr,101,"IndexOutOfBounds");
    fclose(fptr);
    fclose(yyin);
    /* codeIntrepret(head); */
    return 0;
}
