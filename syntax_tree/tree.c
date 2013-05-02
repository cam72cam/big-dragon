#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

tree_t * make_tree(void * node, tree_types type) {
	tree_t * tree = malloc(sizeof(tree_t));
	tree->node = node;
	tree->type = type;
	return tree;
}

void tree_error(tree_t * given, tree_types expected) {
	fprintf(stderr, "\nIn tree.h: expected tree type %d, given %d\n", expected, given->type);
	exit(-1);
}

void print_spaces(int spaces){
	int i;
	for(i = 0; i < spaces; i++)
		fprintf(stderr, " ");
}
