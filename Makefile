SHELL   = /bin/bash

SYN_TREE_SRC	= tree.c identifier.c identifier_list.c program.c
SYN_TREE_OBJ	= $(SYN_TREE_SRC:%.c=syntax_tree/%.o)
SYNTAX_TREE		= $(SYN_TREE_SRC:%.c=syntax_tree/%)

main: lex yacc syn_tree
	cc $(SYN_TREE_OBJ) lex.yy.c y.tab.c -o bigd -DYYSTYPE=tree_t*

syn_tree:
	cd syntax_tree && cc -c $(SYN_TREE_SRC)

lex: bigd.l
	lex -d bigd.l
yacc: bigd.y
	yacc -d -y bigd.y
clean:
	rm $(SYN_TREE_OBJ)
	rm lex.yy.c y.tab.c y.tab.h bigd  

