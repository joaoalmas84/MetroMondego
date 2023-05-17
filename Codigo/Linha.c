#include "Linha.h"

// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funções auxiliares ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// devolve 1 se nome existir em p
int verificaNome_Lin(ptrLin p, char* nome) {
    if (p == NULL) {
        return 0;
    } else {
        ptrLin aux = p;
        while (aux != NULL) {
            if (strcmp(tolowerString(aux->nome), tolowerString(nome)) == 0) {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

ptrLin insereLin(ptrLin p, ptrLin novo) {
    printf("\nnovo->nome : %s", novo->nome);
    if (p == NULL) {
        p = novo;
        return p;
    } else {
        ptrLin aux = p;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = NULL;
        return p;
    }
}

ptrLin batota(ptrLin p, ptrPar listaP) {
    ptrLin l1 = malloc(sizeof(lin));
    ptrLin l2 = malloc(sizeof(lin));
    ptrLin l3 = malloc(sizeof(lin));
    if (l1 == NULL || l2 == NULL || l3 ==NULL) {
        if (erroMemoria() == 1) {
            return p;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }

    strcpy(l1->nome, "Skirt");
    l1->nParAssoc = 3;
    l1->parAssoc = malloc(sizeof(par)*3);
    if (l1->parAssoc == NULL) {
        if (erroMemoria() == 1) {
            return p;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    l1->parAssoc[0] = listaP[0];
    l1->parAssoc[1] = listaP[1];
    l1->parAssoc[2] = listaP[2];
    p = l1;
    l1->prox = l2;

    strcpy(l2->nome, "Bruh");
    l2->nParAssoc = 3;
    l2->parAssoc = malloc(sizeof(par)*3);
    if (l2->parAssoc == NULL) {
        if (erroMemoria() == 1) {
            return p;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    l2->parAssoc[0] = listaP[0];
    l2->parAssoc[1] = listaP[1];
    l2->parAssoc[2] = listaP[2];
    l2->prox = l3;

    strcpy(l3->nome, "Sonhar");
    l3->nParAssoc = 3;
    l3->parAssoc = malloc(sizeof(par)*3);
    if (l3->parAssoc == NULL) {
        if (erroMemoria() == 1) {
            return p;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    l3->parAssoc[0] = listaP[0];
    l3->parAssoc[1] = listaP[1];
    l3->parAssoc[2] = listaP[2];
    l3->prox = NULL;

    return p;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funcionalidades |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
ptrLin addLin(ptrLin p, char* nome, char*cod, ptrPar listaP, int parTotal) {
    ptrLin novo = malloc(sizeof(lin));
    if (novo == NULL) {
        if (erroMemoria() == 1) {
            return p;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }

    ptrPar aux = malloc(sizeof(par));
    if (aux == NULL) {
        if (erroMemoria() == 1) {
            return p;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }

    novo->parAssoc = aux;
    strcpy(novo->nome, nome);
    novo->nParAssoc = 0;
    addPar_Lin(novo, nome, cod, listaP, parTotal, 0);
    p = insereLin(p, novo);

    return p;
}

ptrLin dellLin(ptrLin p, char* nome) {
    ptrLin aux1 = p, aux2 = aux1->prox;
    while (aux1 != NULL) {
        if (strcmp(tolowerString(aux1->nome), tolowerString(nome)) == 0) {
            p = aux1->prox;
            free(aux1);
            return p;
        } else if (strcmp(tolowerString(aux2->nome), tolowerString(nome)) == 0) {
            aux1->prox = aux2->prox;
            free(aux2);
            return p;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return p;
}

ptrLin removePar_Lin(ptrLin p, char* cod) {
    for (int i = 0; i < p->nParAssoc; ++i) {
        if (strcmp(tolowerString(p->parAssoc[i].cod), tolowerString(cod)) == 0) {
            for (int j = i; j < p->nParAssoc ; ++j) {
                p->parAssoc[j] = p->parAssoc[j+1];
            }
            break;
        }
    }

    ptrPar aux = realloc(p->parAssoc, sizeof(par)*(p->nParAssoc-1));
    if (aux == NULL) {
        if (erroMemoria() == 1) {
            return p;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    p->nParAssoc--;
    p->parAssoc = aux;
    return p;
}

ptrLin alterName_Lin(ptrLin p, char* newName) {
    strcpy(p->nome, newName);
    return p;
}

ptrLin addPar_Lin(ptrLin p, char* nome, char*cod, ptrPar listaP, int parTotal, int flag) {
    int i;
    if (flag == 0) { // flag == 0: estamos a adicionar a primeira paragem desta linha
        for (i = 0; i < parTotal; ++i) {
            if (strcmp(tolowerString(listaP[i].cod), tolowerString(cod)) == 0) {
                break;
            }
        }
        p->nParAssoc++;
        p->parAssoc[p->nParAssoc-1] = listaP[i];
    } else {
        ptrLin aux = p;
        while (aux != NULL) {
            if (strcmp(tolowerString(aux->nome), tolowerString(nome)) == 0) {
                break;
            }
            aux = aux->prox;
        }
        for (i = 0; i < parTotal; ++i) {
            if (strcmp(tolowerString(listaP[i].cod), tolowerString(cod)) == 0) {
                break;
            }
        }
        if (verificaCod_Paragens(aux->parAssoc, cod, aux->nParAssoc) == 1) {
            printf("\n+-------------------------------------------------------+");
            wprintf(L"\n| A Paragem %s já se ecnontra nesta linha.", listaP[i].nome);
            printf("\n+-------------------------------------------------------+");
            return p;
        }
        ptrPar auxMem = realloc(aux->parAssoc, sizeof(par)*(aux->nParAssoc+1));
        if (auxMem == NULL) {
            if (erroMemoria() == 1) {
                return p;
            } else if (erroMemoria() == 2) {
                exit(1);
            }
        }
        aux->parAssoc = auxMem;
        aux->nParAssoc++;
        aux->parAssoc[aux->nParAssoc-1] = listaP[i];
    }
    return p;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
