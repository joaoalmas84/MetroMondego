#include "Menu.h"

// <- Função principal (só para não lhe chamar main)
void menu(ptrLin linList, ptrPar parList, int parTotal) {

}

// +----------+
// | Paragens |
// +----------+

ptrPar adicionaParagem(ptrPar lista, int *total) {
    int i = 0, j = 0, res = 0, ans = 0;
    char nome[50];
    char *cod;

    printf("\n+--------------+\n| Nova Paragem |\n+--------------+-------------------------------------------+");
    wprintf(L"\n| Não é possível existirem duas paragens com o mesmo nome. |");
    printf("\n+----------------------------------------------------------+");
    printf("\n->");
    do {
        if (j > 0) {
            printf("\n+----------------------------------------------------+");
            wprintf(L"\n|                   Nome inválido!                   |");
            wprintf(L"\n| Já existe uma paragem com esse nome registada no   |");
            wprintf(L"\n|              sistema, tente novamente.             |");
            printf("\n+----------------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        scanf(" %s", nome);
        j++;
    } while(verificaNome_Paragens(lista, nome, *total) == 1);

    do {
        cod = geraCod();
    } while (verificaCod_Paragens(lista, cod, *total) == 1);

    lista = addPar(lista, nome, cod, total);

    return lista;
}

ptrLin atualizaParagem(ptrLin listaL, ptrPar listaP, int parTotal) {

}

ptrPar eliminaParagem(ptrPar lista) {

}

void listPar(ptrPar lista, int total) {
    if (total == 0) {
        listaVazia();
        return;
    }
    printf("\n+-----------------------------------------+");
    printf("\n| Todas as paragens registadas no sistema |");
    printf("\n+---+--------+----------------------------+");
    wprintf(L"\n|   | Código | Nome ");
    printf("\n+---+--------+----------------------------+");
    for (int i = 0; i < total; ++i) {
        wprintf(L"\n| %d |  %s  | %s", i, lista[i].cod, lista[i].nome);
        printf("\n+---+--------+----------------------------+");
    }
}

// +--------+
// | Linhas |
// +--------+

ptrLin adicionaLinha(ptrLin listaL, ptrPar listaP, int parTotal) {

}

ptrLin atualizaLinha(ptrLin listaL, ptrPar listaP, int parTotal) {

}

ptrLin eliminaLinha(ptrLin lista, char* nome) {

}

void listaLin(ptrLin p) {

}