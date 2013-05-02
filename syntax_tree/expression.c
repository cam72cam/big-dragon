#include <stdlib.h>
#include "expression.h"

tree_t	* make_expression(simple_expression_t * left, relop_t * op, simple_expression_t * right) {
	expression_t * node = malloc(sizeof(expression_t));
	node->left	= left;
	node->op	= op;
	node->right	= right;
	return make_tree(node, EXPRESSION_T);
}
void	  print_expression(expression_t * node, int spaces){
	print_spaces(spaces);
	fprintf(stderr, "EXPRESSION: \n");
	print_simple_expression(node->left, spaces + SP_INDENT);
	if(node->op != NULL)
		print_relop(node->op, spaces + SP_INDENT);
	if(node->right != NULL)
		print_simple_expression(node->right, spaces + SP_INDENT);
}
