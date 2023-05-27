#include "Linha.h"

// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funções auxiliares ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// devolve 1 se nome existir em p
int verificaNome_Lin(ptrLin listLin, char* nome) {
    if (listLin == NULL) {
        return 0;
    } else {
        ptrLin aux = listLin;
        while (aux != NULL) {
            if (strcmp(tolowerString(aux->nome), tolowerString(nome)) == 0) {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

ptrLin insereLin(ptrLin listLin, ptrLin newLin) {
    if (listLin == NULL) {
        listLin = newLin;
        return listLin;
    } else {
        ptrLin aux = listLin;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = newLin;
        newLin->prox = NULL;
        return listLin;
    }
}

ptrLin createNewLin(char *nome) {
    ptrLin novo = malloc(sizeof(lin));
    if (novo == NULL) {
        if (erroMemoria() == 1) {
            return NULL;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }

    strcpy(novo->nome, nome);
    novo->parAssoc = NULL;
    novo->nParAssoc = 0;
    novo->prox = NULL;

    return novo;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funcionalidades |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

ptrLin dellLin(ptrLin listLin, char* nome) {
    ptrLin aux1 = listLin, aux2 = aux1->prox;
    while (aux1 != NULL) {
        if (strcmp(tolowerString(aux1->nome), tolowerString(nome)) == 0) {
            listLin = aux1->prox;
            free(aux1);
            return listLin;
        } else if (strcmp(tolowerString(aux2->nome), tolowerString(nome)) == 0) {
            aux1->prox = aux2->prox;
            free(aux2);
            return listLin;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return listLin;
}

ptrLin removePar_Lin(ptrLin lin, char* cod) {
    for (int i = 0; i < lin->nParAssoc; ++i) {
        if (strcmp(tolowerString(lin->parAssoc[i].cod), tolowerString(cod)) == 0) {
            for (int j = i; j < lin->nParAssoc ; ++j) {
                lin->parAssoc[j] = lin->parAssoc[j+1];
            }
            break;
        }
    }
    ptrPar aux = realloc(lin->parAssoc, sizeof(par)*(lin->nParAssoc-1));
    if (aux == NULL && lin->nParAssoc-1 > 0) {
        if (erroMemoria() == 1) {
            return lin;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    lin->nParAssoc--;
    lin->parAssoc = aux;
    return lin;
}

ptrLin alterName_Lin(ptrLin lin, char* newName) {
    strcpy(lin->nome, newName);
    return lin;
}

ptrLin addPar_Lin(ptrLin listLin, char* nome, ptrPar listPar, char*cod, int totalPar) {
    int i;
    ptrLin aux = listLin;
    while (aux->prox != NULL) {
        if (strcmp(tolowerString(aux->nome), tolowerString(nome)) == 0) {
            break;
        }
        aux = aux->prox;
    }

    for (i = 0; i < totalPar; ++i) {
        if (strcmp(tolowerString(listPar[i].cod), tolowerString(cod)) == 0) {
            break;
        }
    }

    aux->parAssoc = realloc(aux->parAssoc, sizeof(par)*(aux->nParAssoc+1));
    if (aux->parAssoc == NULL) {
        if (erroMemoria() == 1) {
            return aux;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    aux->nParAssoc++;
    aux->parAssoc[aux->nParAssoc-1] = listPar[i];

    listPar[i].linAssoc = addLin_Par(listPar[i].linAssoc, aux);
    listPar[i].nLinAssoc++;

    return listLin;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
