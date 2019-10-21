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
void dump(elem_t *list);
int pop(elem_t **pile);
int _add(elem_t **pile);
int _sub(elem_t **pile);
int _mul(elem_t **pile);
int _div(elem_t **pile);
int _mod(elem_t **pile);
int assert(elem_t **pile, int value);

#endif
