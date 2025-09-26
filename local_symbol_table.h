#ifndef Local_lSYMBOL_TABLE_H
#define Local_lSYMBOL_TABLE_H

#include "AST.h"
#include "dim_node.h"

#define MAX_LOCAL_TABLES 100

typedef struct Lsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable
//    int varType;      // this is to know if its variable,array or pointer
    int size;         // size of the type of the variable
    int binding;    // stores the static memory address allocated to the variable
    struct Lsymbol *next;
//    struct DimNode* dimlist;
}Lsymbol;

extern int curr_addr_offset;
extern int curr_funct;
extern struct Lsymbol* local_tables[MAX_LOCAL_TABLES];

// Returns a pointer to the lsymbol table entry for the variable, returns NULL otherwise and throws and error if not found
struct Lsymbol *find_lsymbol(char * name);

//adds a lsymbol to the lsymbol table
struct Lsymbol* add_lsymbol(Lsymbol *id, int type);

// Creates a lsymbol data.
struct Lsymbol *create_lsymbol_id(char *name, int size);  

//appends a lsymbol to the list
struct Lsymbol* append_lsymbol_id_list(Lsymbol *list,Lsymbol *id);

//prints the lsymbol table
void print_lsymbol_table();


//prints the data containing inside the list
void print_lsymbol_list(Lsymbol* t);

//this simply checks if its present or not unlike the find_lsymbol() function
struct Lsymbol* is_lpresent(char* name);


void check_lpresent(Lsymbol* main,char* name);

//this retrieves the type of the variable associated with it(TYPE_INT,TYPE_STRING etc)
int get_ltype(Lsymbol* entry);

#endif