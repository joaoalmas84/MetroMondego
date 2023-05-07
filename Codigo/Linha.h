#ifndef CODIGO_LINHA_H
#define CODIGO_LINHA_H

#include "utils.h"
#include "Paragem.h"

// Extras
int verificaNome_Linhas(ptrLin p, char* nome);
ptrLin insereLin(ptrLin p, ptrLin novo);
ptrLin preencheLista_Linhas(ptrLin p);

// Funções do Enunciado
ptrLin adicionarLinha(ptrLin pL, ptrPar pP, int parTotal);
ptrLin atualizarLinha(ptrLin p, char nome[50]);
void visualizarLinhas(ptrLin p);
#endif //CODIGO_LINHA_H
