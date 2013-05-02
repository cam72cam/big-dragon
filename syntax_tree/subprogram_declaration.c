#include "subprogram_declaration.h"
#include <stdlib.h>

tree_t	* make_subprogram_declaration(subprogram_head_t	* head,	declarations_t * declarations, statement_list_t	* statements) {
	subprogram_declaration_t	* node	= malloc(sizeof(subprogram_declaration_t));
	node->head							= head;
	node->declarations					= declarations;
	node->statements					= statements;
	return make_tree(node,  SUBPROGRAM_DECLARATION_T);
}

void * print_subprogram_declaration(subprogram_declaration_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "SUBPROGRAM DECLARATION:\n");
	print_subprogram_head(node->head, spaces + SP_INDENT);
	print_declarations(node->declarations, spaces + SP_INDENT);
	print_statement_list(node->statements, spaces + SP_INDENT);
}
