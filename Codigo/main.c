#include "Menu.h"
#include "Skirt.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrLin listL = NULL;
    ptrPar listP = NULL;
    int totalPar = 0;

    printf("\n\t\t\t\t+-------+");
    printf("\n\t\t\t\t| Start |");
    printf("\n\t\t\t\t+-------+\n");
    getchar();

    menu(listL, listP, &totalPar);

    listL = EliminaParagemLinha(listL, "009ed6");

    visualizaLin(listL, "009ed6");
    return 0;
}
