#include "Menu.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrLin listL = NULL;
    ptrPar listP = NULL;
    int totalPar = 0;
    char nome[50], cod[5];

    init_rand();
    listP = preencheLista_Paragens(listP, &totalPar);
    printf("\n+-------+");
    printf("\n| Start |");
    printf("\n+-------+");
    scanf(" %s", cod);
    listL = getLinFromFile(listL, "Linha da Baixa");

    listP = getParToLinFromFile(listL, listP, &totalPar, "Linha da Baixa");
    printf("\nNo main:");
    visualizaParAll(listP, totalPar);
    menu(listL, listP, totalPar);

    return 0;
}
