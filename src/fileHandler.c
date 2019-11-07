#include "../lib/lib.h"

adat_t exitAndMsg(char* msg, int code) {
    adat_t adat;
    adat.adt.msg = msg;
    adat.adt.ret = code;
    return adat;
}

int getNbLine(char *b) {
    int k, l = 0;
    for (k; b[k] != '\0'; k++) {
        if (b[k] == '\n')
            l++;
    }
    return l;
}

int getLine(char* path) {
    int in, rt;
    char buffer[1024];
    // rt = 0;
    in = open(path, O_RDONLY);
    rt = read(rt, buffer, 1023);
    buffer[rt] = '\0';
    close(in);
    return getNbLine(buffer);
}

adat_t getAvm(char* path) {
    adat_t adat;
    int in, size, rt;
    in = open(path, O_RDONLY);
    if (in == -1)
        return exitAndMsg("Error while opening file. Please check filepath.", 1);
    /*
    int i = 0;
    rt = 1;
    char bfr[8];
    while (rt != 0) {
        while (i < 9)
            bfr[i] = '\0'; i++;
        rt = read(in, bfr, 8);
        my_strcpy(adat.data, bfr); 
    }
    */
    char* bfr = malloc(sizeof(char *) * 1024);
    rt = read(in, bfr, 1023);
    if (rt == 0 || rt == -1)
        return exitAndMsg("Error blank file?", 1);
    bfr[rt++] = '\n';
    bfr[rt] = '\0';
    adat.data = bfr;
    close(in);
    adat.read_ret = rt;
    // free(bfr); // TODO FREE
    return adat;
}