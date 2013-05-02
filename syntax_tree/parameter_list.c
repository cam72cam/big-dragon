#include "parameter_list.h"
#include <stdlib.h>

tree_t	* make_parameter_list(identifier_t * ident, type_t * type, parameter_list_t * next) {
	parameter_list_t	* node	= malloc(sizeof(parameter_list_t));
	node->ident					= ident;
	node->type					= type;
	node->next					= next;
	return make_tree(node, PARAMETER_LIST_T);
}

void * print_parameter_list(parameter_list_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "PARAMETER_LIST:\n");
	for(; node != NULL; node = node->next) {
		print_identifier(node->ident, spaces + SP_INDENT);
		print_type(node->type, spaces + SP_INDENT);
	}
}
