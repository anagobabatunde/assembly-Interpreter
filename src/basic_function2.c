/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** basic_function2.c
** File description:
**      second part of funcs
*/

#include "../lib/lib.h"

int _sub(elem_t **pile) {
    int sum = 0;
    sum = pop(&(*pile)) - pop(&(*pile));
    push(&(*pile), sum);
    return (sum);
}

int _mul(elem_t **pile) {
    int sum = 0;
    sum = pop(&(*pile)) * pop(&(*pile));
    push(&(*pile), sum);
    return (sum);
}

int _div(elem_t **pile) {
    int sum = 0;
    sum = pop(&(*pile)) / pop(&(*pile));
    push(&(*pile), sum);
    return (sum);
}

int _mod(elem_t **pile) {
    int sum = 0;
    sum = pop(&(*pile)) % pop(&(*pile));
    push(&(*pile), sum);
    return (sum);
}
