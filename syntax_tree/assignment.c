#include "assignment.h"
#include <stdlib.h>

tree_t	* make_assignment(variable_t * variable, expression_t * expression) {
	assignment_t	* node	= malloc(sizeof(assignment_t));
	node->variable			= variable;
	node->expression		= expression;
	return make_tree(node,  ASSIGNMENT_T);
}

void * print_assignment(assignment_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "ASSIGNMENT:\n");
	print_variable(node->variable, spaces + SP_INDENT);
	print_expression(node->expression, spaces + SP_INDENT);
}
