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
    int i = 0;
    if (listLin == NULL) {
        listLin = newLin;
        return listLin;
    } else {
        ptrLin aux = listLin;
        while(aux->prox != NULL) {
            aux = aux->prox;
            i++;
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

ptrLin removePar_All(ptrLin listLin, ptrPar listPar, int parTotal, char* cod) {
    ptrLin aux = listLin;
    while (aux != NULL) {
        for (int i = 0; i < aux->nParAssoc; ++i) {
            if (strcmp(tolowerString(aux->parAssoc[i].cod), tolowerString(cod)) == 0) {
                aux = removePar_Lin(aux, cod);
            }
        }
        if (aux->nParAssoc == 0) {
            listLin = dellLin(listLin, aux->nome);
        }
        aux = aux->prox;
    }
    for (int i = 0; i < parTotal; ++i) {
        if (strcmp(tolowerString(listPar[i].cod), tolowerString(cod)) == 0) {
            listPar[i].nLinAssoc = 0;
            listPar[i].linAssoc = NULL;
            break;
        }
    }
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

ptrLin alterName_Lin(ptrLin lin, char* newName, ptrPar listPar, int parTotal) {
    ptrLin aux = NULL;
    for (int i = 0; i < lin->nParAssoc; ++i) {
        for (int j = 0; j < parTotal; ++j) {
            if (strcmp(tolowerString(lin->parAssoc[i].cod), tolowerString(listPar[j].cod)) == 0) {
                aux = listPar[j].linAssoc;
                while (aux != NULL) {
                    if (strcmp(tolowerString(aux->nome), tolowerString(lin->nome)) == 0) {
                        strcpy(aux->nome, newName);
                        break;
                    }
                    aux = aux->prox;
                }
                break;
            }
        }
    }
    strcpy(lin->nome, newName);
    return lin;
}

ptrLin addPar_Lin(ptrLin listLin, char* nomeLin,  ptrPar listPar, char* nomePar, char* cod, int totalPar, int flag) {
    int i;
    ptrLin aux = listLin;

    while (aux->prox != NULL) {
        if (strcmp(tolowerString(aux->nome), tolowerString(nomeLin)) == 0) {
            break;
        }
        aux = aux->prox;
    }
    if (flag == 1) {
        for (i = 0; i < totalPar; ++i) {
            if (strcmp(tolowerString(listPar[i].nome), tolowerString(nomePar)) == 0) {
                break;
            }
        }
    } else if (flag == 0) {
        for (i = 0; i < totalPar; ++i) {
            if (strcmp(tolowerString(listPar[i].cod), tolowerString(cod)) == 0) {
                break;
            }
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

    listPar = addLin_Par(listLin, nomeLin, listPar, totalPar, cod, nomePar);
    listPar[i].nLinAssoc++;

    return listLin;
}

ptrLin getLinFromFile(ptrLin listLin, char* fileName) {
    FILE* f;
    char nomeLin[50];
    ptrLin novo = NULL;
    int i = 0;

    f = fopen(fileName, "r");
    if (f == NULL) {
        printf("\nErro ao abrir o ficheiro %s", fileName);
        return listLin;
    }

    fgets(nomeLin, sizeof(nomeLin), f);
    if (nomeLin[strlen(nomeLin) - 1] == '\n') {
        nomeLin[strlen(nomeLin) - 1] = '\0';
    }

    novo = createNewLin(nomeLin);
    listLin = insereLin(listLin, novo);

    fclose(f);
    return listLin;
}

ptrPar getParToLinFromFile(ptrLin listLin, ptrPar listPar, int* totalPar, char* fileName) {
    FILE* f;
    int i, j, k;
    char nomeLin[50], line[50], nomePar[50], cod[50];

    f = fopen(fileName, "r");
    if (f == NULL) {
        printf("\nErro ao abrir o ficheiro %s", fileName);
        return listPar;
    }

    fgets(nomeLin, sizeof(nomeLin), f);
    if (nomeLin[strlen(nomeLin) - 1] == '\n') {
        nomeLin[strlen(nomeLin) - 1] = '\0';
    }
    while (fgets(line, sizeof(line), f) != NULL) {
        i = j = k = 0;
        while (line[i+1] != '#') {
            nomePar[i] = line[i];
            i++;
        }
        nomePar[i] = '\0';
        for ( j = i+3, k = 0; line[j] != '\n'; ++j, ++k) {
            cod[k] = line[j];
        }
        cod[k] = '\0';

        if (verificaNome_Paragens(listPar, nomePar, *totalPar) == 1) {
            printf("\nJa existe -> %s # %s", nomePar, cod);
            listLin = addPar_Lin(listLin, nomeLin, listPar, nomePar, NULL, *totalPar, 1);
            continue;
        } else {
            printf("\nA adicionar -> %s # %s", nomePar, cod);
            if (verificaCod_Paragens(listPar, cod, *totalPar) == 1) {
                wprintf(L"\nO Código associado à paragem de %s no ficheiro já está associado a outra apragem.\nA gerar novo codigo");
                while (verificaCod_Paragens(listPar, cod, *totalPar) == 1) {
                    strcpy(cod, geraCod());
                }
            }
            listPar = addPar(listPar, nomePar, cod, totalPar);
            listLin = addPar_Lin(listLin, nomeLin, listPar, NULL, cod, *totalPar, 0);
        }
    }

    fclose(f);

    return listPar;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
