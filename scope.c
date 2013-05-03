#include "scope.h"
#include <stdlib.h>
#include <string.h>

void add_scope(char * name) {
	if(top_scope == NULL) {
		top_scope = malloc(sizeof(scope_t));
		top_scope->up = NULL;
		top_scope->down = NULL;
		current_scope = top_scope;
	} else {
		current_scope->up = malloc(sizeof(scope_t));
		current_scope->up->down = current_scope;
		current_scope = current_scope->up;
		current_scope->up = NULL;
	}
	current_scope->size = 200;
	current_scope->length = 0;
	current_scope->name = malloc(sizeof(char) * (strlen(name)  +1));
	strcpy(current_scope->name, name);
	current_scope->list = malloc(sizeof(scope_ident_t)*(current_scope->size +1));
}
void register_identifier(tree_t * node) {
	current_scope->list[current_scope->length].node = node;
	current_scope->length++;
	//TODO DYNAMICALLY EXTEND
}
scope_ident_t * find_identifier(char * ident) {
	int i;
	scope_t * curr;
	char * str;
	
	subprogram_declaration_t 	* tmp_fn;
	identifier_t 				* tmp_ident;
	
	for(curr = current_scope; curr != NULL; curr = curr->down) {
		for(i = 0; i < curr->length; i++) {
			switch(curr->list[i].node->type) {
				case SUBPROGRAM_DECLARATION_T:
					tmp_fn = SUBPROGRAM_DECLARATION_N(curr->list[i].node);
					str = tmp_fn->head->ident->ident;
					break;
				case IDENTIFIER_T:
					tmp_ident = IDENTIFIER_N(curr->list[i].node);
					str = tmp_ident->ident;
					break;
			}
			fprintf(stderr, "CURR IDENT %s %s\n", curr->name, str);
			if(0 == strcmp(ident, str)) {
				//TODO MEMCPY
				fprintf(stderr, "SCOPE: %s | %s = %s\n", curr->name, str, ident);
				return &curr->list[i];
			}
		}
	}
	fprintf(stderr, "COULD NOT FIND IDENTIFIER %s\n", ident);
	return NULL;
}

void print_scope() {
	
}
