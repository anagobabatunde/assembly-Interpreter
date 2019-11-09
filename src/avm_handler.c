/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** avm_handler.c
** File description:
**      handles the avm
*/

#include "../lib/lib.h"

elem_t *parse_alone(char *oper, elem_t *list) {
    elem_t *tmp = list;
    int (*func[6])(elem_t * *list) = {pop, _add, _sub, _mul, _div, _mod};
    char op[8][5] = {"pop", "add", "sub", "mul", "div", "mod", "\0"};
    if (my_strcmp(oper, "dump")) {
        dump(tmp);
        return tmp;
    }
    for (int i = 0; my_strcmp(op[i], "\0") != 0; i++) {
        if (my_strcmp(oper, op[i]) == 0)
            func[i](&tmp);
    }
    return tmp;
}

void parser(char *line, elem_t **list) {
    elem_t *tmp = *list;
    int (*function[2])(elem_t **list, int value) = {push, assert};
    if (my_strcmp(line, "exit") == 0)
        exit_msg("", 2);
    char *operation = get_operation(line);
    char manip[3][6] = {"push", "assert", "\0"};
    if (not_alone(line) != 0) {
        for (int i = 0; my_strcmp(manip[i], "\0") != 0; i++) {
            if (my_strcmp(operation, manip[i]) == 0)
                function[i](&tmp, my_getnbr(get_value(line)));
        }
        *list = tmp;
    } else
        *list = parse_alone(operation, tmp);
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
