#ifndef CODIGO_PRECURSO_H
#define CODIGO_PRECURSO_H

#include "Utils.h"
#include "Menu.h"

ptrPrec createNewPrec();
void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal);
int calculaPrecursos(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish);
void calculaPrecursosTransbord(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish, int nPrec);
void mostraPrecurso(ptrPrec p, int n, int transbordFlag);
ptrPrec addToParagens(ptrPrec p, char* nome); // <- Adiciona uma paragem à array de paragens do precurso
ptrPrec removeFromParagens(ptrPrec p);
ptrPrec addToLinhas(ptrPrec p, char* nome);         // <- Adiciona uma linha à lsita ligada de paragens do precurso
ptrPrec removeFromLinhas(ptrPrec p);
ptrLin searchPar(ptrPar listPar, int parTotal, char* nomePar);
ptrLin searchLin(ptrLin listLin, char* nomeLin);        // <- recebe a linha na lista de linhas associadas a uma paragem
                                                        // e devolve essa mesma linha mas na lista que contém todas as linhas
                                                        // registadas no sistema de modo a que possamos aceder Às paragens dessa linha


// apagar depois
void printPrec(ptrPrec p);

#endif //CODIGO_PRECURSO_H
