/*
** ETNA PROJECT, 10/01/2019 by anago_b
** function for my_printf
** File description:
**      test all flage
*/

#include "../../lib/lib.h"
#include "../../lib/struct.h"

int undefined_flag(int pres)
{
    if (pres == 0) {
        my_putstr("error undefined flag");
        return (1);
    }
    return (0);
}

list_t arr[] = {
    {'d', &flags_d},
    {'i', &flags_i},
    {'s', &flags_s},
    {'c', &flags_c},
    {'o', &flags_o},
    {'x', &flags_x},
    {'X', &flags_upper_x},
    {'u', &flags_u},
    {'f', &flags_f},
    {'%', &flags_percent},
    {'\0', NULL}
};

int verify_flag(char c, va_list list)
{
    int length = 0;
    for (int i = 0; arr[i].c != '\0'; i++) {
        if (arr[i].c == c) {
            length += arr[i].ptrf(list);
            return (length);
        }
    }
    return (0);
}

int main_function(char const *format, va_list list)
{
    int pres = 0;
    char *tab = malloc(sizeof(char) * 32);
    int j = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != 0) {
            pres = pres + verify_flag(format[++i], list);
            if (undefined_flag(pres) == 1) {
                break;
            }
        }
        else {
            tab[j+1] = format[i];
            my_putchar(format[i]);
        }
    }
    tab[j] = '\0';
    pres  += my_strlen(tab);
    free(tab);
    return (pres);
}
