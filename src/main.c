#include "../lib/lib.h"

int main(int argc, char **argv)
{
    elem_t *result = NULL;
    adat_t data;
    if (argc>=3 || argc<=1) {
        my_printf("Usage: ./abstractvm path/to/program.avm\n(Hint: there's pre-made AVM files in the res folder.)\n");
        return 1;
    } else if (argc==2) { // TODO : is if not needed ?
        data = getAvm(argv[1]);
        if (data.adt.ret == 1) {
            if (data.adt.msg)
                my_printf("%s\n" , data.adt.msg);
            return data.adt.ret;
        }
    }
    result = handleAvm(&data);

    dump(result);

    // my_printf("apres\n\n");
    // my_printf("j'ai enleve ça %d\n",pop(&list));
    my_printf("\n--endline--\n");
    return 0;
}