#ifndef TREE_VISUALIZATION_H
#define TREE_VISUALIZATION_H

#include "AST.h"
#include "param_list.h"
#include "dim_node.h"
#include "global_symbol_table.h"

void tree_visual_print_tree_structure(tnode *root, char *prefix, int is_last, int is_root,int skip_middle);
void tree_visual_printTree(tnode *root);
void tree_visual_print_tree_compact(tnode *root, int depth);
void tree_visual_printTreeCompact(tnode *root);



#endif