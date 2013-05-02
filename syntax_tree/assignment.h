#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

typedef struct assignment_s assignment_t;

#include "tree.h"

typedef struct assignment_s {
	variable_t		* variable;
	expression_t	* expression;
} assignment_t;

tree_t	* make_assignment(variable_t * variable, expression_t * expression);
void	* print_assignment(assignment_t * node, int spaces);
#endif
