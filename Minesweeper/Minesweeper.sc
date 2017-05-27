struct cell {
	isBomb, neighborBombs, isOpened
};

seedIsValid(num) {
	return ((num <= @numMax) && (num >= @numMin) && (num % 2 == 1));
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

getNextRandom(min, max, seed) { // https://stackoverflow.com/questions/3062746/special-simple-random-number-generator
	*seed = (*seed ^ (*seed << 21));
	*seed = (*seed ^ (*seed >> 35));
	*seed = (*seed ^ (*seed << 4));
	return (*seed & (max - min)) + min;
}

genRandomBoard(size, seed) {
	max = size * size - 1;
	for (i = 0; i < size; i = i + 1;) {
		num = getNextRandom(0, max, &seed);
		puti(num);
		
		x = num % size;
		y = num / size;
		
		if (@board[y][x].isBomb == 1) {
			i = i - 1; // repeated bomb, modify num & generate again
			num = num * 71;
		} else {
			@board[y][x].isBomb = 1;
		}
	}

	for (i = 0; i < size; i = i + 1;) {
		for (j = 0; j < size; j = j + 1;) {
			puti_(@board[i][j].isBomb);
		}
		putc('');
	}
}

initBoard() {
	for (i = 0; i < 8; i = i + 1;) {
		for (j = 0; j < 8; j = j + 1;) {
			@board[i][j].isBomb = 0;
			@board[i][j].neighborBombs = 0;
			@board[i][j].isOpened = 0;
		}
	}
}

numMax = 99;
numMin = 1;
<cell> board[8][8];

main() {
	initBoard();
	genRandomBoard(8, getSeed());	
}

main();


















