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
        p = erroMemoria_Lin(p);
    }

    printf("\nA preecher lista...");
    p = l1;

    strcpy(l1->nome, "Linha1");
    l1->parExistentes = 0;
    l1->nParExitentes = 0;
    l1->prox = l2;

    strcpy(l2->nome, "Linha2");
    l2->parExistentes = NULL;
    l2->nParExitentes = 0;
    l2->prox = l3;

    strcpy(l3->nome, "Linha3");
    l3->parExistentes = NULL;
    l3->nParExitentes = 0;
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

ptrLin adicionarLinha(ptrLin pL, ptrPar pP, int parTotal) {
    int x = 0, i = 0, ans = 0, res = 0, flag = 0;
    char cod[4];
    ptrLin aux1 = pL, aux2 = aux1->prox;
    ptrLin novo = malloc(sizeof(lin));
    if (novo == NULL) {
        pL = erroMemoria_Lin(pL);
        return pL;
    }

    printf("\n+------------+\n| Nova Linha |\n+------------+-------------------------------------------+");
    wprintf(L"\n| Não é possível existirem duas linhas com o mesmo nome. |");
    printf("\n+--------------------------------------------------------+");

    printf("\nNome:");
    do {
        if (i > 0) {
            printf("\n+----------------------------------------------------+");
            wprintf(L"\n|                   Nome inválido                    |");
            wprintf(L"\n|  Já existe uma linha com esse nome registada no    |");
            wprintf(L"\n|              sistema, tente novamente.             |");
            printf("\n+----------------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        scanf(" %s", novo->nome);
        i++;
    } while (verificaNome_Linhas(pL, novo->nome) == 0);

    res = i = 0;
    printf("\n+--------------------+\n| Adicionar Paragens |\n+--------------------+-------------------------------------------------------------+");
    wprintf(L"\n| Para ser registada no sistema uma linha necessita de ter pelo menos uma paragem. |");
    printf("\n|               1.Vizualizar Paragens     2.Adicionar Paragem                      |");
    printf("\n+----------------------------------------------------------------------------------+");
    printf("\n->");

    do {
        if (i > 0) {
            printf("\n+----------------------------------------------+");
            wprintf(L"\n|      Resposta inválida, tente novamente.     |");
            printf("\n| 1.Adicionar Paragem    2.Vizualizar Paragens |");
            printf("\n+----------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        res = scanf("%d", &ans);
        i++;
    } while (!res || ans != 1 && ans != 2);

    res = i = 0;
    if (ans == 1) {
        printf("\n->");
        do {
            if (i > 0) {
                if (flag == 1){
                    printf("\n+------------------------------------------------+");
                    wprintf(L"\n| O código introduzido não corresponde a nenhuma |");
                    wprintf(L"\n| paragem registada no sistema, tente novamente. |");
                    printf("\n+------------------------------------------------+");
                    printf("\n->");
                } else {
                    printf("\n+----------------------------------------------------+");
                    wprintf(L"\n|                   Codigo inválido                  |");
                    wprintf(L"\n| O código alfanumérico é composto por 4 caracteres, |");
                    wprintf(L"\n| letras e números apenas(Ex:L4J7), tente novamente. |");
                    printf("\n+----------------------------------------------------+");
                    printf("\n->");
                }
            }
            fflush(stdin);
            res = scanf(" %s", cod);
            if (verificaCod_Paragens(pP, cod, parTotal) == 1 && strlen(cod) == 4) {// <- Condição necessária para escolher
                flag = 1;                                                       //    escolher a mensagem de erro
            }
            i++;
        } while (!res || verificaCod_Paragens(pP, cod, parTotal) != 0);
    } else if(ans == 2) {
        visualizarPar(pP, parTotal);
        printf("Introduza o código da paragem que pretende"); // Ficámos Aqui!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

    pL = insereLin(pL, novo);

    return pL;
}

ptrLin atualizarLinha(ptrLin p, char nome[50]) {

}

void visualizarLinhas(ptrLin p) {
    ptrLin aux = p;
    int i = 0, j = 0, ans = 0, res = 0;
    if (p == NULL) {
        printf("\n+---------------------------------------------------+");
        printf("\n|             A lista encontra-se vazia.            |");
        printf("\n|           Voltar para o menu principal?           |");
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
            return;
        } else {
            exit(1); // substituir esta passo por uma função que guarde toda a informação nos ficheiros e termine o programa
        }
    } else {
        printf("\n+---------------------------------------+");
        printf("\n| Todas as linhas registadas no sistema |");
        printf("\n+---+--------------+--------------------+");
        wprintf(L"\n|   | N.º Paragens | Nome ");
        printf("\n+---+--------------+--------------------+");

        while (aux != NULL) {
            wprintf(L"\n| %d |       %d      | %s", j, aux->nParExitentes, aux->nome);
            printf("\n+---+--------------+--------------------+");
            j++;
            aux = aux->prox;
        }
    }
}