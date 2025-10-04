#ifndef Local_lSYMBOL_TABLE_H
#define Local_lSYMBOL_TABLE_H

#include "AST.h"
#include "dim_node.h"
#include "global_symbol_table.h"

#define MAX_LOCAL_TABLES 100

typedef struct Lsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable
    int varType;      // this is to know if its variable,array or pointer
    int size;         // size of the type of the variable
    int binding;    // stores the static memory address allocated to the variable
    struct Lsymbol *next;
//    struct DimNode* dimlist;
}Lsymbol;

extern int curr_addr_offset;
extern int curr_funct;
extern struct Lsymbol* curr_lsymbol_table;

// Returns a pointer to the lsymbol table entry for the variable, returns NULL otherwise and throws and error if not found
struct Lsymbol *find_lsymbol(char * name);

//adds a lsymbol to the lsymbol table
struct Lsymbol* add_lsymbol(Lsymbol *id, int type);

// Creates a lsymbol data.
struct Lsymbol *create_lsymbol_id(char *name, int size,int varType);  

//appends a lsymbol to the list
struct Lsymbol * append_lsymbol_id_list(Lsymbol *list,Lsymbol *id);

//prints the lsymbol table
void print_lsymbol_table();


//prints the data containing inside the list
void print_lsymbol_list(Lsymbol* t);



void check_lpresent(Lsymbol* main,char* name);

//this retrieves the type of the variable associated with it(TYPE_INT,TYPE_STRING etc)
int get_ltype(Lsymbol* entry);

//this is to get the binding address for the new variable as all the binding address is w.r.t BP we have a logical address
//here i am finding the sum of all the size of the variables declared in the lsymbol table 
int get_curr_offset(Lsymbol* head);


//free the local symbol table of the function
void lst_destroy(Lsymbol* head);


//To set up the bindings of all the variables in the table
Lsymbol* lst_set_bindings(Lsymbol* head);

//--------------------GET SYMBOL TABLE DATAS-----------------------------START-------//

int get_var_type(Gsymbol* gentry, Lsymbol* lentry,char* varname);

int get_type(Gsymbol* gentry, Lsymbol* lentry,char* varname);

DimNode* get_dimlist(Gsymbol* gentry, Lsymbol* lentry,char* varname);

int get_binding(Gsymbol* gentry, Lsymbol* lentry, char* varname,FILE* fptr, int regNo); // here the function will also be adding some xsm code as well

//--------------------GET SYMBOL TABLE DATAS-----------------------------END---------//
#endif