#include "../lib/lib.h"

void parser(char* dat, int readReturn) {
  
}

void handleAvm(adat_t **avm) {
    adat_t *adat = NULL;
    adat = avm;
    int k,line, col = 0;
    size_t len = 0;
    char* tBfr =  malloc(sizeof(char*));
    // tBfr[0] = '\0';
    for (k = 0; adat->data[k] != '\0'; k++) {
        if (adat->data[k] == '\n' || adat->data[k] == '\0') {
            if (notAlone(tBfr))
                printf(" aye that guy not alone need to handle him ");
            printf("-nl-\n");
            tBfr[0] = '\0';
        } else {
            len = my_strlen(tBfr);
            tBfr[len++] = adat->data[k];
            tBfr[len] = '\0';
        }
    }
    free(tBfr);
}

int notAlone(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ')
            return 1;
        i++;
    }
    return 0;
}
