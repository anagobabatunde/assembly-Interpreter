/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** basic_function.c
** File description:
**      first part of functions
*/

#include "../lib/lib.h"

int push(elem_t **list, int valeur)
{
    elem_t *head = NULL;

    if (list == NULL)
        return -1;
    head = malloc(sizeof(*head));
    if (head == NULL)
        return -1;
    head->value = valeur;
    head->next = *list;
    *list = head;
    return 0;
}

int dump(elem_t **list)
{
    elem_t *elem = NULL;

    elem = *list;
    while (elem != NULL)
    {
        my_printf("%d\n", elem->value);
        elem = elem->next;
    }
    return 1;
}

int pop(elem_t **pile)
{
    int val = 0;
    val = (*pile)->value;
    delete_node(&(*pile), val);
    return val;
}

int _add(elem_t **pile) {
    int previs = (*pile)->value;
    *pile = (*pile)->next;
    int prevus = (*pile)->value;
    delete_node(&(*pile), previs);
    delete_node(&(*pile), prevus);
    int sum = previs + prevus;
    push(&(*pile), sum);
    return (sum);
}

