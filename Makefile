RUN := ./nas/nas
COMPILE := ./c6c

run: 
	$(RUN) $(P).as

run-test:
ifeq ($(O), 1)
	$(RUN) ./test-$(F)/$(P).as > ./test-$(F)/$(P).out
else
	$(RUN) ./test-$(F)/$(P).as
endif

run-all-tests: 
	for file in $(basename $(wildcard ./test-$(F)/*.as)); do \
		echo "==========$$file=========="; 	\
			if [ "$(O)" = "1" ]; then \
					$(RUN) $$file.as > $$file.out; \
			else \
					$(RUN) $$file.as; \
			fi \
	done

compile:
	$(COMPILE) $(P).sc > $(P).as

compile-test:
	$(COMPILE) ./test-$(F)/$(P).sc > ./test-$(F)/$(P).as

compile-all-tests:
	for file in $(basename $(wildcard ./test-$(F)/*.sc)); do \
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

clean:
	rm lex.yy.c y.tab.* c6c
	
cleannas:
	$(MAKE) -C nas clean

cleantest:
	rm ./test/*.as

.PHONY: run run-test run-all-tests compile compile-test compile-all-tests $(TEST_FILES) nas clean cleannas cleantest