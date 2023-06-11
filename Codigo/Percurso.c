#include "Percurso.h"

void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal) {
    int flag = 0,  i = 0, j = 0, nPar = 0, nPrec;
    char nomeStart[50], nomeFinish[50];
    ptrPerc p = createNewPerc();

    do {
        nomeStart[0] = '\0';
        printf("\n\t\t       +-----------------------------------+");
        printf("\n\t\t       | Calcular Percurso - Ponto Partida |");
        printf("\n\t\t  +----+-----------------------------------+----+");
        printf("\n\t\t  | Introduza o ponto de partida do percurso, o |");
        wprintf(L"\n\t\t  |  nome da paragem onde começará o percurso.  |");
        printf("\n\t\t  |             1.Visualizar Paragens           |");
        printf("\n\t\t  |                   0.Voltar                  |");
        printf("\n\t\t  +---------------------------------------------+");
        printf("\n\t\t  ->");
        getNameParUser(nomeStart, listPar, parTotal);

        if (strcmp(nomeStart, "1") == 0) {
            visualizaParAll(listPar, parTotal);
        } else if (strcmp(nomeStart, "0") == 0) {
            return;
        }
    } while (strcmp(nomeStart, "1") == 0);

    do {
        nomeFinish[0] = '\0';
        printf("\n\t\t       +-----------------------------------+");
        printf("\n\t\t       | Calcular Percurso - Ponto Chegada |");
        printf("\n\t\t  +----+-----------------------------------+----+");
        printf("\n\t\t  | Introduza o ponto de chegada do percurso, o |");
        wprintf(L"\n\t\t  |   nome da paragem onde acabará o percurso.  |");
        printf("\n\t\t  |              1.Visualizar Paragens          |");
        printf("\n\t\t  |                    0.Voltar                 |");
        printf("\n\t\t  +---------------------------------------------+");
        printf("\n\t\t  ->");
        do {
            if (j > 0) {
                printf("\n\t\t+---------------------------------------------+");
                wprintf(L"\n\t\t| O ponto de chegada e o ponto de partida não |");
                wprintf(L"\n\t\t|      podem ser iguais, tente novamente      |");
                printf("\n\t\t|             1. Visualizar Paragens          |");
                printf("\n\t\t|                   0. Voltar                 |");
                printf("\n\t\t+---------------------------------------------+");
                printf("\n\t\t->");
            }
            getNameParUser(nomeFinish, listPar, parTotal);
            j++;
        } while (strcmp(nomeStart, nomeFinish) == 0);

        if (strcmp(nomeFinish, "1") == 0) {
            visualizaParAll(listPar, parTotal);
        } else if (strcmp(nomeFinish, "0") == 0) {
            return;
        }
    } while (strcmp(nomeFinish, "1") == 0);

    nPrec = calculaPercursos(listLin, listPar, parTotal, nomeStart, nomeFinish);
    calculaPercursosTransbord(listLin, listPar, parTotal, nomeStart, nomeFinish, nPrec);
    printf("\n\t\t\t     +-----------------------------------+");
    printf("\n\t\t\t     | Percursos encontrados com sucesso |");
    printf("\n\t\t\t     |     prima ENTER para voltar.      |");
    printf("\n\t\t\t     +-----------------------------------+");
    getchar();
    getchar();
    system("cls");
}

int calculaPercursos(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish) {
    ptrPerc p = createNewPerc();
    ptrLin aux1 = NULL, aux2 = NULL;
    int i, nPrec = 0;
    for (i = 0; i < parTotal; ++i) {
        if (strcmp(tolowerString(listPar[i].nome), tolowerString(nomeStart)) == 0) {
            p = addToParagens(p, listPar[i].nome);
            break;
        }
    }

    aux1 = listPar[i].linAssoc;
    while (aux1 != NULL) {
        aux2 = searchLin(listLin, aux1->nome);
        for (int j = 0; j < aux2->nParAssoc; ++j) {
            if (strcmp(tolowerString(aux2->parAssoc[j].nome), tolowerString(nomeFinish)) == 0) {
                p = addToLinhas(p, aux2->nome);
                p = addToParagens(p, aux2->parAssoc[j].nome);
                nPrec++;
                mostraPercursos(p, nPrec, 0);
                putchar('\n');
                free(p->paragens);
                p->paragens = NULL;
                free(p->linhas);
                p->linhas = NULL;
                p->nPar = 0;
            }
        }
        aux1 = aux1->prox;
    }
    free(p);
    return nPrec;
}

void calculaPercursosTransbord(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish, int nPrec) {
    ptrPerc p = createNewPerc();
    ptrLin aux1 = NULL, aux2 = NULL, aux3 = NULL, aux4 = NULL;
    int i;
    for (i = 0; i < parTotal; ++i) {
        if (strcmp(tolowerString(listPar[i].nome), tolowerString(nomeStart)) == 0) {
            p = addToParagens(p, listPar[i].nome);
            break;
        }
    }

    aux1 = listPar[i].linAssoc;
    while(aux1 != NULL) {
        aux2 = searchLin(listLin, aux1->nome);
        for (int j = 0; j < aux2->nParAssoc; ++j) {
            if (strcmp(tolowerString(nomeStart), tolowerString(aux2->parAssoc[j].nome)) == 0) {
                continue;
            }
            aux3 = searchPar(listPar, parTotal, aux2->parAssoc[j].nome);
            while(aux3 != NULL) {
                if (strcmp(tolowerString(aux3->nome), tolowerString(aux1->nome)) == 0) {
                    aux3 = aux3->prox;
                    continue;
                }
                aux4 = searchLin(listLin, aux3->nome);
                for (int k = 0; k < aux4->nParAssoc; ++k) {
                    if (strcmp(tolowerString(nomeStart), tolowerString(aux4->parAssoc[k].nome)) == 0 || strcmp(tolowerString(aux2->parAssoc[j].nome), tolowerString(aux4->parAssoc[k].nome)) == 0) {
                        continue;
                    }
                    if (strcmp(tolowerString(nomeFinish), tolowerString(aux4->parAssoc[k].nome)) == 0) {
                        p = addToLinhas(p, aux2->nome);
                        p = addToParagens(p, aux2->parAssoc[j].nome);
                        p = addToLinhas(p, aux4->nome);
                        p = addToParagens(p, aux4->parAssoc[k].nome);
                        nPrec++;
                        mostraPercursos(p, nPrec, 1);
                        putchar('\n');
                        free(p->paragens);
                        p->paragens = NULL;
                        free(p->linhas);
                        p->linhas = NULL;
                        p->nPar = 0;
                        p = addToParagens(p, listPar[i].nome);
                    }
                }
                aux3 = aux3->prox;
            }
        }
        aux1 = aux1->prox;
    }
    free(p);
}

void mostraPercursos(ptrPerc p, int n, int transbordFlag) {
    ptrLin aux = NULL;
    int nLin = 0;

    if (transbordFlag == 0) {
        printf("\n+----------------+");
        wprintf(L"\n| Percurso n.º %d |", n);
        printf("\n| sem transbordo |");
        printf("\n+----------------+");
    } else {
        printf("\n+----------------+");
        wprintf(L"\n| Percurso n.º %d |", n);
        printf("\n| com transbordo |");
        printf("\n+----------------+");
    }
    aux = p->linhas;
    putchar('\n');
    putchar(' ');
    for (int i = 0; i < p->nPar; ++i) {
        putchar('+');
        for (int j = 0; j < strlen(p->paragens[i].nome)+2; ++j) {
            putchar('-');
        }
        putchar('+');
        if (i < p->nPar-1) {
            printf("    %s    ", aux->nome);
            aux = aux->prox;
        }
    }

    aux = p->linhas;
    putchar('\n');
    putchar(' ');
    for (int i = 0; i < p->nPar; ++i) {
        printf("| %s |", p->paragens[i].nome);
        if (i < p->nPar-1) {
            printf("   ");
            for (int j = 0; j < strlen(aux->nome)+1; ++j) {
                putchar('-');
            }
            printf(">   ");
            aux = aux->prox;
        }
    }

    aux = p->linhas;
    putchar('\n');
    putchar(' ');
    for (int i = 0; i < p->nPar; ++i) {
        putchar('+');
        for (int j = 0; j < strlen(p->paragens[i].nome)+2; ++j) {
            putchar('-');
        }
        putchar('+');
        if (i < p->nPar-1) {
            printf("   ");
            for (int j = 0; j < strlen(aux->nome)+2; ++j) {
                putchar(' ');
            }
            printf("   ");
            aux = aux->prox;
        }
    }
}

ptrPerc addToParagens(ptrPerc p, char* nome) { // <- Adiciona uma paragem à array de paragens do precurso
    ptrPar aux = realloc(p->paragens, sizeof(par)*(p->nPar+1));
    if (aux == NULL) {
        if (erroMemoria() == 1) {
            return NULL;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    p->paragens = aux;
    p->nPar++;
    strcpy(p->paragens[p->nPar-1].nome, nome);   //
    p->paragens[p->nPar-1].nLinAssoc = 0;        // Como só precisamos do nome os restantes parametros da struct
    p->paragens[p->nPar-1].linAssoc = NULL;      // são inicializados de forma a ficarem inutilizáveis
    p->paragens[p->nPar-1].cod[0] = '\0';        //

    return p;
}

ptrPerc removeFromParagens(ptrPerc p) {
    ptrPar aux = realloc(p->paragens, sizeof(par)*(p->nPar-1));
    if (aux == NULL && p->nPar-1 > 0) {
        if (erroMemoria() == 1) {
            return NULL;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    (p->nPar)--;
    return p;
}

ptrPerc addToLinhas(ptrPerc p, char* nome) { // <- Adiciona uma linha à lsita ligada de paragens do precurso
    ptrLin aux = NULL, novo = NULL;

    novo = createNewLin(nome);  // <- A função createNewLin do ficheiro Linha.c já faz tudo

    if (p->linhas == NULL) {
        p->linhas = novo;
    } else {
        aux = p->linhas;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return p;
}

ptrPerc removeFromLinhas(ptrPerc p) {
    ptrLin auxBack = NULL, auxFront = NULL;
    if (p->linhas != NULL) {
        if (p->linhas->prox == NULL) {
            free(p->linhas);
            p->linhas = NULL;
        } else {
            auxBack = p->linhas;
            auxFront = auxBack->prox;
            while(auxFront->prox != NULL) {
                auxBack = auxBack->prox;
                auxFront = auxFront->prox;
            }
            auxBack->prox = NULL;
            free(auxFront);
        }
    }
    return p;
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

ptrLin searchPar(ptrPar listPar, int parTotal, char* nomePar) {
    for (int i = 0; i < parTotal; ++i) {
        if (strcmp(tolowerString(listPar[i].nome), tolowerString(nomePar)) == 0){
            return listPar[i].linAssoc;
        }
    }
    return NULL;
}

ptrPerc createNewPerc() {
    ptrPerc p = malloc(sizeof(perc));
    if (p == NULL) {
        if (erroMemoria() == 1) {
            return NULL;
        } else if (erroMemoria() == 2) {
            exit(1);
        }
    }
    p->linhas = NULL;
    p->paragens = NULL;
    p->nPar = 0;

    return p;
}

void printPrec(ptrPerc p) {
    ptrLin aux = p->linhas;

    printf("\nLinhas:");
    while (aux != NULL) {
        printf("\n-> %s", aux->nome);
        aux = aux->prox;
    }

    printf("\nParagens:");
    for (int i = 0; i < p->nPar; ++i) {
        printf("\n-> %s", p->paragens[i].nome);
    }
}