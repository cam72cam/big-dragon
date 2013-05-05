#include "integer.h"
#include <stdlib.h>

tree_t	* make_integer(int value) {
	integer_t	* node	= malloc(sizeof(integer_t));
	node->value			= value;
	return make_tree(node,  INTEGER_T);
}

void	  print_integer(integer_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "INTEGER: %d\n", node->value);
}

char	* gencode_integer(integer_t * node) {
	char * val = malloc(sizeof(20));
	sprintf(val, "$%d", node->value);
	return val;
}
