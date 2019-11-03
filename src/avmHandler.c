#include "../lib/lib.h"


char* appendChar(char* src, char *a) {
    char *name = malloc(sizeof(char*));
    // some code that puts something in *name
    char d = a;
    printf(src[0]);
    printf("len is :");
    printf(my_strlen(src));
    printf("\n");
    size_t len = strlen(src);
    // if (len >= (80-1)) DealWithNotEnoughRoom(); 
    name[len++] = d;
    name[len] = '\0';
    return name;
}

char* getLnByLnNum(char* src, int rl) {
    char* des =  malloc(sizeof(char*) * 1024);
    int i, line = 0;
    printf("\ni at %d and line at %d.\n", i, line );
    while (rl != line) {
        i++;
        if (src[i] == '\0' || src[i] == '\n') {
            //printf("\n%s%d\n""new line at pos:", i);
            line++;
            i++;
        }
    }
    for (i; src[i] != '\n' && i < 119; i++) {
        if (src[i] != '\0' || src[i] != '\n') {
            // printf("%c", src[i]);
            appendChar(des, src[i]);
            //printf("%c")
            //size_t dLen = my_strlen(des);
            //des[dLen] = src[i];
            //printf("_%c", src[i]);
            //des[dLen++] = '\0';
            //printf("--- wsh ---\n");
            //printf("%c", dat[k]);
            //my_strcpy(tData, &dat[k]);
        }
        //printf(" %c" , src[i]);
    }
    i, line = 0;
    //printf("\n%s%s-\n", "before out:", des);
    char* tmp = my_strdup(des);
    free(des);
    return tmp;
}

void parser(char* dat, int readReturn) {
    int k,line, col = 0;
    //char* tBfr =  malloc(sizeof(char*));
    //tBfr[0] = '\0';
    //strcpy(tBfr, "wsh");
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
    // tBfr = malloc(sizeof(dat) / sizeof(dat[0]));
    /*
    for (k = 0; dat[k] != '\0'; k++) {
        if (dat[k] == '\n') {
            //printf(tData);
            //tBfr = dat[k];
            //tData[0] = 0;
            printf("-nl-\n");
            tBfr = 0;
        } else {
            //printf("--- wsh ---\n");
            appendChar(tBfr, dat[k]);
            //printf("%c", dat[k]);
            //my_strcpy(tData, &dat[k]);
        }
        // printf("%c" , avm.data[k]);
    */
    char* yes;
    yes = my_strdup(dat);
    // printf(yes);
    printf(getLnByLnNum(yes, 0));
    printf("\n----\n");
    // printf(getLnByLnNum(yes, 1));
    printf("\n----\n");
    // printf("%c\n", tBfr[0]);
    printf("-\n");
}

adat_t handleAvm(adat_t avm) {
    adat_t adat;
    char* data;
    int k;
    parser(avm.data, avm.read_ret);
    return adat;
}

int isAlone(char *str) {
    int i = 0;
    while (str[i] != '\n') {
        if (str[i] != ' ')
            return 1;
        i++;
    }
    return 0;
}
