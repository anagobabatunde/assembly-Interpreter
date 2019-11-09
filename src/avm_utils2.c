#include "../lib/lib.h"

char *get_value(char *line) {
    char *value = malloc(sizeof(char));
    int i, len = 0;
    char *result;
    for(i = return_first_paren(line); line[i] != ')'; i++) {
        len = my_strlen(value);
        if (line[i] != 32)
            value[len] = line[i];
    } 
    value[len + 1] = '\0';
    result = my_strdup(value);
    free(value);
    return result;
}

int not_alone(char *str) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == ' ')
      return 1;
    i++;
  }
  return 0;
}
