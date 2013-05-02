#ifndef EXPRESSION_LIST_H
#define EXPRESSION_LIST_H

typedef struct expression_list_s expression_list_t;

#include "tree.h"
#include "expression.h"

typedef struct expression_list_s {
	expression_list_t	* next;
	expression_t		* expression;
} expression_list_t;

tree_t	* make_expression_list(expression_t * ident, expression_list_t * next);
void	  print_expression_list(expression_list_t * node, int spaces);
#endif
