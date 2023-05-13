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
    char *cod = NULL, letras[] = "ABCDEFGHIJKLMNOPQRSTUVXYWZ", nums[] = "0123456789";
    int j;
    wprintf(L"\nA gerar código alfanumérico...");
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
    int i = 0, res = 0, ans = 0;
    ptrPar aux = malloc(sizeof(par)*(*total+3));
    if(aux == NULL) {
        if (erroMemoria() == 1) {
            return p;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    p = aux;
    (*total) += 3;

    strcpy(p[0].nome, "Mira");
    strcpy(p[0].cod, geraCod());
    p[0].linAssoc = NULL;
    p[0].totLinAssoc = 0;

    strcpy(p[1].nome, "Cantanhede");
    strcpy(p[1].cod, geraCod());
    p[1].linAssoc = NULL;
    p[1].totLinAssoc = 0;

    strcpy(p[2].nome, "Mealhada");
    strcpy(p[2].cod, geraCod());
    p[2].linAssoc = NULL;
    p[2].totLinAssoc = 0;

    return p;
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
        }    } else {

        lista = aux;
        (*total)++;

        strcpy(lista[*total-1].nome, nome);
        strcpy(lista[*total-1].cod, cod);
        lista[*total-1].linAssoc = NULL;
        lista[*total-1].totLinAssoc = 0;

        printf("\nA adicionar paragem...");

        return lista;
    }
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
