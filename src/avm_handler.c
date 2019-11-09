/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** avm_handler.c
** File description:
**      handles the avm
*/

#include "../lib/lib.h"

void parse_alone(char *oper, elem_t **list) {
    int (*func[7])(elem_t **list) = {pop, _add, _sub, _mul, _div, _mod, dump};
    char op[8][5] = {"pop", "add", "sub", "mul", "div", "mod", "dump", "\0"};

    for (int i = 0; my_strcmp(op[i], "\0") != 0; i++) {
        if (my_strcmp(oper, op[i]) == 0)
            func[i](&(*list));
    }
}

void parser(char *line, elem_t **list) {
    int (*function[2])(elem_t **list, int value) = {push, assert};
    char manip[3][6] = {"push", "assert", "\0"};
    char *operation;
    if (my_strcmp(line, "exit") == 0)
        exit_msg("", 2);
    if (not_alone(line) != 0) {
        operation = get_operation(line);
        for (int i = 0; my_strcmp(manip[i], "\0") != 0; i++) {
            if (my_strcmp(operation, manip[i]) == 0)
                function[i](&(*list), my_getnbr(get_value(line)));
        }
    } else {
        operation = get_operation2(line);
        parse_alone(operation, list);
    }
}

adat_t *handle_avm(adat_t *avm) {
    elem_t *list = NULL;
    adat_t *dat = NULL;
    dat = avm;
    int k, len = 0;
    for (k = 0; dat->data[k] != '\0'; k++) {
        if (dat->data[k] == '\n' || dat->data[k] == '\0') {
            parser(dat->handle, &list);
            dat->handle[0] = '\0';
        } else {
            len = my_strlen(dat->handle);
            dat->handle[len++] = dat->data[k];
            dat->handle[len] = '\0';
        }
    }
    return dat;
}
