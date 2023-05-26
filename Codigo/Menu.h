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

void menu(ptrLin listLin, ptrPar listPar, int parTotal);    // <- Função principal (só para não lhe chamar main)

// Paragens
ptrPar registaParagem(ptrPar lista, int *total);
ptrPar eliminaParagem(ptrLin listLin, ptrPar listPar, int *totalPar);
void visualizaPar(ptrPar lista, int total, char* cod);  // <- Lista uma unica paragem
void visualizaParAll(ptrPar lista, int total);           // <- Lista todas as paragens
void visualizaParAllDetailed(ptrPar lista, int total);   // <- Lista todas as paragens detalhadamente

// Paragens -> extras
int checkPar_Dell(ptrPar listPar, int totalPar, char* cod);
ptrLin removePar_All(ptrLin listLin, ptrPar listPar, int parTotal, char* cod);

// Linhas
ptrLin adicionaLinha(ptrLin listLin, ptrPar listPar, int totalPar);
ptrLin eliminaLinha(ptrLin listLin);
ptrLin atualizaLinha(ptrLin listLin, ptrPar listPar, int totalPar);
ptrLin removeParagem_Lin(ptrLin listLin, ptrPar listaP, int parTotal, char *nomePar);
ptrLin alteraNome_Lin(ptrLin listLin, char *nomeLin);
void visualizaLin(ptrLin listLin, char* nome);    // <- Lista uma unica linha
void visualizaLinAll(ptrLin listLin);             // <- Lista todas as linhas
void visualizaLinAllDetailed(ptrLin listLin);     // <- Lista todas as linhas detalhadamente

// Linhas -> extras
void getCodUser(char* cod, ptrPar listaP, int parTotal, char* nomeLin, ptrLin listaL);
#endif //CODIGO_MENU_H
