#ifndef CODIGO_PRECURSO_H
#define CODIGO_PRECURSO_H

#include "Utils.h"
#include "Menu.h"

void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal);
ptrLin calculaPrecursos(ptrLin listLin, ptrPar listPar, int parTotal, ptrLin precurso, char* nomeStart, char* nomeFinish);

#endif //CODIGO_PRECURSO_H
