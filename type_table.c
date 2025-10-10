#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type_table.h"

TypeTable* type_table = NULL;
TypeTable* curr_type = NULL;
TypeTable* curr_function_type = NULL;
DataType curr_funct_return_type = TYPE_FUNCT;


void typetable_create(const char* name, const DataType type, const ParamList* plist) {

    if(typetable_lookup(name) != NULL){
        printf("Error: tuple with the name %s is already defined\n", name);
        exit(0);
    }

    TypeTable* temp = malloc(sizeof(TypeTable));

    temp->name = strdup(name);
    temp->type = type;
    if(plist) temp->plist = paramlist_deepcopy(plist);
    if(plist) temp->size = get_paramlist_length((ParamList*) plist);
    else temp->size = 1;
    temp->next = NULL;

    TypeTable* head = type_table;
    while(head && head->next){
        head = head->next;
    }
    if(!head){
        type_table = temp;
    }else{
        head->next = temp;
    }

    printf("type_table_create: name: %s\n",name);
    paramlist_display((ParamList*)plist);
}

TypeTable* typetable_lookup(const char* name){

    TypeTable* head = type_table;
    while(head){
        if(strcmp(head->name, name) == 0){
            return head;
        }
        head = head->next;
    }

}
void typetable_destroy() {

    TypeTable* head = type_table;
    TypeTable* next = head;

    while(head){
        next = head->next;
        if(head->plist){
            paramlist_destroy(head->plist);
        }
        free(head->name);
        free(head);
        head->next = NULL;
        head = next;
    }

    type_table = NULL;

}

void typetable_print(const TypeTable* head) {
    const TypeTable* temp = head;

    printf("\n========================== TYPE TABLE =================================\n");
    printf("%-15s %-10s %-10s %-30s\n", "Name", "TypeID", "Size", "Fields");
    printf("-----------------------------------------------------------------------\n");

    while (temp) {
        // Print type details
        printf("%-15s %-10s %-10d ", 
               temp->name, 
               type_to_string(temp->type), 
               temp->size);

        // Print fields if present
        if (temp->plist) {
            ParamList* p = temp->plist;
            while (p) {
                printf("[%s: %s]", 
                       (p->type == TYPE_INT ? "INT" :
                        p->type == TYPE_STRING ? "STRING" :
                        p->type == TYPE_BOOL ? "BOOL" :
                        p->type == TYPE_TUPLE ? "TUPLE" : "UNKNOWN"),
                       p->name);
                if (p->next) printf(", ");
                p = p->next;
            }
        } else {
            printf("(no fields)");
        }

        printf("\n");
        temp = temp->next;
    }

    printf("=======================================================================\n\n");
}

DataType typetable_lookup_id_type(const TypeTable* entry, const char* name){

    ParamList* plist = entry->plist;

    while(plist){
        if(strcmp(plist->name,name) == 0)return plist->type;
        plist = plist->next;
    }

    printf("Error: No %s present in the tuple definition\n",name);


}

int typetable_lookup_id_offset(const TypeTable* entry, const char* name){

    ParamList* plist = entry->plist;
    int count = 0;

    while(plist){
        if(strcmp(plist->name,name) == 0)return count;
        count++;
        plist = plist->next;
    }

    printf("Error: No %s present in the tuple definition\n",name);

}




