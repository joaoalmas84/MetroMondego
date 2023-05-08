#include "Menu.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrPar listP = NULL;
    int parTotal = 0;
    ptrLin listL = NULL;

    listP = adicionaParagem(listP, &parTotal);
    listPar(listP, parTotal);
    return 0;
}
