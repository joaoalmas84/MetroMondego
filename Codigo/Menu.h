#ifndef CODIGO_MENU_H
#define CODIGO_MENU_H

#include "Utils.h"
#include "Paragem.h"
#include "Linha.h"

// +-----------------------+
// | Interface do programa |
// +-----------------------+
/*
 * Estas funções não alterarem a informação do sistema, servem apenas para obter a informação
 * introduzida pelo utilizador e passa-la para as verdadeiras funções de gestão de memória
 * contidas nos ficheiros Paragem.c/.h e Lista.c/.h
*/

void menu(ptrLin linList, ptrPar parList, int parTotal);    // <- Função principal (só para não lhe chamar main)

// Colunas
ptrPar adicionaParagem(ptrPar lista, int *parTotal);
ptrLin atualizaParagem(ptrLin listaL, ptrPar listaP, int parTotal);
ptrPar eliminaParagem(ptrPar lista);
void listPar(ptrPar lista, int total);

// Linhas
ptrLin adicionaLinha(ptrLin listaL, ptrPar listaP, int parTotal);
ptrLin atualizaLinha(ptrLin listaL, ptrPar listaP, int parTotal);
ptrLin eliminaLinha(ptrLin lista, char* nome);
void listaLin(ptrLin p);

#endif //CODIGO_MENU_H
