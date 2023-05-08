#include "Menu.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrPar listP = NULL;
    int parTotal = 0;
    ptrLin listL = NULL;

    listP = preencheLista_Paragens(listP, &parTotal);

    listP = adicionaParagem(listP, &parTotal);
    listPar(listP, parTotal);
    putchar('\n');

    listP = eliminaParagem(listP, &parTotal);
    listPar(listP, parTotal);
    putchar('\n');
    return 0;
}
