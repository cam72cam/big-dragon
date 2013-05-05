#include "scope.h"
#include <stdlib.h>
#include <string.h>

void push_scope(char * name) {
	fprintf(stderr, "PUSH %s\n", name);
	scope_t * tmp;
	if(top_scope == NULL) {
		top_scope = malloc(sizeof(scope_t));
		top_scope->down = NULL;
		current_scope = top_scope;
	} else {
		register_identifier(IDENTIFIER_N(make_identifier(name)), false);
		tmp = current_scope;
		current_scope = malloc(sizeof(scope_t));
		current_scope->down = tmp;
		find_identifier(name)->scope = current_scope;
	}
	current_scope->size = 200;
	current_scope->length = 0;
	current_scope->name = malloc(sizeof(char) * (strlen(name)  +1));
	strcpy(current_scope->name, name);
	current_scope->list = malloc(sizeof(scope_ident_t)*(current_scope->size +1));
}

void pop_scope() {
	fprintf(stderr, "POP %s\n", current_scope->name);
	current_scope = current_scope->down;
}

void register_identifier(identifier_t * node, bool param) {
	current_scope->list[current_scope->length].node = node;
	current_scope->list[current_scope->length].param = param;
	current_scope->length++;
	//TODO DYNAMICALLY EXTEND
}
scope_ident_t * find_identifier_with_type(char * ident, int type) {
	int i;
	int tmp_type;
	scope_t * curr;
	char * str;
	for(curr = current_scope; curr != NULL; curr = curr->down) {
		for(i = 0; i < curr->length; i++) {
			str = curr->list[i].node->ident;
			if(curr->list[i].node->type == NULL) {
				tmp_type = 0;
			} else {
				tmp_type = curr->list[i].node->type->type;
			}
			if(0 == strcmp(ident, str) && (type == tmp_type || type == -2)) {
				return &curr->list[i];
			}
		}
	}
	str = malloc(sizeof(char) * 1000);
	sprintf(str, "identifier %s of type %d does not exist\n", ident, type);
	yyerror(str);
	return NULL;
}

scope_ident_t * find_identifier(char * ident) {
	return find_identifier_with_type(ident, -2);
}

int	scope_parameters_length(scope_t * scope) {
	int res = 0;
	int i;
	if(scope != NULL) {
		for(i = 0; i < scope->length; i++) {
			if(scope->list[i].param)
				res++;
		}
		return res;
	} else {
		return -1;
	}
}

void print_scope() {
	
}
