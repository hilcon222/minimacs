#include "minimacs.h"

int exists(char *filename) {
    FILE *fp;
    if ((fp = fopen(filename, "r")) != NULL) {
        fclose(fp);
        return true;
    } else {
        return false;
    }
}

int filelen(FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    int res = ftell(fp);
    rewind(fp);
    return res;
}

