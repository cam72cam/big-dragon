#include "assignment.h"
#include <stdlib.h>
#include <string.h>

tree_t	* make_assignment(variable_t * variable, expression_t * expression) {
	assignment_t	* node	= malloc(sizeof(assignment_t));
	node->variable			= variable;
	node->expression		= expression;
	
	node->variable->ident = find_identifier_with_type(node->variable->ident->node->ident, typeof_expression(node->expression));
	return make_tree(node,  ASSIGNMENT_T);
}

void   print_assignment(assignment_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "ASSIGNMENT:\n");
	print_variable(node->variable, spaces + SP_INDENT);
	print_expression(node->expression, spaces + SP_INDENT);
}

void gencode_assignment(assignment_t * node) {
	char * tmp = gencode_expression(node->expression);
	
	fprintf(stderr, "push %%eax\n");
	fprintf(stderr, "movl %s, %%eax\n", tmp);
	fprintf(stderr, "movl %%eax, %s\n", node->variable->ident->address);
	
	fprintf(stderr, "pop %%eax\n");
}
