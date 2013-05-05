#include <stdlib.h>
#include "simple_expression.h"

tree_t	* make_simple_expression(simple_expression_t * left, addop_t * op, term_t * right) {
	simple_expression_t * node = malloc(sizeof(simple_expression_t));
	node->left	= left;
	node->op	= op;
	node->right	= right;
	return make_tree(node, SIMPLE_EXPRESSION_T);
}
void	  print_simple_expression(simple_expression_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "SIMPLE EXPRESSION: \n");
	if(node->left != NULL)
		print_simple_expression(node->left, spaces + SP_INDENT);
	if(node->op != NULL)
		print_addop(node->op, spaces + SP_INDENT);
	print_term(node->right, spaces + SP_INDENT);
}

int 	  typeof_simple_expression(simple_expression_t * node) {
	if(node->left == NULL) {
		return typeof_term(node->right);
	}
	return INTEGER_TYPE; //TODO SAME FIX AS MULTOP
}

char	* gencode_simple_expression(simple_expression_t * node) {
	char * right;
	char * left;
	char * result;
	if(node->left == NULL) {
		return gencode_term(node->right);
	}
	fprintf(stderr, "push %%ebx\n");
	fprintf(stderr, "push %%ecx\n");
	right = gencode_term(node->right);
	fprintf(stderr, "movl %s, %%ebx\n", right);
	left = gencode_simple_expression(node->left);
	fprintf(stderr, "movl %s, %%ecx\n", left);
	
	result = gencode_addop(node->op, "%ebx", "%ecx");
	
	fprintf(stderr, "pop %%ecx\n");
	fprintf(stderr, "pop %%ebx\n");
	return result;
}
