#include "Menu.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrLin listL = NULL;
    ptrPar listP = NULL;
    int totalPar = 0;
    char nome[50], cod[5], x[5];

    printf("\n\t\t\t\t+-------+");
    printf("\n\t\t\t\t| Start |");
    printf("\n\t\t\t\t+-------+\n");
    getchar();

    //init_rand();
    //listP = preencheLista_Paragens(listP, &totalPar);

    menu(listL, listP, &totalPar);

    return 0;
}
