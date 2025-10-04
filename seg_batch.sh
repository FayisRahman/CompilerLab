#!/bin/bash

lex exptree.l
yacc -d exptree.y
gcc -g -O0 -fsanitize=address,undefined \
    lex.yy.c y.tab.c reghandling.c AST.c evaluator.c dim_node.c \
    global_symbol_table.c param_list.c local_symbol_table.c tree_visualization.c \
    -o sol.out

