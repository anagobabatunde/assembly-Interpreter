#include "../lib/lib.h"

int isRegFile(const char *p) {
    struct stat pt;
    stat(p, &pt);
    return S_ISREG(pt.st_mode);
}

void exitAndMsg(char* msg, int code) {
    my_printf("%s\n", msg);
    exit(code); // unauthorized function..
}

void getAvm(char* path) {
    FILE *in = NULL;
    char *ext = strrchr(path, '.');
    if (! isRegFile(path) || ext == NULL || strcmp((ext + 1),"avm") != 0)
       exitAndMsg("Not a regular .avm file!", 1);
    in = fopen(path, "rt");
    if (in == NULL)
        exitAndMsg("Error while opening file. Please check filepath.", 1);
    /*
    // Print the file
    char c;
    while (fscanf(in, "%c", &c) == 1)
        fprintf(stdout, "%c", c);
    */
    fclose(in);
}