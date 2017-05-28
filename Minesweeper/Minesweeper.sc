// struct def

struct cell {
	isBomb, neighborBombs, status // status - 0: closed, 1: revealed, 2: marked bomb
};

struct cursor {
	x, y
};


// helper func

seedIsValid(num) {
	return ((num <= @numMax) && (num >= @numMin) && (num % 2 == 1));
}

getNextRandom(min, max, seed) { // https://stackoverflow.com/questions/3062746/special-simple-random-number-generator
	*seed = (*seed ^ (*seed << 21));
	*seed = (*seed ^ (*seed >> 35));
	*seed = (*seed ^ (*seed << 4));
	return (*seed & (max - min)) + min; // take last few bits
}

getSeed() {
	if (@isStdGUI == 1) {
		puts_("Enter an ODD number between "); puti_(@numMin); puts_(" to "); puti_(@numMax); puts(" to generate the board: ");
	}
	geti(num);

	while (seedIsValid(num) == 0) {
		if (@isStdGUI == 1) {
			puts("Number invalid!");
			puts_("Enter an ODD number between "); puti_(@numMin); puts_(" to "); puti_(@numMax); puts(" to generate the board: ");
		} else {
			putc_('*'); putc_('x');
		}

		geti(num);
	}

	return num;
}


// I/O helper func

putBoard() {
	if (@isStdGUI == 0) {
		putc_('*'); putc_('b');
	}
	for (i = 0; i < @boardSize; i = i + 1;) {
		for (j = 0; j < @boardSize; j = j + 1;) {
			if (@isStdGUI == 1) {
				if (@c.x == j && @c.y == i) {
					putc_('*');
				} else if (@board[i][j].status == 2) {
					putc_('B');
				} else if (@board[i][j].status == 1) {
					puti_(@board[i][j].neighborBombs);
				} else {
					putc_('.');
				}
			} else {
				puti_(@board[i][j].isBomb); puti_(@board[i][j].neighborBombs); puti_(@board[i][j].status);
			}
		}
	}
}

putCmdInst() {
	if (@isStdGUI == 1) {
		puts("\t<i,j,k,l> to move up, left, down, right\n\t<r> to reveal\n\t<b> to mark bomb\n\t<u> to unmark bomb\n\t<q> to quit");
	}
}

putCursor() {
	if (@isStdGUI == 1) {
		putc_('('); puti_(@c.x); putc_(','); puti_(@c.y); putc(')');
	}
}


// game actions

moveCursor(command) {
	if (command == 'i') {
		@c.y = ((@c.y - 1) + @boardSize) % @boardSize;
	} else if (command == 'j') {
		@c.x = ((@c.x - 1) + @boardSize) % @boardSize;
	} else if (command == 'k') {
		@c.y = (@c.y + 1) % @boardSize;
	} else {
		@c.x = (@c.x + 1) % @boardSize;
	}
}

revealNeighbors(i, j) {
	for (k = -1; k <= 1; k = k + 1;) {
		for (l = -1; l <= 1; l = l + 1;) {
			if (i+k >= 0 && i+k < @boardSize && j+l >= 0 && j+l < @boardSize && @board[i+k][j+l].status != 1) {
				@board[i+k][j+l].status = 1;
				if (@board[i+k][j+l].neighborBombs == 0) {
					revealNeighbors(i+k, j+l);
				}
				@numOfRevealed = @numOfRevealed + 1;
			}
		}
	}
}

reveal() {
	@board[@c.y][@c.x].status = 1;
	if (@board[@c.y][@c.x].isBomb == 1) {
		@isEnd = 1;
	} else {
		if (@board[@c.y][@c.x].neighborBombs == 0) {
			revealNeighbors(@c.y, @c.x);
		}
		@numOfRevealed = @numOfRevealed + 1;
	}
}

markBomb() {
	if (@board[@c.y][@c.x].status == 0) {
		@board[@c.y][@c.x].status = 2;
		if (@board[@c.y][@c.x].isBomb == 1) {
			@numOfMatched = @numOfMatched + 1;
		}
	}
}

unmarkBomb() {
	if (@board[@c.y][@c.x].status == 2) {
		@board[@c.y][@c.x].status = 0;
		if (@board[@c.y][@c.x].isBomb == 1) {
			@numOfMatched = @numOfMatched - 1;
		}
	}
}


// game logic

init() {
	// init board
	for (i = 0; i < @boardSize; i = i + 1;) {
		for (j = 0; j < @boardSize; j = j + 1;) {
			@board[i][j].isBomb = 0;
			@board[i][j].neighborBombs = 0;
			@board[i][j].status = 0;
		}
	}

	// init cursor to middle of board
	@c.x = 3; @c.y = 3;

	// init other info
	@isEnd = 0;
	@numOfRevealed = 0;
	@numOfMatched = 0;
}

genRandomBoard(seed) {
	// generate random bombs
	max = @boardSize * @boardSize - 1;
	for (i = 0; i < @boardSize; i = i + 1;) {
		num = getNextRandom(0, max, &seed);
		
		x = num % @boardSize;
		y = num / @boardSize;
		
		if (@board[y][x].isBomb == 1) {
			i = i - 1; // repeated bomb, modify num & generate again
			num = num * 71;
		} else {
			@board[y][x].isBomb = 1;
		}
	}

	// get neighbor bomb info
	for (i = 0; i < @boardSize; i = i + 1;) {
		for (j = 0; j < @boardSize; j = j + 1;) {
			if (@board[i][j].isBomb == 1) {
				for (k = -1; k <= 1; k = k + 1;) {
					for (l = -1; l <= 1; l = l + 1;) {
						if (i+k >= 0 && i+k < @boardSize && j+l >= 0 && j+l < @boardSize) {
							@board[i+k][j+l].neighborBombs = @board[i+k][j+l].neighborBombs + 1;
						}
					}
				}
				@board[i][j].neighborBombs = @board[i][j].neighborBombs - 1;
			}
		}
	}
}

checkEndGame() {
	return (@numOfRevealed + @numOfMatched == @boardSize * @boardSize);
}

playerLose() {
	if (@isStdGUI == 1) {
		puts("Bomb! You lose.\n");
	} else {
		putc_('*'); putc('L');
	}
}

playerWin() {
	if (@isStdGUI == 1) {
		puts("Congratulations! You have sweeped all the mines. You are a hero!\n");
	} else {
		putc_('*'); putc_('W');
	}
}

start() {
	putBoard();
	putCmdInst();
	putCursor();

	while (1) {
		getc(command); 

		while (command == '\n' || command == ' ' || command == '\t') {
			getc(command); 
		}
		getc(nl);

		if (command == 'i' || command == 'j' || command == 'k' || command == 'l') {
			moveCursor(command);
			if (@isStdGUI == 0) {
				putc_('*'); putc_(command);
			}
		} else if (command == 'r') {
			reveal();
		} else if (command == 'b') {
			markBomb();
		} else if (command == 'u') {
			unmarkBomb();
		} else if (command == 'q') {
			if (@isStdGUI == 0) {
				putc_('*'); putc_('q');
			}
			return -1;
		} else {
			continue;
		}

		if (@isEnd == 0) {
			@isEnd = checkEndGame();
			if (@isEnd == 0) {
				if (@isStdGUI == 1) {
					putBoard();
					putCursor();
				} else {
					if (command != 'i' && command != 'j' && command != 'k' && command != 'l') {
						putBoard();
					}
				}
			} else {
				playerWin();
				putBoard();
				break;
			}
		} else {
			playerLose();
			putBoard();
			break;
		}
	}
	return 0;
}


// main

numMax = 99;
numMin = 1;
boardSize = 8;
isEnd = 0;
numOfRevealed = 0;
numOfMatched = 0;
isStdGUI = 0; // 1: stdin as game panel; 0: pipe to ncurses game window

<cell> board[8][8];
<cursor> c;

main() {
	init();

	if (@isStdGUI == 1) {
		puts("Start game!");
	} else {
		putc_('s');
	}

	genRandomBoard(getSeed());	
	status = start();

	if (status == -1) {
		if (@isStdGUI == 1) {
			puts("Have a nice day!");
		} else {
			putc_('q');
		};
		return 0;
	}

	if (@isStdGUI == 1) {
		puts("New game? <y/n>");
	}

	getc(newGame);
	while (newGame == '\n' || (newGame != 'y' && newGame != 'n')) {
		getc(newGame);
	}
	getc(nl);

	if (@isStdGUI == 0) {
		putc_('*'); putc_(newGame);
	}

	while (newGame == 'y') {
		init();
		genRandomBoard(getSeed());	
		status = start();

		if (status == -1) {
			break;
		}

		if (@isStdGUI == 1) {
			puts("New game? <y/n>");
		}

		getc(newGame);
		while (newGame == '\n' || (newGame != 'y' && newGame != 'n')) {
			getc(newGame); 
		}
		getc(nl);

		if (@isStdGUI == 0) {
			putc_('*'); putc_(newGame);
		}
	}

	if (@isStdGUI == 1) {
		puts("Have a nice day!");
	} else {
		putc_('q');
	};
}

main();


















