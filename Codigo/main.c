#include "Menu.h"

int main() {
    setlocale(LC_ALL,"portuguese");
    ptrPar listP = NULL;
    int parTotal = 0;
    ptrLin listL = NULL;

/*
    char a[] = "Joao", b[] = "Ricardo", c[] = "Miguel";
    printf("\na -> %s\nb -> %s\nc -> %s", a, b, c);
    printf("\nstrcmp(a, b) -> %d", strcmp(a, b));
    printf("\nstrcmp(b, a) -> %d", strcmp(b, a));

    exit(1);
*/
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
    listL = adicionaLinha(listL, listP, parTotal);
    listaLin(listL);
    listL = adicionaLinha(listL, listP, parTotal);
    listaLin(listL);

    listaLinAll(listL);

    return 0;
}
