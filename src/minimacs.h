#ifndef MINIMACS_H
#define MINIMACS_H

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#ifdef PROD
#include <config.h>
#else
#define PACKAGE "minimacs"
#define PACKAGE_BUGREPORT "elia.toselli@outlook.it"
#define PACKAGE_NAME "minimacs"
#define PACKAGE_STRING "minimacs 0.2"
#define PACKAGE_TARNAME "minimacs"
#define PACKAGE_URL ""
#define PACKAGE_VERSION "0.2"
#define VERSION "0.2"
#endif

#define CTRL(c) ((c) & 037)
#define errexit(string) fprintf(stderr, string); exit(1)
#define check_args() if (argc == 1) { errexit("minimacs: must specify the file to edit.\n"); }
#define initnc() initscr(); raw(); noecho(); keypad(stdscr, true)
#define endnc() noraw(); echo(); endwin()

int exists(char *);
int filelen(FILE *fp);


#endif