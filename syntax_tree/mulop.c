#include <stdlib.h>
#include <string.h>
#include "mulop.h"

tree_t	* make_mulop(char * type) {
	mulop_t * node = malloc(sizeof(mulop_t));
	       if(strcmp("*", type)) {
		node->type = MULT;
	} else if (strcmp("/", type) || strcmp("div", type)) {
		node->type = DIV;
	} else if (strcmp("and", type)) {
		node->type = AND;
	} else if (strcmp("mod", type)) {
		node->type = MOD;
	}
	return make_tree(node, MULOP_T);
}

void	  print_mulop(mulop_t * node, int spaces) {
	print_spaces(spaces);
	switch(node->type) {
		case MULT:
			fprintf(stderr, "mulop: MULT");
			break;
		case DIV:
			fprintf(stderr, "mulop: DIV");
			break;
		case AND:
			fprintf(stderr, "mulop: AND");
			break;
		case MOD:
			fprintf(stderr, "mulop: MOD");
			break;
	}
}
