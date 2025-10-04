#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global_symbol_table.h"

int curr_stack_address = 4095;
struct Gsymbol *top = NULL;
struct Gsymbol *tail = NULL;
int flabel_count = 0;
int is_global_vars_declared = 0;


void add_gsymbol(Gsymbol *id, int type) {
    if(is_gpresent(id->name)!=NULL){
        printf("Error: Variable %s already Declared\n", id->name);
    exit(0);
    }
    id->type = type;
    id->binding = curr_stack_address + 1;
    curr_stack_address += id->size;

    if(curr_stack_address > 5119){
        printf("Error: Memory Overflow\n");
        exit(0);
    }

    if (!top) {
        top = id;
        tail = id;
        tail->next = NULL;
    } else {
        tail->next = id;
        tail = id;
        tail->next = NULL;
    }
}

struct Gsymbol* is_gpresent(char* name){
    Gsymbol *tail = top;
    
    while(tail){
        if(!name){
            printf("heyy");
        }else if(strcmp(tail->name, name) == 0){
            return tail;
        }
        tail = tail->next;
    }
}


struct Gsymbol *find_gsymbol(char * name){
    if (!name) {
        fprintf(stderr, "find_gsymbol called with NULL name!\n");
        exit(1);
    }
    Gsymbol *tail = top;
    while(tail){
        if(strcmp(tail->name, name) == 0){
            return tail;
        }
        tail = tail->next;
    }
    // printf("Error: Variable %s Not Declared\n", name);
    // exit(0);
}

struct Gsymbol* create_gsymbol_id(char *name, int size){
    printf("create_gsymbol_id: name=%s size=%d\n", name ? name : "NULL", size);
    if (!name) {
        fprintf(stderr, "ERROR: create_gsymbol_id got NULL name!\n");
        exit(1);
    }
    Gsymbol *temp = malloc(sizeof(struct Gsymbol));
    temp->name = strdup(name);
    temp->type = TYPE_NULL;
    temp->size = size;
    temp->next = NULL;
    temp->binding = 0;
    return temp;
}

Gsymbol* append_gsymbol_id_list(Gsymbol *list, Gsymbol *id){
    if (list == NULL) return id;
    Gsymbol *temp = list;
    while (temp->next) temp = temp->next;
    temp->next = id;
    return list;
}

int get_gtype(Gsymbol* entry){
    if(!entry)return TYPE_NULL;
    return entry->type;
}

void print_gsymbol_table() {
    struct Gsymbol *temp = top;

    if (temp == NULL) {
        printf("Symbol Table is empty.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s %-10s\n", "Name","varType" , "Type", "Size", "Binding");
    printf("-----------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%-20s %-10d %-10d %-10d %-10d\n", 
               temp->name, 
               temp->varType,
               temp->type, 
               temp->size, 
               temp->binding);
        temp = temp->next;
    }
    printf("-----------------------------------------------------------\n\n");
}

void print_gsymbol_list(Gsymbol* t) {
    struct Gsymbol *temp = t;

    if (temp == NULL) {
        printf("Symbol Table is empty.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s %-10s\n", "Name","varType","Type", "Size", "Binding");
    printf("-----------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%-20s %-10d %-10d %-10d %-10d\n", 
               temp->name, 
               temp->varType,
               temp->type, 
               temp->size, 
               temp->binding);
        temp = temp->next;
    }
    printf("-----------------------------------------------------------\n\n");
}