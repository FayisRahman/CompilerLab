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

    extern int yylex();
    extern FILE *yyin;
    void yyerror(char* s);
    struct tnode* head = NULL;
    FILE* fptr = NULL;
    void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType);
    

#line 94 "y.tab.c"

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

#line 245 "y.tab.c"

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   648

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

#define YYUNDEFTOK  2
#define YYMAXUTOK   299


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
       2,     2,     2,     2,     2,     2,     2,     2,    55,     2,
      47,    48,     2,     2,    46,     2,    53,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,    54,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    61,    62,    65,    73,    80,    81,    84,
     105,   108,   111,   123,   129,   137,   148,   151,   154,   155,
     158,   164,   169,   172,   174,   181,   182,   185,   190,   197,
     206,   216,   219,   228,   233,   242,   252,   255,   268,   273,
     288,   292,   297,   300,   308,   312,   318,   352,   354,   358,
     363,   364,   365,   375,   378,   381,   388,   396,   401,   416,
     434,   440,   469,   481,   500,   526,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   569,   572,   577,   582,   587,
     592,   595,   598,   604,   609,   615,   621,   627,   633,   639,
     642,   646,   650,   654,   658,   662,   666,   670,   674,   688,
     702,   713,   725,   739,   755,   768,   782,   787,   792,   798,
     802
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "WRITE", "READ", "INT", "STR", "ID",
  "NUM", "STRING", "begin", "end", "MAIN", "DECL", "ENDDECL", "TYPE",
  "ENDTYPE", "TUPLE", "PLUS", "MINUS", "DIV", "MUL", "ARROW", "IF", "THEN",
  "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL",
  "CONTINUE", "BREAK", "RETURN", "BREAKPOINT", "GT", "GE", "LT", "LE",
  "NE", "EQ", "AND", "OR", "MOD", "';'", "','", "'('", "')'", "'{'", "'}'",
  "'['", "']'", "'.'", "'='", "'&'", "$accept", "Program", "GDeclBlock",
  "GDeclList", "GDecl", "GidList", "Gid", "TDeclBlock", "TDeclList",
  "TDeclStart", "TDecl", "TIdList", "TIdDecl", "FDefBlock", "Fdef",
  "Paramlist", "ParamDecl", "Param", "LdeclBlock", "LDecList", "LDecl",
  "IdList", "IdDecl", "ArgList", "MainBlock", "body", "Slist", "Type",
  "DimList", "InputStmt", "OutputStmt", "AsgStmt", "Stmt", "Ifstmt",
  "Whilestmt", "DoWhilestmt", "RepeatUntiltstmt", "Jumpstmt", "Debugstmt",
  "E", "DimAccess", YY_NULLPTR
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
     295,   296,   297,   298,   299,    59,    44,    40,    41,   123,
     125,    91,    93,    46,    61,    38
};
# endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,    50,    41,   202,    89,   135,    51,  -122,  -122,  -122,
    -122,  -122,   168,    29,  -122,   101,  -122,  -122,  -122,    29,
    -122,   172,  -122,    66,    29,  -122,  -122,     3,   100,   108,
    -122,   169,  -122,  -122,   133,   174,   122,  -122,  -122,  -122,
     137,   184,   145,    43,  -122,    29,   149,   154,  -122,    66,
      29,   163,   170,   166,  -122,    46,  -122,    70,   212,    29,
    -122,    63,    29,   208,  -122,    29,  -122,  -122,   217,  -122,
     180,    69,   177,    84,    29,   224,  -122,  -122,  -122,  -122,
     208,   197,   198,  -122,    78,   280,   199,   224,   208,  -122,
    -122,  -122,   240,   125,  -122,   201,   205,    44,   249,   211,
     216,   280,   280,   226,   227,    61,   231,   195,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,   207,
     224,  -122,  -122,    78,    61,    81,   262,    61,   271,    61,
      80,   234,    61,    61,   295,   210,  -122,  -122,    67,  -122,
    -122,   277,   279,    61,   282,   445,  -122,  -122,  -122,  -122,
     241,  -122,   313,    59,   283,   238,    85,   239,   455,    61,
      61,    61,   326,   357,   248,   250,   287,    24,   289,   253,
    -122,  -122,   370,  -122,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,  -122,  -122,   255,
     298,   261,   302,    98,   263,    61,  -122,    61,  -122,   120,
     483,   493,   293,   291,    61,    61,  -122,  -122,   102,   559,
    -122,  -122,    31,    31,  -122,  -122,     0,     0,     0,     0,
     604,   604,   595,   568,  -122,  -122,   272,  -122,   273,   281,
     290,   521,   531,  -122,  -122,  -122,   280,   280,   401,   414,
      61,  -122,   292,   294,  -122,  -122,  -122,  -122,   162,   232,
     -19,   296,   559,  -122,  -122,   280,   297,   303,  -122,  -122,
     247,  -122,  -122,   314,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      17,     0,     0,     0,     0,     0,     0,    19,     1,    50,
      51,    52,     0,     0,     4,     0,    20,    16,    18,     0,
       6,     0,     8,     0,     0,    26,     3,     0,     0,     0,
      23,     0,     5,     7,    54,     0,     0,    11,    25,     2,
       0,     0,     0,     0,    24,    31,    12,    13,     9,     0,
      31,     0,     0,     0,    22,     0,    30,     0,     0,    31,
      10,     0,    31,    36,    21,     0,    14,    33,     0,    32,
       0,     0,     0,     0,     0,     0,    29,    34,    53,    15,
      36,     0,     0,    38,     0,     0,     0,     0,    36,    35,
      37,    42,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    67,
      68,    49,    69,    70,    71,    72,    73,    74,    46,     0,
       0,    43,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,   102,   107,
     106,     0,     0,     0,     0,     0,    83,    47,    48,    27,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
     108,   104,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    28,     0,
       0,     0,     0,     0,     0,     0,   110,     0,    61,     0,
       0,     0,     0,     0,     0,     0,    99,   100,     0,    45,
      98,    89,    84,    85,    86,    87,    90,    92,    91,    93,
      94,    95,    96,    97,    88,    60,     0,    55,     0,     0,
       0,     0,     0,   109,    62,    63,     0,     0,     0,     0,
       0,   101,     0,     0,    56,    57,    65,    64,     0,     0,
       0,     0,    44,    59,    58,     0,     0,     0,    78,    79,
       0,    76,    77,     0,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,   315,  -122,   275,  -122,  -122,  -122,
     333,  -122,   300,  -122,   316,    83,   306,  -122,   -75,  -122,
     276,  -122,   237,  -122,    77,   -83,  -101,     4,  -122,  -122,
    -122,  -122,  -105,  -122,  -122,  -122,  -122,  -122,  -122,  -121,
    -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,    21,    22,    36,    37,     3,     5,     6,
       7,    29,    30,    24,    25,    55,    56,    69,    75,    82,
      83,    93,    94,   208,    14,    86,   107,    57,    46,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   145,
     130
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     134,   135,   148,   152,   119,    87,   156,    15,   158,   237,
      40,   162,   163,   120,     1,    28,    23,    27,   174,   175,
     176,   177,   172,    31,    41,    23,   258,   169,    27,   148,
     148,   138,   139,   140,     9,    10,    11,   150,   199,   200,
     201,     8,   193,   141,   186,   142,   209,    31,     9,    10,
      11,   176,   177,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   126,     4,   138,   139,
     140,   143,   207,    34,   231,   186,   232,    67,    84,   144,
     141,   190,   142,   238,   239,    91,    84,    35,   153,   166,
      26,    68,    65,    53,    66,   127,    16,   128,   129,    92,
      19,    39,   154,   174,   175,   176,   177,   191,   143,    65,
     127,    72,   192,    28,   167,    65,   144,    79,   127,   252,
     168,   178,   179,   180,   181,   182,   183,   184,   185,   186,
      65,   159,    81,    61,   160,   248,   249,   196,   174,   175,
     176,   177,    71,   148,   148,    73,   229,    42,   240,   159,
     241,    17,     4,    43,   260,   148,   178,   179,   180,   181,
     182,   183,   184,   185,   186,    95,    96,    48,    49,    97,
     122,   123,   233,     9,    10,    11,    44,     9,    10,    11,
      45,    47,    20,    98,    50,    99,    32,   255,   256,   100,
     101,    51,   102,    52,   103,   104,   105,   106,    95,    96,
      58,    59,    97,     9,    10,    11,   147,     9,    10,    11,
      62,    64,    89,    95,    96,    12,    98,    97,    99,    63,
      70,    74,   100,   101,    77,   102,    80,   103,   104,   105,
     106,    98,    78,    99,    85,    95,    96,   100,   101,    97,
     102,   165,   103,   104,   105,   106,    88,   121,   124,   118,
      95,    96,   125,    98,    97,    99,   131,   149,   132,   100,
     101,   257,   102,   133,   103,   104,   105,   106,    98,   155,
      99,   136,   137,   263,   100,   101,   146,   102,   157,   103,
     104,   105,   106,    95,    96,   170,   171,    97,   161,   173,
     194,   188,   195,   197,   206,   204,   210,   205,    95,    96,
     225,    98,    97,    99,   159,   226,   227,   100,   101,   228,
     102,   230,   103,   104,   105,   106,    98,   236,    99,   237,
     242,   243,   164,   101,    60,   102,   244,   103,   104,   105,
     106,   174,   175,   176,   177,   245,    33,   253,    18,   254,
      38,   259,   261,    54,   174,   175,   176,   177,   262,   178,
     179,   180,   181,   182,   183,   184,   185,   186,    90,   264,
     151,   189,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    76,     0,     0,   202,   174,   175,   176,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   174,   175,
     176,   177,     0,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,     0,     0,   203,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,     0,     0,   211,   174,
     175,   176,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   174,   175,   176,   177,     0,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,     0,     0,   250,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
       0,     0,   251,   174,   175,   176,   177,     0,     0,     0,
       0,     0,     0,   174,   175,   176,   177,     0,     0,     0,
       0,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     198,   174,   175,   176,   177,     0,     0,     0,     0,     0,
       0,   174,   175,   176,   177,     0,     0,     0,     0,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   234,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   235,   174,
     175,   176,   177,     0,     0,     0,     0,     0,     0,   174,
     175,   176,   177,     0,     0,     0,     0,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   246,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   247,   174,   175,   176,
     177,     0,     0,     0,     0,     0,   174,   175,   176,   177,
       0,     0,     0,     0,     0,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   178,   179,   180,   181,   182,   183,
     184,     0,   186,   174,   175,   176,   177,     0,     0,     0,
       0,     0,   174,   175,   176,   177,     0,     0,     0,     0,
       0,   178,   179,   180,   181,   182,   183,     0,     0,   186,
     178,   179,   180,   181,     0,     0,     0,     0,   186
};

static const yytype_int16 yycheck[] =
{
     101,   102,   107,   124,    87,    80,   127,     3,   129,    28,
       7,   132,   133,    88,    15,    12,    12,    13,    18,    19,
      20,    21,   143,    19,    21,    21,    45,   138,    24,   134,
     135,     7,     8,     9,     5,     6,     7,   120,   159,   160,
     161,     0,   153,    19,    44,    21,   167,    43,     5,     6,
       7,    20,    21,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,    22,    17,     7,     8,
       9,    47,    48,     7,   195,    44,   197,     7,    74,    55,
      19,    22,    21,   204,   205,     7,    82,    21,     7,    22,
      13,    21,    46,    50,    48,    51,     7,    53,    54,    21,
      49,    24,    21,    18,    19,    20,    21,    48,    47,    46,
      51,    48,    53,    12,    47,    46,    55,    48,    51,   240,
      53,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      46,    51,    48,    50,    54,   236,   237,    52,    18,    19,
      20,    21,    59,   248,   249,    62,    48,    47,    46,    51,
      48,    16,    17,    45,   255,   260,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     3,     4,    45,    46,     7,
      45,    46,    52,     5,     6,     7,     7,     5,     6,     7,
      47,     7,    14,    21,    47,    23,    14,    25,    26,    27,
      28,     7,    30,    48,    32,    33,    34,    35,     3,     4,
      51,    47,     7,     5,     6,     7,    11,     5,     6,     7,
      47,    45,    14,     3,     4,    13,    21,     7,    23,    49,
       8,    13,    27,    28,     7,    30,    49,    32,    33,    34,
      35,    21,    52,    23,    10,     3,     4,    27,    28,     7,
      30,    31,    32,    33,    34,    35,    49,     7,    47,    50,
       3,     4,    47,    21,     7,    23,     7,    50,    47,    27,
      28,    29,    30,    47,    32,    33,    34,    35,    21,     7,
      23,    45,    45,    26,    27,    28,    45,    30,     7,    32,
      33,    34,    35,     3,     4,     8,     7,     7,    54,     7,
       7,    50,    54,    54,     7,    47,     7,    47,     3,     4,
      45,    21,     7,    23,    51,     7,    45,    27,    28,     7,
      30,    48,    32,    33,    34,    35,    21,    24,    23,    28,
      48,    48,    27,    28,    49,    30,    45,    32,    33,    34,
      35,    18,    19,    20,    21,    45,    21,    45,     5,    45,
      24,    45,    45,    43,    18,    19,    20,    21,    45,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    82,    45,
     123,    48,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    65,    -1,    -1,    48,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    48,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    36,    37,    38,    39,    40,    41,
      42,    -1,    44,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    -1,    -1,    44,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    57,    63,    17,    64,    65,    66,     0,     5,
       6,     7,    13,    58,    80,    83,     7,    16,    66,    49,
      14,    59,    60,    83,    69,    70,    80,    83,    12,    67,
      68,    83,    14,    60,     7,    21,    61,    62,    70,    80,
       7,    21,    47,    45,     7,    47,    84,     7,    45,    46,
      47,     7,    48,    50,    68,    71,    72,    83,    51,    47,
      62,    71,    47,    49,    45,    46,    48,     7,    21,    73,
       8,    71,    48,    71,    13,    74,    72,     7,    52,    48,
      49,    48,    75,    76,    83,    10,    81,    74,    49,    14,
      76,     7,    21,    77,    78,     3,     4,     7,    21,    23,
      27,    28,    30,    32,    33,    34,    35,    82,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    50,    81,
      74,     7,    45,    46,    47,    47,    22,    51,    53,    54,
      96,     7,    47,    47,    82,    82,    45,    45,     7,     8,
       9,    19,    21,    47,    55,    95,    45,    11,    88,    50,
      81,    78,    95,     7,    21,     7,    95,     7,    95,    51,
      54,    54,    95,    95,    27,    31,    22,    47,    53,    96,
       8,     7,    95,     7,    18,    19,    20,    21,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    50,    48,
      22,    48,    53,    96,     7,    54,    52,    54,    45,    95,
      95,    95,    48,    48,    47,    47,     7,    48,    79,    95,
       7,    48,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    45,     7,    45,     7,    48,
      48,    95,    95,    52,    45,    45,    24,    28,    95,    95,
      46,    48,    48,    48,    45,    45,    45,    45,    82,    82,
      48,    48,    95,    45,    45,    25,    26,    29,    45,    45,
      82,    45,    45,    26,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      71,    71,    72,    73,    73,    74,    74,    75,    75,    76,
      77,    77,    78,    78,    79,    79,    80,    81,    82,    82,
      83,    83,    83,    84,    84,    85,    85,    85,    85,    85,
      86,    87,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    90,    91,    92,
      93,    93,    93,    94,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     2,     1,     3,
       3,     1,     2,     2,     4,     5,     3,     0,     2,     1,
       2,     6,     3,     1,     2,     2,     1,     9,    10,     3,
       1,     0,     2,     1,     2,     3,     0,     2,     1,     3,
       3,     1,     1,     2,     3,     1,     8,     3,     2,     1,
       1,     1,     1,     4,     0,     5,     6,     6,     7,     7,
       5,     4,     5,     5,     6,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,    10,     8,     8,     7,     7,
       2,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     1,     2,     2,     2,     1,     1,     2,     4,
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
#line 60 "exptree.y"
                                                    {}
#line 1675 "y.tab.c"
    break;

  case 3:
#line 61 "exptree.y"
                                          {}
#line 1681 "y.tab.c"
    break;

  case 4:
#line 62 "exptree.y"
                               {}
#line 1687 "y.tab.c"
    break;

  case 5:
#line 65 "exptree.y"
                                     {
                stack_address = curr_stack_address;
                setup_pointers_codegen(fptr,top,NULL);
                is_global_vars_declared = 1;
                print_gsymbol_table();
                printf("------Global Variables Declared-----\n");
                driver_codegen(fptr);
            }
#line 1700 "y.tab.c"
    break;

  case 6:
#line 73 "exptree.y"
                           {
                stack_address = curr_stack_address;
                is_global_vars_declared = 1;
                driver_codegen(fptr);
            }
#line 1710 "y.tab.c"
    break;

  case 7:
#line 80 "exptree.y"
                              {}
#line 1716 "y.tab.c"
    break;

  case 8:
#line 81 "exptree.y"
                   {}
#line 1722 "y.tab.c"
    break;

  case 9:
#line 84 "exptree.y"
                           {
            Gsymbol* temp = (yyvsp[-1].gsymbol);
            Gsymbol* temp1 = (yyvsp[-1].gsymbol);
            while(temp){
                temp1 = temp->next;
                temp->next = NULL;
                if((yyvsp[-2].type)->type == TYPE_TUPLE){
                    temp->size = (yyvsp[-2].type)->size;
                }
                if(temp->varType == TYPE_FUNCT_PTR)temp->size = 1;
                if((yyvsp[-2].type)->type == TYPE_TUPLE && temp->varType == TYPE_PTR){
                    temp->size++;
                }
                add_gsymbol(temp,(yyvsp[-2].type)->type);
                temp->typeEntry = (yyvsp[-2].type);
                temp->type = (yyvsp[-2].type)->type;
                temp = temp1;
            }
        }
#line 1746 "y.tab.c"
    break;

  case 10:
#line 105 "exptree.y"
                         {
            (yyval.gsymbol) = append_gsymbol_id_list((yyvsp[-2].gsymbol),(yyvsp[0].gsymbol));    
        }
#line 1754 "y.tab.c"
    break;

  case 11:
#line 108 "exptree.y"
              { (yyval.gsymbol) = (yyvsp[0].gsymbol);}
#line 1760 "y.tab.c"
    break;

  case 12:
#line 111 "exptree.y"
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
#line 1777 "y.tab.c"
    break;

  case 13:
#line 123 "exptree.y"
                 {
            Gsymbol* temp = create_gsymbol_id((yyvsp[0].node)->varname, 2);
            (yyvsp[0].node)->Gentry = temp;
            temp->varType = TYPE_PTR;
            (yyval.gsymbol) = temp;
        }
#line 1788 "y.tab.c"
    break;

  case 14:
#line 129 "exptree.y"
                               {
            int size = get_paramlist_length((yyvsp[-1].plist));
            Gsymbol* temp = create_gsymbol_id((yyvsp[-3].node)->varname, 1);
            temp->plist = paramlist_deepcopy((yyvsp[-1].plist));
            temp->varType = TYPE_FUNCT;
            temp->flabel = flabel_count++;
            (yyval.gsymbol) = temp;
        }
#line 1801 "y.tab.c"
    break;

  case 15:
#line 137 "exptree.y"
                                   {
            int size = get_paramlist_length((yyvsp[-1].plist));
            Gsymbol* temp = create_gsymbol_id((yyvsp[-3].node)->varname, 1);
            temp->plist = paramlist_deepcopy((yyvsp[-1].plist));;
            temp->varType = TYPE_FUNCT_PTR;
            temp->flabel = flabel_count++;
            (yyval.gsymbol) = temp;
        }
#line 1814 "y.tab.c"
    break;

  case 16:
#line 148 "exptree.y"
                                      {
                typetable_print(type_table);
            }
#line 1822 "y.tab.c"
    break;

  case 17:
#line 151 "exptree.y"
                {}
#line 1828 "y.tab.c"
    break;

  case 18:
#line 154 "exptree.y"
                              {}
#line 1834 "y.tab.c"
    break;

  case 19:
#line 155 "exptree.y"
                    {}
#line 1840 "y.tab.c"
    break;

  case 20:
#line 158 "exptree.y"
                       {
                typetable_create((yyvsp[0].node)->varname,TYPE_TUPLE,NULL);
                (yyval.string) = (yyvsp[0].node)->varname;
            }
#line 1849 "y.tab.c"
    break;

  case 21:
#line 164 "exptree.y"
                                                 {
                typetable_append_plist((char*) (yyvsp[-5].string), (yyvsp[-3].plist));
                
            }
#line 1858 "y.tab.c"
    break;

  case 22:
#line 169 "exptree.y"
                                  {
                (yyval.plist) = append_param_to_list((yyvsp[-2].plist),(yyvsp[0].plist));
            }
#line 1866 "y.tab.c"
    break;

  case 23:
#line 172 "exptree.y"
                      { (yyval.plist) = (yyvsp[0].plist); }
#line 1872 "y.tab.c"
    break;

  case 24:
#line 174 "exptree.y"
                      {
                (yyval.plist) = create_param((yyvsp[0].node)->varname, (yyvsp[-1].type)->type);
                (yyval.plist)->typeEntry = (yyvsp[-1].type);
            }
#line 1881 "y.tab.c"
    break;

  case 25:
#line 181 "exptree.y"
                             {}
#line 1887 "y.tab.c"
    break;

  case 26:
#line 182 "exptree.y"
                   {}
#line 1893 "y.tab.c"
    break;

  case 27:
#line 185 "exptree.y"
                                                                  {    
                
                function_block((yyvsp[-8].type)->type,(yyvsp[-7].node),paramlist_deepcopy((yyvsp[-5].plist)),(yyvsp[-1].node),TYPE_FUNCT);

            }
#line 1903 "y.tab.c"
    break;

  case 28:
#line 190 "exptree.y"
                                                                      {
                
                function_block((yyvsp[-9].type)->type, (yyvsp[-7].node),paramlist_deepcopy((yyvsp[-5].plist)),(yyvsp[-1].node), TYPE_FUNCT_PTR);

            }
#line 1913 "y.tab.c"
    break;

  case 29:
#line 197 "exptree.y"
                                      {
                (yyval.plist) = append_param_to_list((yyvsp[-2].plist),(yyvsp[0].plist));
                if(is_global_vars_declared == 1){
                    Lsymbol* t1 = create_lsymbol_id((yyvsp[0].plist)->name, (yyvsp[0].plist)->varType == TYPE_PTR ? 1 : (yyvsp[0].plist)->size, (yyvsp[0].plist)->varType);
                    t1->type = (yyvsp[0].plist)->type;
                    t1->typeEntry = (yyvsp[0].plist)->typeEntry;
                    curr_lsymbol_table = append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
            }
#line 1927 "y.tab.c"
    break;

  case 30:
#line 206 "exptree.y"
                        {
                (yyval.plist) = (yyvsp[0].plist);
                if(is_global_vars_declared == 1){
                    Lsymbol* t1 = create_lsymbol_id((yyvsp[0].plist)->name, (yyvsp[0].plist)->size, (yyvsp[0].plist)->varType);
                    t1->type = (yyvsp[0].plist)->type;
                    t1->typeEntry = (yyvsp[0].plist)->typeEntry;
                    curr_lsymbol_table =  append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
                
            }
#line 1942 "y.tab.c"
    break;

  case 31:
#line 216 "exptree.y"
                                            {(yyval.plist) = NULL;curr_lsymbol_table= NULL;}
#line 1948 "y.tab.c"
    break;

  case 32:
#line 219 "exptree.y"
                         {
                (yyvsp[0].plist)->type = (yyvsp[-1].type)->type;
                (yyvsp[0].plist)->typeEntry = (yyvsp[-1].type);
                (yyvsp[0].plist)->size = (yyvsp[-1].type)->size;
                (yyval.plist) = (yyvsp[0].plist);
                
            }
#line 1960 "y.tab.c"
    break;

  case 33:
#line 228 "exptree.y"
                 {
                (yyval.plist) = create_param((yyvsp[0].node)->varname,TYPE_NULL);
                (yyval.plist)->size = 1;
                (yyval.plist)->varType = TYPE_VAR;
            }
#line 1970 "y.tab.c"
    break;

  case 34:
#line 233 "exptree.y"
                     {
                (yyval.plist) = create_param((yyvsp[0].node)->varname,TYPE_NULL);
                (yyval.plist)->size = 1;
                (yyval.plist)->varType = TYPE_PTR;
                
            }
#line 1981 "y.tab.c"
    break;

  case 35:
#line 242 "exptree.y"
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
#line 1996 "y.tab.c"
    break;

  case 36:
#line 252 "exptree.y"
               {(yyval.lsymbol) = NULL;lst_set_bindings(curr_lsymbol_table);}
#line 2002 "y.tab.c"
    break;

  case 37:
#line 255 "exptree.y"
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
#line 2020 "y.tab.c"
    break;

  case 38:
#line 268 "exptree.y"
                    {
                (yyval.lsymbol) = (yyvsp[0].lsymbol);   
            }
#line 2028 "y.tab.c"
    break;

  case 39:
#line 273 "exptree.y"
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
#line 2046 "y.tab.c"
    break;

  case 40:
#line 288 "exptree.y"
                                 {
                check_lpresent((yyvsp[-2].lsymbol),(yyvsp[0].lsymbol)->name);
                (yyval.lsymbol) = append_lsymbol_id_list((yyvsp[-2].lsymbol), (yyvsp[0].lsymbol));
            }
#line 2055 "y.tab.c"
    break;

  case 41:
#line 292 "exptree.y"
                     {
                (yyval.lsymbol) = (yyvsp[0].lsymbol);
            }
#line 2063 "y.tab.c"
    break;

  case 42:
#line 297 "exptree.y"
                 {
                (yyval.lsymbol) = create_lsymbol_id((yyvsp[0].node)->varname, curr_type->size, TYPE_VAR);
            }
#line 2071 "y.tab.c"
    break;

  case 43:
#line 300 "exptree.y"
                    {
                int size = 2;
                if(curr_type->type == TYPE_TUPLE){
                    size = 1 + curr_type->size;
                }
                (yyval.lsymbol) = create_lsymbol_id((yyvsp[0].node)->varname, size, TYPE_PTR);
                printf("ptr name: %s\n",(yyvsp[0].node)->varname);
            }
#line 2084 "y.tab.c"
    break;

  case 44:
#line 308 "exptree.y"
                            {
                (yyvsp[-2].node)->middle = (yyvsp[0].node);
                (yyval.node) = (yyvsp[-2].node);
            }
#line 2093 "y.tab.c"
    break;

  case 45:
#line 312 "exptree.y"
                { (yyval.node) = (yyvsp[0].node);}
#line 2099 "y.tab.c"
    break;

  case 46:
#line 318 "exptree.y"
                                                      {

        //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome
        print_lsymbol_table();

        curr_function_type = (yyvsp[-7].type);

        // tree_visual_printTree($7);

        fprintf(fptr, "MAIN:");

        int p = getReg();

        fprintf(fptr, "MOV R%d, BP\n", p);
        fprintf(fptr, "PUSH R%d\n", p);
        fprintf(fptr, "MOV BP, SP\n");

        int curr_offset = get_curr_offset(curr_lsymbol_table);

        if(curr_offset!=0)fprintf(fptr, "ADD SP, %d\n", curr_offset);

        freeReg();

        setup_pointers_codegen(fptr,NULL,curr_lsymbol_table);

        codeGen((yyvsp[-1].node),0,0,fptr);

        // lst_destroy($6);

        curr_lsymbol_table = NULL;
}
#line 2135 "y.tab.c"
    break;

  case 47:
#line 352 "exptree.y"
                       {(yyval.node) = (yyvsp[-1].node);}
#line 2141 "y.tab.c"
    break;

  case 48:
#line 354 "exptree.y"
                     {
            struct tnode* temp = createTree(0,TYPE_NULL,NULL,CONNECTOR,NULL,(yyvsp[-1].node), NULL, (yyvsp[0].node));
            (yyval.node) = temp;
        }
#line 2150 "y.tab.c"
    break;

  case 49:
#line 358 "exptree.y"
               {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2158 "y.tab.c"
    break;

  case 50:
#line 363 "exptree.y"
                  { (yyval.type) = typetable_lookup("int"); curr_type = (yyval.type);}
#line 2164 "y.tab.c"
    break;

  case 51:
#line 364 "exptree.y"
                  { (yyval.type) = typetable_lookup("str"); curr_type = (yyval.type);}
#line 2170 "y.tab.c"
    break;

  case 52:
#line 365 "exptree.y"
                 {
                curr_type = typetable_lookup((yyvsp[0].node)->varname);
                if(curr_type == NULL){
                    printf("Error: No UserDefined struct %s exists\n", (yyvsp[0].node)->varname);
                    exit(0); 
                }
                (yyval.type) = curr_type;
            }
#line 2183 "y.tab.c"
    break;

  case 53:
#line 375 "exptree.y"
                              {
            (yyval.DimList) = append_dim((yyvsp[-3].DimList), (yyvsp[-1].node)->val);
        }
#line 2191 "y.tab.c"
    break;

  case 54:
#line 378 "exptree.y"
                        { (yyval.DimList) = create_dimlist(NULL); }
#line 2197 "y.tab.c"
    break;

  case 55:
#line 381 "exptree.y"
                                   {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);
                int varType = get_var_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 2209 "y.tab.c"
    break;

  case 56:
#line 388 "exptree.y"
                                            {
                Gsymbol* temp = find_gsymbol((yyvsp[-3].node)->varname);
                (yyvsp[-3].node)->Gentry = temp;
                check_not_out_of_bounds((yyvsp[-2].DimList),(yyvsp[-3].node)->Gentry->dimlist);
                (yyvsp[-5].node)->left = (yyvsp[-3].node);
                (yyvsp[-3].node)->dimlist = (yyvsp[-2].DimList);
                (yyval.node) = createTree(0,TYPE_NULL, "Read", READNODE,NULL,(yyvsp[-3].node), NULL, NULL);
            }
#line 2222 "y.tab.c"
    break;

  case 57:
#line 396 "exptree.y"
                                      {
                Gsymbol* entry = find_gsymbol((yyvsp[-2].node)->varname);
                tnode* temp = createTree(0, TYPE_PTR, "*", PTRNODE, entry,(yyvsp[-2].node), NULL,NULL);
                (yyval.node) = createTree(0, TYPE_NULL, "Read", READNODE,NULL,temp, NULL, NULL);
            }
#line 2232 "y.tab.c"
    break;

  case 58:
#line 401 "exptree.y"
                                         {
                Gsymbol* ptr1 = find_gsymbol((yyvsp[-4].node)->varname);
                Lsymbol* ptr2 = find_lsymbol((yyvsp[-4].node)->varname);
                int type = get_type(ptr1,ptr2,(yyvsp[-4].node)->varname);
                check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,397);
                int varType = get_var_type(ptr1,ptr2,(yyvsp[-4].node)->varname);
                if(varType == TYPE_PTR){
                    printf("Error: %s is of pointer type, use -> operator to access its attributes\n", (yyvsp[-4].node)->varname);
                    exit(0);
                }
                TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[-4].node)->varname);
                tnode* dot = createTree(0,typetable_lookup_id_type(typet,(yyvsp[-2].node)->varname),".",DOTNODE,NULL,(yyvsp[-4].node),NULL,(yyvsp[-2].node));
                (yyval.node) = createTree(0,typetable_lookup_id_type(typet,(yyvsp[-2].node)->varname),"Read",READNODE,NULL,dot,NULL,NULL);
                dot->typeEntry = typet;
            }
#line 2252 "y.tab.c"
    break;

  case 59:
#line 416 "exptree.y"
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
#line 2272 "y.tab.c"
    break;

  case 60:
#line 434 "exptree.y"
                                  {
                (yyvsp[-4].node)->left = (yyvsp[-2].node);
                (yyval.node) = (yyvsp[-4].node);
            }
#line 2281 "y.tab.c"
    break;

  case 61:
#line 440 "exptree.y"
                       {
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
                printf("typee-->%s\n",ptr2->name);
                check_data_types(ptr2->type,(yyvsp[-1].node)->type,ptr2->type,409);
                type = ptr2->typeEntry;
            }else if(ptr1){
                check_data_types(ptr1->type,(yyvsp[-1].node)->type,ptr1->type,412);
                type = ptr1->typeEntry;
            }else{
                printf("Error: Variable %s Not Declared\n", (yyvsp[-3].node)->varname);
                exit(0);
            }
            if(type != (yyvsp[-1].node)->typeEntry){
                char* returnType = (yyvsp[-1].node)->typeEntry->name;
                char* returningType = type->name;
                printf("Error: Assignment with different data types, LHS => %s and RHS => %s\n", returningType, returnType);
		        exit(1);
            }
            (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,ptr1,(yyvsp[-3].node), NULL, (yyvsp[-1].node));
        }
#line 2315 "y.tab.c"
    break;

  case 62:
#line 469 "exptree.y"
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
#line 2332 "y.tab.c"
    break;

  case 63:
#line 481 "exptree.y"
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
                printf("Error: Variable %s Not Declared\n", (yyvsp[-3].node)->varname);
                exit(0);
            }
            tnode* t = createTree(0,TYPE_PTR, "*", PTRNODE, NULL,(yyvsp[-3].node), NULL, NULL);
            (yyval.node) = createTree(0,TYPE_PTR, "=", ASSIGNMENT,NULL,t, NULL, (yyvsp[-1].node));
        }
#line 2356 "y.tab.c"
    break;

  case 64:
#line 500 "exptree.y"
                              {
            Gsymbol* ptr1 = find_gsymbol((yyvsp[-5].node)->varname);
            Lsymbol* ptr2 = find_lsymbol((yyvsp[-5].node)->varname);
            TypeTable* type = NULL;
            if(ptr2){
                type = ptr2->typeEntry;
            }else if(ptr1){
                type = ptr1->typeEntry;
            }else{
                printf("Error: Variable %s Not Declared\n", (yyvsp[-5].node)->varname);
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
            tnode* dot = createTree(0,typetable_lookup_id_type(type,(yyvsp[-3].node)->varname),".",DOTNODE,NULL,(yyvsp[-5].node),NULL,(yyvsp[-3].node));
            (yyval.node) = createTree(0,TYPE_VAR, "=", ASSIGNMENT,ptr1,dot, NULL, (yyvsp[-1].node));
            (yyval.node)->typeEntry = type;
        }
#line 2387 "y.tab.c"
    break;

  case 65:
#line 526 "exptree.y"
                                {
            Gsymbol* ptr1 = find_gsymbol((yyvsp[-5].node)->varname);
            Lsymbol* ptr2 = find_lsymbol((yyvsp[-5].node)->varname);
            TypeTable* type = NULL;
            if(ptr2){
                type = ptr2->typeEntry;
            }else if(ptr1){
                type = ptr1->typeEntry;
            }else{
                printf("Error: Variable %s Not Declared\n", (yyvsp[-5].node)->varname);
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
#line 2422 "y.tab.c"
    break;

  case 66:
#line 558 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2428 "y.tab.c"
    break;

  case 67:
#line 559 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2434 "y.tab.c"
    break;

  case 68:
#line 560 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2440 "y.tab.c"
    break;

  case 69:
#line 561 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2446 "y.tab.c"
    break;

  case 70:
#line 562 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2452 "y.tab.c"
    break;

  case 71:
#line 563 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2458 "y.tab.c"
    break;

  case 72:
#line 564 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2464 "y.tab.c"
    break;

  case 73:
#line 565 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2470 "y.tab.c"
    break;

  case 74:
#line 566 "exptree.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2476 "y.tab.c"
    break;

  case 75:
#line 569 "exptree.y"
                                                       {
            (yyval.node) = createIfNode((yyvsp[-4].node),(yyvsp[-7].node),(yyvsp[-2].node));
        }
#line 2484 "y.tab.c"
    break;

  case 76:
#line 572 "exptree.y"
                                            {
            (yyval.node) = createIfNode((yyvsp[-2].node),(yyvsp[-5].node),NULL);
        }
#line 2492 "y.tab.c"
    break;

  case 77:
#line 577 "exptree.y"
                                                    {
                (yyval.node) = createWhileNode((yyvsp[-2].node),(yyvsp[-5].node));
            }
#line 2500 "y.tab.c"
    break;

  case 78:
#line 582 "exptree.y"
                                           {
                (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
            }
#line 2508 "y.tab.c"
    break;

  case 79:
#line 587 "exptree.y"
                                                      {
                        (yyval.node) = createDoWhileNode((yyvsp[-5].node),(yyvsp[-2].node));
                    }
#line 2516 "y.tab.c"
    break;

  case 80:
#line 592 "exptree.y"
                           {
                (yyval.node) = createJumpNode(CONTINUENODE);
            }
#line 2524 "y.tab.c"
    break;

  case 81:
#line 595 "exptree.y"
                        {
                (yyval.node) = createJumpNode(BREAKNODE);
            }
#line 2532 "y.tab.c"
    break;

  case 82:
#line 598 "exptree.y"
                           { 
                (yyval.node) = createTree(0, (yyvsp[-1].node)->type, NULL, RETURNNODE, NULL,(yyvsp[-1].node), NULL,NULL);
                (yyval.node)->typeEntry = (yyvsp[-1].node)->typeEntry;
            }
#line 2541 "y.tab.c"
    break;

  case 83:
#line 604 "exptree.y"
                           {
                (yyval.node) = createTree(0,TYPE_NULL,"BRKP", BREAKPOINTNODE,NULL,NULL, NULL, NULL);
            }
#line 2549 "y.tab.c"
    break;

  case 84:
#line 609 "exptree.y"
               {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,567);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "+", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2560 "y.tab.c"
    break;

  case 85:
#line 615 "exptree.y"
                {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,573);
        (yyval.node) =  createTree(0, (yyvsp[-2].node)->type , "-", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2571 "y.tab.c"
    break;

  case 86:
#line 621 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,579);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "/", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2582 "y.tab.c"
    break;

  case 87:
#line 627 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,585);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "*", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2593 "y.tab.c"
    break;

  case 88:
#line 633 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,591);
        (yyval.node) = createTree(0, (yyvsp[-2].node)->type, "%", OPERATOR,NULL,(yyvsp[-2].node), NULL, (yyvsp[0].node));
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2604 "y.tab.c"
    break;

  case 89:
#line 639 "exptree.y"
                {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2612 "y.tab.c"
    break;

  case 90:
#line 642 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,600);
        (yyval.node) = createTree(0,TYPE_BOOL,">",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2621 "y.tab.c"
    break;

  case 91:
#line 646 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,604);
        (yyval.node) = createTree(0,TYPE_BOOL,"<",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2630 "y.tab.c"
    break;

  case 92:
#line 650 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,608);
        (yyval.node) = createTree(0,TYPE_BOOL,">=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2639 "y.tab.c"
    break;

  case 93:
#line 654 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,612);
        (yyval.node) = createTree(0,TYPE_BOOL,"<=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2648 "y.tab.c"
    break;

  case 94:
#line 658 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,616);
        (yyval.node) = createTree(0,TYPE_BOOL,"!=",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2657 "y.tab.c"
    break;

  case 95:
#line 662 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_INT,620);
        (yyval.node) = createTree(0,TYPE_BOOL,"==",EXPRESSION,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2666 "y.tab.c"
    break;

  case 96:
#line 666 "exptree.y"
              {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_BOOL,624);
        (yyval.node) = createTree(0,TYPE_BOOL,"&&",OPERATOR,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2675 "y.tab.c"
    break;

  case 97:
#line 670 "exptree.y"
             {
        check_data_types((yyvsp[-2].node)->type,(yyvsp[0].node)->type,TYPE_BOOL,628);
        (yyval.node) = createTree(0,TYPE_BOOL,"||",OPERATOR,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
    }
#line 2684 "y.tab.c"
    break;

  case 98:
#line 674 "exptree.y"
                {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[-2].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[-2].node)->varname);
        int type = get_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
        check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,635);
        int varType = get_var_type(ptr1,ptr2,(yyvsp[-2].node)->varname);
        if(varType == TYPE_PTR){
            printf("Error: %s is of pointer type, use -> operator to access its attributes\n", (yyvsp[-2].node)->varname);
            exit(0);
        }
        TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[-2].node)->varname);
        (yyval.node) = createTree(0,typetable_lookup_id_type(typet,(yyvsp[0].node)->varname),".",DOTNODE,NULL,(yyvsp[-2].node),NULL,(yyvsp[0].node));
        (yyval.node)->typeEntry = typet;
    }
#line 2703 "y.tab.c"
    break;

  case 99:
#line 688 "exptree.y"
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
#line 2722 "y.tab.c"
    break;

  case 100:
#line 702 "exptree.y"
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
#line 2738 "y.tab.c"
    break;

  case 101:
#line 713 "exptree.y"
                         {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[-3].node)->varname);
        print_gsymbol_list(ptr1);
        if(!ptr1 || (ptr1->varType != TYPE_FUNCT && ptr1->varType != TYPE_FUNCT_PTR)){
            printf("Error: No function with name %s declared\n",(yyvsp[-3].node)->varname);
            exit(0);
        }
        paramlist_is_input_args_correct(ptr1->plist, (yyvsp[-1].node));
        TypeTable* typet = get_typetable(ptr1,NULL,(yyvsp[-3].node)->varname);
        (yyval.node) = createTree(0,ptr1->type,"funtion()",FUNCTIONNODE,NULL,(yyvsp[-3].node),NULL,(yyvsp[-1].node));
        (yyval.node)->typeEntry = typet;
    }
#line 2755 "y.tab.c"
    break;

  case 102:
#line 725 "exptree.y"
         {
        Gsymbol* ptr1 = find_gsymbol((yyvsp[0].node)->varname);
        Lsymbol* ptr2 = find_lsymbol((yyvsp[0].node)->varname);
        
        int varType = get_var_type(ptr1,ptr2,(yyvsp[0].node)->varname);
        printf("%s is of %s\n",(yyvsp[0].node)->varname, type_to_string(varType));
        if(varType != TYPE_VAR && varType != TYPE_PTR){
            printf("Error: %s is not of variable type\n",(yyvsp[0].node)->varname);
            exit(1);
        }
        TypeTable* typet = get_typetable(ptr1,ptr2,(yyvsp[0].node)->varname);
        (yyval.node) = createTree(0, get_type(ptr1,ptr2,(yyvsp[0].node)->varname), (yyvsp[0].node)->varname, LEAFNODE, ptr1,NULL, NULL,NULL);
        (yyval.node)->typeEntry = typet;
    }
#line 2774 "y.tab.c"
    break;

  case 103:
#line 739 "exptree.y"
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
#line 2795 "y.tab.c"
    break;

  case 104:
#line 755 "exptree.y"
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
#line 2813 "y.tab.c"
    break;

  case 105:
#line 768 "exptree.y"
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
#line 2832 "y.tab.c"
    break;

  case 106:
#line 782 "exptree.y"
             {
        (yyval.node) = createTree(-10, TYPE_STRING, (yyvsp[0].string), LEAFNODE,NULL, NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("str");
        (yyval.node)->typeEntry = typet;
    }
#line 2842 "y.tab.c"
    break;

  case 107:
#line 787 "exptree.y"
          {
        (yyval.node) = createTree((yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2852 "y.tab.c"
    break;

  case 108:
#line 792 "exptree.y"
                {
        (yyval.node) = createTree(-(yyvsp[0].node)->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("int");
        (yyval.node)->typeEntry = typet;
    }
#line 2862 "y.tab.c"
    break;

  case 109:
#line 798 "exptree.y"
                                  {
                check_data_types((yyvsp[-1].node)->type,TYPE_INT,TYPE_INT,756);
                (yyval.DimList) = append_dim_with_id((yyvsp[-3].DimList),(yyvsp[-1].node));
            }
#line 2871 "y.tab.c"
    break;

  case 110:
#line 802 "exptree.y"
                        {
                check_data_types((yyvsp[-1].node)->type,TYPE_INT,TYPE_INT,760);
                (yyval.DimList) = append_dim_with_id(NULL,(yyvsp[-1].node));
            }
#line 2880 "y.tab.c"
    break;


#line 2884 "y.tab.c"

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
#line 808 "exptree.y"



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
    
    int param_list_size = paramlist_get_size($4);

    //setting up the argument values into the respective addresses in the from the local symbol table
    int count = param_list_size;
    int returnSize = curr_function_type->size;
    if(functionType == TYPE_FUNCT_PTR){
        returnSize = 1;
    }
    while(count--){
        fprintf(fptr, "MOV R%d, SP\n", p);
        fprintf(fptr, "SUB R%d, %d\n", p, param_list_size + 2 + returnSize - 1); //here the 3 is the RETURN VALUE, RETURN ADDRESS, OLD BP and the -1 for preventing the overreduction as subtracting curr_offset u reach the OLD BP 
                                                                    // and from there to reach the return value part u just need to subtract 2 and to reach the 1st arg u just need to subtract the whole paramlist
        fprintf(fptr, "MOV R%d, [R%d]\n", p, p);
        fprintf(fptr, "PUSH R%d\n", p);
    }

    // This is to set up space for the locally declared variables in the function
    int curr_offset = get_curr_offset(curr_lsymbol_table) - param_list_size;

    fprintf(fptr, "MOV R%d, \"SPACE\"\n", p);
    for(int i=0;i<curr_offset;i++){
        fprintf(fptr,"PUSH R%d\n",p);
    }

    freeReg();

    /* tree_visual_printTree($8); */

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





int main() {
    
    yyin = fopen("a.txt", "r");
    fptr = fopen("a.xsm", "w");
    typetable_create("int", TYPE_INT,  NULL);
    typetable_create("str", TYPE_STRING, NULL);
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
