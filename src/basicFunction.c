#include "../lib/lib.h"

int push(elem_t **list, int valeur)
{
    elem_t *head = NULL;

    if (list == NULL || valeur == 0)
        return -1;
    head = malloc(sizeof(*head));
    if (head == NULL)
        return -1;
    head->value = valeur;
    head->next = *list;
    *list = head;
    return 0;
}

void print_list(elem_t *list)
{
    elem_t *elem = NULL;

    elem = list;
    while (elem != NULL)
    {
        printf("%d\n", elem->value);
        elem = elem->next;
    }
}

int pop(elem_t **pile)
{
    int val;
    elem_t *tmp;
    if (pile == NULL)
        return -1;
    
    tmp = (*pile)->next;
    val = (*pile)->value;
    free(*pile);
    *pile = tmp;
    return val;
}

int add(elem_t **pile) {
    elem_t *tmp;
    tmp = *pile;
    int sum = 0;
    sum = pop(&tmp) + pop(&tmp);
    *pile = tmp;
    push(pile, sum);
    return (sum);
}

int sub(elem_t **pile) {
    elem_t *tmp;
    tmp = *pile;
    int sum = 0;
    sum = pop(&tmp) - pop(&tmp);
    *pile = tmp;
    push(pile, sum);
    return (sum);
}

int mul(elem_t **pile) {
    elem_t *tmp;
    tmp = *pile;
    int sum = 0;
    sum = pop(&tmp) * pop(&tmp);
    *pile = tmp;
    push(pile, sum);
    return (sum);
}

int div(elem_t **pile) {
    elem_t *tmp;
    tmp = *pile;
    int sum = 0;
    sum = pop(&tmp) / pop(&tmp);
    *pile = tmp;
    push(pile, sum);
    return (sum);
}