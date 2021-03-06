#include "if.h"
#include <stdlib.h>

tree_t	* make_if(expression_t * expression, statement_t * statement, else_t * elsey) {
	if_t	* node	= malloc(sizeof(if_t));
	node->expression		= expression;
	node->statement			= statement;
	node->elsey				= elsey;
	return make_tree(node,  IF_T);
}

void   print_if(if_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "IF:\n");
	print_expression(node->expression, spaces + SP_INDENT);
	print_spaces(spaces);
	fprintf(stderr, "THEN:\n");
	print_statement(node->statement, spaces + SP_INDENT);
	print_else(node->elsey, spaces + SP_INDENT);
}

void gencode_if(if_t * node) {
	static int ifc = 0;
	int tmp = ifc;
	ifc++;
	char * ifres;
	ifres = gencode_expression(node->expression);
	fprintf(stderr, "cmpl $0x1, %s\n", ifres);
	fprintf(stderr, "je .ifeq%d\n", tmp);
	fprintf(stderr, "jne .ifneq%d\n", tmp);
	
	fprintf(stderr, ".ifeq%d:\n", tmp);
	gencode_statement(node->statement);
	fprintf(stderr, "jmp .ifend%d\n", tmp);
	
	fprintf(stderr, ".ifneq%d:\n", tmp);
	gencode_else(node->elsey);
	fprintf(stderr, "jmp .ifend%d\n", tmp);
	
	fprintf(stderr, ".ifend%d:\n", tmp);
}
