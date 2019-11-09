#include "../lib/lib.h"
#include <stdio.h>

int return_first_paren(char *line) {
    int tmp = 0;
    for(int i = 0; line[i] != '('; i++) {
        tmp = i;
    }
    return tmp + 1;
}

int return_first_space(char *line) {
  int tmp = 0;
  for (int i = 0; line[i] != 32; i++) {
    tmp = i;
  }
  return tmp + 1;
}

char *get_operation(char *line) {
  char *op = malloc(sizeof(char));
  int tmp = 0;
  char *result;
  for (int i = 0; line[i] != 32; i++) {
    op[i] = line[i];
    tmp = i;
  }
  op[tmp + 1] = '\0';
  result = my_strdup(op);
  free(op);
  return result;
}

char *get_type(char *line) {
  char *type = malloc(sizeof(char));
  int i, len = 0;
  char *result;
  for (i = return_first_space(line); line[i] != '('; i++) {
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
    printf("\n j'ai reçu la phrase %s\n",line);
    printf("--je suis la pos de la first parenthese %d\n\n" , return_first_paren(line));
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

void parser(char *line, elem_t **list) {
  elem_t *tmp;
  tmp = *list;
  int (*func[6])(elem_t * *list) = {pop, _add, _sub, _mul, _div, _mod};
  int (*function[2])(elem_t **list, int value) = {push, assert};

  if (my_strcmp(line, "exit") == 0) {
    exit(1);
  }
  char *operation = get_operation(line);
  char op[8][5] = {"pop", "add", "sub", "mul", "div", "mod", "\0"};
  char manip[3][6] = {"push", "assert", "\0"};

  if (notAlone(line) != 0) {
    for (int i = 0; my_strcmp(manip[i], "\0") != 0; i++) {
      if (my_strcmp(operation, manip[i]) == 0) {
        printf("je suis la vrai operation %s %s\n", manip[i], operation);
        printf("--je suis le chiffre %s\n",get_value(line));
        // function[i](&tmp, );
      }
    }
  } else {
    for (int i = 0; my_strcmp(op[i], "\0") != 0; i++) {
      if (my_strcmp(operation, op[i]) == 0) {
        printf("je suis la vrai fonction %s \n", op[i]);
        func[i](&tmp);
      }
    }
  }
}

elem_t *handleAvm(adat_t *avm) {
  elem_t *list = NULL;
  adat_t *adat = NULL;
  adat = avm;
  int k, len = 0;
  char *tBfr = malloc(sizeof(char *));
  // tBfr[0] = '\0';
  for (k = 0; adat->data[k] != '\0'; k++) {
    if (adat->data[k] == '\n' || adat->data[k] == '\0') {
      // if (notAlone(tBfr))
      parser(tBfr, &list);
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
