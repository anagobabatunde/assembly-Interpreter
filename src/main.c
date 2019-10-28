#include "../lib/lib.h"

int main(int argc, char **argv)
{
    if (argc>=3 || argc<=1) {
        printf("Usage: ./abstractvm path/to/program.avm\n(Hint: there's pre-made AVM files in the avms folder.)\n");
        return 1;
    } else if (argc==2) { // TODO : is if not needed ?
        adat_t data;
        data = getAvm(argv[1]);
        if (data.ret == 1) {
            if (data.msg)
                my_printf("%s\n" , data.msg);
            return 1;
        }
    }
    elem_t *list = NULL;

    for (int i = 0; i < 11; i++)
    {
        push(&list, i);
    }
    dump(list);

    // printf("apres\n\n");
    // printf("j'ai enleve ça %d\n",pop(&list));
    return 0;
}