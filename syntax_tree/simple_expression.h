#ifndef SIMPLE_EXPRESSION_H
#define SIMPLE_EXPRESSION_H

typedef struct simple_expression_s simple_expression_t;

#include "tree.h"

typedef struct simple_expression_s {
	simple_expression_t * left;
	addop_t	* op;
	term_t * right;
} simple_expression_t;

tree_t	* make_simple_expression(simple_expression_t * left, addop_t * op, term_t * right);
void	  print_simple_expression(simple_expression_t * node, int spaces);
int 	  typeof_simple_expression(simple_expression_t * node);
#endif
