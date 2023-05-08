#ifndef CODIGO_LINHA_H
#define CODIGO_LINHA_H

#include "utils.h"
#include "Paragem.h"

// Extras
int verificaNome_Linhas(ptrLin p, char* nome);
ptrLin insereLin(ptrLin p, ptrLin novo);
ptrLin preencheLista_Linhas(ptrLin p);
ptrLin erroMemoria_Lin(ptrLin p);// Mensagem de erro quando a alocação de memória falha
void visualizarParExistentes(ptrLin p);
ptrLin associaParagem(ptrLin pL, ptrPar par_a_associar, int pos);

// Funções do Enunciado
ptrLin addLin(ptrLin linList, ptrPar parList, int parTotal);
ptrLin atualizaLin(ptrLin p, char nome[50]);
void listaLin(ptrLin p);

#endif //CODIGO_LINHA_H
