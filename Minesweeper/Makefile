RUN := ../nas/nas
COMPILE := ../c6c

minesweeper:
	$(COMPILE) Minesweeper.sc > Minesweeper.as

run: 
	$(RUN) Minesweeper.as

MinesweeperWin: Minesweeper.c
	gcc $< -lncurses -o $@

test: test.c
	gcc $< -o $@

test-win:
	script -q /dev/null ./test | ./MinesweeperWin

.PHONY: run test-win