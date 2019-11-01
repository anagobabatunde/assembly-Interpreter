#include "./lib.h"

typedef struct list {
    char c;
    int (*ptrf)(va_list);
} list_t;