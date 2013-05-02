#include <stdlib.h>
#include "simple_expression.h"

tree_t	* make_simple_expression(simple_expression_t * left, addop_t * op, term_t * right) {
	simple_expression_t * node = malloc(sizeof(simple_expression_t));
	node->left	= left;
	node->op	= op;
	node->right	= right;
	return make_tree(node, SIMPLE_EXPRESSION_T);
}
void	* print_simple_expression(simple_expression_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "SIMPLE EXPRESSION: ");
	if(node->left != NULL)
		print_simple_expression(node->left, spaces + SP_INDENT);
	if(node->op != NULL)
		print_addop(node->op, spaces + SP_INDENT);
	print_term(node->right, spaces + SP_INDENT);
}
