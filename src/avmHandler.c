#include "../lib/lib.h"

adat_t handleAvm(adat_t avm) {
    adat_t adat;
    elFamosoParser(avm.data);
    return adat;
}

void elFamosoParser(char dat[]) {
    int k,line,col = 0;
    // printf(dat);
    /*for (k = 0; dat[k] != '\0'; k++) {
        //tab[line][col] = buffer[k];
        col++;
        printf("%s", dat[k]);
        if (dat[k] == '\n') {
            line++;
            printf("%s%s", dat[k], "-");
            col = 0;
        }
    }*/
    printf("%c" , bfr);
    // printf(dat[1]);
    // TODO : Investigate why segfault
    printf("\n");
}