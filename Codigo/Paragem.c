#include "Paragem.h"

// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Funções auxiliares ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// <- devolve 1 se nome existir em lista
int verificaNome_Paragens(ptrPar lista, char *nome, int total) {
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
int verificaCod_Paragens(ptrPar lista, char *cod, int total) {
    if (total == 0) {
        return 0;
    } else {
        for (int i = 0; i < total; ++i) {
            if (strcmp(tolowerString(cod), tolowerString(lista[i].cod)) == 0) {
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

// Preenche o array com 3 paragens antes de começar o programa de modo a que tenhamos alguns dados com que trablhar
ptrPar preencheLista_Paragens(ptrPar p, int *total) {
    int i = 0, res = 0, ans = 0;
    ptrPar aux = malloc(sizeof(par)*(*total+3));
    if(aux == NULL) {
        return p = erroMemoria_Par(p);
    } else {
        p = aux;
        (*total) += 3;

        strcpy(p[0].nome, "Mira");
        strcpy(p[0].cod, geraCod());
        p[0].linAssoiadas = NULL;
        p[0].totLinAssociadas = 0;

        strcpy(p[1].nome, "Cantanhede");
        strcpy(p[1].cod, geraCod());
        p[1].linAssoiadas = NULL;
        p[1].totLinAssociadas = 0;

        strcpy(p[2].nome, "Mealhada");
        strcpy(p[2].cod, geraCod());
        p[2].linAssoiadas = NULL;
        p[2].totLinAssociadas = 0;

        return p;
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
    ptrPar aux = realloc(lista, sizeof(par)*(*total+1));
    if (aux == NULL) {
        return lista = erroMemoria_Par(lista);
    } else {

        lista = aux;
        (*total)++;

        strcpy(lista[*total-1].nome, nome);
        strcpy(lista[*total-1].cod, cod);
        lista[*total-1].linAssoiadas = NULL;
        lista[*total-1].totLinAssociadas = 0;

        printf("\nA adicionar paragem...");

        return lista;
    }
}

// Elimina Paragem
ptrPar dellPar(ptrPar lista, char *cod, int *total) {
    ptrPar aux = NULL;
    for (int i = 0; i < *total; ++i) {
        if (strcmp(tolowerString(lista[i].cod),tolowerString(cod)) == 0) {
            for (int j = i; j < *total-1; ++j) {
                lista[i] = lista[i+1];
            }
            break;
        }
    }
    aux = realloc(lista, sizeof(par)*(*total-1));
    if (aux == NULL) {
       return lista = erroMemoria_Par(lista);
    } else {
        printf("\nA eliminar paragem...");
        (*total)--;
        lista = aux;
        return lista;
    }
}



//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
