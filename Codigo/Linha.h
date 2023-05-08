#ifndef CODIGO_LINHA_H
#define CODIGO_LINHA_H

#include "Utils.h"

// Funções auxiliares
ptrLin preencheLista_Linhas(ptrLin p);          // <- Preenche a lsita com 3 linhas
int verificaNome_Linhas(ptrLin p, char* nome);  // <- devolve 1 se nome existir em p
ptrLin insereLin(ptrLin p, ptrLin novo);
ptrLin associaPar(ptrPar novo, ptrPar listaP, char *cod);
ptrLin erroMemoria_Lin(ptrLin p);               // <- Mensagem de erro quando a alocação de memória falha


// Funcionalidades
ptrLin addLin(ptrLin listaL, ptrPar listaP, int parTotal, int *nparAssociadas); // <- adiciona linha

#endif //CODIGO_LINHA_H
