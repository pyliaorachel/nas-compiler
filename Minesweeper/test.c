#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int nextcommand() {
	int ch;

	ch = getchar();
	while(ch == '\n' || ch == ' ' || ch == '\t') ch = getchar();

	return ch;
}

int main() {
	int ch;
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
	while ((ch = nextcommand()) != 'q') {
		switch(ch) {
			case 'i':
			case 'j':
			case 'k':
			case 'l':
				printf("%c", ch);
				break;
			case 'r':
				/* reset board */
				printf("r");

				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						printf("%d%d%d", rand() % 2, rand() % 9, rand() % 3);
					}
				}
				break;
		}
	}

	/* terminate */
	printf("q");

	return 0;
}