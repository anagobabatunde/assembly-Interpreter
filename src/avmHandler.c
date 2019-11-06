#include "../lib/lib.h"

void parser(char* dat, int readReturn) {
    int k,line, col = 0;
    size_t len = 0;
    char* tBfr =  malloc(sizeof(char*));
    // tBfr[0] = '\0';
    for (k = 0; dat[k] != '\0'; k++) {
        if (dat[k] == '\n' || dat[k] == '\0') {
            if (notAlone(tBfr))
                printf(" aye that guy not alone need to handle him ");
            printf("-nl-\n");
            tBfr[0] = '\0';
        } else {
            len = my_strlen(tBfr);
            tBfr[len++] = dat[k];
            tBfr[len] = '\0';
        }
    }
    printf("\n----\n");
    printf("%s\n", tBfr);
    free(tBfr);
    printf("-\n");
}

void handleAvm(adat_t **avm) {
    adat_t *adat = NULL;
    adat = avm;
    char* data;
    int k;
    // printf("wsh");
    // printf("%d", adat->read_ret);
    // printf("%s\n", adat->data);
    parser(adat->data, adat->read_ret);
    // return ;
    
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
