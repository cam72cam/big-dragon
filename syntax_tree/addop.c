#include <stdlib.h>
#include <string.h>
#include "addop.h"

tree_t	* make_addop(char * type) {
	addop_t * node = malloc(sizeof(addop_t));
	       if (0 == strcmp("+", type)) {
		node->type = PLUS;
	} else if (0 == strcmp("-", type)) {
		node->type = MINUS;
	} else if (0 == strcmp("or", type)) {
		node->type = OR;
	}
	return make_tree(node, ADDOP_T);
}

void	print_addop(addop_t * node, int spaces) {
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

char * gencode_addop(addop_t * node, char * left, char * right) {
	switch(node->type) {
		case PLUS:
			fprintf(stderr, "addl %s, %s\n", left, right);
			break;
		case MINUS:
			fprintf(stderr, "subl %s, %s\n", left, right);
			break;
		case OR:
			fprintf(stderr, "or %s, %s\n", left, right);
			break;
	}
}
