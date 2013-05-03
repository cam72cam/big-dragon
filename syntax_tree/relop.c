#include <stdlib.h>
#include <string.h>
#include "relop.h"

tree_t	* make_relop(char * type) {
	relop_t * node = malloc(sizeof(relop_t));
		   if (0 == strcmp("=", type)) {
		node->type = EQ;
	} else if (0 == strcmp("<>", type)) {
		node->type = NE;
	} else if (0 == strcmp("<", type)) {
		node->type = LT;
	} else if (0 == strcmp(">", type)) {
		node->type = GT;
	} else if (0 == strcmp("<=", type)) {
		node->type = LT_EQ;
	} else if (0 == strcmp(">=", type)) {
		node->type = GT_EQ;
	}
	return make_tree(node, RELOP_T);
}

void	  print_relop(relop_t * node, int spaces) {
	print_spaces(spaces);
	switch(node->type) {
		case EQ:
			fprintf(stderr, "RELOP: EQUAL");
			break;
		case NE:
			fprintf(stderr, "RELOP: NOT EQUAL");
			break;
		case LT:
			fprintf(stderr, "RELOP: LESS THAN");
			break;
		case GT:
			fprintf(stderr, "RELOP: GREATER THAN");
			break;
		case LT_EQ:
			fprintf(stderr, "RELOP: LESS THAN OR EQUAL");
			break;
		case GT_EQ:
			fprintf(stderr, "RELOP: GREATER THAN OR EQUAL");
			break;
	}
	fprintf(stderr, "\n");
}
