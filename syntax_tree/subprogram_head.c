#include "subprogram_head.h"
#include <stdlib.h>

tree_t	* make_subprogram_head(identifier_t * ident, parameter_list_t * params, type_t * type) {
	subprogram_head_t	* node	= malloc(sizeof(subprogram_head_t));
	node->ident					= ident;
	node->params				= params;
	node->type					= type;
	return make_tree(node,  SUBPROGRAM_HEAD_T);
}

void * print_subprogram_head(subprogram_head_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "SUBPROGRAM HEAD:\n");
	print_identifier(node->ident, spaces + SP_INDENT);
	print_parameter_list(node->params, spaces + SP_INDENT);
	print_type(node->type, spaces + SP_INDENT);
}
