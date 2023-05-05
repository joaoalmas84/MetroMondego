#ifndef CODIGO_STRUCTS_H
#define CODIGO_STRUCTS_H

typedef struct Paragem par, *ptrPar;

typedef struct Linha lin, *ptrLin;

struct Paragem {
    char nome[50];
    char cod[5];
    ptrLin linAssoiadas;// <- lista ligada de linhas
    int totLinAssociadas;
};

struct Linha {
    char nome[50];
    ptrPar parAssociadas; // <- array dinamico de paragens
    int totParAssociadas;
    ptrLin prox;
};

#endif //CODIGO_STRUCTS_H
