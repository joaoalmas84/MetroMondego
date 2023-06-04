#include "Precurso.h"

void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal) {
    int flag = 0,  i = 0;
    char nomeStart[50], nomeFinish[50];

    printf("\n\t                 +-------------------+");
    printf("\n\t                 | Calcular Precurso |");
    printf("\n\t  +--------------+-------------------+-----------+");
    printf("\n\t  | Introduza o ponto de partida do precurso, o  |");
    wprintf(L"\n\t  |  nome da paragem onde começará o precurso.   |");
    printf("\n\t  +----------------------------------------------+");
    printf("\n\t  ->");
    getNameParUser(nomeStart, listPar, parTotal);

    printf("\n\t                 +-------------------+");
    printf("\n\t                 | Calcular Precurso |");
    printf("\n\t  +---------------------------------------------+");
    printf("\n\t  | Introduza o ponto de chegada do precurso, o |");
    wprintf(L"\n\t  |   nome da paragem onde acabará o precurso.  |");
    printf("\n\t  +---------------------------------------------+");
    printf("\n\t  ->");
    getNameParUser(nomeFinish, listPar, parTotal);

    calculaPrecursos(listLin, listPar, parTotal, nomeStart, nomeFinish);
}

void calculaPrecursos(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish) {
    char** linhas = NULL;
    char** paragens = NULL;
    ptrLin aux = NULL;
    int i, j, k, nVoltas = 0, numPar = 1, numLin = 0;

    for (i = 0; i < parTotal; ++i) {
        if (strcmp(tolowerString(listPar[i].nome), tolowerString(nomeStart)) == 0) {
            break;
        }
    }

    aux = listPar[i].linAssoc;
    while (aux != NULL) {
        for (j = 0; j < aux->nParAssoc; ++j) {
            if (strcmp(tolowerString(aux->parAssoc[j].nome), tolowerString(nomeFinish)) == 0) {
                numPar++;
                numLin++;
                paragens = realloc(paragens, numPar*sizeof(char*));
                if (paragens == NULL) {
                    if (erroMemoria() == 1) {
                        return;
                    } else if (erroMemoria() == 2) {
                        exit(1);
                    }
                }
                for (k = 0; k < numPar; ++k) {
                    paragens[k] = malloc(50*sizeof(char));
                    if (paragens[k] == NULL) {
                        if (erroMemoria() == 1) {
                            return;
                        } else if (erroMemoria() == 2) {
                            exit(1);
                        }
                    }
                    if (k == 0) {
                        strcpy(paragens[k], listPar[i].nome);
                    } else {
                        strcpy(paragens[k], aux->parAssoc[k].nome);
                    }
                }
                linhas = realloc(linhas, numLin*sizeof(char*));
                for (int l = 0; l < numLin; ++l) {
                    linhas[l] = malloc(50*sizeof(char));
                    if (linhas[l] == NULL) {
                        if (erroMemoria() == 1) {
                            return;
                        } else if (erroMemoria() == 2) {
                            exit(1);
                        }
                    }
                    strcpy(linhas[l], aux->nome);
                }
            }
        }
        aux = aux->prox;
    }
    mostraPrecurso(linhas, paragens);
}

void mostraPrecurso(char** linhas, char** paragens) {
    printf("\n+----------+");
    printf("\n| Precurso |");
    printf("\n+----------+");

    printf("\nParagem %s\t%s\tParagem %s", paragens[0], linhas[0], paragens[1]);
    printf("\n ___________\t___________");
    printf("\n|___________| -----------> |___________|");
}