#!/bin/bash

lex exptree.l
yacc -v -d exptree.y -Wconflicts-sr
gcc -g -O0 lex.yy.c y.tab.c reghandling.c AST.c evaluator.c dim_node.c global_symbol_table.c param_list.c local_symbol_table.c tree_visualization.c type_table.c ./TreeViz/tree_viz.c class_table.c -o sol.out
