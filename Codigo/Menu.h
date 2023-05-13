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

// Paragens
ptrPar adicionaParagem(ptrPar lista, int *total);
ptrPar atualizaParagem(ptrPar lista, int total);
ptrPar eliminaParagem(ptrPar lista, int *total);
void listPar(ptrPar lista, int total);

// Linhas
ptrLin adicionaLinha(ptrLin listaL, ptrPar listaP, int parTotal);
ptrLin atualizaLinha(ptrLin listaL, ptrPar listaP, int parTotal);
ptrLin eliminaLinha(ptrLin lista, char* nome);
void listaLin(ptrLin p); // <- Lista uma unica linha
void listaLinAll(ptrLin p); // <- Lista todas as linhas

// Linhas -> extras
void getCodUser(char *cod, ptrPar listaP, int parTotal);
#endif //CODIGO_MENU_H
