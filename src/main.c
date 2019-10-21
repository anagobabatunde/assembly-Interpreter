#include "../lib/lib.h"

int main()
{
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