#include "utils.h"
#include "Paragem.h"

//  +--------+
//  | Extras |
//  +--------+

ptrPar preencheLista_Paragens(ptrPar p, int *total) {
    int i = 0, res = 0, ans = 0;
    ptrPar aux = malloc(sizeof(par)*(*total+3));
    if(aux == NULL) {
        p = erroMemoria_Par(p);
        return p;
    } else {
        p = aux;
        (*total) += 3;

        strcpy(p[0].nome, "Mira");
        geraCod(p, 0, *total);
        p[0].linAssoiadas = NULL;
        p[0].totLinAssociadas = 0;

        strcpy(p[1].nome, "Cantanhede");
        geraCod(p, 1, *total);
        p[1].linAssoiadas = NULL;
        p[1].totLinAssociadas = 0;

        strcpy(p[2].nome, "Mealhada");
        geraCod(p, 2, *total);
        p[2].linAssoiadas = NULL;
        p[1].totLinAssociadas = 0;

        return p;
    }
}

ptrPar geraCod(ptrPar p, int pos, int total) {
    char aux[5], charSet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVXYWZ";
    int flag = 0, j;
    wprintf(L"\nA gerar código alfanumérico...");
    do {
        for (j = 0; j < 4; ++j) {
            aux[j] = charSet[rand() % (strlen(charSet)-1)];
        }
        aux[j] = '\0';
        if (total > 1) {
            for (int k = 0; k < total; ++k) {
                if (strcmp(aux, p[k].cod) == 0) {
                    flag = 1;
                } else {
                    flag = 0;
                }
            }
        } else {
            flag = 0;
        }
    } while(flag == 1);
    strcpy(p[pos].cod, aux);
    return p;
}

int verificaNome_Paragens(ptrPar p, char* nome, int total) {// <- devolve 0 se nome existir em p
    if (total == 0) {                                       //    devolve 1 caso contrário
        return 1;
    } else {
        for (int i = 0; i < total; ++i) {
            if (strcmp(tolowerString(p[i].nome), tolowerString(nome)) == 0) {
                return 0;
            }
        }
        return 1;
    }
}

int verificaCod_Paragens(ptrPar p, char cod[4], int total) {// <- devolve 0 se cod existir em p
    if (total == 0) {                                       //    devolve 1 caso contrário
        return 1;
    } else {
        for (int i = 0; i < total; ++i) {
            if (strcmp(tolowerString(p[i].cod), tolowerString(cod)) == 0) {
                return 0;
            }
        }
        return 1;
    }
}

ptrPar dell(ptrPar p, int pos, int total) {
    for (int i = pos; i < total; ++i) {
        p[i] = p[i+1];
    }
    return p;
}

//  +----------------------+
//  | Funções do Enunciado |
//  +----------------------+

ptrPar registarPar(ptrPar p, int *total) {
    int i = 0, j = 0, res = 0, ans = 0;
    ptrPar aux = realloc(p, sizeof(par)*(*total+1));
    if(aux == NULL) {
        p = erroMemoria_Par(p);
        return p;
    } else {
        p = aux;
        ++(*total);

        printf("\n+--------------+\n| Nova Paragem |\n+--------------+-------------------------------------------+");
        wprintf(L"\n| Não é possível existirem duas paragens com o mesmo nome. |");
        printf("\n+----------------------------------------------------------+");

        printf("\nNome:");
        do {
            if (j > 0) {
                printf("\n+----------------------------------------------------+");
                wprintf(L"\n|                   Nome inválido                    |");
                wprintf(L"\n| Já existe uma paragem com esse nome registada no   |");
                wprintf(L"\n|                      sistema.                      |");
                printf("\n+----------------------------------------------------+");
                printf("\nTente novamente:");
            }
            fflush(stdin);
            scanf(" %s", p[*total-1].nome);
            j++;
        } while(verificaNome_Paragens(p, p[*total-1].nome, *total-1) == 0);
        p = geraCod(p, *total-1, *total);
        printf("\nA adicionar nova paragem...");

        return p;
    }
}

ptrPar eliminaPar(ptrPar p, int *total) {
    int pos = 0, flag = 0, i = 0;
    char cod[5];

    printf("\n+------------------+\n| Eliminar Paragem |\n+------------------+----------------------------------+");
    wprintf(L"\n| Introduza o código da paragem que pretende eliminar |");
    printf("\n|                       (Ex:L4J7).                    |");
    printf("\n+-----------------------------------------------------+");
    printf("\n->");
    do {
        if(i > 0) {
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
        flag = 0;
        fflush(stdin);
        scanf("%s", cod);
        if (verificaCod_Paragens(p, cod, *total) == 1 && strlen(cod) == 4) {// <- Condição necessária para escolher
            flag = 1;                                                       //    escolher a mensagem de erro
        }
        i++;
    } while (strlen(cod) != 4 || verificaCod_Paragens(p, cod, *total) == 1);

    for (int k = 0; k < *total; ++k) {
        if (strcmp(tolowerString(cod), tolowerString(p[k].cod)) == 0) {
            p = dell(p, k, *total);
            ptrPar aux = realloc(p, sizeof(par)*(*total-1));
            if (aux == NULL) {
                p = erroMemoria_Par(p);
            } else {
                printf("\nA eliminar paragem...");
                (*total)--;
            }
        }
    }
    return p;
}

void visualizarPar(ptrPar p, int total) {
    int i= 0, ans = 0, res = 0;
    if (total == 0) {
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
    }
    printf("\n+-----------------------------------------+");
    printf("\n| Todas as paragens registados no sistema |");
    printf("\n+---+--------+----------------------------+");
    wprintf(L"\n|   | Código | Nome ");
    printf("\n+---+--------+----------------------------+");
    for (int j = 0; j < total; ++j) {
        wprintf(L"\n| %d |  %s  | %s", j, p[j].cod, p[j].nome);
        printf("\n+---+--------+----------------------------+");
    }
}