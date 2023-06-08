#include "Precurso.h"

void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal) {
    int flag = 0,  i = 0, nPar = 0;
    char nomeStart[50], nomeFinish[50];
    ptrPrec p = createNewPrec();

    printf("\nSem transbordo:");
    calculaPrecursos(listLin, listPar, parTotal, "Pombal", "Coimbra-B");
    printf("\nCom transbordo:");
    calculaPrecursosTransbord(listLin, listPar, parTotal, "Pombal", "Coimbra-B");
    exit(1);
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

void calculaPrecursos(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish) {
    ptrPrec p = createNewPrec();
    ptrLin aux1 = NULL, aux2 = NULL;
    int i;
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
                printf("\nPrecurso:");
                printPrec(p);//mostraPrecurso(p);
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
}

void calculaPrecursosTransbord(ptrLin listLin, ptrPar listPar, int parTotal, char* nomeStart, char* nomeFinish) {
    ptrPrec p = createNewPrec();
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
                       printf("\nPrecurso:");
                       printPrec(p);//mostraPrecurso(p);
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

void mostraPrecurso(ptrPrec p) {
    ptrLin aux;
    int nLin = 0;

    printf("\n+----------+");
    printf("\n| Precurso |");
    printf("\n+----------+");

    aux = p->linhas;
    while (aux != NULL) {
        nLin++;
        aux = aux->prox;
    }
    printf("\nnumLin -> %d\nnumPar -> %d", nLin, p->nPar);

    aux = p->linhas;
    printf("\nLinhas:");
    while(aux != NULL) {
        printf("\n-> %s", aux->nome);
        aux = aux->prox;
    }

    printf("\nParagens:");
    for (int i = 0; i < p->nPar; ++i) {
        printf("\n-> %s", p->paragens[i].nome);
    }

    printf("\n\t\t     +---------------------------------+");
    printf("\n\t\t     | Precurso encontrado com sucesso |");
    printf("\n\t\t     |     prima ENTER para voltar.    |");
    printf("\n\t\t     +---------------------------------+");
    getchar();
    getchar();
    system("cls");
}

ptrPrec addToParagens(ptrPrec p, char* nome) { // <- Adiciona uma paragem à array de paragens do precurso
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

ptrPrec removeFromParagens(ptrPrec p) {
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

ptrPrec addToLinhas(ptrPrec p, char* nome) { // <- Adiciona uma linha à lsita ligada de paragens do precurso
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

ptrPrec removeFromLinhas(ptrPrec p) {
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

ptrPrec createNewPrec() {
    ptrPrec p = malloc(sizeof(prec));
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

void printPrec(ptrPrec p) {
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