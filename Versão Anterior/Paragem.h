#ifndef CODIGO_PARAGEM_H
#define CODIGO_PARAGEM_H

#include "utils.h"

// Extras
ptrPar geraCod(ptrPar p, int pos, int total);
ptrPar preencheLista_Paragens(ptrPar p, int *total);
int verificaNome_Paragens(ptrPar p, char* nome, int total);// <- devolve 0 se nome existir em p
int verificaCod_Paragens(ptrPar p, char cod[4], int total, int *pos);// <- devolve 0 se cod existir em p
ptrPar dell(ptrPar p, int pos, int total);
ptrPar erroMemoria_Par(ptrPar p);// Mensagem de erro quando a alocação de memória falha
void listaVazia_Par(); // Mensagem de erro quando a lista se encontra vazia

// Funções do Enunciado
ptrPar addPar(ptrPar p, int *total);
ptrPar dellPar(ptrPar p, int *total);
void listPar(ptrPar p, int total);

#endif //CODIGO_PARAGEM_H
