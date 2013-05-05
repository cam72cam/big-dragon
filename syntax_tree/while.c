#include "while.h"
#include <stdlib.h>

tree_t	* make_while(expression_t * expression, statement_t * statement) {
	while_t	* node	= malloc(sizeof(while_t));
	node->expression		= expression;
	node->statement			= statement;
	return make_tree(node,  WHILE_T);
}

void   print_while(while_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "WHILE:\n");
	print_expression(node->expression, spaces + SP_INDENT);
	fprintf(stderr, "DO:\n");
	print_statement(node->statement, spaces + SP_INDENT);
}

void gencode_while(while_t * node) {
	static int cnt;
	int lcnt = cnt;
	cnt++;
	char * tmp;
	fprintf(stderr, ".while%d:\n", lcnt);
	
	gencode_statement(node->statement);
	
	tmp = gencode_expression(node->expression);
	fprintf(stderr, "cmpl $0x1, %s\n", tmp); //if the expression is true
	fprintf(stderr, "je .while%d\n", lcnt); // go back to the top and do it again
	
}
