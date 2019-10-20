#ifndef MY_LIST_
#define MY_LIST_


#include <stdio.h>
#include <stdlib.h>

struct element  {
    int value;
    struct element *next;
};

typedef struct element elem_t;

int push(elem_t **list, int valeur);
void print_list(elem_t *list);
int pop(elem_t **pile);
int add(elem_t **pile);
int sub(elem_t **pile);
int mul(elem_t **pile);
int div(elem_t **pile);

#endif
