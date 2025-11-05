#ifndef TREE_VIZ_H
#define TREE_VIZ_H

#include "../AST.h"   // or the correct relative path to where tnode is defined

// Function declaration
void export_ast_to_graphviz(struct tnode* root, const char* filename);

#endif
