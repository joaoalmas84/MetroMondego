#ifndef CODIGO_LINHA_H
#define CODIGO_LINHA_H

#include "Utils.h"
#include "Paragem.h"
#include "Menu.h"
// Funções auxiliares
int verificaNome_Lin(ptrLin listLin, char* nome);  // <- devolve 1 se nome existir em listLin
ptrLin insereLin(ptrLin listLin, ptrLin newLin);
ptrLin createNewLin(char *nome);
ptrLin removePar_All(ptrLin listLin, ptrPar listPar, int parTotal, char* cod); // <- remove uma paragem especifica de todas as linhas

// Funcionalidades
ptrLin dellLin(ptrLin listLin, char* nome);
ptrLin removePar_Lin(ptrLin lin, char* cod);
ptrLin alterName_Lin(ptrLin lin, char* newName, ptrPar listPar, int parTotal);
ptrLin addPar_Lin(ptrLin listLin, char* nomeLin,  ptrPar listPar, char* nomePar, char* cod, int totalPar, int flag);
ptrLin getLinFromFile(ptrLin listLin, char *fileName);
ptrPar getParToLinFromFile(ptrLin listLin, ptrPar listPar, int* totalPar, char* fileName);

#endif //CODIGO_LINHA_H

