#ifndef CODIGO_UTILS_H
#define CODIGO_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

void init_rand();// inicializa gerador de valores aleatórios
char* tolowerString(char* s);// devolve uma string igual à passada por parâmetro mas toda em lowercase

#endif //CODIGO_UTILS_H
