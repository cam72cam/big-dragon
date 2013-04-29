#include "program.h"
#include <stdlib.h>

tree_t * make_program(identifier_t * name) {
	program_t * node 	= malloc(sizeof(program_t));
	node->name = name;
	return make_tree(node, PROGRAM_T);
}
