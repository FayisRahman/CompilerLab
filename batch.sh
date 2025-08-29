#!/bin/bash

lex exptree.l
yacc -d exptree.y
gcc -g lex.yy.c y.tab.c reghandling.c AST.c evaluator.c symbol_table.c -o sol
