#ifndef CODIGO_PRECURSO_H
#define CODIGO_PRECURSO_H

#include "Utils.h"
#include "Menu.h"

void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal);
void calculaPrecursos(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish, char** linhas, char ** paragens, int *numPar, int *numLin, int transbord);
void mostraPrecurso(char** linhas, char** paragens, int numLin, int numPar);
char** addToLista(char** list, int* tam, char* newString); // <- Adiciona uma string a um array de strings
ptrLin searchLin(ptrLin listLin, char* nomeLin);    // <- recebe a linha na lista de linhas associadas a uma paragem
                                                    // e devolve essa mesma linha mas na lista que contém todas as linhas
                                                    // registadas no sistema de modo a que possamos aceder Às paragens dessa linha
#endif //CODIGO_PRECURSO_H
