#include "program.h"
#include <stdlib.h>

tree_t	* make_program (identifier_t * name, identifier_list_t * args, declarations_t * declarations, subprogram_declarations_t * subprogram_declarations, statement_list_t * statements) {
	program_t * node 				= malloc(sizeof(program_t));
	node->name 						= name;
	node->args 						= args;
	node->declarations 				= declarations;
	node->subprogram_declarations 	= subprogram_declarations;
	node->statements 				= statements;
	return make_tree(node, PROGRAM_T);
}

void   print_program(program_t * node, int spaces) {
	print_spaces(spaces);
	fprintf(stderr, "PROGRAM:\n");
	print_identifier(node->name, spaces + SP_INDENT);
	print_identifier_list(node->args, spaces + SP_INDENT);
	print_declarations(node->declarations, spaces + SP_INDENT);
	print_subprogram_declarations(node->subprogram_declarations, spaces + SP_INDENT);
	print_statement_list(node->statements, spaces + SP_INDENT);
}

void gencode_program(program_t * node) {
	fprintf(stderr, "%s:\n", node->name->ident);
	fprintf(stderr, "push %%ebp\n");
	
	gencode_declarations(node->declarations);
	
	gencode_statement_list(node->statements);
	
	fprintf(stderr, "pop %%ebp\n\n");
}
