#include "variable.h"
#include <stdlib.h>

tree_t	* make_variable(identifier_t * ident, expression_t * expression) {
	variable_t	* node	= malloc(sizeof(variable_t));
	node->ident			= ident;
	node->expression	= expression;
	return make_tree(node,  VARIABLE_T);
}

void print_variable(variable_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "VARIABLE:\n");
	print_identifier(node->ident, spaces + SP_INDENT);
	if(node->expression != NULL) {
		print_expression(node->expression, spaces + SP_INDENT);
	}
}
