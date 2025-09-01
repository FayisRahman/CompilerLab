#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "AST.h"
#include "dim_node.h"

typedef struct Gsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable
    int varType;      // this is to know if its variable,array or pointer
    int size;         // size of the type of the variable
    int binding;    // stores the static memory address allocated to the variable
    struct Gsymbol *next;
    struct DimNode* dimlist;
}Gsymbol;

extern struct Gsymbol *top;
extern struct Gsymbol *tail;

extern int curr_stack_address;

// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise and throws and error if not found
struct Gsymbol *find_symbol(char * name);

//adds a symbol to the symbol table
void add_symbol(Gsymbol *id, int type);

// Creates a symbol data.
struct Gsymbol *create_symbol_id(char *name, int size);  

//appends a symbol to the list
struct Gsymbol* append_symbol_id_list(Gsymbol *list,Gsymbol *id);

//prints the symbol table
void print_symbol_table();


//prints the data containing inside the list
void print_symbol_list(Gsymbol* t);

//this simply checks if its present or not unlike the find_symbol() function
struct Gsymbol* is_present(char* name);


//this retrieves the type of the variable associated with it(TYPE_INT,TYPE_STRING etc)
int get_type(Gsymbol* entry);

#endif