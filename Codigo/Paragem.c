#include "Paragem.h"

// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funções auxiliares ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// devolve 1 se nome existir em lista
int verificaNome_Paragens(ptrPar listPar, char *nome, int total) {
    if (total == 0) {
        return 0;
    } else {
        for (int i = 0; i < total; ++i) {
            if (strcmp(tolowerString(listPar[i].nome), tolowerString(nome)) == 0) {
                return 1;
            }
        }
        return 0;
    }
}

// devolve 1 se cod existir em lista
int verificaCod_Paragens(ptrPar list, char *cod, int total) {
    if (total == 0) {
        return 0;
    } else {
        for (int i = 0; i < total; ++i) {
            if (strcmp(tolowerString(cod), tolowerString(list[i].cod)) == 0) {
                return 1;
            }
        }
        return 0;
    }
}

// devolve string com 4 caracteres (letras e números) apenas, todos em uppercase
char* geraCod() {
    char *cod = NULL;
    char charSet[] = "ABCDEFGHIJKLMNOPQRSTUVXYWZ0123456789";
    int j;
    char *aux = malloc(sizeof(char)*5);
    if (aux == NULL) {
        if (erroMemoria() == 1) {
            return NULL;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    } else {
        cod = aux;
        for (j = 0; j < 4; ++j) {
            cod[j] = charSet[rand() % (strlen(charSet) - 1)];
        }
        cod[j] = '\0';
    }
    return cod;
}

// devolve 1 se a oaragem a eliminar não tiver linhas associadas (pode ser eliminada)
int checkPar_Dell(ptrPar lista, int total, char* cod) {
    int i;
    for (i = 0; i < total; ++i) {
        if (strcmp(tolowerString(lista[i].cod), tolowerString(cod)) == 0) {
            break;
        }
    }
    if (lista[i].linAssoc == NULL && lista[i].nLinAssoc == 0) {
        return 1;
    } else {
        return 0;
    }
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funcionalidades |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// Adiciona Paragem
ptrPar addPar(ptrPar listPar, char *nome, char *cod, int *total) {
    ptrPar aux = realloc(listPar, sizeof(par)*(*total+1));
    if (aux == NULL) {
        if (erroMemoria() == 1) {
            return listPar;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }

    listPar = aux;
    (*total)++;
    strcpy(listPar[*total-1].nome, nome);
    strcpy(listPar[*total-1].cod, cod);
    listPar[*total-1].linAssoc = NULL;
    listPar[*total-1].nLinAssoc = 0;

    return listPar;
}

// Elimina Paragem
ptrPar dellPar(ptrPar listPar, char *cod, int *total) {
    ptrPar aux = NULL;
    for (int i = 0; i < *total; ++i) {
        if (strcmp(tolowerString(listPar[i].cod),tolowerString(cod)) == 0) {
            for (int j = i; j < *total; ++j) {
                listPar[j] = listPar[j+1];
            }
            break;
        }
    }
    aux = realloc(listPar, sizeof(par)*(*total-1));
    if (aux == NULL && *total-1 > 0) {
        if (erroMemoria() == 1) {
            return listPar;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    } else {
        (*total)--;
        listPar = aux;
    }
    return listPar;
}

// Adiciona linha a paragem
ptrPar addLin_Par(ptrLin listLin, char* nomeLin, ptrPar listPar, int parTotal, char* cod, char* nomePar) {
    int i;
    ptrLin aux1 = NULL;
    if (cod == NULL) {
        for (i = 0; i < parTotal; ++i) {
            if (strcmp(tolowerString(listPar[i].nome), tolowerString(nomePar)) == 0) {
                break;
            }
        }
    } else {
        for (i = 0; i < parTotal; ++i) {
            if (strcmp(tolowerString(listPar[i].cod), tolowerString(cod)) == 0) {
                break;
            }
        }
    }

    aux1 = listLin;
    while (aux1 != NULL) {
        if (strcmp(tolowerString(aux1->nome), tolowerString(nomeLin)) == 0) {
            break;
        }
        aux1 = aux1->prox;
    }

    ptrLin novo = createNewLin(aux1->nome);
    novo->nParAssoc = aux1->nParAssoc;
    novo->parAssoc = aux1->parAssoc;
    if (listPar[i].linAssoc == NULL) {
        listPar[i].linAssoc = novo;
    } else {
        ptrLin aux2 = listPar[i].linAssoc;
        while (aux2->prox != NULL) {
            aux2 = aux2->prox;
        }
        aux2->prox = novo;
    }
    return listPar;
}

// remove linha da paragem
ptrPar removeLin_Par(ptrPar listPar, char* cod, int totalPar, char* nomeLin) {
    int i;
    for (i = 0; i < totalPar; ++i) {
        if (strcmp(tolowerString(listPar[i].cod), tolowerString(cod)) == 0) {
            break;
        }
    }
    ptrLin aux1 = listPar[i].linAssoc, aux2 = aux1->prox;
    while (aux1 != NULL) {
        if (strcmp(tolowerString(aux1->nome), tolowerString(nomeLin)) == 0) {
            listPar[i].linAssoc = aux2;
            free(aux1);
            listPar[i].nLinAssoc--;
            return listPar;
        } else if (strcmp(tolowerString(aux2->nome), tolowerString(nomeLin)) == 0) {
            aux1 = aux2->prox;
            free(aux2);
            listPar[i].nLinAssoc--;
            return listPar;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return listPar;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
