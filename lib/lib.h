#ifndef MY_LIST_
#define MY_LIST_


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h> 

struct element  {
    int value;
    struct element *next;
};

typedef struct element elem_t;

int push(elem_t **list, int valeur);
void print_list(elem_t *list);
int pop(elem_t **pile);
int _add(elem_t **pile);
int _sub(elem_t **pile);
int _mul(elem_t **pile);
int _div(elem_t **pile);
void getAvm(char* path);
void exitAndMsg(char* msg, int code);
int isRegFile(const char *p);

#endif
