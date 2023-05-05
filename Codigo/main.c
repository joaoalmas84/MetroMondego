#include "utils.h"
#include "Paragem.h"
#include "Linha.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrPar parLista = NULL;// <- array dinamico com todas as paragens registadas no sistema
    int parTotal = 0;
    ptrLin linLista = NULL;// <- lista ligada com todas as linhas registadas no sistema

/*
    init_rand();
    parLista = preencheLista_Paragens(parLista, &parTotal);
    putchar('\n');

    vizualizarPar(parLista, parTotal);
    putchar('\n');

    //parLista = registarPar(parLista, &parTotal);
    //putchar('\n');

    //vizualizarPar(parLista, parTotal);
    //putchar('\n');

    eliminaPar(parLista, &parTotal);
    putchar('\n');

    vizualizarPar(parLista, parTotal);
    putchar('\n');
*/


    linLista = preencheLista_Linhas(linLista);
    vizualizarLinhas(linLista);
    putchar('\n');
    linLista = adicionarLinha(linLista);
    putchar('\n');
    vizualizarLinhas(linLista);
    free(parLista);
    return 0;
}