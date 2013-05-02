#include "program.h"
#include <stdlib.h>

tree_t * make_program(identifier_t * name) {
	program_t * node 	= malloc(sizeof(program_t));
	node->name = name;
	return make_tree(node, PROGRAM_T);
}

void * print_program(program_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "PROGRAM:\n");
	print_identifier(node->name, spaces + SP_INDENT);
}
