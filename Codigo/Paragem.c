#include "Paragem.h"

// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funções auxiliares ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// <- devolve 1 se nome existir em lista
int verificaNome_Paragens(ptrPar lista, char* nome, int total) {
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
int verificaCod_Paragens(ptrPar lista, char cod[4], int total) {
    if (total == 0) {
        return 0;
    } else {
        for (int i = 0; i < total; ++i) {
            if (strcmp(tolowerString(lista[i].cod), tolowerString(cod)) == 0) {
                return 1;
            }
        }
        return 0;
    }
}


char* geraCod() {
    char *cod, charSet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVXYWZ";
    int flag = 0, j;
    wprintf(L"\nA gerar código alfanumérico...");
    char *aux = malloc(sizeof(char)*5);
    if (aux == NULL) {
        return NULL;
    } else {
        cod = aux;
        do {
            for (j = 0; j < 4; ++j) {
                cod[j] = charSet[rand() % (strlen(charSet) - 1)];
            }
            cod[j] = '\0';
        } while (flag == 1);
    }
    return cod;
}

// Mensagem de erro quando a alocação de memória falha
ptrPar erroMemoria_Par(ptrPar p) {
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

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funcionalidades |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +-----------------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// Adiciona Paragem
ptrPar addPar(ptrPar lista, char *nome, char *cod, int *total) {
    ptrPar aux = realloc(lista, sizeof(int)*(*total+1));
    if (aux == NULL) {
        return lista = erroMemoria_Par(lista);
    } else {
        lista = aux;
        (*total)++;

        strcpy(lista[*total-1].nome, nome);
        strcpy(lista[*total-1].cod, cod);
        lista[*total-1].linAssoiadas = NULL;
        lista[*total-1].totLinAssociadas = 0;

        //printf("\nTotal -> %d\nCod -> %s\nNome -> %s",*total, lista[*total-1].cod, lista[*total-1].nome);

        return lista;
    }
}



//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
