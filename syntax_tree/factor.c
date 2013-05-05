#include <stdlib.h>
#include "factor.h"

tree_t* make_factor(tree_t * node) {
	factor_t * fnode = malloc(sizeof(factor_t));
	identifier_t * ident;
	if(node->type == IDENTIFIER_T) {
		ident = IDENTIFIER_N(node);
		fnode->scoped_ident = find_identifier(ident->ident);
	} else {
		fnode->node = node;
	}
	fnode->not = false;
	return make_tree(fnode, FACTOR_T);
}

void	print_factor(factor_t * node, int spaces) {
	if(node->node == NULL) {
		print_identifier(node->scoped_ident->node, spaces);
	} else {
		switch(node->node->type) {
			case PROCEDURE_STATEMENT_T:
				print_procedure_statement(PROCEDURE_STATEMENT_N(node->node), spaces);
				break;
			case INTEGER_T:
				print_integer(INTEGER_N(node->node), spaces);
				break;
			case EXPRESSION_T:
				print_expression(EXPRESSION_N(node->node), spaces);
				break;
			case FACTOR_T:
				if(node->not) {
					print_spaces(spaces);
					fprintf(stderr, "NOT\n");
					print_factor(FACTOR_N(node->node), spaces + SP_INDENT);
				}
				break;
		}
	}
}
int 	  typeof_factor(factor_t * node) {
	if(node->node == NULL) {
		return node->scoped_ident->node->type->type;
	} else {
		switch(node->node->type) {
			case PROCEDURE_STATEMENT_T:
				return PROCEDURE_STATEMENT_N(node->node)->identifier->node->type->type;
			case INTEGER_T:
				return INTEGER_TYPE;
			case EXPRESSION_T:
				return typeof_expression(EXPRESSION_N(node->node));
				break;
			case FACTOR_T:
				return typeof_factor(FACTOR_N(node->node));
		}
	}
	return -1;
}

char *	gencode_factor(factor_t * node) {
	char * tmp;
	static int c = 0;
	int lc = c;
	c++;
	if(node->node == NULL) {
		return node->scoped_ident->address;
	} else {
		switch(node->node->type) {
			case PROCEDURE_STATEMENT_T:
				return gencode_procedure_statement(PROCEDURE_STATEMENT_N(node->node));
				break;
			case INTEGER_T:
				return gencode_integer(INTEGER_N(node->node));
				break;
			case EXPRESSION_T:
				return gencode_expression(EXPRESSION_N(node->node));
				break;
			case FACTOR_T:
				if(node->not) {
					tmp = gencode_factor(FACTOR_N(node->node));
					fprintf(stderr, "cmpl $1, %s\n", tmp);
					fprintf(stderr, "movl $1, %s\n", tmp);
					fprintf(stderr, "jne .ft%d\n", lc); // if was true, set false;
					fprintf(stderr, "movl $0, %s\n", tmp);
					fprintf(stderr, ".ft%d\n", lc);
					return tmp;
				}
				break;
		}
	}
}
