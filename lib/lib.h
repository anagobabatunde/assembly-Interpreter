#ifndef MY_LIST_
#define MY_LIST_


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdarg.h>

struct element  {
    int value;
    struct element *next;
};

typedef struct element elem_t;

// LesMy
int     my_nbrlen(int n);
int     my_getnbr(char *str);
int     my_strlen(char *str);
int     my_strcmp(char *s1, char *s2);
int     my_strncmp(char *s1, char *s2, int n);
int     my_printf(const char *format, ...);
int     my_strlen2(char *str);
int     my_getnbr2(char *str, int *i);
void    my_putnbr_base(int n, char *base);
void    my_putnbr_unsigned(unsigned int n);
void    my_putchar(char c);
void    my_putnbr(int n);
void    my_putstr(char *str);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *str);

// PF
int main_function(char const *format, va_list list);
int unsigned_octal(unsigned int n, char *base);
int unsigned_hexadecimal(unsigned int n, char *base);
int flags_c(va_list list);
int flags_s(va_list list);
int flags_d(va_list list);
int flags_i(va_list list);
int flags_o(va_list list);
int flags_u(va_list list);
int flags_x(va_list list);
int flags_dot(va_list list);
int flags_upper_x(va_list list);
int flags_f(va_list list);
int flags_percent(va_list list);
void flagus(void (**ptrf)());

// Project
int push(elem_t **list, int valeur);
void dump(elem_t *list);
int pop(elem_t **pile);
int _add(elem_t **pile);
int _sub(elem_t **pile);
int _mul(elem_t **pile);
int _div(elem_t **pile);
int _mod(elem_t **pile);
int assert(elem_t **pile, int value);
void getAvm(char* path);
void exitAndMsg(char* msg, int code);
int isRegFile(const char *p);

#endif
