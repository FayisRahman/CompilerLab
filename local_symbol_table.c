#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local_symbol_table.h"

struct Lsymbol* local_tables[MAX_LOCAL_TABLES];
int curr_addr_offset = 0;
int curr_funct = 0;


Lsymbol* add_lsymbol(Lsymbol *id, int type) {
    if(is_gpresent(id->name)!=NULL){
        printf("Error: Variable %s already Declared\n", id->name);
        exit(0);
    }

    if(curr_stack_address > 1024){
        printf("Error: Memory Overflow\n");
        exit(0);
    }

    Lsymbol* t = local_tables[curr_funct];
    if(!t){
        local_tables[curr_funct] = id;
    }else{
        while(t->next){
            t=t->next;
        }
        t->next = id;
    }
}

struct Lsymbol* is_lpresent(char* name){
    Lsymbol *tail = local_tables[curr_funct];
    while(tail){
        if(strcmp(tail->name, name) == 0){
            return tail;
        }
        tail = tail->next;
    }
}

void check_lpresent(Lsymbol* main,char* name){
    Lsymbol *tail = main;
    while(tail){
        if(strcmp(tail->name, name) == 0){
            printf("Error: Variable already declared in the scope\n");
            exit(0);
        }
        tail = tail->next;
    }
}

struct Lsymbol *find_lsymbol(char * name){
    if (!name) {
        fprintf(stderr, "find_lsymbol called with NULL name!\n");
        exit(1);
    }
    Lsymbol *tail = local_tables[curr_funct];
    while(tail){
        if(strcmp(tail->name, name) == 0){
            return tail;
        }
        tail = tail->next;
    }
    printf("Error: Variable %s Not Declared\n", name);
    exit(0);
}

struct Lsymbol* create_lsymbol_id(char *name, int size){
    printf("create_lsymbol_id: name=%s size=%d\n", name ? name : "NULL", size);
    if (!name) {
        fprintf(stderr, "ERROR: create_lsymbol_id got NULL name!\n");
        exit(1);
    }
    Lsymbol *temp = malloc(sizeof(struct Lsymbol));
    temp->name = strdup(name);
    temp->type = TYPE_NULL;
    temp->size = size;
    temp->next = NULL;
    temp->binding = 0;
    return temp;
}

Lsymbol* append_lsymbol_id_list(Lsymbol *list, Lsymbol *id){
    if (list == NULL) return id;
    Lsymbol *temp = list;
    while (temp->next) temp = temp->next;
    temp->next = id;
    return list;
}

int get_ltype(Lsymbol* entry){
    if(!entry)return TYPE_NULL;
    return entry->type;
}

void print_lsymbol_table() {
    struct Lsymbol *temp = local_tables[curr_funct];

    if (temp == NULL) {
        printf("lSymbol Table is empty.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s %-10s\n", "Name","varType" , "Type", "Size", "Binding");
    printf("-----------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%-20s %-10d %-10d %-10d\n", 
               temp->name,
               temp->type, 
               temp->size, 
               temp->binding);
        temp = temp->next;
    }
    printf("-----------------------------------------------------------\n\n");
}

void print_lsymbol_list(Lsymbol* t) {
    struct Lsymbol *temp = t;

    if (temp == NULL) {
        printf("lSymbol Table is empty.\n");
        return;
    }

    printf("\n%-20s %-10s %-10s %-10s %-10s\n", "Name","varType","Type", "Size", "Binding");
    printf("-----------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%-20s %-10d %-10d %-10d\n", 
               temp->name, 
               temp->type, 
               temp->size, 
               temp->binding);
        temp = temp->next;
    }
    printf("-----------------------------------------------------------\n\n");
}