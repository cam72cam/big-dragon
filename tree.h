#ifndef TREE_H
#define TREE_H

typedef struct tree_s {
	int type;
	union {
		int ival;	/* NUM */
		char* sval;
	} attribute;
	struct tree_s *left, *right;
}
tree_t;


tree_t *make_tree( int type, tree_t *left, tree_t *right );
void	print_tree( tree_t *t, int spaces );

#endif

