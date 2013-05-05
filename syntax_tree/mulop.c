#include <stdlib.h>
#include <string.h>
#include "mulop.h"

tree_t	* make_mulop(char * type) {
	mulop_t * node = malloc(sizeof(mulop_t));
	       if(0 == strcmp("*", type)) {
		node->type = MULT;
	} else if (0 == strcmp("/", type) || 0 == strcmp("div", type)) {
		node->type = DIV;
	} else if (0 == strcmp("and", type)) {
		node->type = AND;
	} else if (0 == strcmp("mod", type)) {
		node->type = MOD;
	}
	return make_tree(node, MULOP_T);
}

void	  print_mulop(mulop_t * node, int spaces) {
	print_spaces(spaces);
	switch(node->type) {
		case MULT:
			fprintf(stderr, "mulop: MULT");
			break;
		case DIV:
			fprintf(stderr, "mulop: DIV");
			break;
		case AND:
			fprintf(stderr, "mulop: AND");
			break;
		case MOD:
			fprintf(stderr, "mulop: MOD");
			break;
	}
	fprintf(stderr, "\n");
}

int typeof_mulop(mulop_t* node) {
	switch(node->type) {
		case DIV:
			return REAL_TYPE;
		case MULT:
			return -1;
		case AND:
		case MOD:
			return INTEGER_TYPE;
	}
	return -100;
}


char  	* gencode_mulop(mulop_t * node, char * left, char * right) {
	switch(node->type) {
		case MULT:
			fprintf(stderr, "imull %s, %s\n", left, right);
			break;
		case DIV:
			fprintf(stderr, "push %%edx\n");
			fprintf(stderr, "push %%eax\n");
			fprintf(stderr, "xorl %%edx, %%edx\n");
			fprintf(stderr, "movl %s, %%eax\n", left);
			fprintf(stderr, "idivl %s\n", right); //eax is value
			fprintf(stderr, "movl %%eax, %s\n", right);
			fprintf(stderr, "pop %%eax\n");
			fprintf(stderr, "pop %%edx\n");
			break;
		case AND:
			fprintf(stderr, "mulop: AND TODO\n");
			break;
		case MOD:
			fprintf(stderr, "push %%edx\n");
			fprintf(stderr, "push %%eax\n");
			fprintf(stderr, "xorl %%edx, %%edx\n");
			fprintf(stderr, "movl %s, %%eax\n", left);
			fprintf(stderr, "idivl %s\n", right);
			fprintf(stderr, "movl %%edx, %s\n", right); //edx is remainder
			fprintf(stderr, "pop %%eax\n");
			fprintf(stderr, "pop %%edx\n");
			break;
	}
	return right;
}
