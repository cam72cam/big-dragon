#include "procedure_statement.h"
#include <stdlib.h>
#include <string.h>

tree_t	* make_procedure_statement(identifier_t * ident, expression_list_t * params) {
	int given, expected;
	char * buffer;
	procedure_statement_t	* node	= malloc(sizeof(procedure_statement_t));
	node->identifier			= find_identifier(ident->ident);
	node->params				= params;
	
	given = expression_list_length(params);
	expected = scope_parameters_length(node->identifier->scope);
	if(given != expected) {
		buffer = malloc(sizeof(char) * 1000);
		sprintf(buffer, "function %s expected %d parameters, given %d", ident->ident, expected, given);
		yyerror(buffer);
		free(buffer);
	}
	return make_tree(node, PROCEDURE_STATEMENT_T);
}

void   print_procedure_statement(procedure_statement_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "PROCEDURE_STATEMENT:\n");
	print_identifier(node->identifier->node, spaces + SP_INDENT);
	print_expression_list(node->params, spaces + SP_INDENT);
}
