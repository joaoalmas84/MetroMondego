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