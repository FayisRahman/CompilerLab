#ifndef CLASS_TABLE_H
#define CLASS_TABLE_H

struct Classtable {
    char *Name;                           //name of the class
    struct Fieldlist *Memberfield;        //pointer to Fieldlist
    struct Memberfunclist *Vfuncptr;      //pointer to Memberfunclist
    struct Classtable *Parentptr;         //pointer to the parent's class table
    int Class_index;                      //position of the class in the virtual function table
    int Fieldcount;                       //count of fields
    int Methodcount;                      //count of methods
    struct Classtable *Next;              //pointer to next class table entry
};

struct Fieldlist{
    char *Name;                             //name of the field
    int Fieldindex;                         //position of the field
    struct Typetable *Type;                 //pointer to typetable
    struct Classtable *Ctype;               //pointer to the class containing the field
    struct Fieldlist *Next;                 //pointer to next fieldlist entry
};


struct Memberfunclist {
    char *Name;                         //name of the member function in the class
    struct Typetable *Type;             //pointer to typetable
    struct ParamList *Paramlist;        //pointer to the head of the formal parameter list
    int Funcposition;                   //position of the function in the class table
    int Flabel;                         //A label for identifying the starting address of the function's code in the memory
    struct Memberfunclist *Next;        //pointer to next Memberfunclist entry
};

extern struct ClassTable* class_table;
extern struct ClassTable* curr_class_table;


struct Classtable* CInstall(char *name,char *parent_class_name);
struct Classtable* CLookup(char *name);
void Class_Finstall(struct Classtable *cptr, char *typename, char *name);
void Class_Minstall(struct Classtable *cptr, char *name, struct Typetable *type, struct ParamList *Paramlist);
struct Memberfunclist* Class_Mlookup(struct Classtable* Ctype,char* Name);
struct Fieldlist* Class_Flookup(struct Classtable* Ctype,char* Name);

#endif