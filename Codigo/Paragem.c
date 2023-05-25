#include "Paragem.h"

// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funções auxiliares ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// <- devolve 1 se nome existir em lista
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

// <- devolve 1 se cod existir em lista
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


char* geraCod() {
    char *cod = NULL;
    char letras[] = "ABCDEFGHIJKLMNOPQRSTUVXYWZ", nums[] = "0123456789";
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
            if (j == 0 || j == 2) {
                cod[j] = letras[rand() % (strlen(letras) - 1)];
            } else {
                cod[j] = nums[rand() % (strlen(nums) - 1)];
            }
        }
        cod[j] = '\0';
    }
    return cod;
}

// Preenche o array com 3 paragens antes de começar o programa de modo a que tenhamos alguns dados com que trablhar
ptrPar preencheLista_Paragens(ptrPar listPar, int *total) {
    ptrPar aux = NULL;
    FILE *f;
    f = fopen("Paragens.txt", "r");
    if (f == NULL) {
        printf("\nErro ao abrir o ficheiro Paragens.txt\n");
        return listPar;
    }

    char line[100];

    while (fgets(line, 100, f) != NULL) {
        aux = realloc(listPar, sizeof(par)*(*total+1));
        if (aux == NULL) {
            if (erroMemoria() == 1) {
                return listPar;
            } else if (erroMemoria() == 2) {
                exit(1);
            }
        }
        (*total)++;
        listPar = aux;
        sscanf(line, "%s", listPar[*total-1].nome);
        do {
            strcpy(listPar[*total-1].cod, geraCod());
        } while (verificaCod_Paragens(listPar, listPar[*total-1].cod, *total-1) == 1);
    }
    fclose(f);
    return listPar;
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
            for (int j = i; j < *total-1; ++j) {
                listPar[i] = listPar[i+1];
            }
            break;
        }
    }
    aux = realloc(listPar, sizeof(par)*(*total-1));
    if (aux == NULL) {
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
ptrPar addLin_Par(ptrPar listPar, char* cod, int totalPar, ptrLin lin) {
    int i;
    ptrLin novo = createNewLin(lin->nome);
    novo->nParAssoc = lin->nParAssoc;
    novo->parAssoc = lin->parAssoc;
    for (i = 0; i < totalPar; ++i) {
        if (strcmp(tolowerString(listPar[i].cod), tolowerString(cod)) == 0) {
            break;
        }
    }
    if (listPar[i].linAssoc == NULL) {
        listPar[i].linAssoc = novo;
        novo->prox = NULL;
    } else {
        ptrLin aux2 = listPar[i].linAssoc;
        while (aux2 != NULL) {
            aux2 = aux2->prox;
        }
        aux2 = novo;
        novo->prox = NULL;
    }
    return listPar;
}

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
