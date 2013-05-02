#include <stdlib.h>
#include "else.h"

tree_t * make_else(tree_t * node){
	else_t * enode = malloc(sizeof(enode));
	enode->node = node;
	return make_tree(enode, ELSE_T);
}
void	 print_else(else_t * node, int spaces){
	print_spaces(spaces);
	fprintf(stderr, "ELSE:\n");
	switch(node->node->type) {
		case IF_T:
			print_if(IF_N(node->node), spaces);
			break;
		case STATEMENT_T:
			print_statement(STATEMENT_N(node->node), spaces);
			break;
	}
}
