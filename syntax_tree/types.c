#include <stdlib.h>
#include "types.h"

tree_t	* make_type(int type) {
	type_t * node = malloc(sizeof(type_t));
	node->type = type;
	return make_tree(node, TYPE_T);
}
void	  print_type(type_t * node, int spaces) {
	print_spaces(spaces);
	switch(node->type) {
		case INTEGER_TYPE:
			fprintf(stderr, "TYPE: INTEGER\n");
			break;
		case REAL_TYPE:
			fprintf(stderr, "TYPE: REAL\n");
			break;
	}
}
