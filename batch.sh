#!/bin/bash

lex exptree.l
yacc -d exptree.y
gcc lex.yy.c y.tab.c reghandling.c AST.c evaluator.c dim_node.c global_symbol_table.c param_list.c local_symbol_table.c -o sol.out
