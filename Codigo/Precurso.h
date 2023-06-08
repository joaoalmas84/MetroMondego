#ifndef CODIGO_PRECURSO_H
#define CODIGO_PRECURSO_H

#include "Utils.h"
#include "Menu.h"

ptrPrec createNewPrec();
void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal);
ptrPrec calculaPrecursos(ptrPrec p, ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish, int transbord);
void mostraPrecurso(ptrPrec p);
ptrPrec addToParagens(ptrPrec p, char* nome); // <- Adiciona uma paragem à array de paragens do precurso
ptrPrec addToLinhas(ptrPrec p, char* nome);         // <- Adiciona uma linha à lsita ligada de paragens do precurso
ptrLin searchLin(ptrLin listLin, char* nomeLin);        // <- recebe a linha na lista de linhas associadas a uma paragem
                                                        // e devolve essa mesma linha mas na lista que contém todas as linhas
                                                        // registadas no sistema de modo a que possamos aceder Às paragens dessa linha
#endif //CODIGO_PRECURSO_H
