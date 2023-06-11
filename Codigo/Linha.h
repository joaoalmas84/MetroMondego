#ifndef CODIGO_LINHA_H
#define CODIGO_LINHA_H

#include "Utils.h"
#include "Paragem.h"

// Funções auxiliares
int verificaNome_Lin(ptrLin listLin, char* nome);   // <- devolve 1 se nome existir em listLin
ptrLin insereLin(ptrLin listLin, ptrLin newLin);    // <- insere a newLin na listLin
ptrLin createNewLin(char *nome);                    // <- aloca memoria para uma nova linha e inicializa todos os campos
ptrLin removePar_All(ptrLin listLin, ptrPar listPar, int parTotal, char* cod); // <- remove uma paragem especifica de todas as linhas

// Funcionalidades
ptrLin dellLin(ptrLin listLin, char* nome);
ptrLin removePar_Lin(ptrLin lin, char* cod);
ptrLin alterName_Lin(ptrLin lin, char* newName, ptrPar listPar, int parTotal);
ptrLin addPar_Lin(ptrLin listLin, char* nomeLin,  ptrPar listPar, char* nomePar, char* cod, int totalPar, int flag);
ptrLin getLinFromFile(ptrLin listLin, char* fileName);                                      // <- Leitura do nome da linha pelo ficheiro linha
ptrPar getParToLinFromFile(ptrLin listLin, ptrPar listPar, int* totalPar, char* fileName);  // <- Leitura das paragens do ficheiro linha
                                                                                            // e adição das mesmas à linha

#endif //CODIGO_LINHA_H

