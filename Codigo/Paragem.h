#ifndef CODIGO_PARAGEM_H
#define CODIGO_PARAGEM_H

#include "Utils.h"
#include "Linha.h"

// Funções auxiliares
int verificaNome_Paragens(ptrPar listPar, char *nome, int total);  // <- devolve 1 de nome existir em lista
int verificaCod_Paragens(ptrPar listPar, char *cod, int total);       // <- devolve 1 de cod existir em lista
char* geraCod();                                                    // <- devolve string com 4 caracteres (letras e números) apenas, todos em uppercase
int checkPar_Dell(ptrPar lista, int total, char* cod);          // <- devolve 1 se a paragem a eliminar não tiver linhas associadas (pode ser eliminada)

// Funcionalidades
ptrPar addPar(ptrPar listPar, char *nome, char *cod, int *total);     // <- adiciona paragem
ptrPar dellPar(ptrPar listPar, char *cod, int *total);                // <- elimina paragem
ptrPar addLin_Par(ptrLin listLin, char* nomeLin, ptrPar listPar, int parTotal, char* cod, char* nomePar); // <- adiciona linha a paragem
ptrPar removeLin_Par(ptrPar listPar, char* cod, int totalPar, char* nomeLin); // <- remove linha da paragem

#endif //CODIGO_PARAGEM_H
