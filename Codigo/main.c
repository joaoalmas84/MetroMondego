#include "Menu.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrPar listP = NULL;
    int parTotal = 0;
    ptrLin listL = NULL;


    init_rand();
    listP = preencheLista_Paragens(listP, &parTotal);
    listPar(listP, parTotal);
    putchar('\n');
/*
    listP = adicionaParagem(listP, &parTotal);
    listPar(listP, parTotal);
    putchar('\n');

    listP = eliminaParagem(listP, &parTotal);
    listPar(listP, parTotal);
    putchar('\n');
*/

    listL = adicionaLinha(listL, listP, parTotal);
    listaLin(listL);

    return 0;
}
