#include <stdio.h>

int main() {
	int ch;

	printf("sb");

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			printf("%d%d%d", i, j, 2);
		}
	}

	while ((ch = getchar()) != 'q') {
		printf("%c", ch);
	}

	printf("q");

	return 0;
}