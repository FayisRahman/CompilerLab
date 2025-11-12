#include "class_table.h"
#include <stdio.h>

struct Classtable* class_table = NULL;
struct Classtable* class_table_tail = NULL;
struct Classtable* curr_class_table = NULL;
int Class_index = 0;



struct Classtable* CInstall(char *name,char *parent_class_name){

    struct Classtable* temp = malloc(sizeof(Classtable));
    temp->Name = strdup(name);
    Classtable* parent = CLookup(parent_class_name);
    temp->Parentptr = parent;
    temp->Memberfield = NULL;
    temp->Vfuncptr = NULL;
    temp->Class_index = Class_index++;
    temp->Fieldcount = 0;      
    temp->Methodcount = 0;
    temp->Next = NULL;

    if(!class_table){
        class_table = temp;
        class_table_tail = temp;
    }else{
        class_table_tail->Next = temp;
        class_table_tail = temp;
    }

    return temp;
    
}

struct Classtable* CLookup(char *name){

    Classtable* temp = class_table;
    if(name == NULL) return NULL;
    while(temp){
        if(strcmp(temp->Name,name) == 0){
            return temp;
        }
        temp = temp->Next;
    }

    return NULL;

}

void CprintEntry(Classtable* entry){
    if(!entry){
        printf("NULL Classtable Entry\n");
        return;
    }
    printf("Class Name: %s\n",entry->Name);
    if(entry->Parentptr){
        printf("Parent Class Name: %s\n",entry->Parentptr->Name);
    }else{
        printf("Parent Class Name: NULL\n");
    }
    printf("Field Count: %d\n",entry->Fieldcount);
    printf("Method Count: %d\n",entry->Methodcount);
}

void CPrintTable(){
    Classtable* temp = class_table;
    printf("-----------------------------------------------------------\n");
    printf("Class Name\tParent Name\tField Count\tMethod Count\n");
    printf("-----------------------------------------------------------\n");
    while(temp){
        printf("%s\t\t",temp->Name);
        if(temp->Parentptr){
            printf("%s\t\t",temp->Parentptr->Name);
        }else{
            printf("NULL\t\t");
        }
        printf("%d\t\t%d\n",temp->Fieldcount,temp->Methodcount);
        temp = temp->Next;
    }
    printf("-----------------------------------------------------------\n");
}


void Class_Finstall(struct Classtable *cptr, char *typename, char *name){

    TypeTable* type = typetable_lookup(typename);

    Classtable* ctype = CLookup(typename);

    if(!type && !ctype){
        printf("Error: Class_Finstall() => No type or class %s found\n",typename);
        exit(0);
    }

    Fieldlist* field = cptr->Memberfield;

    while(field && field->Next){
        field = field->Next;
    }

    Fieldlist* temp = malloc(sizeof(Fieldlist));

    temp->Name = strdup(name);
    temp->Type = type;
    temp->Fieldindex = field != NULL ? field->Fieldindex + 1 : 0;
    temp->Ctype = ctype;
    temp->Next = NULL;
    cptr->Fieldcount++;

    if(!field){
        cptr->Memberfield = temp;
    }else{
        field->Next = temp;
    }



}
void Class_Minstall(struct Classtable *cptr, char *name, struct TypeTable *type, struct ParamList *Paramlist){

    Memberfunclist* funclist = cptr->Vfuncptr;

    while(funclist && funclist->Next) funclist = funclist->Next;

    Memberfunclist* temp = malloc(sizeof(Memberfunclist));

    temp->Name = strdup(name);
    temp->Type = type;
    temp->Paramlist = Paramlist;

    temp->Funcposition = funclist != NULL ? funclist->Funcposition + 1 : 0;
    temp->Flabel = flabel_count++;
    temp->Next = NULL;
    cptr->Methodcount++;

    if(!funclist){
        cptr->Vfuncptr = temp;
    }else{
        funclist->Next = temp;
    }
}
struct Memberfunclist* Class_Mlookup(struct Classtable* Ctype,char* Name){


    Memberfunclist* funclist = Ctype->Vfuncptr;

    while(funclist){
        if(strcmp(funclist->Name,Name) == 0) return funclist;
        funclist = funclist->Next;
    }

    return NULL;
    
}
struct Fieldlist* Class_Flookup(struct Classtable* Ctype,char* Name){

    Fieldlist* field = Ctype->Memberfield;

    while(field ){
        if(strcmp(field->Name,Name) == 0)return field;
        field = field->Next;
    }

    return NULL;

}

struct Fieldlist* fieldlist_create(char* Name, struct Classtable* ctype, struct TypeTable* type){
    struct Fieldlist* temp = malloc(sizeof(Fieldlist));

    temp->Name = strdup(Name);
    temp->Type = type;
    temp->Ctype = ctype;
    temp->Next = NULL;

    return temp;

}