#include "statement_list.h"
#include <stdlib.h>

tree_t	* make_statement_list(statement_t * statement, statement_list_t * next) {
	statement_list_t	* node	= malloc(sizeof(statement_list_t));
	node->statement				= statement;
	node->next					= next;
	return make_tree(node, STATEMENT_LIST_T);
}

void   print_statement_list(statement_list_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "STATEMENT_LIST:\n");
	for(; node != NULL && node->statement != NULL; node = node->next)
		print_statement(node->statement, spaces + SP_INDENT);
}

void gencode_statement_list(statement_list_t * node) {
	for(; node != NULL && node->statement != NULL; node = node->next)
		gencode_statement(node->statement);
}
