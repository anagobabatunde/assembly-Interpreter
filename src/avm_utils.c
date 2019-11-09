/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** avm_utils.c
** File description:
**      utils for the avm
*/

#include "../lib/lib.h"

int return_first_paren(char *line) {
    int tmp = 0;
    for (int i = 0; line[i] != '('; i++) {
        tmp = i;
    }
    return tmp + 2;
}

int return_first_space(char *line) {
    int tmp = 0;
    for (int i = 0; line[i] != 32; i++) {
        tmp = i;
    }
    return tmp + 1;
}

char *get_operation(char *line) {
    char *op = malloc(sizeof(char));
    int tmp = 0;
    char *result;
    // line[my_strlen(line)] = '\0';
    // my_printf("Line is [%s]\n", line);
    for (int i = 0; line[i] != ' '; i++) {
        op[i] = line[i];
        tmp = i;
    }
    op[tmp + 1] = '\0';
    result = my_strdup(op);
    free(op);
    return result;
}

char *get_type(char *line) {
    char *type = malloc(sizeof(char));
    int i, len = 0;
    char *result;
    for (i = return_first_space(line); line[i] != '('; i++) {
        len = my_strlen(type);
        if (line[i] != 32)
            type[len] = line[i];
    }
    type[len + 2] = '\0';
    result = my_strdup(type);
    free(type);
    return result;
}

