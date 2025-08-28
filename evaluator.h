#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "AST.h"
#include <stdbool.h>

void codeIntrepret(struct tnode *t);

int arithemetic_expression_eval(struct tnode* root);
void assignment_expression_eval(struct tnode* root);
bool boolean_expression_eval(struct tnode* root);

#endif