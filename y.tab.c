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

#line 256 "y.tab.c"

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
#define YYLAST   782

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

#define YYUNDEFTOK  2
#define YYMAXUTOK   304


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
       2,     2,     2,     2,     2,     2,     2,     2,    59,     2,
      52,    53,     2,     2,    51,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,    58,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    62,    63,    66,    74,    81,    82,    85,
     107,   110,   113,   125,   131,   139,   150,   153,   156,   157,
     160,   164,   170,   177,   180,   182,   189,   190,   193,   198,
     205,   214,   224,   227,   236,   241,   250,   260,   263,   276,
     281,   296,   300,   305,   308,   316,   325,   331,   366,   368,
     372,   377,   378,   379,   389,   392,   395,   402,   410,   415,
     420,   437,   443,   476,   488,   507,   521,   554,   568,   579,
     593,   604,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   623,   626,   631,   636,   641,   646,   649,   652,
     658,   663,   669,   675,   681,   687,   693,   696,   700,   704,
     708,   712,   720,   728,   732,   736,   739,   742,   756,   767,
     785,   799,   815,   828,   842,   847,   852,   858,   862,   868,
     879
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WRITE", "READ", "INT", "STR", "ID",
  "NUM", "NILL", "STRING", "begin", "end", "MAIN", "DECL", "ENDDECL",
  "TYPE", "ENDTYPE", "TUPLE", "STRUCT", "PLUS", "MINUS", "DIV", "MUL",
  "ARROW", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "REPEAT", "UNTIL", "CONTINUE", "BREAK", "RETURN", "BREAKPOINT", "FREE",
  "ALLOC", "INITIALIZE", "GT", "GE", "LT", "LE", "NE", "EQ", "AND", "OR",
  "MOD", "';'", "','", "'('", "')'", "'{'", "'}'", "'['", "']'", "'='",
  "'&'", "'.'", "$accept", "Program", "GDeclBlock", "GDeclList", "GDecl",
  "GidList", "Gid", "TDeclBlock", "TDeclList", "TDeclStart", "TDecl",
  "TIdList", "TIdDecl", "FDefBlock", "Fdef", "Paramlist", "ParamDecl",
  "Param", "LdeclBlock", "LDecList", "LDecl", "IdList", "IdDecl",
  "ArgList", "MainBlock", "body", "Slist", "Type", "DimList", "InputStmt",
  "OutputStmt", "AsgStmt", "Allocstmnt", "Stmt", "Ifstmt", "Whilestmt",
  "DoWhilestmt", "RepeatUntiltstmt", "Jumpstmt", "Debugstmt", "E",
  "DimAccess", "Field", YY_NULLPTR
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
      59,    44,    40,    41,   123,   125,    91,    93,    61,    38,
      46
};
# endif

#define YYPACT_NINF (-132)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      35,     1,   100,   177,    53,   121,   144,    88,  -132,  -132,
    -132,  -132,  -132,   117,   213,  -132,   142,  -132,  -132,  -132,
    -132,   213,  -132,   174,  -132,     5,   213,  -132,  -132,   112,
     107,   114,  -132,   178,  -132,  -132,   136,   193,   118,  -132,
    -132,  -132,   154,   203,   158,     0,  -132,   213,   160,   173,
    -132,     5,   213,   179,   172,   198,  -132,    46,  -132,     8,
     230,   213,  -132,    96,   213,   207,  -132,   213,  -132,  -132,
     243,  -132,   194,   101,   199,   171,   213,   244,  -132,  -132,
    -132,  -132,   207,   214,   208,  -132,   103,   329,   215,   244,
     207,  -132,  -132,  -132,   264,   125,  -132,   220,   221,    90,
     267,   223,   225,   329,   329,   231,   236,   108,   242,   227,
     228,   205,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,   169,  -132,   241,   244,  -132,  -132,   103,
     108,   120,   290,   108,    49,   292,   188,   245,   108,   108,
     353,   229,  -132,  -132,   -10,  -132,  -132,  -132,   293,   295,
     108,   297,   562,   240,  -132,   298,   254,  -132,  -132,    82,
     299,  -132,   255,  -132,   421,    80,   301,   -30,   251,   374,
     259,   572,  -132,   108,   108,   108,   434,   468,   260,   261,
     308,    86,   262,  -132,  -132,   481,  -132,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
    -132,    60,    77,   272,   265,   603,  -132,  -132,   274,   323,
     284,    18,   282,   287,   108,  -132,   285,  -132,   391,   613,
     644,   313,   310,   108,   108,  -132,  -132,   196,   685,  -132,
      17,    17,  -132,  -132,   -12,   -12,   -12,   -12,   733,   733,
     724,   694,  -132,   294,   296,  -132,   288,  -132,  -132,   289,
    -132,   300,   303,  -132,   654,   305,  -132,  -132,  -132,   329,
     329,   515,   528,   108,  -132,  -132,  -132,   312,   318,  -132,
    -132,  -132,  -132,   167,   253,    -1,   320,   685,  -132,  -132,
     329,   321,   322,  -132,  -132,   291,  -132,  -132,   324,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      17,     0,     0,     0,     0,     0,     0,     0,    19,     1,
      51,    52,    53,     0,     0,     4,     0,    20,    21,    16,
      18,     0,     6,     0,     8,     0,     0,    27,     3,     0,
       0,     0,    24,     0,     5,     7,    55,     0,     0,    11,
      26,     2,     0,     0,     0,     0,    25,    32,    12,    13,
       9,     0,    32,     0,     0,     0,    23,     0,    31,     0,
       0,    32,    10,     0,    32,    37,    22,     0,    14,    34,
       0,    33,     0,     0,     0,     0,     0,     0,    30,    35,
      54,    15,    37,     0,     0,    39,     0,     0,     0,     0,
      37,    36,    38,    43,     0,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,    74,    81,    50,    75,    76,    77,
      78,    79,    80,     0,    47,     0,     0,    44,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,   110,   115,   105,   114,     0,     0,
       0,     0,     0,   106,    90,     0,     0,    48,    49,     0,
       0,    28,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,   116,   112,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,   119,    29,     0,     0,
       0,     0,     0,     0,     0,   118,     0,    62,     0,     0,
       0,     0,     0,     0,     0,   107,   108,     0,    46,    96,
      91,    92,    93,    94,    97,    99,    98,   100,   101,   102,
     103,   104,    95,     0,     0,    71,     0,    65,    61,     0,
      56,     0,     0,    59,     0,     0,   117,    63,    64,     0,
       0,     0,     0,     0,   109,    69,    70,     0,     0,    57,
      58,    66,    67,     0,     0,     0,     0,    45,    68,    60,
       0,     0,     0,    85,    86,     0,    83,    84,     0,    82
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,  -132,   325,  -132,   326,  -132,  -132,  -132,
     337,  -132,   302,  -132,   319,    92,   306,  -132,   -17,  -132,
     314,  -132,   222,  -132,    38,   -85,  -102,    22,  -132,  -132,
    -132,  -132,  -132,  -108,  -132,  -132,  -132,  -132,  -132,  -132,
    -112,  -131,   -87
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    14,    23,    24,    38,    39,     3,     6,     7,
       8,    31,    32,    26,    27,    57,    58,    71,    77,    84,
      85,    95,    96,   227,    15,    88,   111,    59,    48,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     152,   136,   153
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   140,   141,   158,   125,    10,    11,    12,   187,   188,
     189,   190,    36,   182,   180,    69,   123,   123,   164,     4,
       5,   169,   171,   213,   123,    16,   176,   177,    37,   260,
     160,    70,   158,   158,   211,    25,    29,   199,   185,   189,
     190,   162,   181,    33,   167,    25,   133,   205,    29,   283,
     135,     1,    28,   123,   123,    55,   144,   145,   146,   147,
      17,   218,   219,   220,    41,    89,   199,    33,   202,   228,
     148,   251,   149,   126,   173,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   170,   144,
     145,   146,   147,   144,   145,   146,   147,    67,    86,    68,
       9,   150,   254,   148,   209,   149,    86,   148,   151,   149,
      93,   261,   262,   243,   132,   144,   145,   146,   147,    42,
     135,   204,    10,    11,    12,    30,    94,   165,    18,   148,
     244,   149,    22,   210,   150,    43,   133,   160,   150,   226,
     135,   151,    21,   166,    63,   151,   133,    67,   134,    74,
     135,   277,    67,    73,    81,    30,    75,   273,   274,    44,
     150,    19,     4,     5,    45,   158,   158,   151,    50,    51,
      97,    98,   123,   123,    99,   128,   129,   158,   285,    10,
      11,    12,    10,    11,    12,    46,   123,   123,    47,    34,
     100,    13,   101,   123,   280,   281,   102,   103,   123,   104,
      49,   105,   106,   107,   108,   109,    52,   110,    97,    98,
      53,    54,    99,    10,    11,    12,    60,   157,    10,    11,
      12,    76,    67,    91,    83,    61,    65,   159,   100,   160,
     101,    64,    97,    98,   102,   103,    99,   104,    72,   105,
     106,   107,   108,   109,   173,   110,   174,   263,    66,   264,
      79,    80,   100,    82,   101,    87,    97,    98,   102,   103,
      99,   104,   179,   105,   106,   107,   108,   109,    90,   110,
     124,   127,   130,   131,   137,   138,   100,   139,   101,   155,
     156,   142,   102,   103,   282,   104,   143,   105,   106,   107,
     108,   109,   154,   110,    97,    98,   161,   168,    99,   172,
     160,   183,   184,   175,   186,   201,   206,   203,   212,   214,
     207,   216,   223,   224,   100,   225,   101,   246,   173,   288,
     102,   103,   245,   104,   248,   105,   106,   107,   108,   109,
     249,   110,    97,    98,   250,   252,    99,   253,   255,   259,
     260,   267,   268,    20,   265,    40,   266,    56,    35,     0,
     269,   163,   100,   270,   101,   272,    97,    98,   102,   103,
      99,   104,   278,   105,   106,   107,   108,   109,   279,   110,
     284,   286,   287,    78,   289,     0,   100,    62,   101,     0,
       0,     0,   178,   103,     0,   104,     0,   105,   106,   107,
     108,   109,     0,   110,   187,   188,   189,   190,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     0,     0,     0,     0,     0,     0,
       0,   215,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   187,   188,   189,   190,     0,     0,     0,   256,     0,
       0,     0,     0,     0,   187,   188,   189,   190,     0,     0,
       0,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,     0,     0,   208,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     0,     0,     0,   221,   187,   188,
     189,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,   188,   189,   190,     0,     0,     0,     0,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,     0,
       0,   222,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,     0,     0,   229,   187,   188,   189,   190,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,   188,
     189,   190,     0,     0,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     0,     0,     0,   275,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,     0,
       0,   276,   187,   188,   189,   190,     0,     0,     0,     0,
       0,     0,   187,   188,   189,   190,     0,     0,     0,     0,
       0,     0,     0,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   217,   187,   188,   189,   190,     0,     0,     0,
       0,     0,     0,   187,   188,   189,   190,     0,     0,     0,
       0,     0,     0,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   247,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   257,   187,   188,   189,   190,     0,     0,
       0,     0,     0,     0,   187,   188,   189,   190,     0,     0,
       0,     0,     0,     0,     0,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   258,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   271,   187,   188,   189,   190,     0,
       0,     0,     0,     0,   187,   188,   189,   190,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   191,   192,   193,   194,   195,
     196,   197,     0,   199,   187,   188,   189,   190,     0,     0,
       0,     0,     0,   187,   188,   189,   190,     0,     0,     0,
       0,     0,     0,     0,     0,   191,   192,   193,   194,   195,
     196,     0,     0,   199,   191,   192,   193,   194,     0,     0,
       0,     0,   199
};

static const yytype_int16 yycheck[] =
{
      87,   103,   104,   111,    89,     5,     6,     7,    20,    21,
      22,    23,     7,   144,    24,     7,   103,   104,   130,    18,
      19,   133,   134,    53,   111,     3,   138,   139,    23,    30,
      60,    23,   140,   141,   165,    13,    14,    49,   150,    22,
      23,   126,    52,    21,   131,    23,    56,   159,    26,    50,
      60,    16,    14,   140,   141,    55,     7,     8,     9,    10,
       7,   173,   174,   175,    26,    82,    49,    45,   155,   181,
      21,    53,    23,    90,    56,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,    39,     7,
       8,     9,    10,     7,     8,     9,    10,    51,    76,    53,
       0,    52,   214,    21,    24,    23,    84,    21,    59,    23,
       7,   223,   224,    53,    24,     7,     8,     9,    10,     7,
      60,    39,     5,     6,     7,    13,    23,     7,     7,    21,
      53,    23,    15,    53,    52,    23,    56,    60,    52,    53,
      60,    59,    54,    23,    52,    59,    56,    51,    58,    53,
      60,   263,    51,    61,    53,    13,    64,   259,   260,    52,
      52,    17,    18,    19,    50,   273,   274,    59,    50,    51,
       3,     4,   259,   260,     7,    50,    51,   285,   280,     5,
       6,     7,     5,     6,     7,     7,   273,   274,    52,    15,
      23,    14,    25,   280,    27,    28,    29,    30,   285,    32,
       7,    34,    35,    36,    37,    38,    52,    40,     3,     4,
       7,    53,     7,     5,     6,     7,    56,    12,     5,     6,
       7,    14,    51,    15,    53,    52,    54,    58,    23,    60,
      25,    52,     3,     4,    29,    30,     7,    32,     8,    34,
      35,    36,    37,    38,    56,    40,    58,    51,    50,    53,
       7,    57,    23,    54,    25,    11,     3,     4,    29,    30,
       7,    32,    33,    34,    35,    36,    37,    38,    54,    40,
      55,     7,    52,    52,     7,    52,    23,    52,    25,    52,
      52,    50,    29,    30,    31,    32,    50,    34,    35,    36,
      37,    38,    50,    40,     3,     4,    55,     7,     7,     7,
      60,     8,     7,    58,     7,     7,     7,    53,     7,    58,
      55,    52,    52,    52,    23,     7,    25,    52,    56,    28,
      29,    30,    50,    32,    50,    34,    35,    36,    37,    38,
       7,    40,     3,     4,    50,    53,     7,    50,    53,    26,
      30,    53,    53,     6,    50,    26,    50,    45,    23,    -1,
      50,   129,    23,    50,    25,    50,     3,     4,    29,    30,
       7,    32,    50,    34,    35,    36,    37,    38,    50,    40,
      50,    50,    50,    67,    50,    -1,    23,    51,    25,    -1,
      -1,    -1,    29,    30,    -1,    32,    -1,    34,    35,    36,
      37,    38,    -1,    40,    20,    21,    22,    23,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    20,    21,    22,    23,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    -1,    -1,    49,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    16,    62,    68,    18,    19,    69,    70,    71,     0,
       5,     6,     7,    14,    63,    85,    88,     7,     7,    17,
      71,    54,    15,    64,    65,    88,    74,    75,    85,    88,
      13,    72,    73,    88,    15,    65,     7,    23,    66,    67,
      75,    85,     7,    23,    52,    50,     7,    52,    89,     7,
      50,    51,    52,     7,    53,    55,    73,    76,    77,    88,
      56,    52,    67,    76,    52,    54,    50,    51,    53,     7,
      23,    78,     8,    76,    53,    76,    14,    79,    77,     7,
      57,    53,    54,    53,    80,    81,    88,    11,    86,    79,
      54,    15,    81,     7,    23,    82,    83,     3,     4,     7,
      23,    25,    29,    30,    32,    34,    35,    36,    37,    38,
      40,    87,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   103,    55,    86,    79,     7,    50,    51,
      52,    52,    24,    56,    58,    60,   102,     7,    52,    52,
      87,    87,    50,    50,     7,     8,     9,    10,    21,    23,
      52,    59,   101,   103,    50,    52,    52,    12,    94,    58,
      60,    55,    86,    83,   101,     7,    23,   103,     7,   101,
      39,   101,     7,    56,    58,    58,   101,   101,    29,    33,
      24,    52,   102,     8,     7,   101,     7,    20,    21,    22,
      23,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     7,   103,    53,    39,   101,     7,    55,    53,    24,
      53,   102,     7,    53,    58,    57,    52,    50,   101,   101,
     101,    53,    53,    52,    52,     7,    53,    84,   101,    53,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,    53,    53,    50,    52,    50,    50,     7,
      50,    53,    53,    50,   101,    53,    57,    50,    50,    26,
      30,   101,   101,    51,    53,    50,    50,    53,    53,    50,
      50,    50,    50,    87,    87,    53,    53,   101,    50,    50,
      27,    28,    31,    50,    50,    87,    50,    50,    28,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    63,    63,    64,    64,    65,
      66,    66,    67,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    72,    72,    73,    74,    74,    75,    75,
      76,    76,    76,    77,    78,    78,    79,    79,    80,    80,
      81,    82,    82,    83,    83,    84,    84,    85,    86,    87,
      87,    88,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    91,    92,    92,    92,    92,    92,    93,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    95,    95,    96,    97,    98,    99,    99,    99,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   102,   102,   103,
     103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     2,     1,     3,
       3,     1,     2,     2,     4,     5,     3,     0,     2,     1,
       2,     2,     6,     3,     1,     2,     2,     1,     9,    10,
       3,     1,     0,     2,     1,     2,     3,     0,     2,     1,
       3,     3,     1,     1,     2,     3,     1,     8,     3,     2,
       1,     1,     1,     1,     4,     0,     5,     6,     6,     5,
       7,     5,     4,     5,     5,     4,     6,     6,     6,     5,
       5,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,    10,     8,     8,     7,     7,     2,     2,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     4,
       1,     2,     2,     2,     1,     1,     2,     4,     3,     3,
       3
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
#line 1726 "y.tab.c"
    break;

  case 3:
#line 62 "exptree.y"
                                          {}
#line 1732 "y.tab.c"
    break;

  case 4:
#line 63 "exptree.y"
                               {}
#line 1738 "y.tab.c"
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
#line 1751 "y.tab.c"
    break;

  case 6:
#line 74 "exptree.y"
                           {
                stack_address = curr_stack_address;
                is_global_vars_declared = 1;
                driver_codegen(fptr);
            }
#line 1761 "y.tab.c"
    break;

  case 7:
#line 81 "exptree.y"
                              {}
#line 1767 "y.tab.c"
    break;

  case 8:
#line 82 "exptree.y"
                   {}
#line 1773 "y.tab.c"
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
#line 1798 "y.tab.c"
    break;

  case 10:
#line 107 "exptree.y"
                         {
            (yyval.gsymbol) = append_gsymbol_id_list((yyvsp[-2].gsymbol),(yyvsp[0].gsymbol));    
        }
#line 1806 "y.tab.c"
    break;

  case 11:
#line 110 "exptree.y"
              { (yyval.gsymbol) = (yyvsp[0].gsymbol);}
#line 1812 "y.tab.c"
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
#line 1829 "y.tab.c"
    break;

  case 13:
#line 125 "exptree.y"
                 {
            Gsymbol* temp = create_gsymbol_id((yyvsp[0].node)->varname, 2);
            (yyvsp[0].node)->Gentry = temp;
            temp->varType = TYPE_PTR;
            (yyval.gsymbol) = temp;
        }
#line 1840 "y.tab.c"
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
#line 1853 "y.tab.c"
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
#line 1866 "y.tab.c"
    break;

  case 16:
#line 150 "exptree.y"
                                      {
                // typetable_print(type_table);
            }
#line 1874 "y.tab.c"
    break;

  case 17:
#line 153 "exptree.y"
                {}
#line 1880 "y.tab.c"
    break;

  case 18:
#line 156 "exptree.y"
                              {}
#line 1886 "y.tab.c"
    break;

  case 19:
#line 157 "exptree.y"
                    {}
#line 1892 "y.tab.c"
    break;

  case 20:
#line 160 "exptree.y"
                       {
                typetable_create((yyvsp[0].node)->varname,TYPE_TUPLE,NULL);
                (yyval.string) = (yyvsp[0].node)->varname;
            }
#line 1901 "y.tab.c"
    break;

  case 21:
#line 164 "exptree.y"
                        {
                typetable_create((yyvsp[0].node)->varname,TYPE_TUPLE,NULL);
                (yyval.string) = (yyvsp[0].node)->varname;
            }
#line 1910 "y.tab.c"
    break;

  case 22:
#line 170 "exptree.y"
                                                 {
                typetable_append_plist((char*) (yyvsp[-5].string), (yyvsp[-3].plist));
                ParamList* temp = (yyvsp[-3].plist);
                
                
            }
#line 1921 "y.tab.c"
    break;

  case 23:
#line 177 "exptree.y"
                                  {
                (yyval.plist) = append_param_to_list((yyvsp[-2].plist),(yyvsp[0].plist));
            }
#line 1929 "y.tab.c"
    break;

  case 24:
#line 180 "exptree.y"
                      { (yyval.plist) = (yyvsp[0].plist); }
#line 1935 "y.tab.c"
    break;

  case 25:
#line 182 "exptree.y"
                      {
                (yyval.plist) = create_param((yyvsp[0].node)->varname, (yyvsp[-1].type)->type);
                (yyval.plist)->typeEntry = (yyvsp[-1].type);
            }
#line 1944 "y.tab.c"
    break;

  case 26:
#line 189 "exptree.y"
                             {}
#line 1950 "y.tab.c"
    break;

  case 27:
#line 190 "exptree.y"
                   {}
#line 1956 "y.tab.c"
    break;

  case 28:
#line 193 "exptree.y"
                                                                  {    
                
                function_block((yyvsp[-8].type)->type,(yyvsp[-7].node),paramlist_deepcopy((yyvsp[-5].plist)),(yyvsp[-1].node),TYPE_FUNCT);

            }
#line 1966 "y.tab.c"
    break;

  case 29:
#line 198 "exptree.y"
                                                                      {
                
                function_block((yyvsp[-9].type)->type, (yyvsp[-7].node),paramlist_deepcopy((yyvsp[-5].plist)),(yyvsp[-1].node), TYPE_FUNCT_PTR);

            }
#line 1976 "y.tab.c"
    break;

  case 30:
#line 205 "exptree.y"
                                      {
                (yyval.plist) = append_param_to_list((yyvsp[-2].plist),(yyvsp[0].plist));
                if(is_global_vars_declared == 1){
                    Lsymbol* t1 = create_lsymbol_id((yyvsp[0].plist)->name, (yyvsp[0].plist)->varType == TYPE_PTR ? 1 : (yyvsp[0].plist)->size, (yyvsp[0].plist)->varType);
                    t1->type = (yyvsp[0].plist)->type;
                    t1->typeEntry = (yyvsp[0].plist)->typeEntry;
                    curr_lsymbol_table = append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
            }
#line 1990 "y.tab.c"
    break;

  case 31:
#line 214 "exptree.y"
                        {
                (yyval.plist) = (yyvsp[0].plist);
                if(is_global_vars_declared == 1){
                    Lsymbol* t1 = create_lsymbol_id((yyvsp[0].plist)->name, (yyvsp[0].plist)->size, (yyvsp[0].plist)->varType);
                    t1->type = (yyvsp[0].plist)->type;
                    t1->typeEntry = (yyvsp[0].plist)->typeEntry;
                    curr_lsymbol_table =  append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
                
            }
#line 2005 "y.tab.c"
    break;

  case 32:
#line 224 "exptree.y"
                                            {(yyval.plist) = NULL;curr_lsymbol_table= NULL;}
#line 2011 "y.tab.c"
    break;

  case 33:
#line 227 "exptree.y"
                         {
                (yyvsp[0].plist)->type = (yyvsp[-1].type)->type;
                (yyvsp[0].plist)->typeEntry = (yyvsp[-1].type);
                (yyvsp[0].plist)->size = (yyvsp[-1].type)->size;
                (yyval.plist) = (yyvsp[0].plist);
                
            }
#line 2023 "y.tab.c"
    break;

  case 34:
#line 236 "exptree.y"
                 {
                (yyval.plist) = create_param((yyvsp[0].node)->varname,TYPE_NULL);
                (yyval.plist)->size = 1;
                (yyval.plist)->varType = TYPE_VAR;
            }
#line 2033 "y.tab.c"
    break;

  case 35:
#line 241 "exptree.y"
                     {
                (yyval.plist) = create_param((yyvsp[0].node)->varname,TYPE_NULL);
                (yyval.plist)->size = 1;
                (yyval.plist)->varType = TYPE_PTR;
                
            }
#line 2044 "y.tab.c"
    break;

  case 36:
#line 250 "exptree.y"
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
#line 2059 "y.tab.c"
    break;

  case 37:
#line 260 "exptree.y"
               {(yyval.lsymbol) = NULL;lst_set_bindings(curr_lsymbol_table);}
#line 2065 "y.tab.c"
    break;

  case 38:
#line 263 "exptree.y"
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
#line 2083 "y.tab.c"
    break;

  case 39:
#line 276 "exptree.y"
                    {
                (yyval.lsymbol) = (yyvsp[0].lsymbol);   
            }
#line 2091 "y.tab.c"
    break;

  case 40:
#line 281 "exptree.y"
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
#line 2109 "y.tab.c"
    break;

  case 41:
#line 296 "exptree.y"
                                 {
                check_lpresent((yyvsp[-2].lsymbol),(yyvsp[0].lsymbol)->name);
                (yyval.lsymbol) = append_lsymbol_id_list((yyvsp[-2].lsymbol), (yyvsp[0].lsymbol));
            }
#line 2118 "y.tab.c"
    break;

  case 42:
#line 300 "exptree.y"
                     {
                (yyval.lsymbol) = (yyvsp[0].lsymbol);
            }
#line 2126 "y.tab.c"
    break;

  case 43:
#line 305 "exptree.y"
                 {
                (yyval.lsymbol) = create_lsymbol_id((yyvsp[0].node)->varname, curr_type->size, TYPE_VAR);
            }
#line 2134 "y.tab.c"
    break;

  case 44:
#line 308 "exptree.y"
                    {
                int size = 2;
                if(curr_type->type == TYPE_TUPLE){
                    size = 1 + curr_type->size;
                }
                (yyval.lsymbol) = create_lsymbol_id((yyvsp[0].node)->varname, size, TYPE_PTR);
                printf("ptr name: %s\n",(yyvsp[0].node)->varname);
            }
#line 2147 "y.tab.c"
    break;

  case 45:
#line 316 "exptree.y"
                            {

                tnode* temp = (yyvsp[-2].node);
                while(temp->middle){
                    temp = temp->middle;
                }
                temp->middle = (yyvsp[0].node);
                (yyval.node) = (yyvsp[-2].node);
            }
#line 2161 "y.tab.c"
    break;

  case 46:
#line 325 "exptree.y"
                { (yyval.node) = (yyvsp[0].node);}
#line 2167 "y.tab.c"
    break;

  case 47:
#line 331 "exptree.y"
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
#line 2204 "y.tab.c"
    break;

  case 48:
#line 366 "exptree.y"
                       {(yyval.node) = (yyvsp[-1].node);}
#line 2210 "y.tab.c"
    break;

  case 49:
#line 368 "exptree.y"
                     {
            struct tnode* temp = createTree(0,TYPE_NULL,NULL,CONNECTOR,NULL,(yyvsp[-1].node), NULL, (yyvsp[0].node));
            (yyval.node) = temp;
        }
#line 2219 "y.tab.c"
    break;

  case 50:
#line 372 "exptree.y"
               {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2227 "y.tab.c"
    break;

  case 51:
#line 377 "exptree.y"
                  { (yyval.type) = typetable_lookup("int"); curr_type = (yyval.type);}
#line 2233 "y.tab.c"
    break;

  case 52:
#line 378 "exptree.y"
                  { (yyval.type) = typetable_lookup("str"); curr_type = (yyval.type);}
#line 2239 "y.tab.c"
    break;

  case 53:
#line 379 "exptree.y"
                 {
                curr_type = typetable_lookup((yyvsp[0].node)->varname);
                if(curr_type == NULL){
                    printf("Error: No UserDefined struct %s exists\n", (yyvsp[0].node)->varname);
                    exit(0); 
                }
                (yyval.type) = curr_type;
            }
#line 2252 "y.tab.c"
    break;

  case 54:
#line 389 "exptree.y"
                              {
            (yyval.DimList) = append_dim((yyvsp[-3].DimList), (yyvsp[-1].node)->val);
        }
#line 2260 "y.tab.c"
    break;

  case 55:
#line 392 "exptree.y"
                        { (yyval.DimList) = create_dimlist(NULL); }
#line 2266 "y.tab.c"
    break;

  case 56:
#line 395 "exptree.y"
                                   {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);
                int varType = get_var_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 2278 "y.tab.c"
    break;

  case 57:
#line 402 "exptree.y"
                                            {
                Gsymbol* temp = find_gsymbol((yyvsp[-3].node)->varname);
                (yyvsp[-3].node)->Gentry = temp;
                check_not_out_of_bounds((yyvsp[-2].DimList),(yyvsp[-3].node)->Gentry->dimlist);
                (yyvsp[-5].node)->left = (yyvsp[-3].node);
                (yyvsp[-3].node)->dimlist = (yyvsp[-2].DimList);
                (yyval.node) = createTree(0,TYPE_NULL, "Read", READNODE,NULL,(yyvsp[-3].node), NULL, NULL);
            }
#line 2291 "y.tab.c"
    break;

  case 58:
#line 410 "exptree.y"
                                      {
                Gsymbol* entry = find_gsymbol((yyvsp[-2].node)->varname);
                tnode* temp = createTree(0, TYPE_PTR, "*", PTRNODE, entry,(yyvsp[-2].node), NULL,NULL);
                (yyval.node) = createTree(0, TYPE_NULL, "Read", READNODE,NULL,temp, NULL, NULL);
            }
#line 2301 "y.tab.c"
    break;

  case 59:
#line 415 "exptree.y"
                                     {
                int type = (yyvsp[-2].node)->type;
                TypeTable* typet = (yyvsp[-2].node)->typeEntry;
                (yyval.node) = createTree(0,(yyvsp[-2].node)->type,"Read",READNODE,NULL,(yyvsp[-2].node),NULL,NULL);
            }
#line 2311 "y.tab.c"
    break;

  case 60:
#line 420 "exptree.y"
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
#line 2331 "y.tab.c"
    break;

  case 61:
#line 437 "exptree.y"
                                  {
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 2340 "y.tab.c"
    break;

  case 62:
#line 443 "exptree.y"
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
#line 2378 "y.tab.c"
    break;

  case 63:
#line 476 "exptree.y"
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
#line 2395 "y.tab.c"
    break;

  case 64:
#line 488 "exptree.y"
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
#line 2419 "y.tab.c"
    break;

  case 65:
#line 507 "exptree.y"
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
#line 2438 "y.tab.c"
    break;

  case 66:
#line 521 "exptree.y"
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
#line 2473 "y.tab.c"
    break;

  case 67:
#line 554 "exptree.y"
                                     {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-5].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-5].node)->varname);

                TypeTable* type = get_typetable(ptr1,ptr2,(yyvsp[-5].node)->varname);

                check_data_types(type->type,type->type,TYPE_TUPLE,559);

                tnode* temp = createTree(type->size, TYPE_NULL, "Alloc", ALLOCNODE,NULL,(yyvsp[-5].node), NULL, NULL);

                temp->typeEntry = type;

                (yyval.node) = temp;
            }
#line 2492 "y.tab.c"
    break;

  case 68:
#line 568 "exptree.y"
                                       {

                if((yyvsp[-5].node)->typeEntry->type != TYPE_TUPLE){
                    printf("Error: Piecewise allocation not possible %s\n", (yyvsp[-5].node)->right->varname);
                    exit(0);
                }

                tnode* temp = createTree((yyvsp[-5].node)->typeEntry->size, TYPE_NULL, "Alloc", ALLOCNODE,NULL,(yyvsp[-5].node), NULL, NULL);

                (yyval.node) = temp;
          }
#line 2508 "y.tab.c"
    break;

  case 69:
#line 579 "exptree.y"
                                {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);

                TypeTable* type = get_typetable(ptr1,ptr2,(yyvsp[-2].node)->varname);

                check_data_types(type->type,type->type,TYPE_TUPLE,559);

                tnode* temp = createTree(type->size, TYPE_NULL, "free", FREENODE,NULL,(yyvsp[-2].node), NULL, NULL);

                temp->typeEntry = type;

                (yyval.node) = temp;
          }
#line 2527 "y.tab.c"
    break;

  case 70:
#line 593 "exptree.y"
                                   {

                if((yyvsp[-2].node)->typeEntry->type != TYPE_TUPLE){
                    printf("Error: Piecewise deallocation not possible %s\n", (yyvsp[-2].node)->right->varname);
                    exit(0);
                }

                tnode* temp = createTree((yyvsp[-2].node)->typeEntry->size, TYPE_NULL, "free", FREENODE,NULL,(yyvsp[-2].node), NULL, NULL);

                (yyval.node) = temp;
          }
#line 2543 "y.tab.c"
    break;

  case 71:
#line 604 "exptree.y"
                                 {
            tnode* temp = createTree(0, TYPE_NULL, "initalize", INITIALIZENODE,NULL,NULL, NULL, NULL);
            (yyval.node) = temp;
          }
#line 2552 "y.tab.c"
    break;

  case 72:
#line 611 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2558 "y.tab.c"
    break;

  case 73:
#line 612 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2564 "y.tab.c"
    break;

  case 74:
#line 613 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2570 "y.tab.c"
    break;

  case 75:
#line 614 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2576 "y.tab.c"
    break;

  case 76:
#line 615 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2582 "y.tab.c"
    break;

  case 77:
#line 616 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2588 "y.tab.c"
    break;

  case 78:
#line 617 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2594 "y.tab.c"
    break;

  case 79:
#line 618 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2600 "y.tab.c"
    break;

  case 80:
#line 619 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2606 "y.tab.c"
    break;

  case 81:
#line 620 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2612 "y.tab.c"
    break;

  case 82:
#line 623 "exptree.y"
                                                       {
            (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-7].node),(yyvsp[-2].node));
        }
#line 2620 "y.tab.c"
    break;

  case 83:
#line 626 "exptree.y"
                                            {
            (yyval.node) = createIfNode((yyvsp[-2].node),(yyvsp[-5].node),NULL);
        }
#line 2628 "y.tab.c"
    break;

  case 84:
#line 631 "exptree.y"
                                                    {
                (yyval.node) = createWhileNode((yyvsp[-2].node),(yyvsp[-5].node));
            }
#line 2636 "y.tab.c"
    break;

  case 85:
#line 636 "exptree.y"
                                           {
                (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
            }
#line 2644 "y.tab.c"
    break;

  case 86:
#line 641 "exptree.y"
                                                      {
                        (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
                    }
#line 2652 "y.tab.c"
    break;

  case 87:
#line 646 "exptree.y"
                           {
                (yyval.node) = createJumpNode(CONTINUENODE);
            }
#line 2660 "y.tab.c"
    break;

  case 88:
#line 649 "exptree.y"
                        {
                (yyval.node) = createJumpNode(BREAKNODE);
            }
#line 2668 "y.tab.c"
    break;

  case 89:
#line 652 "exptree.y"
                           { 
                (yyval.node) = createTree(0, (yyvsp[-1].node)->type, NULL, RETURNNODE, NULL,(yyvsp[-1].node), NULL,NULL);
                (yyval.node)->typeEntry = (yyvsp[-1].node)->typeEntry;
            }
#line 2677 "y.tab.c"
    break;

  case 90:
#line 658 "exptree.y"
                           {
                (yyval.node) = createTree(0,TYPE_NULL,"BRKP", BREAKPOINTNODE,NULL,NULL, NULL, NULL);
            }
#line 2685 "y.tab.c"
    break;

  case 91:
#line 663 "exptree.y"
               {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,567);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "+", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2696 "y.tab.c"
    break;

  case 92:
#line 669 "exptree.y"
                {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,573);
        (yyval.node) =  createTree(0, (yyvsp[-2].node)->type , "-", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2707 "y.tab.c"
    break;

  case 93:
#line 675 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,579);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "/", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2718 "y.tab.c"
    break;

  case 94:
#line 681 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,585);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "*", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2729 "y.tab.c"
    break;

  case 95:
#line 687 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,591);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "%", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2740 "y.tab.c"
    break;

  case 96:
#line 693 "exptree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2748 "y.tab.c"
    break;

  case 97:
#line 696 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,600);
        (yyval.node) = createTree(0,TYPE_BOOL,">",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2757 "y.tab.c"
    break;

  case 98:
#line 700 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,604);
        (yyval.node) = createTree(0,TYPE_BOOL,"<",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2766 "y.tab.c"
    break;

  case 99:
#line 704 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,608);
        (yyval.node) = createTree(0,TYPE_BOOL,">=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2775 "y.tab.c"
    break;

  case 100:
#line 708 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,612);
        (yyval.node) = createTree(0,TYPE_BOOL,"<=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2784 "y.tab.c"
    break;

  case 101:
#line 712 "exptree.y"
             {
        if((yyvsp[-2].node)->type == TYPE_TUPLE && (yyvsp[0].node)->nodetype == NULLNODE){

        }else{
            check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,616);
        }
        (yyval.node) = createTree(0,TYPE_BOOL,"!=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2797 "y.tab.c"
    break;

  case 102:
#line 720 "exptree.y"
             {
        if((yyvsp[-2].node)->type == TYPE_TUPLE && (yyvsp[0].node)->nodetype == NULLNODE){
                
        }else{
            check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,616);
        }
        (yyval.node) = createTree(0,TYPE_BOOL,"==",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2810 "y.tab.c"
    break;

  case 103:
#line 728 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_BOOL,624);
        (yyval.node) = createTree(0,TYPE_BOOL,"&&",OPERATOR,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2819 "y.tab.c"
    break;

  case 104:
#line 732 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_BOOL,628);
        (yyval.node) = createTree(0,TYPE_BOOL,"||",OPERATOR,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2828 "y.tab.c"
    break;

  case 105:
#line 736 "exptree.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2836 "y.tab.c"
    break;

  case 106:
#line 739 "exptree.y"
            {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2844 "y.tab.c"
    break;

  case 107:
#line 742 "exptree.y"
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
#line 2863 "y.tab.c"
    break;

  case 108:
#line 756 "exptree.y"
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
#line 2879 "y.tab.c"
    break;

  case 109:
#line 767 "exptree.y"
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
#line 2902 "y.tab.c"
    break;

  case 110:
#line 785 "exptree.y"
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
#line 2921 "y.tab.c"
    break;

  case 111:
#line 799 "exptree.y"
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
#line 2942 "y.tab.c"
    break;

  case 112:
#line 815 "exptree.y"
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
#line 2960 "y.tab.c"
    break;

  case 113:
#line 828 "exptree.y"
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
#line 2979 "y.tab.c"
    break;

  case 114:
#line 842 "exptree.y"
             {
        (yyval.node) = createTree(-10, TYPE_STRING, (yyvsp[0].string), LEAFNODE,NULL, NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("str");
        (yyval.node)->typeEntry = typet;
    }
#line 2989 "y.tab.c"
    break;

  case 115:
#line 847 "exptree.y"
          {
        (yyval.node) = createTree((yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2999 "y.tab.c"
    break;

  case 116:
#line 852 "exptree.y"
                {
        (yyval.node) = createTree(-(yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 3009 "y.tab.c"
    break;

  case 117:
#line 858 "exptree.y"
                                  {
                check_data_types((yyvsp[-1].node)->type,TYPE_INT,TYPE_INT,756);
                (yyval.DimList) = append_dim_with_id((yyvsp[-3].DimList),(yyvsp[-1].node));
            }
#line 3018 "y.tab.c"
    break;

  case 118:
#line 862 "exptree.y"
                        {
                check_data_types((yyvsp[-1].node)->type,TYPE_INT,TYPE_INT,760);
                (yyval.DimList) = append_dim_with_id(NULL,(yyvsp[-1].node));
            }
#line 3027 "y.tab.c"
    break;

  case 119:
#line 868 "exptree.y"
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
#line 3043 "y.tab.c"
    break;

  case 120:
#line 879 "exptree.y"
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
#line 3064 "y.tab.c"
    break;


#line 3068 "y.tab.c"

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
#line 899 "exptree.y"



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
