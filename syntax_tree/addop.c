#include <stdlib.h>
#include "addop.h"

tree_t	* make_addop(char * type) {
	addop_t * node = malloc(sizeof(addop_t));
	       if(strcmp("+", type)) {
		node->type = PLUS;
	} else if (strcmp("-", type)) {
		node->type = MINUS;
	} else if (strcmp("or", type)) {
		node->type = OR;
	}
	return make_tree(node, ADDOP_T);
}

void	* print_addop(addop_t * node, int spaces) {
	print_spaces(spaces);
	switch(node->type) {
		case PLUS:
			fprintf(stderr, "addop: PLUS");
			break;
		case MINUS:
			fprintf(stderr, "addop: MINUS");
			break;
		case OR:
			fprintf(stderr, "addop: OR");
			break;
	}
}