#include "if.h"
#include <stdlib.h>

tree_t	* make_if(expression_t * expression, statement_t * statement) {
	if_t	* node	= malloc(sizeof(if_t));
	node->expression		= expression;
	node->statement			= statement;
	return make_tree(node,  IF_T);
}

void * print_if(if_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "IF:\n");
	print_expression(node->expression, spaces + SP_INDENT);
	print_spaces(spaces);
	fprintf(stderr, "THEN:\n");
	print_statement(node->statement, spaces + SP_INDENT);
}
