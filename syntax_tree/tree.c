#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include <execinfo.h>

void print_trace (void);

tree_t * make_tree(void * node, tree_types type) {
	tree_t * tree = malloc(sizeof(tree_t));
	tree->node = node;
	tree->type = type;
	return tree;
}

void tree_error(tree_t * given, tree_types expected) {
	fprintf(stderr, "\nIn tree.h: expected tree type %d, given %d\n", expected, given->type);
	print_trace();
	exit(-1);
}

void print_spaces(int spaces){
	int i;
	for(i = 0; i < spaces; i++)
		fprintf(stderr, " ");
}

//From : http://stackoverflow.com/questions/3151779
void print_trace (void)
{
	void *trace[16];
	char **messages = (char **)NULL;
	int i, trace_size = 0;

	trace_size = backtrace(trace, 16);
	/* overwrite sigaction with caller's address */
//	trace[1] = (void *)ctx.eip;
	messages = backtrace_symbols(trace, trace_size);
	/* skip first stack frame (points here) */
	printf("[bt] Execution path:\n");
	for (i=1; i<trace_size; ++i)
	{
		printf("[bt] #%d %s\n", i, messages[i]);

		char syscom[256];
		sprintf(syscom,"addr2line %p -e bigd", trace[i]); //last parameter is the name of this app
		system(syscom);
	}
}
