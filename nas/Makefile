nas: lex.yy.c nas.tab.c
	gcc -o $@ $^
lex.yy.c: nas.l
	flex $^
nas.tab.c: nas.y
	bison -d $^
clean:
	rm nas.tab.* lex.yy.c nas
.PHONY: clean
