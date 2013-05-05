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

char * gencode_procedure_statement(procedure_statement_t * node) {
	int i;
	int param_num;
	char * str;
	expression_list_t * expr;
	
	param_num = scope_parameters_length(node->identifier->scope);
//	for(i = 0; i < param_num; i++) {
	i = 0;
	for(expr = node->params; expr != NULL && expr->expression != NULL; expr = expr->next) {
		str = gencode_expression(expr->expression);
		fprintf(stderr, "push %%eax\n");
		fprintf(stderr, "movl %s, %%eax\n", str);
		fprintf(stderr, "movl %%eax, %d(%%esp)\n", 4*i);
		fprintf(stderr, "pop %%eax\n");
		i++;
	}
	fprintf(stderr, "call %s\n", node->identifier->node->ident);
	return "%eax";
}
