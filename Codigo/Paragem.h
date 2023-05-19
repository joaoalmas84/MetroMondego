#ifndef CODIGO_PARAGEM_H
#define CODIGO_PARAGEM_H

#include "Utils.h"
#include "Menu.h"

// Funções auxiliares
int verificaNome_Paragens(ptrPar lista, char *nome, int total); // <- devolve 1 de nome existir em lista
int verificaCod_Paragens(ptrPar lista, char *cod, int total); // <- devolve 1 de cod existir em lista
char* geraCod();    // <- devolve string com 4 caracteres (letras e números) apenas, todos em uppercase
ptrPar preencheLista_Paragens(ptrPar p, int *total); // <- Preenche o array com 3 paragens

// Funcionalidades
ptrPar addPar(ptrPar lista, char *nome, char *cod, int *total);                 // <- adiciona paragem
ptrPar dellPar(ptrPar lista, char *cod, int *total);                            // <- elimina paragem
ptrLin addLin_Par(ptrLin list, ptrLin lin);

#endif //CODIGO_PARAGEM_H
