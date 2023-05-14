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
    ptrLin linAssoc;    // <- lista ligada de linhas
    int nLinAssoc;
};

struct Linha {
    char nome[50];
    ptrPar parAssoc;   // <- array dinamico de paragens
    int nParAssoc;
    ptrLin prox;
};

void init_rand();                // <- inicializa gerador de valores aleatórios
char* tolowerString(char* s);    // <- devolve uma string igual à passada por parâmetro mas toda em lowercase
void listaVazia();               // <- mensagem de erro quando a lista se encontra vazia
int erroMemoria();               // <- mensagem de erro quando a alocaçãod e memoria falha

#endif //CODIGO_UTILS_H
