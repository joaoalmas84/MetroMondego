#ifndef CODIGO_LINHA_H
#define CODIGO_LINHA_H

#include "Utils.h"
#include "Paragem.h"

// Funções auxiliares
int verificaNome_Lin(ptrLin listLin, char* nome);  // <- devolve 1 se nome existir em listLin
ptrLin insereLin(ptrLin listLin, ptrLin newLin);
ptrLin createNewLin(char *nome);
ptrLin batota(ptrLin listLin, ptrPar listPar);

// Funcionalidades
ptrLin dellLin(ptrLin lin, char* nome);
ptrLin removePar_Lin(ptrLin lin, char* cod);
ptrLin alterName_Lin(ptrLin lin, char* newName);
ptrLin addPar_Lin(ptrLin listLin, char* nome,  ptrPar listPar, char*cod, int totalPar);

#endif //CODIGO_LINHA_H

