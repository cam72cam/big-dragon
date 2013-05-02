#include <stdlib.h>
#include "factor.h"

tree_t* make_factor(tree_t * node) {
	factor_t * fnode = malloc(sizeof(factor_t));
	fnode->not = false;
	return make_tree(fnode, FACTOR_T);
}
void	print_factor(factor_t * node, int spaces) {
	//TODO
}
