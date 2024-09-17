#ifndef CODIGO_MENU_H
#define CODIGO_MENU_H

#include "Utils.h"
#include "Paragem.h"
#include "Linha.h"
#include "Percurso.h"

// +-----------------------+
// | Interface do programa |
// +-----------------------+
/*
 * Estas funções não alteram a informação do sistema, servem apenas para obter a informação
 * introduzida pelo utilizador e passa-la para as verdadeiras funções de gestão de memória
 * contidas nos ficheiros Paragem.c/.h e Linha.c/.h e cálculo de percursos Percurso.c/.h
*/

void menu(ptrLin listLin, ptrPar listPar, int *parTotal);    // <- Função principal (só para não lhe chamar main)
void menuCounter(int parTotal, int linTotal);                // <- Apresentação do n.º de paragens e n.º de linhas

// Paragens
ptrPar registaParagem(ptrPar listPar, int *parTotal);
ptrPar eliminaParagem(ptrLin listLin, ptrPar listPar, int *totalPar);
void visualizaPar(ptrPar listPar, int parTotal, char* cod, char* nome); // <- Lista uma unica paragem
void visualizaParAll(ptrPar listPar, int parTotal);                     // <- Lista todas as paragens
void visualizaParAllDetailed(ptrPar listPar, int parTotal);             // <- Lista todas as paragens detalhadamente

// Linhas
ptrLin adicionaLinha(ptrLin listLin, ptrPar listPar, int totalPar);
ptrLin atualizaLinha(ptrLin listLin, ptrPar listPar, int totalPar);
ptrLin removeParagem_Lin(ptrLin listLin, ptrPar listaP, int parTotal, char *nomePar);
ptrLin alteraNome_Lin(ptrLin listLin, char *nomeLin, ptrPar listPar, int parTotal);
void visualizaLin(ptrLin listLin, char* nome);      // <- Lista uma unica linha
void visualizaLinAll(ptrLin listLin);               // <- Lista todas as linhas
void visualizaLinAllDetailed(ptrLin listLin);       // <- Lista todas as linhas detalhadamente

// Dados
void saveDadosPar(ptrPar listPar, int totalPar);
ptrPar loadDadosPar(ptrPar listPar, int* totalPar);
void saveDadosLin(ptrLin listLin);
ptrLin loadDadosLin(ptrLin listLin);

// Extras
void getCodUser(char* cod, ptrPar listPar, int parTotal);
void getNameParUser(char* name, ptrPar listPar, int parTotal);
void getCodAddPar(char* cod, ptrPar listaP, int parTotal, char* nomeLin, ptrLin listaL);

#endif //CODIGO_MENU_H
