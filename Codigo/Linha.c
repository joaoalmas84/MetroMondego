#include "utils.h"
#include "Linha.h"

//  +--------+
//  | Extras |
//  +--------+

ptrLin preencheLista_Linhas(ptrLin p) {
    ptrLin l1 = malloc(sizeof(lin));
    ptrLin l2 = malloc(sizeof(lin));
    ptrLin l3 = malloc(sizeof(lin));

    if (l1 == NULL || l2 == NULL || l3 == NULL) {
        wprintf(L"\nErro na alocação de memória.\nA sair da função...");
        return p;
    }

    printf("\nA preecher lista...");
    p = l1;

    strcpy(l1->nome, "Linha1");
    l1->parAssociadas = NULL;
    l1->totParAssociadas = 0;
    l1->prox = l2;

    strcpy(l2->nome, "Linha2");
    l2->parAssociadas = NULL;
    l2->totParAssociadas = 0;
    l2->prox = l3;

    strcpy(l3->nome, "Linha3");
    l3->parAssociadas = NULL;
    l3->totParAssociadas = 0;
    l3->prox = NULL;

    return p;
}

int verificaNome_Linhas(ptrLin p, char* nome) {
    ptrLin aux;
    if (p == NULL) {
        return 1;
    } else {
        aux = p;
        while (aux != NULL) {
            if (strcmp(tolowerString(aux->nome), tolowerString(nome)) == 0) {
                return 0;
            }
            aux = aux->prox;
        }
        return 1;
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
            if(strcmp(tolowerString(novo->nome), tolowerString(aux1->nome)) < 0) {
                p = novo;
                novo->prox = aux1;
                return p;
            } else if (strcmp(tolowerString(novo->nome), tolowerString(aux2->nome)) < 0){
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

//  +----------------------+
//  | Funções do Enunciado |
//  +----------------------+

ptrLin adicionarLinha(ptrLin p) {
    int x = 0, i = 0;
    char res = 0;
    ptrLin aux1 = p, aux2 = aux1->prox;
    ptrLin novo = malloc(sizeof(lin));
    if (novo == NULL) {
        wprintf(L"\nErro na alocação de memória.\nA sair da função...");
        return p;
    }

    printf("\n+------------+\n| Nova Linha |\n+------------+");
    printf("\nNome:");
    do {
        if (i > 0) {
            wprintf(L"\nJá existe uma linha com esse nome registada no sistema.\nTente novamente:");
        }
        fflush(stdin);
        scanf(" %s", novo->nome);
        i++;
    } while (verificaNome_Linhas(p, novo->nome) == 0);

    p = insereLin(p, novo);

    return p;
}

ptrLin atualizarLinha(ptrLin p, char nome[50]) {

}

void vizualizarLinhas(ptrLin p) {
    ptrLin aux = p;
    int i = 0;
    if (p == NULL) {
        printf("\nA lista encontra-se vazia.");
        return;
    }
    printf("\n+---------------------------------------+");
    printf("\n| Todas as linhas registadas no sistema |");
    printf("\n+---+-----------------------------------+");
    while (aux != NULL) {
        wprintf(L"\n| %d | %s", i, aux->nome);
        printf("\n+---+-----------------------------------+");
        i++;
        aux = aux->prox;
    }
}