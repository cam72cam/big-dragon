#include <stdlib.h>
#include "statement.h"

tree_t* make_statement(tree_t * node) {
	statement_t * fnode = malloc(sizeof(statement_t));
	fnode->node = node;
	return make_tree(fnode, STATEMENT_T);
}
void	print_statement(statement_t * node, int spaces) {
	switch(node->node->type) {
		case ASSIGNMENT_T:
			print_assignment(ASSIGNMENT_N(node->node), spaces);
			break;
		case PROCEDURE_STATEMENT_T:
			print_procedure_statement(PROCEDURE_STATEMENT_N(node->node), spaces);
			break;
		case STATEMENT_LIST_T:
			print_statement_list(STATEMENT_LIST_N(node->node), spaces);
			break;
		case IF_T:
			print_if(IF_N(node->node), spaces + SP_INDENT);
			break;
		case WHILE_T:
			print_while(WHILE_N(node->node), spaces);
			break;
	}
}
