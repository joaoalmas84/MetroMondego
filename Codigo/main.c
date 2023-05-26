#include "Menu.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrLin listL = NULL;
    ptrPar listP = NULL;
    int totalPar = 0;

    listP = preencheLista_Paragens(listP, &totalPar);
    menu(listL, listP, totalPar);

    return 0;
}
