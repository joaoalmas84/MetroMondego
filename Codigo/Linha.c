#include "Linha.h"

// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funções auxiliares ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// Preenche a lsita com 3 linhas
ptrLin preencheLista_Linhas(ptrLin p) {
    ptrLin l1 = malloc(sizeof(lin));
    ptrLin l2 = malloc(sizeof(lin));
    ptrLin l3 = malloc(sizeof(lin));

    if (l1 == NULL || l2 == NULL || l3 == NULL) {
        return p = erroMemoria_Lin(p);
    } else {
        printf("\nA preecher lista...");
        p = l1;

        strcpy(l1->nome, "Linha1");
        l1->parExistentes = NULL;
        l1->nParExistentes = 0;
        l1->prox = l2;

        strcpy(l2->nome, "Linha2");
        l2->parExistentes = NULL;
        l2->nParExistentes = 0;
        l2->prox = l3;

        strcpy(l3->nome, "Linha3");
        l3->parExistentes = NULL;
        l3->nParExistentes = 0;
        l3->prox = NULL;
    }
    return p;
}

// devolve 1 se nome existir em p
int verificaNome_Linhas(ptrLin p, char* nome) {
    ptrLin aux;
    if (p == NULL) {
        return 0;
    } else {
        aux = p;
        while (aux != NULL) {
            if (strcmp(tolowerString(aux->nome), tolowerString(nome)) == 0) {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

ptrLin insereLin(ptrLin p, ptrLin novo) {
    ptrLin aux1 = p, aux2 = aux1->prox;
    printf("\nA inserir linha...");
    if (p == NULL) {
        p = novo;
        return p;
    } else {
        while (aux2->prox != NULL) {
            if (strcmp(tolowerString(novo->nome), tolowerString(aux1->nome)) < 0) {
                p = novo;
                novo->prox = aux1;
                return p;
            } else if (strcmp(tolowerString(novo->nome), tolowerString(aux2->nome)) < 0) {
                aux1->prox = novo;
                novo->prox = aux2;
                return p;
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
        aux2->prox = novo;
        novo->prox = NULL;
        return p;
    }
}

ptrLin erroMemoria_Lin(ptrLin p) {
    int i = 0, res = 0, ans = 0;
    printf("\n+---------------------------------------------------+");
    printf("\n|            Erro na alocação de memória.           |");
    printf("\n|           Voltar para  o menu principal?          |");
    printf("\n|              1.Voltar     2.Terminar              |");
    printf("\n+---------------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            printf("\n+----------------------------------------------------+");
            wprintf(L"\n|         Resposta inválida, tente novamente.        |");
            printf("\n|              1.Voltar     2.Terminar               |");
            printf("\n+----------------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        res = scanf("%d", &ans);
        i++;
    } while (!res || ans != 1 && ans != 0);
    if (ans == 1) {
        return p;
    } else {
        exit(1); // substituir esta passo por uma função que guarde toda a informação nos ficheiros e termine o programa
    }
}

ptrLin associaPar(ptrPar novo, ptrPar listaP, char *cod) {
    printf("\npL.nome -> %s\npP.nome -> %s\npos -> %d", pL->nome, pP->nome, pos);
    exit(1);
    pL->nParExistentes++;
    ptrPar aux = realloc(pL->parExistentes, sizeof(par)*(pL->nParExistentes));
    if (aux == NULL) {
        return pL = erroMemoria_Lin(pL);
    } else {
        printf("\nA associar paragem...");
        pL->parExistentes = aux;
        pL->parExistentes[pL->nParExistentes-1] = pP[pos];
    }
    visualizarParExistentes(pL);
    exit(1);
    return pL;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funcionalidades |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
ptrLin addLin(ptrLin listaL, ptrPar listaP, int parTotal, int *parAssociadas ) {

}



//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
