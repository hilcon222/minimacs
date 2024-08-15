#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#ifdef PROD
#include <config.h>
#else
#define PACKAGE "minimacs"
#define PACKAGE_BUGREPORT "elia.toselli@outlook.it"
#define PACKAGE_NAME "minimacs"
#define PACKAGE_STRING "minimacs 0.1"
#define PACKAGE_TARNAME "minimacs"
#define PACKAGE_URL ""
#define PACKAGE_VERSION "0.1"
#define VERSION "0.1"
#endif

#ifndef CTRL
#define CTRL(c) ((c) & 037)
#endif


int rows, cols;

char *buffer;
char *pos;
int maxsiz;
int inpsize;

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
    noraw();
    endwin();
}

void init_program() {
    initscr();
	clear();
	noecho();
	raw();
    keypad(stdscr, true);
}

int inpchar(void) {
    extern int maxsiz, inpsize;
    extern char *buffer;
    int c = getch();
    if (inpsize == maxsiz) {
        if ((buffer = (char *) realloc(buffer, maxsiz + BUFSIZ)) == NULL) {
            endprog();
            fprintf(stderr, "Too little memory space.\n");
            exit(1);
        }
        maxsiz += BUFSIZ;
    }
    if (c == KEY_BACKSPACE) {
        inpsize--;
        int x, y;
        getyx(stdscr, y, x);
        if (y == 1 && x == 0) {
            return 0;
        }
        move(y, x-1);
        delch();
        *(pos--) = '\0';
        return 0;
    }
    if (c == CTRL('x')) {
        int c2;
        if ((c2 = getch()) == CTRL('c')) {
            endprog();
            exit(0);
        }
        return 0;
    }
    inpsize++;
    addch(c);
    *(pos++) = c;
    return c;
}

int main() {
    extern char * buffer;
    init_program();
    getmaxyx(stdscr, rows, cols);
    firstLine();
    attrset(A_NORMAL);
    buffer = (char *) malloc(BUFSIZ);
    extern int maxsiz;
    maxsiz = BUFSIZ;
    extern int inpsize;
    inpsize = 0;
    int c;
    pos = buffer;
    lastLine();
    move(1,0);
    attrset(A_NORMAL);
    while (1) {
        c = inpchar();
    }

    endprog();
}
