#ifndef CODIGO_PARAGEM_H
#define CODIGO_PARAGEM_H

#include "utils.h"
#include "Structs.h"

// Extras
ptrPar geraCod(ptrPar p, int pos, int total);
ptrPar preencheLista_Paragens(ptrPar p, int *total);
int verificaNome_Paragens(ptrPar p, char* nome, int total);
ptrPar dell(ptrPar p, int pos, int *total);

// Funções do Enunciado
ptrPar registarPar(ptrPar p, int *total);
ptrPar eliminaPar(ptrPar p, int *total);
void vizualizarPar(ptrPar p, int total);

#endif //CODIGO_PARAGEM_H
