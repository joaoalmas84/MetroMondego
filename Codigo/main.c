#include "Menu.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrLin listL = NULL;
    ptrPar listP = NULL;
    int totalPar = 0;

    printf("\n\t\t\t +--------------------------+");
    wprintf(L"\n\t\t\t | Prima ENTER para começar |");
    printf("\n\t\t\t +--------------------------+");
    getchar();

    menu(listL, listP, &totalPar);

    printf("\nVolte Sempre!");


    return 0;
}
