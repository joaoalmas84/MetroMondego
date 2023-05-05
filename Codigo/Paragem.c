#include "utils.h"
#include "Paragem.h"

//  +--------+
//  | Extras |
//  +--------+

ptrPar preencheLista_Paragens(ptrPar p, int *total) {
    ptrPar aux = malloc(sizeof(par)*(*total+3));
    if(aux == NULL) {
        wprintf(L"\nErro na alocação de memória.\nA sair da função...");
        return p;
    }

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

int verificaNome_Paragens(ptrPar p, char* nome, int total) {
    if (total == 0) {
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

ptrPar dell(ptrPar p, int pos, int *total) {
    for (int i = pos; i < *total; ++i) {
        p[i] = p[i+1];
    }
    (*total)--;

    return p;
}

//  +----------------------+
//  | Funções do Enunciado |
//  +----------------------+

ptrPar registarPar(ptrPar p, int *total) { // Não está a dar
    int i = 0;
    ptrPar aux = realloc(p, sizeof(par)*(*total+1));
    if(aux == NULL) {
        wprintf(L"\nErro na alocação de memória!\nA sair da função...\n(O array é retornado sem alterações)");
        return p;
    }
    p = aux;
    ++(*total);

    printf("\n+--------------+\n| Nova Paragem |\n+--------------+");
    printf("\nNome:");
    do {
        if (i > 0) {
            wprintf(L"\nJá existe uma paragem com esse nome registada no sistema.\nTente novamente:");
        }
        fflush(stdin);
        scanf(" %s", p[*total-1].nome);
        i++;
    } while(verificaNome_Paragens(p, p[*total-1].nome, *total-1) == 0);
    p = geraCod(p, *total-1, *total);
    printf("\nA adicionar nova paragem...");

    return p;
}

ptrPar eliminaPar(ptrPar p, int *total) {
    int pos = 0, flag = 0, i = 0;
    char cod[5];

    printf("\n+------------------+\n| Eliminar Paragem |\n+------------------+");
    wprintf(L"\nIntroduza o código da paragem que pretende eliminar\n(Exemplo: LJJQ):");
    do {
        if(i > 0) {
            wprintf(L"\nCodigo inválido\nO código alfanumérico é composto por 4 caracteres,\nletras ou números apenas (Exemplo: LJJQ)\nTente novamente:");
        }
        fflush(stdin);
        scanf("%s", cod);
        i++;
    } while (strlen(cod) != 4);

    for (int j = 0; j < *total; ++j) {
        if (strcmp(tolowerString(cod), tolowerString(p[j].cod)) == 0) {
            p = dell(p, j, total);
        }
    }
    return p;
}

void vizualizarPar(ptrPar p, int total) {
    if (total == 0) {
        printf("A lista de paragens encontra-se vazia.");
        return;
    }
    printf("\n+-----------------------------------------+");
    printf("\n| Todas as paragens registados no sistema |");
    printf("\n+---+--------+----------------------------+");
    wprintf(L"\n|   | Código | Nome                       |");
    printf("\n+---+--------+----------------------------+");
    for (int i = 0; i < total; ++i) {
        wprintf(L"\n| %d |  %s  | %s", i, p[i].cod, p[i].nome);
        printf("\n+---+--------+----------------------------+");
    }
}