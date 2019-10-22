/*
** ETNA PROJECT, 10/01/2019 by anago_b
** function for my_printf
** File description:
**     flag func 3
*/

#include "../../lib/lib.h"

void my_putnbr_float(double n)
{
    int nb;
    int i_precision = 6;

    nb = n;
    my_putnbr(nb);
    my_putchar('.');
    while (i_precision--) {
        n = (n - nb) * 10;
        nb = n;
        my_putnbr(nb);
    }
}

int flags_f(va_list list)
{
    int n = 0;
    double var = va_arg(list, double);

    n = var;
    my_putnbr_float(var);
    return (my_nbrlen(n) + 7);
}

int flags_percent(va_list list)
{
    double var = va_arg(list, double);

    (void)var;
    my_putstr("%");
    return (1);
}

int flags_dot(va_list list)
{
    int *tab = 0;

    tab = malloc(sizeof(int));
    char *str = va_arg(list, char *);
    my_printf("%s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' &&  str[i + 1] == '.') {
            while (str[i] != 'f') {
                tab[i] = str[i] - 55;
                i++;
            }
        }
    }
    free(tab);
    return (1);
}