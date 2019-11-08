#include "../lib/lib.h"
#include <stdio.h>

int return_first_paren(char *line)
{
    char *op = malloc(sizeof(char));
    int tmp = 0;
    for(int i = 0; line[i] != '('; i++) {
        op[i] = line[i];
        tmp = i;
    }
    op[tmp + 2] = '\0';
    return tmp + 1;
}

int return_first_space(char *line)
{
    char *op = malloc(sizeof(char));
    int tmp = 0;
    for(int i = 0; line[i] != 32; i++) {
        op[i] = line[i];
        tmp = i;
    }
    op[tmp + 2] = '\0';
    return tmp + 1;
}

char *get_operation(char *line)
{
    char *op = malloc(sizeof(char));
    int tmp = 0;
    char *result;
    for(int i = 0; line[i] != 32; i++) {
        op[i] = line[i];
        tmp = i;
    }
    op[tmp + 2] = '\0';
    result = my_strdup(op);
    free(op);
    return result;
}

char *get_type(char *line) {
    char *type = malloc(sizeof(char));
    int i, len = 0;
    char *result;
    for(i = return_first_space(line); line[i] != '('; i++) {
        len = my_strlen(type);
        if (line[i] != 32)
            type[len] = line[i];
    } 
    type[len + 2] = '\0';
    result = my_strdup(type);
    free(type);
    return result;
}

char *get_value(char *line) {
    char *value = malloc(sizeof(char));
    int i, len = 0;
    char *result;
    for(i = return_first_paren(line) + 1; line[i] != ')'; i++) {
        len = my_strlen(value);
        if (line[i] != 32)
            value[len] = line[i];
    } 
    value[len + 2] = '\0';
    result = my_strdup(value);
    free(value);
    return result;
}


void parser(char* line) {
    int (*func[6])(elem_t ** list) = {pop, _add, _sub, _mul, _div, _mod};
    char op[6][5] = {"pop","add","sub", "mul", "div", "mod"};
    for(int i = 0; op[i] == get_operation(line); i++) {
        printf("j'ai trouvé mon conjoint");
    }
    char *type = NULL;
    type = get_value(line);
    // my_printf("-%c-\n", type[0]);
    my_printf("-%s-\n", get_operation(line));
}

void handleAvm(adat_t *avm) {
    adat_t *adat = NULL;
    adat = avm;
    //char* data;
    int k, len = 0;
    char* tBfr =  malloc(sizeof(char*));
    // tBfr[0] = '\0';
    for (k = 0; adat->data[k] != '\0'; k++) {
        if (adat->data[k] == '\n' || adat->data[k] == '\0') {
            if (notAlone(tBfr))
                parser(tBfr);
            // my_printf("-nl-\n");
            tBfr[0] = '\0';
        } else {
            len = my_strlen(tBfr);
            tBfr[len++] = adat->data[k];
            tBfr[len] = '\0';
        }
    }
    free(tBfr);
}

int notAlone(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ')
            return 1;
        i++;
    }
    return 0;
}


