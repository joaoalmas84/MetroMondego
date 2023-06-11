#ifndef CODIGO_PERCURSO_H
#define CODIGO_PERCURSO_H

#include "Utils.h"
#include "Menu.h"

void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal);
int calculaPercursos(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish); // <- calcula percursos sem transbordo
void calculaPercursosTransbord(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish, int nPrec); // <- calcula percursos com transbordo
void mostraPercursos(ptrPerc p, int n, int transbordFlag);
ptrPerc createNewPerc();                            // <- aloca memoria para um novo percurso e inicializa todos os campos
ptrPerc addToParagens(ptrPerc p, char* nome);       // <- Adiciona uma paragem ao array de paragens do percurso
ptrPerc removeFromParagens(ptrPerc p);              // <- Remove uma paragem do array de paragens do percurso
ptrPerc addToLinhas(ptrPerc p, char* nome);         // <- Adiciona uma linha à lista ligada de paragens do percurso
ptrPerc removeFromLinhas(ptrPerc p);                // <- Remove uma linha da lista ligada de paragens do percurso
ptrLin searchPar(ptrPar listPar, int parTotal, char* nomePar);  // <- recebe a paragem na lista de paragens associadas a uma linha
                                                                // e devolve essa mesma paragem mas na lista que contém todas as paragens
                                                                // registadas no sistema de modo a que possamos aceder às paragens dessa linha
ptrLin searchLin(ptrLin listLin, char* nomeLin);        // <- recebe a linha na lista de linhas associadas a uma paragem
                                                        // e devolve essa mesma linha mas na lista que contém todas as linhas
                                                        // registadas no sistema de modo a que possamos aceder Às paragens dessa linha

#endif //CODIGO_PERCURSO_H
