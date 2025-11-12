#ifndef GLOBAL_SYMBOL_TABLE_H
#define GLOBAL_SYMBOL_TABLE_H


#include "AST.h"
#include "dim_node.h"
#include "type_table.h"
#include "exptree.h"

typedef struct Gsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable
    int varType;      // this is to know if its variable,array or pointer
    int size;         // size of the type of the variable
    int binding;    // stores the static memory address allocated to the variable
    struct Gsymbol *next;
    struct DimNode* dimlist;
    struct ParamList* plist;
    struct TypeTable* typeEntry;
    struct Classtable* centry;
    int flabel;
}Gsymbol;

extern struct Gsymbol *top;
extern struct Gsymbol *tail;
extern int flabel_count;
extern int is_global_vars_declared; // 0 -> N0 1->YES

extern int curr_stack_address;

// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise and throws and error if not found
struct Gsymbol *find_gsymbol(char * name);

//adds a symbol to the symbol table
void add_gsymbol(Gsymbol *id, int type);

// Creates a symbol data.
struct Gsymbol *create_gsymbol_id(char *name, int size);  

//appends a symbol to the list
struct Gsymbol* append_gsymbol_id_list(Gsymbol *list,Gsymbol *id);

//prints the symbol table
void print_gsymbol_table();


//prints the data containing inside the list
void print_gsymbol_list(Gsymbol* t);

//this simply checks if its present or not unlike the find_gsymbol() function
struct Gsymbol* is_gpresent(char* name);


//this retrieves the type of the variable associated with it(TYPE_INT,TYPE_STRING etc)
int get_gtype(Gsymbol* entry);

#endif