#include "identifier_list.h"
#include <stdlib.h>

tree_t * make_identifier_list(identifier_t * ident, identifier_list_t * next) {
	identifier_list_t	* node	= malloc(sizeof(identifier_list_t));
	node->identifier			= ident;
	node->next					= next;
	return make_tree(node, IDENTIFIER_LIST_T);
}

void * print_identifier_list(identifier_list_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "IDENT_LIST:\n");
	for(; node != NULL; node = node->next)
		print_identifier(node->identifier, spaces + SP_INDENT);
	
}
