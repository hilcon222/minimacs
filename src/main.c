#include "minimacs.h"

char *filename;

int main(int argc, char **argv) {
    extern char *filename;
    check_args();
    filename = argv[1];
    initnc();
    printw("hey");
    refresh();
    getch();
    endnc();
}