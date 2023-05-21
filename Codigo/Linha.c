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

ptrLin batota(ptrLin listLin, ptrPar listPar) {
    ptrLin l1 = malloc(sizeof(lin));
    ptrLin l2 = malloc(sizeof(lin));
    ptrLin l3 = malloc(sizeof(lin));
    if (l1 == NULL || l2 == NULL || l3 ==NULL) {
        if (erroMemoria() == 1) {
            return listLin;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }

    strcpy(l1->nome, "Skirt");
    l1->nParAssoc = 3;
    l1->parAssoc = malloc(sizeof(par)*3);
    if (l1->parAssoc == NULL) {
        if (erroMemoria() == 1) {
            return listLin;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    l1->parAssoc[0] = listPar[0];
    l1->parAssoc[1] = listPar[1];
    l1->parAssoc[2] = listPar[2];
    listLin = l1;
    l1->prox = l2;

    strcpy(l2->nome, "Bruh");
    l2->nParAssoc = 3;
    l2->parAssoc = malloc(sizeof(par)*3);
    if (l2->parAssoc == NULL) {
        if (erroMemoria() == 1) {
            return listLin;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    l2->parAssoc[0] = listPar[0];
    l2->parAssoc[1] = listPar[1];
    l2->parAssoc[2] = listPar[2];
    l2->prox = l3;

    strcpy(l3->nome, "Sonhar");
    l3->nParAssoc = 3;
    l3->parAssoc = malloc(sizeof(par)*3);
    if (l3->parAssoc == NULL) {
        if (erroMemoria() == 1) {
            return listLin;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    l3->parAssoc[0] = listPar[0];
    l3->parAssoc[1] = listPar[1];
    l3->parAssoc[2] = listPar[2];
    l3->prox = NULL;

    return listLin;
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
    if (aux == NULL) {
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

ptrLin addPar_Lin(ptrLin lin, ptrPar listPar, char*cod, int totalPar) {
    int i;

    for (i = 0; i < totalPar; ++i) {
        if (strcmp(tolowerString(listPar[i].cod), tolowerString(cod)) == 0) {
            break;
        }
    }

    lin->parAssoc = realloc(lin->parAssoc, sizeof(par)*(lin->nParAssoc+1));
    if (lin->parAssoc == NULL) {
        if (erroMemoria() == 1) {
            return lin;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    lin->nParAssoc++;
    lin->parAssoc[lin->nParAssoc-1] = listPar[i];

    listPar = addLin_Par(listPar, cod, totalPar, lin);
    listPar[i].nLinAssoc++;

    return lin;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
