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
    int gauche = (*pile)->value;
    *pile = (*pile)->next;
    int droite = (*pile)->value;
    delete_node(&(*pile), gauche);
    delete_node(&(*pile), droite);
    if (droite == 0) {
        droite = 1;
        sum = gauche / droite;
    } else if (gauche == 0) {
        sum = 0;
    }
    push(&(*pile), sum);
    return (sum);
}

int _mod(elem_t **pile) {
    int sum, droite, gauche = 0;
    gauche = pop(&(*pile));
    droite = pop(&(*pile));
    if (droite == 0) {
        return gauche;
    }
    sum = gauche % droite;
    push(&(*pile), sum);
    return (sum);
}
