#ifndef TYPE_TABLE_H
#define TYPE_TABLE_H

#include "param_list.h"
#include "AST.h"
#include "exptree.h"

#define MAX_MEMBER_FIELDS 8

struct ParamList;

/*
 * TypeTable:
 *  - Holds user-defined and primitive type definitions.
 *  - For tuples (user-defined types), 'plist' describes its fields.
 */

typedef struct TypeTable {
    char* name;
    DataType type;
    int size;
    struct ParamList* plist;
    struct TypeTable* next;
}TypeTable;

extern TypeTable* type_table;
extern TypeTable* curr_type;
extern TypeTable* curr_function_type;
extern DataType curr_funct_return_type;

void typetable_create(const char* name, const DataType type, const struct ParamList* plist);
TypeTable* typetable_lookup(const char* name);
void typetable_destroy();
void typetable_print(const TypeTable* head);
DataType typetable_lookup_id_type(const TypeTable* entry, const char* name);
int typetable_lookup_id_offset(const TypeTable* entry, const char* name);
void typetable_append_plist(const char* name, struct ParamList* plist);
TypeTable* typetable_lookup_id_typetable(const TypeTable* entry, const char* name);
#endif