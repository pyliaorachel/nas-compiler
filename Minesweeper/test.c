#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int nextcommand() {
	int ch, next;

	ch = getchar();
	next = getchar();
	while(next != '\n') {
		if (next != ' ' && next != '\t') ch = next;
		next = getchar();
	}

	return ch;
}

int main() {
	int ch, endGame = 0, quit = 0;
	srand(time(NULL));

	/* init */
	printf("sb");

	/* set board */
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d%d%d", rand() % 9, rand() % 9, rand() % 3);
		}
	}

	/* receive commands */
	while (!quit && (ch = nextcommand()) != 'q') {
		switch(ch) {
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'e':
			case 'x':
				printf("%c", ch);
				break;
			case 'W':
			case 'L':
				endGame = 1;
				printf("%c", ch);
				break;
			case 'n':
				if (endGame) quit = 1;
				printf("%c", ch);
				break;
			case 'y':
				printf("%c", ch);
				if (!endGame) break;
				endGame = 0;
			case 'b':
				/* reset board */
				printf("b");

				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						printf("%d%d%d", rand() % 2, rand() % 9, rand() % 3);
					}
				}
				break;
		}
	}

	/* terminate game + program */
	printf("qq");

	return 0;
}