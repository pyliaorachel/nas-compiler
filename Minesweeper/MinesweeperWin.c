#include <ncurses.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 0

#define BOARD_SIZE_GRIDS 8
#define BOARD_WIDTH (BOARD_SIZE_GRIDS * 8)
#define BOARD_HEIGHT (BOARD_SIZE_GRIDS * 4)
#define CELL_WIDTH (BOARD_WIDTH / BOARD_SIZE_GRIDS)
#define CELL_HEIGHT (BOARD_HEIGHT / BOARD_SIZE_GRIDS)
#define CELL_CENTER_OFFSET_X (CELL_WIDTH / 2)
#define CELL_CENTER_OFFSET_Y (CELL_HEIGHT / 2)
#define GAME_MSG_X (COLS / 2)
#define GAME_MSG_Y 5

#define INSTR_COLOR 1
#define BOARD_BASE_COLOR 2
#define BOMB_COLOR 3
#define EXPLODE_COLOR 4
#define HIGHLIGHT_COLOR 5
#define MSG_COLOR 6

typedef struct _win_border_struct {
	chtype	ls, rs, ts, bs, 
			tl, tr, bl, br;
} WIN_BORDER;

typedef struct _WIN_struct {
	int startx, starty;
	int height, width;
	WIN_BORDER border;
} WIN;

typedef struct _CURSOR_struct {
	int x, y;
} CURSOR;

typedef struct _CELL_struct {
	bool isBomb;
	int neighborBombs, status;
} CELL;

int nextcommand();

void set_board(CELL board[][BOARD_SIZE_GRIDS]);
void start_game();

void init_params(WIN *p_win);
void init_cursor(WIN *p_win, CURSOR *c);
void draw_board(WIN *win, CELL board[][BOARD_SIZE_GRIDS], bool flag, bool borderOnly);
void print_instructions(char* instr);
void print_game_msg(char* msg);
void print_input(char* input);
void reset_game_screen();

int main(int argc, char *argv[]) {	
	int ch, dummy;

	/* Receive commands */
	while((ch = nextcommand()) != 'q') {	
		switch(ch) {
			case 's':
				start_game();
				break;
		}
	}

	printf("Have a nice day!\n");
	return 0;
}

/* Helper */

int nextcommand() {
	int ch;

	ch = getchar();
	while(ch == '\n' || ch == ' ' || ch == '\t') ch = getchar();

	return ch;
}

/* Game */

void set_board(CELL board[][BOARD_SIZE_GRIDS]) {
	int i, j, flag = 0;
	char isBomb, neighborBombs, status;

	for (i = 0; i < BOARD_SIZE_GRIDS && !flag; i++)
		for (j = 0; j < BOARD_SIZE_GRIDS && !flag; j++) {
			if ((isBomb = nextcommand()) == 'e') {
				flag = 1;
				break;
			}
			neighborBombs = nextcommand();
			status = nextcommand();
			board[i][j].isBomb = (bool) (isBomb - '0');
			board[i][j].neighborBombs = (neighborBombs - '0');
			board[i][j].status = (status - '0');
#if DEBUG
			mvaddch(i + 1, j * 8 + 1, isBomb);
			mvaddch(i + 1, j * 8 + 3, neighborBombs);
			mvaddch(i + 1, j * 8 + 5, status);
			mvaddch(i + 1, j * 8 + 7, '|');
#endif
		}
}

void start_game() {
	WIN win;
	CURSOR c;
	CELL board[BOARD_SIZE_GRIDS][BOARD_SIZE_GRIDS];
	int ch, dummy, isCommandEntered = 0, l, isGameEnd = 0, getSeed = 0;
	char keep[20];
	// char b;

	// while ((b = nextcommand()) != 'b') {
	// 	b = nextcommand();
	// }
	// set_board(board);

	/* Initialize global settings */
	initscr(); start_color(); cbreak();
	keypad(stdscr, TRUE); noecho();
	
	init_pair(INSTR_COLOR, COLOR_GREEN, COLOR_BLACK);
	init_pair(BOARD_BASE_COLOR, COLOR_CYAN, COLOR_BLACK);
	init_pair(BOMB_COLOR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(EXPLODE_COLOR, COLOR_WHITE, COLOR_RED);
	init_pair(HIGHLIGHT_COLOR, COLOR_WHITE, COLOR_BLACK);
	init_pair(MSG_COLOR, COLOR_BLUE, COLOR_BLACK);

	/* Initialize the window parameters */
	init_params(&win);
	init_cursor(&win, &c);

	/* Display game info */
	reset_game_screen();
	move(c.y, c.x);

	/* Display board */
	draw_board(&win, board, TRUE, TRUE);
	move(c.y, c.x);	
	while((ch = getch())) {	

#if DEBUG
		mvaddch(0,2,ch);
		move(c.y, c.x);
#endif

		if (ch == '*') { // commands start with '*' to differentiate between input from stdin & window
			isCommandEntered = 1;
			print_input("_     ");
			move(c.y, c.x);
			continue;
		}

		if (isCommandEntered) {
			if (ch == 'q') break;

#if DEBUG
			mvaddch(0,0,ch);
			move(c.y, c.x);
#endif

			switch(ch) {
				case 'j':
					c.x = (c.x - CELL_WIDTH) < win.startx ? win.startx + BOARD_WIDTH - CELL_CENTER_OFFSET_X : c.x - CELL_WIDTH;
					move(c.y, c.x);
					break;
				case 'l':
					c.x = (c.x + CELL_WIDTH) >= win.startx + BOARD_WIDTH ? win.startx + CELL_CENTER_OFFSET_X : c.x + CELL_WIDTH;
					move(c.y, c.x);
					break;
				case 'i':
					c.y = (c.y - CELL_HEIGHT) < win.starty ? win.starty + BOARD_HEIGHT - CELL_CENTER_OFFSET_Y : c.y - CELL_HEIGHT;
					move(c.y, c.x);
					break;
				case 'k':
					c.y = (c.y + CELL_HEIGHT) >= win.starty + BOARD_HEIGHT ? win.starty + CELL_CENTER_OFFSET_Y : c.y + CELL_HEIGHT;
					move(c.y, c.x);
					break;	
				case 'x':
					if (!getSeed) {
						move(GAME_MSG_Y + 1, GAME_MSG_X - 12);
						print_game_msg("Invalid number! Enter again.");
						move(c.y, c.x);
					}
					break;
				case 'b':
					if (!getSeed) {
						move(GAME_MSG_Y, GAME_MSG_X - 29);
						print_game_msg("                                                           ");
						move(GAME_MSG_Y + 1, GAME_MSG_X - 12);
						print_game_msg("                            ");
						getSeed = 1;
					}
					set_board(board);

					draw_board(&win, board, FALSE, FALSE);
					draw_board(&win, board, TRUE, FALSE);
					move(c.y, c.x);
					break;
				case 'W':
					while ((ch = getch()) != '*')
						;
					ch = getch();
					#if DEBUG
						mvaddch(0,2,ch);
					#endif

					draw_board(&win, board, FALSE, FALSE);
					draw_board(&win, board, TRUE, FALSE);
					move(c.y, c.x);

					move(GAME_MSG_Y, GAME_MSG_X - 3);
					print_game_msg("YOU WIN!");
					move(GAME_MSG_Y + 1, GAME_MSG_X - 6);
					print_game_msg("New game? <y/n>");
					move(c.y, c.x);
					isGameEnd = 1;
					break;
				case 'L':
					while ((ch = getch()) != '*')
						;
					ch = getch();
					#if DEBUG
						mvaddch(0,2,ch);
					#endif
					set_board(board);

					draw_board(&win, board, FALSE, FALSE);
					draw_board(&win, board, TRUE, FALSE);
					move(c.y, c.x);

					move(GAME_MSG_Y, GAME_MSG_X - 4);
					print_game_msg("YOU LOSE!");
					move(GAME_MSG_Y + 1, GAME_MSG_X - 6);
					print_game_msg("New game? <y/n>");
					move(c.y, c.x);
					isGameEnd = 1;
					break;
				case 'y':
					// restart game
					if (isGameEnd) {
						reset_game_screen();
						draw_board(&win, board, TRUE, TRUE);

						init_cursor(&win, &c);
						move(c.y, c.x);
						isGameEnd = 0;
						getSeed = 0;
					}
					break;
				case 'n':
					// quit program
					if (isGameEnd) {
						endwin();
						return;
					}
					break;
				default:
					break;
			}
			isCommandEntered = 0;
		} else {
			if (getSeed) {
				sprintf(keep, "%c_     ", ch);
				print_input(keep);
				move(c.y, c.x);
			}
		}
	}
	endwin();
}

/* Drawing */

void init_params(WIN *p_win) {
	p_win->height = BOARD_HEIGHT;
	p_win->width = BOARD_WIDTH;
	p_win->starty = (LINES - p_win->height)/2;	
	p_win->startx = (COLS - p_win->width)/2;

	p_win->border.ls = ACS_BLOCK;
	p_win->border.rs = ACS_BLOCK;
	p_win->border.ts = ACS_BLOCK;
	p_win->border.bs = ACS_BLOCK;
	p_win->border.tl = ACS_BLOCK;
	p_win->border.tr = ACS_BLOCK;
	p_win->border.bl = ACS_BLOCK;
	p_win->border.br = ACS_BLOCK;
}

void init_cursor(WIN *p_win, CURSOR *c) {
	c->x = p_win->startx + CELL_WIDTH * (BOARD_SIZE_GRIDS / 2) - CELL_CENTER_OFFSET_X;
	c->y = p_win->starty + CELL_HEIGHT * (BOARD_SIZE_GRIDS / 2) - CELL_CENTER_OFFSET_Y;
}

void draw_board(WIN *p_win, CELL board[][BOARD_SIZE_GRIDS], bool flag, bool borderOnly) {	
	int i, j, k, l;
	int x, y, w, h, cx, cy;

	x = p_win->startx;
	y = p_win->starty;
	w = p_win->width;
	h = p_win->height;

	if (flag == TRUE) {	
		attron(COLOR_PAIR(BOARD_BASE_COLOR));

		/* draw board borders */
		mvaddch(y, x, p_win->border.tl);
		mvaddch(y, x + w, p_win->border.tr);
		mvaddch(y + h, x, p_win->border.bl);
		mvaddch(y + h, x + w, p_win->border.br);
		mvhline(y, x + 1, p_win->border.ts, w - 1);
		mvhline(y + h, x + 1, p_win->border.bs, w - 1);
		mvvline(y + 1, x, p_win->border.ls, h - 1);
		mvvline(y + 1, x + w, p_win->border.rs, h - 1);

		/* draw cell borders */
		for(i = y + CELL_HEIGHT; i < y + h; i += CELL_HEIGHT)
			for(j = x + 1; j < x + w; j++)
				mvaddch(i, j, ACS_BLOCK);
		for(i = y + 1; i < y + h; i++)
			for(j = x + CELL_WIDTH; j < x + w; j += CELL_WIDTH)
				mvaddch(i, j, ACS_BLOCK);

		/* draw cell info */
		if (!borderOnly) {
			attron(COLOR_PAIR(HIGHLIGHT_COLOR));

			for (i = 0; i < BOARD_SIZE_GRIDS; i++)
				for (j = 0; j < BOARD_SIZE_GRIDS; j++) {
					cx = x + CELL_CENTER_OFFSET_X + j * CELL_WIDTH;
					cy = y + CELL_CENTER_OFFSET_Y + i * CELL_HEIGHT;
					if (board[i][j].status == 1 && board[i][j].isBomb) {
						attron(COLOR_PAIR(EXPLODE_COLOR));

						for (k = -CELL_CENTER_OFFSET_Y + 1; k < CELL_CENTER_OFFSET_Y; k++) 
							for (l = -CELL_CENTER_OFFSET_X + 1; l < CELL_CENTER_OFFSET_X; l++)
								mvaddch(cy + k, cx + l, ' ');
						mvaddch(cy, cx, 'X');	

						attron(COLOR_PAIR(HIGHLIGHT_COLOR));
					} else if (board[i][j].status == 1) {
						if (board[i][j].neighborBombs == 0) mvaddch(cy, cx, '.');
						else mvaddch(cy, cx, board[i][j].neighborBombs + '0');
					} else if (board[i][j].status == 2) {
						attron(COLOR_PAIR(BOMB_COLOR));
						mvaddch(cy, cx, 'B');
						attron(COLOR_PAIR(HIGHLIGHT_COLOR));
					}
				}
		}
	} else {
		for(i = y; i <= y + h; i++)
			for(j = x; j <= x + w; j++)
				mvaddch(i, j, ' ');
	}

	refresh();
}

void print_instructions(char* instr) {
	attron(COLOR_PAIR(INSTR_COLOR));
	printw(instr);
	refresh();
}

void print_game_msg(char* msg) {
	attron(COLOR_PAIR(MSG_COLOR));
	printw(msg);
	refresh();
}

void print_input(char* input) {
	attron(COLOR_PAIR(MSG_COLOR));
	move(LINES/ 2, COLS * 3 / 4);
	printw(input);
	refresh();
}

void reset_game_screen() {
	move(0, 0);
	print_instructions("\n\n\n\n\t<i,j,k,l> to move up, left, down, right\n\t<r> to reveal\n\t<b> to mark bomb\n\t<u> to unmark bomb\n\t<q> to quit");
	move(GAME_MSG_Y, GAME_MSG_X - 4);
	print_game_msg("         ");
	move(GAME_MSG_Y + 1, GAME_MSG_X - 6);
	print_game_msg("               ");
	move(GAME_MSG_Y, GAME_MSG_X - 29);
	print_game_msg("Enter an ODD number between 1 to 99 to generate the board: ");
	print_input("_     ");
}
