#include <stdlib.h>
#include "term.h"

tree_t	* make_term(term_t * left, mulop_t * op, factor_t * right) {
	term_t * node = malloc(sizeof(term_t));
	node->left	= left;
	node->op	= op;
	node->right	= right;
	return make_tree(node, TERM_T);
}
void	  print_term(term_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "TERM: \n");
	if(node->left != NULL)
		print_term(node->left, spaces + SP_INDENT);
	if(node->op != NULL)
		print_mulop(node->op, spaces + SP_INDENT);
	print_factor(node->right, spaces + SP_INDENT);
}

int 	  typeof_term(term_t * node) {
	if(node->left  == NULL) {
		return typeof_factor(node->right);
	}
	
	if(typeof_mulop(node->op) == REAL_TYPE) {
		return REAL_TYPE;
	} else if(typeof_mulop(node->op) == -1) { //MULT can be either
		if(typeof_term(node->left) == REAL_TYPE || typeof_factor(node->right) == REAL_TYPE) {
			return REAL_TYPE;
		}
	}
	return  INTEGER_TYPE;
}
char * gencode_term(term_t * node) {
	char * right;
	char * left;
	char * result;
	
	if(node->left == NULL) {
		return gencode_factor(node->right);
	}
	fprintf(stderr, "push %%ebx\n");
	fprintf(stderr, "push %%ecx\n");
	right = gencode_factor(node->right);
	fprintf(stderr, "movl %s %%ebx\n", right);
	left = gencode_term(node->left);
	fprintf(stderr, "movl %s %%ecx\n", left);
	fprintf(stderr, "test %%ebx, %%ecx\n");
	fprintf(stderr, "pop %%ecx\n");
	fprintf(stderr, "pop %%ebx\n");
	return "";
}
