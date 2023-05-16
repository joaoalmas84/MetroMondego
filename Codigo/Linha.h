#ifndef CODIGO_LINHA_H
#define CODIGO_LINHA_H

#include "Utils.h"
#include "Paragem.h"
// Funções auxiliares
int verificaNome_Lin(ptrLin p, char* nome);  // <- devolve 1 se nome existir em p
ptrLin insereLin(ptrLin p, ptrLin novo);

// Funcionalidades
ptrLin addLin(ptrLin p, char* nome, char*cod, ptrPar listaP, int parTotal);   // <- adiciona Linha
ptrLin dellLin(ptrLin p, char* nome);
ptrLin removePar_Lin(ptrLin p, char* cod);
ptrLin alterName_Lin(ptrLin p, char* newName);
ptrLin addPar_Lin(ptrLin p, char* nome, char*cod, ptrPar listaP, int parTotal, int flag); // <- se flag == 0: estamos a adicionar a primeira paragem,
                                                                                          //    o que significa que temos acesso ao ponteiro da nova linha
                                                                                          //    se flag == 1: temos de pegar no nome e ir procurar a linha na lista
#endif //CODIGO_LINHA_H
