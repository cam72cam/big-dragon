#include <stdlib.h>
#include "term.h"

tree_t	* make_term(term_t * left, mulop_t * op, factor_t * right) {
	term_t * node = malloc(sizeof(term_t));
	node->left	= left;
	node->op	= op;
	node->right	= right;
	return make_tree(node, TERM_T);
}
void	* print_term(term_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "TERM: ");
	if(node->left != NULL)
		print_term(node->left, spaces + SP_INDENT);
	if(node->right != NULL)
		print_mulop(node->op, spaces + SP_INDENT);
	print_factor(node->right, spaces + SP_INDENT);
}