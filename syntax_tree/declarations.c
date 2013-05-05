#include <stdlib.h>
#include "declarations.h"

tree_t	* make_declarations(identifier_list_t * vars, type_t * type, declarations_t * next) {
	declarations_t * node = malloc(sizeof(declarations_t));
	node->vars = vars;
	node->type = type;
	node->next = next;
	
	set_identifier_list_type(vars, type);
	return make_tree(node, DECLARATIONS_T);
}

void	  scope_add_declarations(declarations_t * list) {
	identifier_list_t * idents;
	if(list != NULL) {
		for(idents = list->vars; idents != NULL; idents = idents->next) {
			register_identifier(idents->identifier, false);
		}
		scope_add_declarations(list->next);
	}
}

void	  print_declarations(declarations_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "DECLARATIONS:\n");
	for(; node->next != NULL; node = node->next) {
		print_identifier_list(node->vars, spaces + SP_INDENT);
		print_type(node->type, spaces + SP_INDENT);
	}
}

int		  declarations_length(declarations_t * node) {
	return node != NULL ? 1 + declarations_length(node->next) : 0;
}


void	  gencode_declarations(declarations_t * node) {
	fprintf(stderr, "movl %%esp, %%ebp\n");
	fprintf(stderr, "subl $0x%x, %%esp\n", declarations_length(node) * 4);
}
