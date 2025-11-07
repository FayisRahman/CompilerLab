#include "class_table.h"

struct Classtable* class_table = NULL;
struct Classtable* class_table_tail = NULL;
struct Classtable* curr_class_table = NULL;
int Class_index = 0;



struct Classtable* CInstall(char *name,char *parent_class_name){

    Classtable* temp = malloc(sizeof(Classtable));
    temp->Name = strdup(name);
    Classtable* parent = CLookup(parent_class_name);
    temp->Parentptr = parent;
    temp->MemberField = NULL;
    temp->Vfuncptr = NULL;
    temp->Class_index = Class_index++;
    temp->Fieldcount = 0;      
    temp->Methodcount = 0;
    temp->next = NULL;

    if(!class_table){
        class_table = temp;
        class_table_tail = temp;
    }else{
        class_table_tail->next = temp;
        class_table_tail = temp;
    }

    return temp;
    
}

struct Classtable* CLookup(char *name){

    Classteable* temp = class_table;
    while(temp){
        if(strcmp(temp->Name,name) == 0){
            return temp;
        }
    }

    return NULL;

}


void Class_Finstall(struct Classtable *cptr, char *typename, char *name){

    TypeTable* type = typetable_lookup(typename);

    Classtable* ctype = CLookup(typename);

    if(!type && !ctype){
        printf("Error: Class_Finstall() => No type or class %s found\n",typename);
        exit(0);
    }

    FieldList* field = cptr->MemberField;

    while(field && field->next){
        field = field->next;
    }

    FieldList* temp = malloc(sizeof(FieldList));

    temp->Name = strdup(name);
    temp->Type = type;
    temp->Fieldindex = field != NULL ? field->Fieldindex + 1 : 0;
    temp->Ctype = ctype;
    temp->Next = NULL;

    if(!field){
        cptr->MemberField = temp;
    }else{
        field->Next = temp;
    }



}
void Class_Minstall(struct Classtable *cptr, char *name, struct Typetable *type, struct ParamList *Paramlist){

    Memberfunclist* funclist = cptr->Vfuncptr;

    while(funclist && funclist->next) funclist = funclist->next;

    Memberfunclist* temp = malloc(sizeof(Memberfunclist));

    temp->Name = strdup(name);
    temp->Type = type;
    temp->Paramlist = paramlist_deepcopy(Paramlist);

    temp->Funcposition = funclist != NULL ? funclist->Funcposition + 1 : 0;
    temp->Flable = flabel_count++;
    temp->Next = NULL;

    if(!funclist){
        cptr->Vfuncptr = temp;
    }else{
        funclist->Next = temp;
    }

    


}
struct Memberfunclist* Class_Mlookup(struct Classtable* Ctype,char* Name){


    Memberfunclist* funclist = cptr->Vfuncptr;

    while(funclist){
        if(strcmp(funclist->Name,Name) == 0) return funclist;
    }

    return NULL;
    
}
struct Fieldlist* Class_Flookup(struct Classtable* Ctype,char* Name){

    FieldList* field = Ctype->MemberField;

    while(field ){
        if(strcmp(field->Name,Name) == 0)return field;
    }

    return NULL;

}