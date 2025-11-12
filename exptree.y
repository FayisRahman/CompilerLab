%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdarg.h>
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
    #include "class_table.h"
    #include "./TreeViz/tree_viz.h"

    extern int yylex();
    extern FILE *yyin;
    extern int yylineno;
    extern char *yytext;
    void yyerror(const char* s,...);
    struct tnode* head = NULL;
    FILE* fptr = NULL;
    void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType);
    Classtable* Cptr = NULL;
    Fieldlist* curr_type1 = NULL;
    int is_declaration_done = 0;
    
%}

%union{
    struct tnode* node;
    char* string;
    int integer;
    struct Gsymbol* gsymbol;
    struct Lsymbol* lsymbol;
    struct DimNode* DimList;
    struct ParamList* plist;
    struct Fieldlist* type;
}
%token<node> WRITE READ INT STR ID NUM NILL SELF
%token<string>  STRING
%token begin end MAIN DECL ENDDECL TYPE ENDTYPE TUPLE STRUCT CLASS ENDCLASS EXTENDS  NEW DELETE
%token PLUS MINUS DIV MUL ARROW
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL CONTINUE BREAK RETURN BREAKPOINT FREE ALLOC INITIALIZE 
%token GT GE LT LE NE EQ AND OR

%type<string> TDeclStart
%type<type> Type
%type<node> E  ArgList Program Slist Stmt InputStmt OutputStmt AsgStmt Ifstmt body Field FieldFunction
%type<node>  Whilestmt DoWhilestmt RepeatUntiltstmt Jumpstmt Debugstmt Allocstmnt
%type<node>  FDefBlock MainBlock
%type<gsymbol> Gid GidList
%type<DimList> DimList DimAccess 
%type<plist> Paramlist Param ParamDecl TIdDecl TIdList ParamdeclBlock
%type<lsymbol> IdList LDecList LDecl LdeclBlock IdDecl 

%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD

%locations 
%%

Program : TDeclBlock ClassDefBlock GDeclBlock FDefBlock MainBlock {}
        | TDeclBlock ClassDefBlock GDeclBlock MainBlock {}
        | TDeclBlock MainBlock {}
        ;

GDeclBlock  : DECL GDeclList ENDDECL {
                stack_address = curr_stack_address;
                setup_pointers_codegen(fptr,top,NULL);
                is_global_vars_declared = 1;
                is_declaration_done = 1;
                print_gsymbol_table();
                printf("------Global Variables Declared-----\n");
                // driver_codegen(fptr);
            }
            | DECL ENDDECL {
                stack_address = curr_stack_address;
                is_global_vars_declared = 1;
                is_declaration_done = 1;
                
            }
            ;

GDeclList   : GDeclList GDecl {}
            | GDecl{}
            ;

GDecl   : Type GidList ';' {
            Gsymbol* temp = $2;
            Gsymbol* temp1 = $2;
            while(temp){
                temp1 = temp->next;
                temp->next = NULL;
                temp->typeEntry = $1->Type;
                temp->centry = $1->Ctype;
                int type = $1->Type ? $1->Type->type : TYPE_CLASS;
                if(type == TYPE_TUPLE && temp->varType != TYPE_ARR){
                    temp->size = $1->Type->size;
                }else if(type == TYPE_CLASS){
                    temp->size = $1->Ctype->Fieldcount + $1->Ctype->Methodcount;
                }
                if(temp->varType == TYPE_FUNCT_PTR)temp->size = 1;
                if(type == TYPE_TUPLE && temp->varType == TYPE_PTR){
                    temp->size++;
                }
                
                add_gsymbol(temp,type);
                
                temp->type = type;
                temp = temp1;
            }
        }
        ;

GidList : GidList ',' Gid{
            $$ = append_gsymbol_id_list($1,$3);    
        } 
        | Gid { $$ = $1;}
        ;

Gid     : ID DimList {
            Gsymbol* temp = create_symbol_id_with_dims($1->varname, $2);
            $1->Gentry = temp;
            if($2){
                $1->type = TYPE_ARR;
                $1->Gentry->varType = TYPE_ARR;
            }else{
                $1->Gentry->varType = TYPE_VAR;
            }

            $$ = temp;
        }
        | MUL ID {
            Gsymbol* temp = create_gsymbol_id($2->varname, 2);
            $2->Gentry = temp;
            temp->varType = TYPE_PTR;
            $$ = temp;
        } //here i used MUL because lex returnes MUL when the it captures '*' 
        | ID '(' ParamdeclBlock ')' {
            // int size = get_paramlist_length($3);
            Gsymbol* temp = create_gsymbol_id($1->varname, 1);
            temp->plist = paramlist_deepcopy($3);
            temp->varType = TYPE_FUNCT;
            temp->flabel = flabel_count++;
            $$ = temp;
        }
        | MUL ID '(' ParamdeclBlock ')' {
            // int size = get_paramlist_length($4);
            Gsymbol* temp = create_gsymbol_id($2->varname, 1);
            temp->plist = paramlist_deepcopy($4);;
            temp->varType = TYPE_FUNCT_PTR;
            temp->flabel = flabel_count++;
            $$ = temp;
        }
        ;


TDeclBlock   : TYPE TDeclList ENDTYPE {
                // typetable_print(type_table);
                driver_codegen(fptr);
            }
            |   {
                driver_codegen(fptr);
            }
            ;

TDeclList   : TDeclList TDecl {}
            | TDecl {}
            ;

TDeclStart  : TUPLE ID {
                typetable_create($2->varname,TYPE_TUPLE,NULL);
                $$ = $2->varname;
            }
            | STRUCT ID {
                typetable_create($2->varname,TYPE_TUPLE,NULL);
                $$ = $2->varname;
            }
            ;

TDecl       : TDeclStart '{' TIdList ';' '}' ';' {
                typetable_append_plist((char*) $1, $3);
                ParamList* temp = $3;
                
                
            }

TIdList     : TIdList ';' TIdDecl {
                $$ = append_param_to_list($1,$3);
            }
            | TIdDecl { $$ = $1; }

TIdDecl     : Type ID {
                if(!$1->Type){
                    printf("Error: Not Allowed to Use Classes in struct\n");
                    exit(0);
                }
                $$ = create_param($2->varname, $1->Type ? $1->Type->type : TYPE_CLASS);
                $$->typeEntry = $1->Type;
            }

// ---------------------CLASS DEFINITION START-------------------------------------------------//

ClassDefBlock   : CLASS ClassDefList ENDCLASS {}
                | CLASS ENDCLASS {}
                ;
ClassDefList    : ClassDefList Classdef
                | Classdef
                ;

Classdef        : Cname '{'DECL ClassdeclList ENDDECL MethodDefns '}' {

                    curr_class_table = NULL;
                    Cptr = NULL;
                    is_declaration_done = 0;

                }
                ;
ClassdeclList  : Fieldlists MethodDecl {is_declaration_done = 1;}
                
                ;

Cname           : ID  {
                        if(typetable_lookup($1->varname) != NULL || CLookup($1->varname)){
                            printf("Error: Type already exists\n");
                            exit(0);
                        }
                        Cptr = CInstall($1->varname,NULL); curr_class_table = Cptr;
                }
                | ID EXTENDS ID {

                    if(CLookup($3->varname) == NULL){
                        printf("Error: Class %s doesnt exist\n",$3->varname);
                        exit(0);
                    }
                    if(typetable_lookup($1->varname) != NULL || CLookup($1->varname)){
                            printf("Error: Type already exists\n");
                            exit(0);
                    }

                    Cptr = CInstall($1->varname,$3->varname); curr_class_table = Cptr;
                }
                ;

Fieldlists      : Fieldlists Fld
                |
                ;

Fld             : Type ID ';'  {

                    Class_Finstall(Cptr,$1->Name,$2->varname);

                } //Installing the field to the class
                ;

MethodDecl      : MethodDecl MDecl
                | MDecl
                ;

MDecl           : Type ID '(' ParamdeclBlock ')' ';' {
                    Class_Minstall(Cptr,$2->varname,$1->Type,$4);
                    
                    }
                                            //Installing the method to class
                ;

MethodDefns     : MethodDefns Fdef
                | Fdef
                ;


FieldFunction   : SELF '.' ID '(' ArgList ')' {

                    if(Cptr == NULL){
                        printf("Error: Not inside a class\n");
                        exit(0);
                    }
                    
                    tnode* t1 = createTree(0,TYPE_FUNCT,$3->varname,METHODNODE,NULL,$3,$5,NULL);
                    t1->centry = Cptr;
                    
                    struct tnode* temp = createTree(0,TYPE_CLASS,$3->varname,DOTNODE,NULL,$1,NULL,t1);
                    $1->centry = Cptr;
                    $$ = temp;
                    temp->centry = Cptr;
                    temp->typeEntry = Class_Mlookup(Cptr, $3->varname)->Type;
                    t1->typeEntry = temp->typeEntry;

                }
                | ID '.' ID '(' ArgList ')' {
                    //This will not occur inside a class.
                    Classtable* cls = get_classtable($1->varname);
                    if(!cls){
                        printf("Error: Not of class type\n");
                        exit(0);
                    }
                    Memberfunclist* func = Class_Mlookup(cls,$3->varname);
                    
                    if(func == NULL){
                        printf("Error: No method %s in class %s\n", $3->varname,$1->varname);
                        exit(0);
                    }
                    TypeTable* type = func->Type;
                    
                    paramlist_is_input_args_correct(func->Paramlist, $5);

                    tnode* t1 = createTree(0,TYPE_FUNCT,$3->varname,METHODNODE,NULL,$3,$5,NULL);
                    t1->centry = cls;
                    t1->typeEntry = type;
                    struct tnode* temp = createTree(0,TYPE_CLASS,"funct",DOTNODE,NULL,$1,NULL,t1);
                    $$ = temp;
                    $$->centry = cls;
                    $$->typeEntry = type;
                }
                | Field '.' ID '(' ArgList ')'{
                    Memberfunclist* func = Class_Mlookup($1->centry,$3->varname);
                    if(!$1->centry){
                        printf("Error: Not of class type\n");
                        exit(0);
                    }
                    paramlist_is_input_args_correct(func->Paramlist, $5);
                    tnode* t1 = createTree(0,TYPE_FUNCT,$3->varname,METHODNODE,NULL,$3,$5,NULL);
                    t1->centry = $1->centry;
                    struct tnode* temp = createTree(0,TYPE_CLASS,"funct",DOTNODE,NULL,$1,NULL,t1);
                    $$ = temp;
                    $$->typeEntry = Class_Mlookup($1->centry,$3->varname)->Type;
                    t1->typeEntry = $$->typeEntry;
                    $$->centry = NULL;
                }
                ;


// ---------------------CLASS DEFINITION END---------------------------------------------------//
// ------------------------------------------------------------------------//

FDefBlock   : FDefBlock Fdef {} 
            | Fdef {}
            ;

Fdef        : Type ID '(' ParamdeclBlock ')' '{' LdeclBlock body '}' {    
                
                function_block($1->Type->type,$2,paramlist_deepcopy($4),$8,TYPE_FUNCT);

            }
            | Type MUL ID '(' ParamdeclBlock ')' '{' LdeclBlock body '}' {
                
                function_block($1->Type->type, $3,paramlist_deepcopy($5),$9, TYPE_FUNCT_PTR);

            }
            ;

ParamdeclBlock : Paramlist {

                    $$ = $1;
                    if(is_declaration_done == 1){
                        if(curr_lsymbol_table== NULL){
                            curr_lsymbol_table = create_lsymbol_id("self", 1, TYPE_VOID);
                        }else{
                            Lsymbol* t1 = create_lsymbol_id("self", 1, TYPE_VOID);
                            append_lsymbol_id_list(curr_lsymbol_table,t1);
                        }
                    }
                }
                ;

Paramlist   : Paramlist ',' ParamDecl {
                $$ = append_param_to_list($1,$3);
                if(is_declaration_done == 1){
                    Lsymbol* t1 = create_lsymbol_id($3->name, $3->varType == TYPE_PTR ? 1 : $3->size, $3->varType);
                    
                    t1->type = $3->type;
                    t1->typeEntry = $3->typeEntry;
                    t1->centry = $3->centry;
                    curr_lsymbol_table = append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
            }
            | ParamDecl {
                $$ = $1;
                if(is_declaration_done == 1){
                    Lsymbol* t1 = create_lsymbol_id($1->name, $1->size, $1->varType);
                    t1->type = $1->type;
                    t1->typeEntry = $1->typeEntry;
                    t1->centry = $1->centry;

                    curr_lsymbol_table =  append_lsymbol_id_list(curr_lsymbol_table, t1);
                }
                
            }
            |   /*paramDecl can be empty */ {$$ = NULL;curr_lsymbol_table= NULL;}
            ;

ParamDecl   : Type Param {
                $2->type = $1->Type ? $1->Type->type : TYPE_CLASS;
                $2->centry = $1->Ctype;
                $2->typeEntry = $1->Type;
                $2->size = $1->Type ? $1->Type->size : $1->Ctype->Fieldcount;
                $$ = $2;
                
            }
            ;

Param       : ID {
                $$ = create_param($1->varname,TYPE_NULL);
                $$->size = 1;
                $$->varType = TYPE_VAR;
            }
            | MUL ID {
                $$ = create_param($2->varname,TYPE_NULL);
                $$->size = 1;
                $$->varType = TYPE_PTR;
                
            }

//-------------------------------------------------------------------------//

LdeclBlock  : DECL LDecList ENDDECL {
                Lsymbol* temp = curr_lsymbol_table;
                while(temp && temp->next){
                    temp = temp->next;
                }
                if(temp) temp->next = $2;
                else curr_lsymbol_table = $2;
                lst_set_bindings(curr_lsymbol_table);
                
                $$ = curr_lsymbol_table;
            }
            |  {$$ = NULL;lst_set_bindings(curr_lsymbol_table);}
            ;

LDecList    : LDecList LDecl {
                Lsymbol* temp = $2;
                while(temp){
                    check_lpresent($1,temp->name);
                    temp = temp->next;
                }
                temp = $1;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = $2;
                $$ = $1;
            }
            | LDecl {
                $$ = $1;   
            }
            ;

LDecl       : Type IdList ';' {
                Lsymbol* temp = $2;
                while(temp){
                    temp->type = $1->Type ? $1->Type->type : TYPE_CLASS;
                    temp->typeEntry = $1->Type;
                    temp->centry = $1->Ctype;
                    if($1->Ctype != NULL){
                        temp->type = TYPE_CLASS;
                    }else if(temp->typeEntry->type == TYPE_TUPLE){
                        temp->type = TYPE_TUPLE;
                    }
                    temp = temp->next;
                }
                print_lsymbol_table();
                $$ = $2;
            }
            ;

IdList      : IdList ',' IdDecl  {
                check_lpresent($1,$3->name);
                $$ = append_lsymbol_id_list($1, $3);
            }
            | IdDecl {
                $$ = $1;
            }
            ;

IdDecl      : ID {
                $$ = create_lsymbol_id($1->varname, curr_type1->Ctype ? curr_type1->Ctype->Fieldcount : curr_type1->Type->size, TYPE_VAR);
            }
            | MUL ID{
                int size = 2;
                if(curr_type1->Type && curr_type1->Type->type == TYPE_TUPLE){
                    size = 1 + curr_type1->Type->size;
                }else 
                $$ = create_lsymbol_id($2->varname, size, TYPE_PTR);
                printf("ptr name: %s\n",$2->varname);
            }
ArgList     : ArgList ',' E {

                tnode* temp = $1;
                while(temp->middle){
                    temp = temp->middle;
                }
                temp->middle = $3;
                $$ = $1;
            }
            | E { $$ = $1;}
            | /* empty */ { $$ = NULL;}
            ;


//-------------------------------------------------------------------------//

MainBlock : Type MAIN '(' ')' '{' LdeclBlock body '}' {

        //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome
        print_lsymbol_table();

        curr_function_type = $1->Type;

        tree_visual_printTree($7);
        export_ast_to_graphviz($7,"Main");

        fprintf(fptr, "MAIN:");

        int p = getReg();

        fprintf(fptr, "MOV R%d, BP\n", p);
        fprintf(fptr, "PUSH R%d\n", p);
        fprintf(fptr, "MOV BP, SP\n");

        int curr_offset = get_ltable_length(curr_lsymbol_table);

        if(curr_offset!=0)fprintf(fptr, "ADD SP, %d\n", curr_offset);

        freeReg();

        setup_pointers_codegen(fptr,NULL,curr_lsymbol_table);

        codeGen($7,0,0,fptr);

        // lst_destroy($6);

        curr_lsymbol_table = NULL;
}

//-------------------------------------------------------------------------//

body : begin Slist end {$$ = $2;}

Slist   : Slist Stmt {
            struct tnode* temp = createTree(0,TYPE_NULL,NULL,CONNECTOR,NULL,$1, NULL, $2);
            $$ = temp;
        }
        | Stmt {
            $$ = $1;
        }
        ;

Type        : INT { 
                    $$ = fieldlist_create("int",NULL,typetable_lookup("int"));
                    curr_type1 = $$;
            }
            | STR { $$ = fieldlist_create("str",NULL,typetable_lookup("str"));curr_type1 = $$; }
            | ID {
                TypeTable* curr_type = typetable_lookup($1->varname);
                Classtable* cls = CLookup($1->varname);
                if(curr_type == NULL && cls == NULL){
                    printf("Error: No UserDefined struct %s exists\n", $1->varname);
                    exit(0); 
                }
                $$ = fieldlist_create($1->varname,cls,curr_type);
                curr_type1 = $$;
            }
            ;

DimList : DimList '[' NUM ']' {
            $$ = append_dim($1, $3->val);
        }
        | /* empty */   { $$ = create_dimlist(NULL); }
        ;

InputStmt   : READ '(' ID  ')' ';' {
                Gsymbol* ptr1 = find_gsymbol($3->varname);
                Lsymbol* ptr2 = find_lsymbol($3->varname);
                int varType = get_var_type(ptr1,ptr2,$3->varname);
                $1->left = $3;
                $$ = $1;
            }
            | READ '(' ID DimAccess ')' ';' {
                Gsymbol* temp = find_gsymbol($3->varname);
                $3->Gentry = temp;
                check_not_out_of_bounds($4,$3->Gentry->dimlist);
                $1->left = $3;
                $3->dimlist = $4;
                $$ = createTree(0,TYPE_NULL, "Read", READNODE,NULL,$3, NULL, NULL);
            }
            | READ '(' MUL ID ')' ';' {
                Gsymbol* entry = find_gsymbol($4->varname);
                tnode* temp = createTree(0, TYPE_PTR, "*", PTRNODE, entry,$4, NULL,NULL);
                $$ = createTree(0, TYPE_NULL, "Read", READNODE,NULL,temp, NULL, NULL);
            }
            | READ '(' Field ')' ';' {
                int type = $3->type;
                TypeTable* typet = $3->typeEntry;
                $$ = createTree(0,$3->type,"Read",READNODE,NULL,$3,NULL,NULL);
            }
            | READ '(' ID ARROW ID ')' ';' {
                Gsymbol* ptr1 = find_gsymbol($3->varname);
                Lsymbol* ptr2 = find_lsymbol($3->varname);
                int type = get_type(ptr1,ptr2,$3->varname);
                check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,649);
                int varType = get_var_type(ptr1,ptr2,$3->varname);
                if(varType != TYPE_PTR){
                    printf("Error: %s is not of pointer type, use . operator to access its attributes\n", $3->varname);
                    exit(0);
                }
                TypeTable* typet = get_typetable(ptr1,ptr2,$3->varname);
                tnode* arrow = createTree(0,typetable_lookup_id_type(typet,$5->varname),"->",ARROWNODE,NULL,$3,NULL,$5);
                $$ = createTree(0,typetable_lookup_id_type(typet,$5->varname),"Read",READNODE,NULL,arrow,NULL,NULL);
                arrow->typeEntry = typet;
            }
            ;

OutputStmt  : WRITE '(' E ')' ';' {
                $1->left = $3;
                $$ = $1;
            }
            ;

AsgStmt : ID '=' E ';' {
            if($3->nodetype != NULLNODE){
                Gsymbol* ptr1 = find_gsymbol($1->varname);
                Lsymbol* ptr2 = find_lsymbol($1->varname);
                int varType = get_var_type(ptr1,ptr2,$1->varname);
                TypeTable* type1 = get_typetable(ptr1,ptr2,$1->varname);

                TypeTable* type2 = $3->typeEntry;

                if(strcmp(type1->name,type2->name) != 0){
                    printf("Error: Assignment with different Data Types, LHS => %s and RHS => %s\n", type1->name,type2->name);
                    exit(0);
                }
                if(varType != TYPE_VAR && varType != TYPE_PTR){
                    printf("Error: %s is not of variable type\n",$1->varname);
                    printf("%s\n",type_to_string(varType));
                    exit(1);
                }
                
                $$ = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL,$1, NULL, $3);
            }else{
                $$ = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL, $1, NULL, $3);
            }
        }
        | ID DimAccess '=' E ';'{
            Gsymbol* temp = find_gsymbol($1->varname);
            if(temp->varType != TYPE_ARR){
                printf("Error: %s is not of array type\n",$1->varname);
                exit(1);
            }
            check_data_types(temp->type,$4->type,temp->type,432);
            $1->Gentry = temp;
            $1->dimlist = $2;
            check_not_out_of_bounds($2,$1->Gentry->dimlist);
            $$ = createTree(0,TYPE_ARR, "=", ASSIGNMENT,$1->Gentry,$1, NULL, $4);
        }
        | MUL ID '=' E ';' {  //here i used MUL because lex returnes MUL when the it captures '*'
            Gsymbol* ptr1 = find_gsymbol($2->varname);
            Lsymbol* ptr2 = find_lsymbol($2->varname);
            int varType = get_var_type(ptr1,ptr2,$2->varname);
            if(varType != TYPE_PTR){
                printf("Error: %s is not of pointer type\n",$2->varname);
                exit(1);
            }
            if(ptr2){
                check_data_types(ptr2->type,$4->type,ptr2->type,447);
            }else if(ptr1){
                check_data_types(ptr1->type,$4->type,ptr1->type,449);
            }else{
                printf("Error: Variable %s Not Declared 498\n", $2->varname);
                exit(0);
            }
            tnode* t = createTree(0,TYPE_PTR, "*", PTRNODE, NULL,$2, NULL, NULL);
            $$ = createTree(0,TYPE_PTR, "=", ASSIGNMENT,NULL,t, NULL, $4);
        }
        | Field '=' E ';' {
            TypeTable* type1 = $1->typeEntry;
            TypeTable* type2 = $3->typeEntry;
            if($3->nodetype != NULLNODE){
                if(strcmp($1->typeEntry->name,$3->typeEntry->name) != 0){
                    printf("Error: Assignment with different Data Types, LHS => %s and RHS => %s\n", type1->name,type2->name);
                    exit(0);
                }
                $$ = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL,$1, NULL, $3);
                $$->typeEntry = $1->typeEntry;
                $$->centry = $1->centry;
            }else {
                $$ = createTree(0,TYPE_VAR, "=", ASSIGNMENT,NULL,$1, NULL, $3);
                $$->typeEntry = $1->typeEntry;
            }
        }
        | ID ARROW ID '=' E ';' {
            Gsymbol* ptr1 = find_gsymbol($1->varname);
            Lsymbol* ptr2 = find_lsymbol($1->varname);
            TypeTable* type = NULL;
            if(ptr2){
                type = ptr2->typeEntry;
            }else if(ptr1){
                type = ptr1->typeEntry;
            }else{
                printf("Error: Variable %s Not Declared 539\n", $1->varname);
                exit(0);
            }
            if(type->type != TYPE_TUPLE){
                printf("Error: Variable %s is not of tuple type\n", $1->varname);
                exit(0);
            }

            if(typetable_lookup_id_type(type,$3->varname) != $5->type){
                printf("Error: Variable %s Not Declared in the tuple definition\n", $3->varname);
                exit(0);
                
            }
            if(get_var_type(ptr1,ptr2,$3->varname) != TYPE_PTR){
                printf("Error: %s is not of pointer type, use . operator\n", $3->varname);
                exit(0);
            }
            tnode* arrow = createTree(0,typetable_lookup_id_type(type,$3->varname),"->",ARROWNODE,NULL,$1,NULL,$3);
            $$ = createTree(0,TYPE_VAR, "=", ASSIGNMENT,ptr1,arrow, NULL, $5);
            $$->typeEntry = type;
        }
        
        ;

Allocstmnt : ID '=' ALLOC'(' ')' ';' {
                Gsymbol* ptr1 = find_gsymbol($1->varname);
                Lsymbol* ptr2 = find_lsymbol($1->varname);

                TypeTable* type = get_typetable(ptr1,ptr2,$1->varname);
                Classtable* cls = get_classtable($1->varname);

                check_data_types(type->type,type->type,TYPE_TUPLE,559);

                tnode* temp = createTree(type->size, TYPE_NULL, "Alloc", ALLOCNODE,NULL,$1, NULL, NULL);

                temp->typeEntry = type;
                temp->centry = cls;

                $$ = temp;
            }
            | Field '=' ALLOC'(' ')' ';' {

                if($1->typeEntry->type != TYPE_TUPLE){
                    printf("Error: Piecewise allocation not possible %s\n", $1->right->varname);
                    exit(0);
                }

                tnode* temp = createTree($1->typeEntry->size, TYPE_NULL, "Alloc", ALLOCNODE,NULL,$1, NULL, NULL);

                $$ = temp;
            }
            | FREE '(' ID ')' ';' {
                Gsymbol* ptr1 = find_gsymbol($3->varname);
                Lsymbol* ptr2 = find_lsymbol($3->varname);

                TypeTable* type = get_typetable(ptr1,ptr2,$3->varname);

                // check_data_types(type->type,type->type,TYPE_TUPLE,559);

                tnode* temp = createTree(type->size, TYPE_NULL, "free", FREENODE,NULL,$3, NULL, NULL);

                temp->typeEntry = type;

                $$ = temp;
            }
            | FREE '(' Field ')' ';' {

                if($3->typeEntry->type != TYPE_TUPLE){
                    printf("Error: Piecewise deallocation not possible %s\n", $3->right->varname);
                    exit(0);
                }

                tnode* temp = createTree($3->typeEntry->size, TYPE_NULL, "free", FREENODE,NULL,$3, NULL, NULL);

                $$ = temp;
            }
            | INITIALIZE '('')'';' {
                tnode* temp = createTree(0, TYPE_NULL, "initalize", INITIALIZENODE,NULL,NULL, NULL, NULL);
                $$ = temp;
            }
            | ID '=' NEW '(' ID ')' ';' {

                Gsymbol* ptr1 = find_gsymbol($1->varname);
                Lsymbol* ptr2 = find_lsymbol($1->varname);

                TypeTable* type = get_typetable(ptr1,ptr2,$1->varname);
                Classtable* cls1 = get_classtable($1->varname);
                Classtable* cls2 = CLookup($5->varname);

                if(!cls1 ){
                    printf("Error: No class entry found for the variable %s\n",$1->varname);
                    exit(0);
                }else if( !cls2){
                    printf("Error: No class entry found for the variable %s\n",$5->varname);
                    exit(0);
                }

                if(strcmp(cls1->Name,cls2->Name) != 0){
                    printf("Error: Allocating to different class type\n");
                    exit(0);
                }

                if(type)check_data_types(type->type,type->type,TYPE_CLASS,738);

                tnode* temp = createTree(cls2->Fieldcount, TYPE_NULL, "Alloc", ALLOCNODE,NULL,$1, NULL, NULL);
                temp->typeEntry = NULL;
                temp->centry = cls1;

                $$ = temp;
            }
            | Field '=' NEW '(' ID ')' ';' {
                Classtable* cls1 = $1->centry;
                Classtable* cls2 = CLookup($5->varname);

                if(!cls1 ){
                    printf("Error: No class entry found for the variable SELFNODE\n");
                    exit(0);
                }else if( !cls2){
                    printf("Error: No class entry found for the variable %s\n",$5->varname);
                    exit(0);
                }

                if(strcmp(cls1->Name,cls2->Name) != 0){
                    printf("Error: Allocating to different class type\n");
                    exit(0);
                }

                tnode* temp = createTree(cls2->Fieldcount, TYPE_NULL, "Alloc", ALLOCNODE,NULL,$1, NULL, NULL);
                temp->typeEntry = NULL;
                temp->centry = cls1;

                $$ = temp;
            }
            | DELETE '(' ID ')' ';'     {
                Classtable* cls = get_classtable($3->varname);
                if(cls == NULL){
                    printf("Error: Piecewise deallocation not possible %s\n", $3->right->varname);
                    exit(0);
                }
                tnode* temp = createTree($3->centry->Fieldcount, TYPE_NULL, "free", FREENODE,NULL,$3, NULL, NULL);
                $$->centry = cls;
                $$ = temp;
            }
            | DELETE '(' Field ')' ';' {
                if($3->centry == NULL){
                    printf("Error: Piecewise deallocation not possible %s\n", $3->right->varname);
                    exit(0);
                }

                tnode* temp = createTree($3->centry->Fieldcount, TYPE_NULL, "free", FREENODE,NULL,$3, NULL, NULL);

                $$ = temp;
            }
        
            ;


Stmt    : InputStmt         { $$ = $1; }
        | OutputStmt        { $$ = $1; }
        | AsgStmt           { $$ = $1; }
        | Ifstmt            { $$ = $1; }
        | Whilestmt         { $$ = $1; }
        | DoWhilestmt       { $$ = $1; }
        | RepeatUntiltstmt  { $$ = $1; }
        | Jumpstmt          { $$ = $1; }
        | Debugstmt         { $$ = $1; }
        | Allocstmnt        { $$ = $1; }
        | FieldFunction  ';'{ $$ = $1; }
        ;

Ifstmt  : IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' {
            $$ = createIfNode($6,$3,$8);
        }   
        | IF '(' E ')' THEN Slist ENDIF ';' {
            $$ = createIfNode($6,$3,NULL);
        }
        ;

Whilestmt   : WHILE '(' E ')' DO Slist ENDWHILE ';' {
                $$ = createWhileNode($6,$3);
            }
            ;

DoWhilestmt : DO Slist WHILE '(' E ')' ';' {
                $$ = createDoWhileNode($2,$5);
            }
            ;

RepeatUntiltstmt    : REPEAT Slist UNTIL '(' E ')'';' {
                        $$ = createDoWhileNode($2,$5);
                    }
                    ;

Jumpstmt    : CONTINUE ';' {
                $$ = createJumpNode(CONTINUENODE);
            }
            | BREAK ';' {
                $$ = createJumpNode(BREAKNODE);
            }
            | RETURN E ';' { 
                $$ = createTree(0, $2->type, NULL, RETURNNODE, NULL,$2, NULL,NULL);
                $$->typeEntry = $2->typeEntry;
            }
            ;

Debugstmt : BREAKPOINT ';' {
                $$ = createTree(0,TYPE_NULL,"BRKP", BREAKPOINTNODE,NULL,NULL, NULL, NULL);
            }
            ;

E   : E PLUS E {
        
        $$ = createTree(0, $1->type, "+", OPERATOR,NULL,$1, NULL, $3);
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        $$->typeEntry = typet;
    }
    | E MINUS E {
        $$ =  createTree(0, $1->type , "-", OPERATOR,NULL,$1, NULL, $3);
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        $$->typeEntry = typet;
    }
    | E DIV E {
        $$ = createTree(0, $1->type, "/", OPERATOR,NULL,$1, NULL, $3);
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        $$->typeEntry = typet;
    }
    | E MUL E {
        $$ = createTree(0, $1->type, "*", OPERATOR,NULL,$1, NULL, $3);
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        $$->typeEntry = typet;
    }
    | E MOD E {
        $$ = createTree(0, $1->type, "%", OPERATOR,NULL,$1, NULL, $3);
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        $$->typeEntry = typet;
    }
    | '(' E ')' {
        $$ = $2;
    }
    | E GT E {
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        $$ = createTree(0,TYPE_BOOL,">",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E LT E {
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        $$ = createTree(0,TYPE_BOOL,"<",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E GE E {
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        $$ = createTree(0,TYPE_BOOL,">=",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E LE E {
        TypeTable* typet = typetable_lookup("int");
        typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        $$ = createTree(0,TYPE_BOOL,"<=",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E NE E {
        if($1->type == TYPE_TUPLE && $3->nodetype == NULLNODE){

        }else{
            TypeTable* typet = typetable_lookup("int");
            typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        }
        $$ = createTree(0,TYPE_BOOL,"!=",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E EQ E {
        if($1->type == TYPE_TUPLE && $3->nodetype == NULLNODE){
                
        }else{
            TypeTable* typet = typetable_lookup("int");
            typetable_check_type($1->typeEntry, $3->typeEntry, typet);
        }
        $$ = createTree(0,TYPE_BOOL,"==",EXPRESSION,NULL,$1,NULL,$3);
    }
    | E AND E {
        check_data_types($1->type,$3->type,TYPE_BOOL,624);
        $$ = createTree(0,TYPE_BOOL,"&&",OPERATOR,NULL,$1,NULL,$3);
    }
    | E OR E {
        check_data_types($1->type,$3->type,TYPE_BOOL,628);
        $$ = createTree(0,TYPE_BOOL,"||",OPERATOR,NULL,$1,NULL,$3);
    }
    | NILL {
        $$ = $1;
    }
    | Field {
        $$ = $1;
    }
    | FieldFunction {
        $$ = $1;
    }
    | ID ARROW ID {
        Gsymbol* ptr1 = find_gsymbol($1->varname);
        Lsymbol* ptr2 = find_lsymbol($1->varname);
        int type = get_type(ptr1,ptr2,$1->varname);
        check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,649);
        int varType = get_var_type(ptr1,ptr2,$1->varname);
        if(varType != TYPE_PTR){
            printf("Error: %s is not of pointer type, use . operator to access its attributes\n", $1->varname);
            exit(0);
        }
        TypeTable* typet = get_typetable(ptr1,ptr2,$1->varname);
        $$ = createTree(0,typetable_lookup_id_type(typet,$3->varname),"->",ARROWNODE,NULL,$1,NULL,$3);
        $$->typeEntry = typet;
    }
    /* | ID '(' ')' {
        Gsymbol* ptr1 = find_gsymbol($1->varname);
        if(!ptr1 || ptr1->varType != TYPE_FUNCT || ptr1->varType != TYPE_FUNCT_PTR){
            printf("Error: No function with name %s declared\n",$1->varname);
            exit(0);
        }
        paramlist_is_input_args_correct(ptr1->plist, NULL);
        TypeTable* typet = get_typetable(ptr1,NULL,$1->varname);
        $$ = createTree(0,ptr1->type,"funtion()",FUNCTIONNODE,NULL,$1,NULL,NULL);
        $$->typeEntry = typet;
    } */
    | ID '(' ArgList ')' {
        Gsymbol* ptr1 = find_gsymbol($1->varname);

        print_gsymbol_list(ptr1);
        if(!ptr1 || (ptr1->varType != TYPE_FUNCT && ptr1->varType != TYPE_FUNCT_PTR)){
            printf("Error: No function with name %s declared\n",$1->varname);
            exit(0);
        }
        tnode* temp = $3;
        // while(temp){
        //     print_ast_node(temp);
        //     temp = temp->middle;
        // }
        paramlist_is_input_args_correct(ptr1->plist, $3);
        TypeTable* typet = get_typetable(ptr1,NULL,$1->varname);
        $$ = createTree(0,ptr1->type,"funtion()",FUNCTIONNODE,NULL,$1,NULL,$3);
        $$->typeEntry = typet;
    }
    | ID {
        Gsymbol* ptr1 = find_gsymbol($1->varname);
        Lsymbol* ptr2 = find_lsymbol($1->varname);
        
        int varType = get_var_type(ptr1,ptr2,$1->varname);
        // printf("%s is of %s\n",$1->varname, type_to_string(varType));
        if(varType != TYPE_VAR && varType != TYPE_PTR){
            printf("Error: %s is not of variable type\n",$1->varname);
            exit(1);
        }
        TypeTable* typet = get_typetable(ptr1,ptr2,$1->varname);
        $$ = createTree(0, get_type(ptr1,ptr2,$1->varname), $1->varname, LEAFNODE, ptr1,NULL, NULL,NULL);
        $$->typeEntry = typet;
        $$->centry = get_classtable($1->varname);
    }
    | ID DimAccess {
        Gsymbol* temp = find_gsymbol($1->varname);
        if(!$2){
            if(temp->varType != TYPE_ARR){
                printf("Error: %s is of array type but using it as variable type here\n",$1->varname);
                exit(1);
            }
        }
        $1->Gentry = temp;
        check_not_out_of_bounds($2,$1->Gentry->dimlist);
        int val = get_pos($2,$1->Gentry->dimlist);
        $$ = createTree(val, temp->type, $1->varname, LEAFNODE, temp,NULL, NULL,NULL);
        TypeTable* typet = get_typetable(temp,NULL,$1->varname);
        $$->typeEntry = typet;
        $$->dimlist = $2;
        $$->centry = get_classtable($1->varname);
    }
    | MUL ID { //here i used MUL because lex returnes MUL when the it captures '*'
        Gsymbol* ptr1 = find_gsymbol($2->varname);
        Lsymbol* ptr2 = find_lsymbol($2->varname);

        if(!ptr1 && !ptr2){
            printf("Error: pointer %s is not declared\n", $2->varname);
        }
        $2->Gentry = ptr1;
        $$ = createTree(0, TYPE_INT, "*", PTRNODE, ptr1,$2, NULL,NULL);
        TypeTable* typet = get_typetable(ptr1,ptr2,$2->varname);
        $$->typeEntry = typet;
        $2->typeEntry = typet;
    }
    | '&' ID {
        Gsymbol* ptr1 = find_gsymbol($2->varname);
        Lsymbol* ptr2 = find_lsymbol($2->varname);

        if(!ptr1 && !ptr2){
            printf("Error: pointer %s is not declared\n", $2->varname);
        }
        $2->Gentry = ptr1;

        $$ = createTree(0, TYPE_INT, "&", ADDRNODE, NULL,$2, NULL,NULL);
        TypeTable* typet = get_typetable(ptr1,ptr2,$2->varname);
        $$->typeEntry = typet;
        $2->typeEntry = typet;
    }
    | STRING {
        $$ = createTree(-10, TYPE_STRING, $1, LEAFNODE,NULL, NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("str");
        $$->typeEntry = typet;
    }
    | NUM {
        $$ = createTree($1->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("int");
        $$->typeEntry = typet;
    }
    | MINUS NUM {
        $$ = createTree(-$2->val, TYPE_INT, NULL, LEAFNODE, NULL,NULL, NULL,NULL);
        TypeTable* typet = typetable_lookup("int");
        $$->typeEntry = typet;
    }
    ;
DimAccess   : DimAccess '[' E ']' {
                check_data_types($3->type,TYPE_INT,TYPE_INT,756);
                $$ = append_dim_with_id($1,$3);
            }
            | '[' E ']' {
                check_data_types($2->type,TYPE_INT,TYPE_INT,760);
                $$ = append_dim_with_id(NULL,$2);
            }
            ;

Field   : Field '.' ID {
            int type = $1->type;
            check_data_types(type,TYPE_TUPLE,TYPE_TUPLE,803);
            TypeTable* typet = $1->typeEntry;
            TypeTable* typet2 = typetable_lookup_id_typetable(typet,$3->varname);
            $$ = createTree(0,typetable_lookup_id_type(typet,$3->varname),".",DOTNODE,NULL,$1,NULL,$3);
            $$->typeEntry = typet2;
            $3->typeEntry = typet2;
            if($1->centry){
                Classtable* cls = $1->centry;
                Fieldlist* field = Class_Flookup(cls,$3->varname);
                if(!field){
                    printf("Error: No field %s found in class %s\n",$3->varname,cls->Name);
                    exit(0);
                }
                $$->centry = field->Ctype;
                $3->centry = field->Ctype;
            }
            // printf("for ID %s -> ID %s\n", $1->varname, $3->varname);
            // if(typet2){
            //     printf("typeEntry name %s 805\n", typet2->name);
            // }else if($$->centry){
            //     printf("centry name %s 805\n", $$->centry->Name);
            // }

            // printf("typeEntry %s 806\n", typet->name);
        }
        | ID '.' ID {
            
            Gsymbol* ptr1 = find_gsymbol($1->varname);
            Lsymbol* ptr2 = find_lsymbol($1->varname);
            int type = get_type(ptr1,ptr2,$1->varname);
            int varType = get_var_type(ptr1,ptr2,$1->varname);
            if(varType == TYPE_PTR){
                printf("Error: %s is of pointer type, use -> operator to access its attributes\n", $1->varname);
                exit(0);
            }
            TypeTable* typet = get_typetable(ptr1,ptr2,$1->varname);
            Classtable* cls = get_classtable($1->varname);
            TypeTable* typet2 = typetable_lookup_id_typetable(typet,$3->varname);
            $$ = createTree(0,typetable_lookup_id_type(typet,$3->varname),"dot",DOTNODE,NULL,$1,NULL,$3);
            $$->typeEntry = typet2;
            $1->typeEntry = typet;
            $1->centry = cls;

         }
        | SELF '.' ID {
            if(Cptr != NULL){
                Fieldlist* t = Class_Flookup(Cptr,$3->varname);
                $$ = createTree(0,t->Type ? t->Type->type : TYPE_CLASS,$3->varname, DOTNODE, NULL,$1,NULL,$3);
                if(!t){
                    printf("Error: No field %s found\n",$3->varname);
                    exit(0);
                }
                $1->centry = Cptr;
                $1->typeEntry = NULL;
                $$->centry = t->Ctype;
                $$->typeEntry = t->Type;
                // printf("---\n");
                // printf("ID SELF -> FOR ID %s\n", $3->varname);
                // if(t->Type){
                //     printf("typeEntry name %s\n", $$->typeEntry->name);
                // }else if(t->Ctype){
                //         printf("centry name %s\n", $$->centry->Name);
                // }
                

            }else{
                printf("Error:Not inside a class\n");
                exit(0);
            }
        }
        ;



%%


void function_block(DataType $1, tnode* $2,ParamList* $4, tnode* $8, DataType functionType){


        Gsymbol* temp = find_gsymbol($2->varname);
        Memberfunclist* func = Cptr ? Class_Mlookup(Cptr,$2->varname) : NULL;
        
        TypeTable* type = temp ? temp->typeEntry : func->Type; 
        int flabel = temp ? temp->flabel : func->Flabel;
        

        ParamList* param = func ? func->Paramlist : temp->plist;
        curr_function_type = type;
        is_paramlist_correct(param,$4);

        print_lsymbol_table();

        curr_funct_return_type = functionType;
        
        //we globally declare the current local symbol so as to avoid restructuring the entire functions since it is being used everywhere and change it would be tiresome 
        // curr_lsymbol_table = $7;

        ParamList* t = $4;
        int p = getReg();
        fprintf(fptr,"F%d:", flabel);
        fprintf(fptr, "MOV R%d, BP\n", p);
        fprintf(fptr, "PUSH R%d\n", p);
        fprintf(fptr, "MOV BP, SP\n");
        
        int param_list_size = get_paramlist_length($4);

        //setting up the argument values into the respective addresses in the from the local symbol table
        int count = param_list_size + 1;
        int returnSize = 1;
        if(functionType == TYPE_FUNCT_PTR){
            returnSize = 1;
        }
        /* fprintf(fptr, "BRKP\n");
        fprintf(fptr, "BRKP\n"); */
        while(count--){
            fprintf(fptr, "MOV R%d, SP\n", p);
            fprintf(fptr, "SUB R%d, %d\n", p, param_list_size + 3 + returnSize - 1); //here the 3 is the RETURN VALUE, RETURN ADDRESS, OLD BP and the -1 for preventing the overreduction as subtracting curr_offset u reach the OLD BP 
                                                                        // and from there to reach the return value part u just need to subtract 2 and to reach the 1st arg u just need to subtract the whole paramlist
            fprintf(fptr, "MOV R%d, [R%d]\n", p, p);
            fprintf(fptr, "PUSH R%d\n", p);
        }

        /* fprintf(fptr, "BRKP\n"); */

        // This is to set up space for the locally declared variables in the function
        int curr_offset = get_ltable_length(curr_lsymbol_table) - param_list_size - 1;

        if(curr_offset > 0)fprintf(fptr, "MOV R%d, \"SPACE\"\n", p);
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


void yyerror(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    fprintf(stderr, "Error at line %d near '%s': ", yylloc.first_line, yytext);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    va_end(args);
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