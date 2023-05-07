#ifndef CODIGO_UTILS_H
#define CODIGO_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

typedef struct Paragem par, *ptrPar;

typedef struct Linha lin, *ptrLin;

struct Paragem {
    char nome[50];
    char cod[5];
    ptrLin linAssoiadas;// <- lista ligada de linhas
    int totLinAssociadas;
};

struct Linha {
    char nome[50];
    ptrPar parExistentes; // <- array dinamico de paragens
    int nParExitentes;
    ptrLin prox;
};

void init_rand();// inicializa gerador de valores aleatórios
char* tolowerString(char* s);// devolve uma string igual à passada por parâmetro mas toda em lowercase
ptrPar erroMemoria_Par(ptrPar p);// Mensagem de erro quando a alocação de memória falha
ptrLin erroMemoria_Lin(ptrLin p);//


#endif //CODIGO_UTILS_H
