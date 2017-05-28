RUN := ../nas/nas
COMPILE := ../c6c

minesweeper: Minesweeper.sc
	$(COMPILE) Minesweeper.sc > Minesweeper.as

run:
	script -q /dev/null $(RUN) Minesweeper.as | ./MinesweeperWin

run-std: 
	$(RUN) Minesweeper.as

MinesweeperWin: MinesweeperWin.c
	gcc $< -lncurses -o $@

test: test.c
	gcc $< -o $@

test-win:
	script -q /dev/null ./test | ./MinesweeperWin

.PHONY: run run-std test-win