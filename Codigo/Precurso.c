#include "Precurso.h"

void precursoMainFunction(ptrLin listLin, ptrPar listPar, int parTotal) {
    int flag = 0,  i = 0;
    char nomeStart[50], nomeFinish[50];
    ptrLin precurso = NULL;

    printf("\n\t                 +-------------------+");
    printf("\n\t                 | Calcular Precurso |");
    printf("\n\t  +--------------+-------------------+-----------+");
    printf("\n\t  | Introduza o ponto de partida do precurso, o  |");
    wprintf(L"\n\t  |  nome da paragem onde começará o precurso.   |");
    printf("\n\t  +----------------------------------------------+");
    printf("\n\t  ->");
    getNameParUser(nomeStart, listPar, parTotal);

    printf("\n\t                 +-------------------+");
    printf("\n\t                 | Calcular Precurso |");
    printf("\n\t  +---------------------------------------------+");
    printf("\n\t  | Introduza o ponto de chegada do precurso, o |");
    wprintf(L"\n\t  |   nome da paragem onde acabará o precurso.  |");
    printf("\n\t  +---------------------------------------------+");
    printf("\n\t  ->");
    getNameParUser(nomeFinish, listPar, parTotal);

    precurso = calculaPrecursos(listLin, listPar, parTotal, precurso, nomeStart, nomeFinish);
}

ptrLin calculaPrecursos(ptrLin listLin, ptrPar listPar, int parTotal, ptrLin precurso, char* nomeStart, char* nomeFinish) {
    ptrLin aux = NULL;
    for (int i = 0; i < parTotal; ++i) {
        if (strcmp(tolowerString(listPar[i].cod), tolowerString(nomeStart)) == 0) {
            break;
        }
        aux = listPar[i].linAssoc;
        while (aux != NULL) {
            for (int j = 0; j < aux->nParAssoc; ++j) {
                if (strcmp(tolowerString(aux->parAssoc[j].nome), tolowerString(nomeFinish)) == 0) {

                }
            }
            aux = aux->prox;
        }
    }
}