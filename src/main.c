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

#ifndef CTRL
#define CTRL(c) ((c) & 037)
#endif


int main() {
    return 0;
}
