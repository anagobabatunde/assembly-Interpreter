/*
** ETNA PROJECT, 08/11/2019 by talamo_a
** main.c
** File description:
**      AVM Main function
*/

#include "../lib/lib.h"

int main(int argc, char **argv)
{
    adat_t data;
    data = mall_all(data);
    if (argc >= 3 || argc <= 1) {
        my_printf("Usage: ./abstractvm path/to/program.avm\n");
        return 1;
    } else if (argc == 2) {
        data = get_avm(data, argv[1]);
        handle_avm(&data);
        if (data.adt.ret == 1) {
            if (data.adt.msg)
                my_printf("%s\n" , data.adt.msg);
            free_all(data);
            return data.adt.ret;
        }
        free_all(data);
    }
    return 0;
}