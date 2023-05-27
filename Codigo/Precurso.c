#include "Precurso.h"

void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal) {
    int flag = 0,  i = 0;
    char codStart[5], codFinish[5];
    ptrLin precurso = NULL;
    printf("\n\t                 +-------------------+");
    printf("\n\t                 | Calcular Precurso |");
    printf("\n\t  +--------------+-------------------+-----------+");
    printf("\n\t  | Introduza o ponto de partida do precurso, o  |");
    wprintf(L"\n\t  | código da paragem onde começará o precurso.  |");
    printf("\n\t  +----------------------------------------------+");
    printf("\n\t  ->");
    getCodUser(codStart, listPar, parTotal);
    printf("\n\t  +---------------------------------------------+");
    printf("\n\t  | Introduza o ponto de chegada do precurso, o |");
    wprintf(L"\n\t  | código da paragem onde acabará o precurso.  |");
    printf("\n\t  +---------------------------------------------+");
    printf("\n\t  ->");
    getCodUser(codFinish, listPar, parTotal);

    precurso = calculaPrecurso(precurso, listLin, listPar, parTotal);
}

ptrLin calculaPrecurso(ptrLin precurso, ptrLin listLin, ptrPar listPar, int parTotal) {

}