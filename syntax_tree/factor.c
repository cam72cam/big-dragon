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
		if(node->scoped_ident == NULL) {
			fprintf(stderr, "SHIT");
		}
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
