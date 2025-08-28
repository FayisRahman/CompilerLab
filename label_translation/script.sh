#!/bin/bash

lex label.l
gcc lex.yy.c label_table.c -o translator -ll
./translator