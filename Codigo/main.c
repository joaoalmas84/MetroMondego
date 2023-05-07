#include "utils.h"
#include "Paragem.h"
#include "Linha.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrPar parLista = NULL;// <- array dinamico com todas as paragens registadas no sistema
    int parTotal = 0;
    ptrLin linLista = NULL;// <- lista ligada com todas as linhas registadas no sistema

    //  +----------+
    //  | Paragens |
    //  +----------+
    init_rand();
    parLista = preencheLista_Paragens(parLista, &parTotal);
    putchar('\n');

    visualizarPar(parLista, parTotal);
    putchar('\n');

    parLista = registarPar(parLista, &parTotal);
    putchar('\n');

    visualizarPar(parLista, parTotal);
    putchar('\n');

    eliminaPar(parLista, &parTotal);
    putchar('\n');

    visualizarPar(parLista, parTotal);
    putchar('\n');

    //  +--------+
    //  | Linhas |
    //  +--------+
    linLista = preencheLista_Linhas(linLista);
    putchar('\n');

    visualizarLinhas(linLista);
    putchar('\n');

    linLista = adicionarLinha(linLista, parLista, parTotal);
    putchar('\n');

    visualizarLinhas(linLista);

    free(parLista);
    free(linLista);

    return 0;
}