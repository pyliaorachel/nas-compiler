struct cell {
	isBomb, neighborBombs, status // status - 0: closed, 1: revealed, 2: marked bomb
};

struct cursor {
	x, y
};

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
	puts_("Enter an ODD number between "); puti_(@numMin); puts_(" to "); puti_(@numMax); puts(" to generate the board: ");
	geti(num);

	while (seedIsValid(num) == 0) {
		puts("Number invalid!");
		puts_("Enter an ODD number between "); puti_(@numMin); puts_(" to "); puti_(@numMax); puts(" to generate the board: ");
		geti(num);
	}

	return num;
}

genRandomBoard(size, seed) {
	// generate random bombs
	max = size * size - 1;
	for (i = 0; i < size; i = i + 1;) {
		num = getNextRandom(0, max, &seed);
		
		x = num % size;
		y = num / size;
		
		if (@board[y][x].isBomb == 1) {
			i = i - 1; // repeated bomb, modify num & generate again
			num = num * 71;
		} else {
			@board[y][x].isBomb = 1;
		}
	}

	// get neighbor bomb info
	for (i = 0; i < size; i = i + 1;) {
		for (j = 0; j < size; j = j + 1;) {
			if (@board[i][j].isBomb == 1) {
				for (k = -1; k <= 1; k = k + 1;) {
					for (l = -1; l <= 1; l = l + 1;) {
						if (i+k >= 0 && i+k < size && j+l >= 0 && j+l < size) {
							@board[i+k][j+l].neighborBombs = @board[i+k][j+l].neighborBombs + 1;
						}
					}
				}
				@board[i][j].neighborBombs = @board[i][j].neighborBombs - 1;
			}
		}
	}
}

init() {
	// init board
	for (i = 0; i < 8; i = i + 1;) {
		for (j = 0; j < 8; j = j + 1;) {
			@board[i][j].isBomb = 0;
			@board[i][j].neighborBombs = 0;
			@board[i][j].status = 0;
		}
	}
	// init cursor to middle of board
	@c.x = 3; @c.y = 3;
}

putBoard() {
	for (i = 0; i < size; i = i + 1;) {
		for (j = 0; j < size; j = j + 1;) {
			if (@board[i][j].status == 2) {
				putc_('B');
			} else if (@board[i][j].status == 1) {
				puti_(@board[i][j].neighborBombs);
			} else {
				putc_('_');
			}
		}
		putc('');
	}
}

putCmdInst() {
	puts("\t<i,j,k,l> to move up, left, down, right\n\t<r> to reveal\n\t<b> to mark bomb\n\t<u> to unmark bomb\n\t<q> to quit");
}

putCursor() {
	putc_('('); puti_(@c.x); putc_(','); puti_(@c.y); putc(')');
}

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

reveal() {
	@board[@c.y][@c.x].status = 1;
}

markBomb() {
	@board[@c.y][@c.x].status = 2;
}

unmarkBomb() {
	@board[@c.y][@c.x].status = 0;
}

start() {
	puts("Start game!");
	putBoard();
	putCmdInst();
	putCursor();

	while (1) {
		getc(command); getc(nl);

		if (command == 'i' || command == 'j' || command == 'k' || command == 'l') {
			moveCursor(command);
		} else if (command == 'r') {
			reveal();
		} else if (command == 'b') {
			markBomb();
		} else if (command == 'u') {
			unmarkBomb();
		} else if (command == 'q') {
			break;
		}

		putBoard();
		putCursor();
	}
}

numMax = 99;
numMin = 1;
boardSize = 8;
<cell> board[8][8];
<cursor> c;

main() {
	init();
	genRandomBoard(8, getSeed());	
	start();
}

main();


















