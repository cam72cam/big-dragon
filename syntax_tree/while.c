#include "while.h"
#include <stdlib.h>

tree_t	* make_while(expression_t * expression, statement_t * statement) {
	while_t	* node	= malloc(sizeof(while_t));
	node->expression		= expression;
	node->statement			= statement;
	return make_tree(node,  WHILE_T);
}

void * print_while(while_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "WHILE:\n");
	print_expression(node->expression, spaces + SP_INDENT);
	fprintf(stderr, "DO:\n");
	print_statement(node->statement, spaces + SP_INDENT);
}
