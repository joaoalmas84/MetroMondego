#include "Utils.h"

// inicializa gerador de valores aleatórios
void init_rand() {
    srand((unsigned) time(NULL));
}

// devolve uma string igual à passada por parâmetro mas toda em lowercase
char* tolowerString(char* s) {
    char *aux = malloc(sizeof(char)*(strlen(s)));
    int i;
    if(aux == NULL) {
        if (erroMemoria() == 1) {
            return NULL;
        } else {
            exit(1);
        }
    }
    for ( i = 0; s[i] != '\0' ; ++i) {
        aux[i] = tolower(s[i]);
    }
    aux[i] = '\0';
    return aux;
}

// mensagem de erro quando a lista se encontra vazia
void listaVazia() {
    int i= 0, ans = 0, res = 0;
    printf("\n\t\t     +--------------------------------+");
    printf("\n\t\t     |   A lista encontra-se vazia.   |");
    printf("\n\t\t     |    Prima ENTER para voltar.    |");
    printf("\n\t\t     +--------------------------------+");
    getchar();
    getchar();
    system("cls");

}

int erroMemoria() {
    int i = 0, res = 0, ans = 0;
    printf("\n+---------------------------------------------------+");
    wprintf(L"\n|           Erro na alocação de memória.            |");
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
    } while (!res || ans < 1 || ans > 2);
    return ans;
}

int erroFile() {
    int i = 0, res = 0, ans = 0;
    printf("\nx+---------------------------------------------------+");
    wprintf(L"\n|            Erro na abertura do ficheiro.          |");
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
    } while (!res || ans < 1 || ans > 2);
    return ans;
}



