#include "Paragem.h"

// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funções auxiliares ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// <- devolve 1 se nome existir em lista
int verificaNome_Paragens(ptrPar lista, char *nome, int total) {
    if (total == 0) {
        return 0;
    } else {
        for (int i = 0; i < total; ++i) {
            if (strcmp(tolowerString(lista[i].nome), tolowerString(nome)) == 0) {
                return 1;
            }
        }
        return 0;
    }
}

// <- devolve 1 se cod existir em lista
int verificaCod_Paragens(ptrPar lista, char *cod, int total) {
    if (total == 0) {
        return 0;
    } else {
        for (int i = 0; i < total; ++i) {
            if (strcmp(tolowerString(cod), tolowerString(lista[i].cod)) == 0) {
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
ptrPar preencheLista_Paragens(ptrPar p, int *total) {
    ptrPar aux = NULL;
    FILE *f;
    f = fopen("Paragens.txt", "r");
    if (f == NULL) {
        printf("\nErro ao abrir o ficheiro Paragens.txt\n");
        return p;
    }

    char line[100];

    while (fgets(line, 100, f) != NULL) {
        aux = realloc(p, sizeof(par)*(*total+1));
        if (aux == NULL) {
            if (erroMemoria() == 1) {
                return p;
            } else if (erroMemoria() == 2) {
                exit(1);
            }
        }
        (*total)++;
        p = aux;
        sscanf(line, "%s", p[*total-1].nome);
        do {
            strcpy(p[*total-1].cod, geraCod());
        } while (verificaCod_Paragens(p, p[*total-1].cod, *total-1) == 1);
    }

    fclose(f);

    return p;
}

void addLin_Par(ptrLin p, char* nome, char*cod, ptrPar listaP, int parTotal) {
    int i;
    for (i = 0; i < parTotal; ++i) {
        if (strcmp(tolowerString(cod), tolowerString(listaP[i].cod)) == 0) {
            break;
        }
    }
    ptrLin aux = p;
    while (aux->prox != NULL) {
        if (strcmp(tolowerString(aux->nome), tolowerString(nome)) == 0) {
            break;
        }
        aux = aux->prox;
    }

    ptrLin novo = malloc(sizeof(lin));
    if (novo == NULL) {
        if (erroMemoria() == 1) {
            return;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }

    novo = aux;

    ptrLin aux2 = p;
    while (aux2->prox != NULL) {
        aux2 = aux->prox;
    }

    aux2->prox = novo;
    novo->prox = NULL;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funcionalidades |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// Adiciona Paragem
ptrPar addPar(ptrPar lista, char *nome, char *cod, int *total) {
    ptrPar aux = realloc(lista, sizeof(par)*(*total+1));
    if (aux == NULL) {
        if (erroMemoria() == 1) {
            return lista;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }

    lista = aux;
    (*total)++;

    strcpy(lista[*total-1].nome, nome);
    strcpy(lista[*total-1].cod, cod);
    lista[*total-1].linAssoc = NULL;
    lista[*total-1].nLinAssoc = 0;

    printf("\nA adicionar paragem...");

    return lista;

}

// Elimina Paragem
ptrPar dellPar(ptrPar lista, char *cod, int *total) {
    ptrPar aux = NULL;
    for (int i = 0; i < *total; ++i) {
        if (strcmp(tolowerString(lista[i].cod),tolowerString(cod)) == 0) {
            for (int j = i; j < *total-1; ++j) {
                lista[i] = lista[i+1];
            }
            break;
        }
    }
    aux = realloc(lista, sizeof(par)*(*total-1));
    if (aux == NULL) {
        if (erroMemoria() == 1) {
            return lista;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    } else {
        printf("\nA eliminar paragem...");
        (*total)--;
        lista = aux;
        return lista;
    }
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
