#include "subprogram_declarations.h"
#include <stdlib.h>

tree_t * make_subprogram_declarations(subprogram_declaration_t * declaration, subprogram_declarations_t * next) {
	subprogram_declarations_t	* node	= malloc(sizeof(subprogram_declarations_t));
	node->declaration					= declaration;
	node->next							= next;
	return make_tree(node, SUBPROGRAM_DECLARATIONS_T);
}

void   print_subprogram_declarations(subprogram_declarations_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "SUBPROGRAM_DECLARATIONS:\n");
	for(; node != NULL && node->declaration != NULL; node = node->next)
		print_subprogram_declaration(node->declaration, spaces + SP_INDENT);
}
