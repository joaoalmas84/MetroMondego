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

typedef struct Percurso perc, *ptrPerc;

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

struct Percurso {
    ptrPar paragens;    // <- array dinamico de paragens
    ptrLin linhas;      // <- lista ligada de linhas
    int nPar;
};

void init_rand();                // <- inicializa gerador de valores aleatórios
char* tolowerString(char* s);    // <- devolve uma string igual à passada por parâmetro mas toda em lowercase
void listaVazia();               // <- mensagem de erro quando a lista se encontra vazia
int erroMemoria();               // <- mensagem de erro quando a alocação de memoria falha
int erroFile();                  // <- mensagem de erro quando a abertura do ficheiro falha

#endif //CODIGO_UTILS_H
