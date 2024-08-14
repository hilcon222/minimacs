#include <ncurses.h>
#include <string.h>
#ifdef PROD
#include <config.h>
#else
#include <../config.h>
#endif
#define VERSION "0.1"


int rows, cols;

void firstLine(void) {
    getmaxyx(stdscr, rows, cols);
    move(0,0);
    attron(A_REVERSE);
    addstr(PACKAGE_STRING);
    int intro_len = strlen(PACKAGE_STRING);
    for (int c = 0; c < cols - intro_len; c++) {
        addch(' ');
    }
    refresh();
}

void lastLine(void) {
    getmaxyx(stdscr, rows, cols);
    move(rows-1,0);
    attron(A_REVERSE);
    addstr("");
    int intro_len = strlen("");
    for (int c = 0; c < cols - intro_len; c++) {
        addch(' ');
    }
    refresh();
}

void endprog(void) {
    echo();
    nocbreak();
    endwin();
}

void init_program() {
    initscr();
	clear();
	noecho();
	cbreak();
    keypad(stdscr, true);
}

int main() {
    init_program();
    getmaxyx(stdscr, rows, cols);
    firstLine();
    attrset(A_NORMAL);

    lastLine();
    attrset(A_NORMAL);
    getch();
    endprog();
}
