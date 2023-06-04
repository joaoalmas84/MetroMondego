#ifndef CODIGO_PRECURSO_H
#define CODIGO_PRECURSO_H

#include "Utils.h"
#include "Menu.h"

void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal);
void calculaPrecursos(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish);
void mostraPrecurso(char** linhas, char** paragens);

#endif //CODIGO_PRECURSO_H
