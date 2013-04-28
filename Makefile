main: lex yacc
	cc -d -g lex.yy.c y.tab.c tree.c -o bigd -DYYSTYPE=tree_t*
lex: bigd.l
	lex -d bigd.l
yacc: bigd.y
	yacc -d -y bigd.y
clean:
	rm lex.yy.c bigd  y.tab.c  y.tab.h
