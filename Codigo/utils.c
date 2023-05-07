#include "utils.h"

void init_rand() {
    srand((unsigned) time(NULL));// inicializa gerador de números aleatorios
}

char* tolowerString(char* s) { // devolve uma string igual à passada por parâmetro mas toda em lowercase
    char *aux = malloc(sizeof(char)*(strlen(s)));
    int i;
    if(aux == NULL) {
        wprintf(L"\nErro na alocação de memória.\nA sair da função...");
        return s;
    }
    for ( i = 0; s[i] != '\0' ; ++i) {
        aux[i] = tolower(s[i]);
    }
    aux[i] = '\0';
    return aux;
}

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

