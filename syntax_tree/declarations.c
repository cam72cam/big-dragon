#include <stdlib.h>
#include "declarations.h"

tree_t	* make_declarations(identifier_list_t * vars, type_t * type, declarations_t * next) {
	declarations_t * node = malloc(sizeof(declarations_t));
	node->vars = vars;
	node->type = type;
	node->next = next;
	return make_tree(node, DECLARATIONS_T);
}
void	  print_declarations(declarations_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "DECLARATIONS:\n");
	for(; node->next != NULL; node = node->next) {
		print_identifier_list(node->vars, spaces + SP_INDENT);
		print_type(node->type, spaces + SP_INDENT);
	}
}
