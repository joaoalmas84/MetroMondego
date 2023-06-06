#include "Precurso.h"

void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal) {
    int flag = 0,  i = 0;
    char nomeStart[50], nomeFinish[50];

    calculaPrecursos(listLin, listPar, parTotal, "Mira", "Pampilhosa", NULL, NULL, 0, 0, 0);

    /*
    do {
        nomeStart[0] = '\0';
        printf("\n\t                 +-------------------+");
        printf("\n\t                 | Calcular Precurso |");
        printf("\n\t  +--------------+-------------------+-----------+");
        printf("\n\t  | Introduza o ponto de partida do precurso, o  |");
        wprintf(L"\n\t  |  nome da paragem onde começará o precurso.   |");
        printf("\n\t  |             1. Visualizar Paragens           |");
        printf("\n\t  |                   0. Voltar                  |");
        printf("\n\t  +----------------------------------------------+");
        printf("\n\t  ->");
        getNameParUser(nomeStart, listPar, parTotal);

        if (strcmp(nomeStart, "1") == 0) {
            visualizaParAll(listPar, parTotal);
        } else if (strcmp(nomeStart, "0") == 0) {
            return;
        }
    } while (strcmp(nomeStart, "1") == 0);

    do {
        nomeFinish[0] = '\0';
        printf("\n\t                 +-------------------+");
        printf("\n\t                 | Calcular Precurso |");
        printf("\n\t  +--------------+-------------------+----------+");
        printf("\n\t  | Introduza o ponto de chegada do precurso, o |");
        wprintf(L"\n\t  |   nome da paragem onde acabará o precurso.  |");
        printf("\n\t  |              1.Visualizar Paragens          |");
        printf("\n\t  |                    0.Voltar                 |");
        printf("\n\t  +---------------------------------------------+");
        printf("\n\t  ->");
        getNameParUser(nomeFinish, listPar, parTotal);

        if (strcmp(nomeFinish, "1") == 0) {
            visualizaParAll(listPar, parTotal);
        } else if (strcmp(nomeFinish, "0") == 0) {
            return;
        }
    } while (strcmp(nomeFinish, "1") == 0);

    calculaPrecursos(listLin, listPar, parTotal, nomeStart, nomeFinish, NULL, NULL, 0, 0, 0);*/
}

void calculaPrecursos(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish, char** linhas, char** paragens, int *numPar, int *numLin, int transbord) {
    ptrLin aux1 = NULL, aux2 = NULL;
    int i;

    for (i = 0; i < parTotal; ++i) {
        if (strcmp(tolowerString(listPar[i].nome), tolowerString(nomeStart)) == 0) {
            paragens = addToLista(paragens, numPar, listPar[i].nome);
            break;
        }
    }
    aux1 = listPar[i].linAssoc;
    while (aux1 != NULL) {
        aux2 = searchLin(listLin, aux1->nome);
        for (int j = 0; j < aux2->nParAssoc; ++j) {
            if (strcmp(tolowerString(aux2->parAssoc[j].nome), tolowerString(nomeFinish)) == 0) {
                paragens = addToLista(paragens, numPar, aux2->parAssoc[j].nome);
                strcpy(linhas[*numLin - 1], aux2->nome);
                mostraPrecurso(linhas, paragens, *numLin, *numPar);
                menu(listLin, listPar, &parTotal);
            }
        }
        aux1 = aux1->prox;
    }
    printf("\ntransbord -> %d", transbord);
    if (transbord == 1) {
        (*numPar)--;
        paragens = realloc(paragens, sizeof(char**)*(*numPar));
        if (paragens == NULL) {
            if (erroMemoria() == 1) {
                return;
            } else {
                exit(1);
            }
        }
    } else {
        aux1 = listPar[i].linAssoc;
        while (aux1 != NULL) {
            aux2 = searchLin(listLin, aux1->nome);
            for (int k = 0; k < aux2->nParAssoc; ++k) {
                printf("\nl -> %d", k);
                calculaPrecursos(listLin, listPar, parTotal, aux2->parAssoc[k].nome, nomeFinish, linhas, paragens, numLin, numPar, 1);
            }
            aux1 = aux1->prox;
        }
        wprintf(L"\nNão foi encontrado nenhum precurso com apenas 1 transbordo que ligue %s a %s.", nomeStart, nomeFinish);
        exit(1);
    }
}

void mostraPrecurso(char** linhas, char** paragens, int numLin, int numPar) {

    printf("\n+----------+");
    printf("\n| Precurso |");
    printf("\n+----------+");

    printf("\nnumLin -> %d\nnumPar -> %d", numLin, numPar);

    printf("\nLinhas:");
    for (int i = 0; i < numLin; ++i) {
        printf("\n-> %s", linhas[i]);
    }

    printf("\nParagens:");
    for (int i = 0; i < numPar; ++i) {
        printf("\n-> %s", paragens[i]);
    }
    printf("\n\t\t     +---------------------------------+");
    printf("\n\t\t     | Precurso encontrado com sucesso |");
    printf("\n\t\t     |     prima ENTER para voltar.    |");
    printf("\n\t\t     +---------------------------------+");
    getchar();
    getchar();
    system("cls");

}

char** addToLista(char** list, int* tam, char* newString) { // <- Adiciona uma string a um array de strings
    printf("\nSkirt");
    char** newList = malloc(sizeof(char*)*(*tam+1));
    if (newList == NULL) {
        if (erroMemoria() == 1) {
            return NULL;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    for (int i = 0; i < *tam; ++i) {
        newList[i] = malloc(sizeof(char)*strlen(list[i]));
        if (newList[i] == NULL) {
            if (erroMemoria() == 1) {
                return NULL;
            } else if (erroMemoria() == 2) {
                exit(1);
            }
        }
        strcpy(newList[i], list[i]);
    }
    newList[*tam] = malloc(sizeof(char));
    if (newList[*tam]) {
        if (erroMemoria() == 1) {
            return NULL;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    newList[*tam][0] = '\0';
    for (int i = 0; i < *tam; ++i) {
        free(list[i]);
    }
    free(list);

    return newList;
}

ptrLin searchLin(ptrLin listLin, char* nomeLin) {
    ptrLin aux = listLin;
    while (aux != NULL) {
        if (strcmp(tolowerString(aux->nome), tolowerString(nomeLin)) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL; // <- Nunca chega aqui
}