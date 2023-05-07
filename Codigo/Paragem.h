#ifndef CODIGO_PARAGEM_H
#define CODIGO_PARAGEM_H

#include "utils.h"

// Extras
ptrPar geraCod(ptrPar p, int pos, int total);
ptrPar preencheLista_Paragens(ptrPar p, int *total);
int verificaNome_Paragens(ptrPar p, char* nome, int total);// <- devolve 0 se nome existir em p
int verificaCod_Paragens(ptrPar p, char cod[4], int total);// <- devolve 0 se cod existir em p
ptrPar dell(ptrPar p, int pos, int total);

// Funções do Enunciado
ptrPar registarPar(ptrPar p, int *total);
ptrPar eliminaPar(ptrPar p, int *total);
void visualizarPar(ptrPar p, int total);

#endif //CODIGO_PARAGEM_H
