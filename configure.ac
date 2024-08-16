AC_INIT([minimacs],[0.2],[elia.toselli@outlook.it])
        AM_INIT_AUTOMAKE([-Wall -Werror foreign])
        AC_PROG_CC
        AC_CONFIG_HEADERS([config.h])
        AC_CONFIG_FILES([
         Makefile
         src/Makefile
        ])
        AC_OUTPUT
AC_CHECK_HEADERS(ncurses.h, [], [AC_MSG_ERROR(A working ncurses is required)])
AC_SEARCH_LIBS(initscr, ncurses, [], [AC_MSG_ERROR(A working ncurses is required)])