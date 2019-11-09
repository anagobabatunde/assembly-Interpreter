/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** file_handler.c
** File description:
**      avm file handler
*/

#include "../lib/lib.h"

adat_t exit_msg(char *msg, int code) {
    adat_t adat;
    adat.adt.msg = msg;
    adat.adt.ret = code;
    return adat;
}

adat_t mall_all(adat_t data) {
    data.data = malloc(sizeof(char *) * 1024);
    data.handle = malloc(sizeof(char *));
    return data;
}

adat_t get_avm(adat_t data, char *path) {
    int in, rt = 0;
    in = open(path, O_RDONLY);
    if (in == -1)
        return exit_msg("Error while opening file.", 1);
    rt = read(in, data.data, 1023);
    if (rt == 0 || rt == -1)
        return exit_msg("Error blank file?", 1);
    data.data[rt++] = '\n';
    data.data[rt] = '\0';
    close(in);
    data.read_ret = rt;
    return data;
}

void free_all(adat_t data) {
    free(data.data);
    free(data.handle);
}
