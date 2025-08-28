#!/bin/bash

lex exptree.l
yacc -d exptree.y
gcc lex.yy.c y.tab.c reghandling.c AST.c evaluator.c -o sol
