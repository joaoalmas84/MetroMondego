#include "Menu.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrPar listP = NULL;
    int totalPar = 0;
    ptrLin listL = NULL;
    char cod[5];

    init_rand();
    listP = preencheLista_Paragens(listP, &totalPar);

    visualizaParAll(listP, totalPar);
    putchar('\n');
/*
    listP = eliminaParagem(listP, &parTotal);
    visualizaParAll(listP, parTotal);
    putchar('\n');
*/
   // listL = batota(listL, listP);
    //putchar('\n');

    listL = adicionaLinha(listL, listP, totalPar);
    visualizaLinAll(listL);
    putchar('\n');
/*
    adicionaLinha(listL, listP, parTotal);
    putchar('\n');
    visualizaLinAll(listL);
*/
    printf("\nCod -> ");
    scanf(" %s", cod);
    for (int i = 0; i < totalPar; ++i) {
        if (strcmp(tolowerString(listP[i].cod), tolowerString(cod)) == 0) {
            break;
        }
    }

    for (int i = 0; i < 5; ++i) {
        listL = atualizaLinha(listL, listP, totalPar);
        visualizaLinAll(listL);
        visualizaPar(listP, totalPar, cod);
    }

    return 0;
}
