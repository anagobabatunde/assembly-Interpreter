/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** avm_utils2.c
** File description:
**      2nd utils for the avm
*/

#include "../lib/lib.h"

char *get_value(char *line) {
    char *value = malloc(sizeof(char));
    int i, len = 0;
    char *result;
    for (i = return_first_paren(line); line[i] != ')'; i++) {
        len = my_strlen(value);
        if (line[i] != 32)
            value[len] = line[i];
    }
    value[len + 1] = '\0';
    result = my_strdup(value);
    free(value);
    return result;
}

int not_alone(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ')
            return 1;
        i++;
    }
    return 0;
}

char *get_operation2(char *line) {
    char *op = malloc(sizeof(char));
    int tmp = 0;
    char *result;
    // line[my_strlen(line)] = '\0';
    //my_printf("Line is [%s]\n", line);
    for (int i = 0; line[i] != '\0'; i++) {
        op[i] = line[i];
        tmp = i;
    }
    op[tmp + 1] = '\0';
    result = my_strdup(op);
    free(op);
    // printf("j'ai recup ça [%s]\n", result);
    return result;
}