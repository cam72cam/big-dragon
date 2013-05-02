#include "procedure_statement.h"
#include <stdlib.h>

tree_t	* make_procedure_statement(identifier_t * ident, expression_list_t * params) {
	procedure_statement_t	* node	= malloc(sizeof(procedure_statement_t));
	node->identifier			= ident;
	node->params				= params;
	return make_tree(node, PROCEDURE_STATEMENT_T);
}

void   print_procedure_statement(procedure_statement_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "PROCEDURE_STATEMENT:\n");
	print_identifier(node->identifier, spaces + SP_INDENT);
	print_expression_list(node->params, spaces + SP_INDENT);
}
