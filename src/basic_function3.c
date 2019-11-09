/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** basic_function3.c
** File description:
**      third and last part of fucntions
*/

#include "../lib/lib.h"

int assert(elem_t **pile, int value)
{
    elem_t *tmp;
    tmp = *pile;
    if (tmp->value == value)
        return (0);
    return (1);
}

void delete_node(elem_t **head_ref, int key)
{
    elem_t *temp = *head_ref, *prev;
    if (temp != NULL && temp->value == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->value != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
} 
