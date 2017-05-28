#include <ncurses.h>
#include <stdio.h>

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
#define HIGHLIGHT_COLOR 4
#define MSG_COLOR 5

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

void init_params(WIN *p_win, CURSOR *c);
void draw_board(WIN *win, bool flag, CELL board[][BOARD_SIZE_GRIDS]);
void print_instructions(char* instr);
void print_game_msg(char* msg);
void print_input(char* input);

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
	int i, j, flag = 0, isBomb, neighborBombs, status;

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
		}
}

void start_game() {
	WIN win;
	CURSOR c;
	CELL board[BOARD_SIZE_GRIDS][BOARD_SIZE_GRIDS];
	int ch, dummy, isCommandEntered = 0, l, isGameEnd = 0;
	char keep[10];

	/* Initialize board */
	if ((ch = nextcommand()) != 'b') return;
	set_board(board);

	/* Initialize global settings */
	initscr(); start_color(); cbreak();
	keypad(stdscr, TRUE); noecho();
	
	init_pair(INSTR_COLOR, COLOR_GREEN, COLOR_BLACK);
	init_pair(BOARD_BASE_COLOR, COLOR_CYAN, COLOR_BLACK);
	init_pair(BOMB_COLOR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(HIGHLIGHT_COLOR, COLOR_WHITE, COLOR_BLACK);
	init_pair(MSG_COLOR, COLOR_BLUE, COLOR_BLACK);

	/* Initialize the window parameters */
	init_params(&win, &c);

	/* Display game info */
	print_instructions("\n\n\n\n\t<i,j,k,l> to move up, left, down, right\n\t<r> to reveal\n\t<b> to mark bomb\n\t<u> to unmark bomb\n\t<q> to quit");
	print_input("_     ");
	move(c.y, c.x);

	/* Display board */
	draw_board(&win, TRUE, board);
	move(c.y, c.x);	
	while((ch = getch())) {	
		if (ch == '\n') {
			isCommandEntered = 1;
			print_input("_     ");
			move(c.y, c.x);
			continue;
		}

		if (isCommandEntered) {
			if (ch == 'q') break;

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
				case 'b':
					set_board(board);
					draw_board(&win, FALSE, board);
					draw_board(&win, TRUE, board);
					move(c.y, c.x);
					break;
				case 'W':
					move(GAME_MSG_Y, GAME_MSG_X - 3);
					print_game_msg("YOU WIN!");
					move(GAME_MSG_Y + 1, GAME_MSG_X - 6);
					print_game_msg("New game? <y/n>");
					move(c.y, c.x);
					isGameEnd = 1;
					break;
				case 'L':
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
						if ((ch = nextcommand()) != 'b') {
							endwin();
							return;
						}
						set_board(board);

						move(GAME_MSG_Y, GAME_MSG_X - 4);
						print_game_msg("               ");
						move(GAME_MSG_Y + 1, GAME_MSG_X - 6);
						print_game_msg("               ");

						print_input("_     ");
						draw_board(&win, TRUE, board);

						move(c.y, c.x);
						isGameEnd = 0;
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
			sprintf(keep, "%c_     ", ch);
			print_input(keep);
			move(c.y, c.x);
		}
	}
	endwin();
}

/* Drawing */

void init_params(WIN *p_win, CURSOR *c) {
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

	c->x = p_win->startx + CELL_WIDTH * (BOARD_SIZE_GRIDS / 2) + CELL_CENTER_OFFSET_X;
	c->y = p_win->starty + CELL_HEIGHT * (BOARD_SIZE_GRIDS / 2) + CELL_CENTER_OFFSET_Y;
}

void draw_board(WIN *p_win, bool flag, CELL board[][BOARD_SIZE_GRIDS]) {	
	int i, j;
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
		attron(COLOR_PAIR(HIGHLIGHT_COLOR));

		for (i = 0; i < BOARD_SIZE_GRIDS; i++)
			for (j = 0; j < BOARD_SIZE_GRIDS; j++) {
				cx = x + CELL_CENTER_OFFSET_X + j * CELL_WIDTH;
				cy = y + CELL_CENTER_OFFSET_Y + i * CELL_HEIGHT;
				if (board[i][j].status == 1) {
					if (board[i][j].neighborBombs == 0) mvaddch(cy, cx, '.');
					else mvaddch(cy, cx, board[i][j].neighborBombs + '0');
				} else if (board[i][j].status == 2) {
					attron(COLOR_PAIR(BOMB_COLOR));
					mvaddch(cy, cx, 'B');
					attron(COLOR_PAIR(HIGHLIGHT_COLOR));
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
