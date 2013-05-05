#include "expression_list.h"
#include <stdlib.h>

tree_t * make_expression_list(expression_t * ident, expression_list_t * next) {
	expression_list_t	* node	= malloc(sizeof(expression_list_t));
	node->expression			= ident;
	node->next					= next;
	return make_tree(node, EXPRESSION_LIST_T);
}

int expression_list_length(expression_list_t * node) {
	return (node == NULL ? 0 : 1 + expression_list_length(node->next));
}

void   print_expression_list(expression_list_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "EXPR_LIST:\n");
	for(; node != NULL; node = node->next)
		print_expression(node->expression, spaces + SP_INDENT);
	
}
