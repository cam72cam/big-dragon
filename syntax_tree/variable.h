#ifndef VARIABLE_H
#define VARIABLE_H

typedef struct variable_s variable_t;

#include "tree.h"
#include "../scope.h"

typedef struct variable_s {
	scope_ident_t	* ident;
	expression_t	* expression;
} variable_t;

tree_t	* make_variable(identifier_t * ident, expression_t * expression);
void	  print_variable(variable_t * node, int spaces);
#endif
