#include "../lib/lib.h"

int isRegFile(const char *p) {
    struct stat pt;
    stat(p, &pt);
    return S_ISREG(pt.st_mode);
}

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
    /* RIP
    char *ext = strrchr(path, '.');
    if (! isRegFile(path) || ext == NULL || strcmp((ext + 1),"avm") != 0)
       return exitAndMsg("Not a regular .avm file!", 1);
    */
    in = open(path, O_RDONLY);
    if (in == -1)
        return exitAndMsg("Error while opening file. Please check filepath.", 1);
    /* //The stat way:
    char* bfr;
    struct stat sz; // is stat allowed?
    stat(path, &sz);
    size = sz.st_size;
    bfr = malloc(size * (sizeof(char)));
    rt = read(in, bfr, size);
    */
    // The dégun way:
    // Andy idea: read 8bit per 8bit, then there will be a '\0'
    //char bfr[1024];
    char* bfr = malloc(sizeof(char *) * 1024);
    //char* bfr;
    //size = 1023;
    //bfr = malloc(size * (sizeof(char)));
    rt = read(in, bfr, 1023);
    if (rt == 0 || rt == -1)
        return exitAndMsg("Error blank file?", 1);
    // printf("%s%d\n","return is :", rt);
    bfr[rt + 1] = '\0';
    adat.data = bfr;
    close(in);
     printf("read ret is :");
     printf("%d\n", rt);
     adat.read_ret = rt; // BUG push int32(42L
    adat.adt.ret = 0;
    free(bfr);
    return adat;
}

int check_args(int c, char *v[]) {
    if (c > 2)  {
        if (!my_strcmp(v[2],"--hardcore"))
            return (2);
        else {
            my_printf("E: Second argument should be \"--hardcore\" !\n"); 
            return (1);
        }
    } else if (c < 2 || c > 3) {
        return (2);
    }
    return 0;
}
