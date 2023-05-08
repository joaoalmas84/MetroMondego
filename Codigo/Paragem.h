#ifndef CODIGO_PARAGEM_H
#define CODIGO_PARAGEM_H

#include "Utils.h"

// Funções auxiliares
int verificaNome_Paragens(ptrPar lista, char* nome, int total); // <- devolve 1 de nome existir em lista
int verificaCod_Paragens(ptrPar lista, char cod[4], int total); // <- devolve 1 de cod existir em lista
char* geraCod();    // <- devolve string com 4 caracteres (letras e números) apenas, todos em uppercase
ptrPar erroMemoria_Par(ptrPar p);   // <- mensagem de erro quando a alocação de memória falha

// Funcionalidades
ptrPar addPar(ptrPar lista, char *nome, char cod[4], int *total); // <- adiciona paragem
#endif //CODIGO_PARAGEM_H
