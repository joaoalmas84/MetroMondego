#ifndef CODIGO_PARAGEM_H
#define CODIGO_PARAGEM_H

#include "Utils.h"
#include "Linha.h"

// Funções auxiliares
int verificaNome_Paragens(ptrPar listPar, char *nome, int total);  // <- devolve 1 de nome existir em lista
int verificaCod_Paragens(ptrPar listPar, char *cod, int total);       // <- devolve 1 de cod existir em lista
char* geraCod();                                                    // <- devolve string com 4 caracteres (letras e números) apenas, todos em uppercase
ptrPar preencheLista_Paragens(ptrPar listPar, int *total);                // <- Preenche o array com 3 paragens

// Funcionalidades
ptrPar addPar(ptrPar listPar, char *nome, char *cod, int *total);     // <- adiciona paragem
ptrPar dellPar(ptrPar listPar, char *cod, int *total);                // <- elimina paragem
ptrPar addLin_Par(ptrPar listPar, char* cod, int totalPar, ptrLin lin);

#endif //CODIGO_PARAGEM_H
