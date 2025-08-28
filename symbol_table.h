#ifndef SYMboL_TABLE_H
#define SYMboL_TABLE_H

typedef struct Gsymbol {
    char* name;       // name of the variable
    int type;         // type of the variable
    int size;         // size of the type of the variable
    int binding;      // stores the static memory address allocated to the variable
    struct Gsymbol *next;
}Gsymbol;

extern struct Gsymbol *top;
extern struct Gsymbol *tail;

extern int curr_stack_address;

// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise. 
struct Gsymbol *Lookup(char * name);

//adds a symbol to the symbol table
void add_symbol(Gsymbol *id, int type);

// Creates a symbol data.
struct Gsymbol *create_symbol_id(char *name, int size);  

//appends a symbol to the list
struct Gsymbol* append_symbol_id_list(Gsymbol *list,Gsymbol *id);

#endif