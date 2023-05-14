#include "Linha.h"

// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funções auxiliares ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// devolve 1 se nome existir em p
int verificaNome_Lin(ptrLin p, char* nome) {
    ptrLin aux;
    if (p == NULL) {
        return 0;
    } else {
        aux = p;
        while (aux->prox != NULL) {
            if (strcmp(tolowerString(aux->nome), tolowerString(nome)) == 0) {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

ptrLin insereLin(ptrLin p, ptrLin novo) {
    ptrLin aux = p;
    printf("\nA inserir linha...");
    if (p == NULL) {
        p = novo;
        return p;
    } else {
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = NULL;
        return p;
    }
}

void addPar_Lin(ptrLin p, char* nome, char*cod, ptrPar listaP, int parTotal, int flag) {
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
        while (aux->prox != NULL) {
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
            wprintf(L"\n| A Paragem da %s já se ecnontra nesta linha.", listaP[i].nome);
            printf("\n+-------------------------------------------------------+");
            return;
        }

        aux->nParAssoc++;
        aux->parAssoc[aux->nParAssoc-1] = listaP[i];
    }
}

ptrLin removePar_Lin(ptrLin p, char* nome, char*cod) {

}

ptrLin alterName_Lin(ptrLin p, char* nome, char* newName) {

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
        } else {
            exit(1);
        }
    }

    ptrPar aux = realloc(novo->parAssoc, sizeof(par)*(novo->nParAssoc+1));
    if (aux == NULL) {
        if (erroMemoria() == 1) {
            return p;
        } else {
            exit(1);
        }
    }

    strcpy(novo->nome, nome);
    novo->parAssoc = aux;

    addPar_Lin(novo, nome, cod, listaP, parTotal, 0);
    p = insereLin(p, novo);

    return p;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
