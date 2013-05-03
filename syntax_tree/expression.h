#ifndef EXPRESSION_H
#define EXPRESSION_H

typedef struct expression_s expression_t;

#include "tree.h"

typedef struct expression_s {
	simple_expression_t * right;
	relop_t	* op;
	simple_expression_t * left;
} expression_t;

tree_t	* make_expression(simple_expression_t * left, relop_t * op, simple_expression_t * right);
void	  print_expression(expression_t * node, int spaces);
int		  typeof_expression(expression_t * node);

#endif
