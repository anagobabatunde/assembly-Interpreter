/*
** ETNA PROJECT, 29/09/2018 by talamo_a
** my_getnbr.c
** File description:
**      Write a function to read an integer from a string taken as parameter.
*/

#include "../../lib/lib.h"

int my_getnbr(char *str)
{
    int i = 0;
    int isneg = 1;
    int res = 0;

    while (str[i] == 43 || str[i] == 45 ){
        if (str[i] == 45)
            isneg *= -1;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57){
        res *= 10;
        res += str[i] - 48;
        i++;
    }
    return (isneg * res);
}
