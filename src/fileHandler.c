#include "../lib/lib.h"

int isRegFile(const char *p) {
    struct stat pt;
    stat(p, &pt);
    return S_ISREG(pt.st_mode);
}

void exitAndMsg(char* msg, int code) {
    my_printf("%s\n", msg);
    exit(code); // unauthorized function ?
}

void getAvm(char* path) {
    int in, size, rt;
    char* bfr;
    /* RIP
    char *ext = strrchr(path, '.');
    if (! isRegFile(path) || ext == NULL || strcmp((ext + 1),"avm") != 0)
       exitAndMsg("Not a regular .avm file!", 1);
    */
    in = open(path, O_RDONLY);
    if (in == -1)
        exitAndMsg("Error while opening file. Please check filepath.", 1);
    struct stat sz; // is stat allowed?
    stat(path, &sz);
    size = sz.st_size;
    bfr = malloc(size * (sizeof(char)));
    rt = read(in, bfr, size);
    if (rt == -1)
        exitAndMsg("Error while reading file. Is file blank?.", 1);
    my_printf("%s\n", bfr);
    close(in);
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