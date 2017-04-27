run: 
	./nas/nas $(P).as

run-test:
	./nas/nas ./test/$(P).as

compile:
	./c6c $(P).sc > $(P).as

compile-test:
	./c6c ./test/$(P).sc > ./test/$(P).as

c6c: lex.yy.c y.tab.c strmap.c c6c.c
	gcc -o $@ $^

lex.yy.c: c6.l
	flex $^

y.tab.c: c6.y
	bison -y -d $^

nas:
	$(MAKE) -C nas nas

cleannas:
	$(MAKE) -C nas clean

clean:
	rm lex.yy.c y.tab.* c6c

.PHONY: run run-test compile compile-test nas clean cleannas