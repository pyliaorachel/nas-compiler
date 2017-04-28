RUN := ./nas/nas
COMPILE := ./c6c

TEST_FILES := $(basename $(wildcard ./test/*.sc))

run: 
	$(RUN) $(P).as

run-test:
	$(RUN) ./test/$(P).as

run-all-tests: 
	for file in $(TEST_FILES); do 			\
		echo "==========$$file=========="; 	\
		$(RUN) $$file.as; 					\
	done

compile:
	$(COMPILE) $(P).sc > $(P).as

compile-test:
	$(COMPILE) ./test/$(P).sc > ./test/$(P).as

compile-all-tests:
	for file in $(TEST_FILES); do 			\
		$(COMPILE) $$file.sc > $$file.as; 	\
	done

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

cleantest:
	rm ./test/*.as

clean:
	rm lex.yy.c y.tab.* c6c

.PHONY: run run-test run-all-tests compile compile-test compile-all-tests $(TEST_FILES) nas clean cleannas cleantest