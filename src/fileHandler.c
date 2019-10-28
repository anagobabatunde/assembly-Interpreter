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
    char bfr[1024];
    //size = 1023;
    //bfr = malloc(size * (sizeof(char)));
    rt = read(in, bfr, 1023);
    if (rt == 0)
        return exitAndMsg("Error blank file?", 1);
    // printf("%s%d\n","return is :", rt);
    bfr[rt + 1] = '\0';
    if (rt == -1)
        return exitAndMsg("Error while reading file!", 1);
    adat.data = bfr;
    close(in);
    adat.adt.ret = 0;
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