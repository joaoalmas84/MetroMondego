#include "Menu.h"

// <- Função principal (só para não lhe chamar main)
void menu(ptrLin linList, ptrPar parList, int parTotal) {

}

// +----------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Paragens |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +----------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

ptrPar adicionaParagem(ptrPar lista, int *total) {
    int i = 0, j = 0, res = 0, ans = 0;
    char nome[50];
    char cod[5];

    printf("\n+--------------+\n| Nova Paragem |\n+--------------+-------------------------------------------+");
    wprintf(L"\n| Não é possível existirem duas paragens com o mesmo nome. |");
    printf("\n+----------------------------------------------------------+");
    printf("\n->");
    do {
        if (j > 0) {
            printf("\n+----------------------------------------------------+");
            wprintf(L"\n|                   Nome inválido!                   |");
            wprintf(L"\n| Já existe uma paragem com esse nome registada no   |");
            wprintf(L"\n|              sistema, tente novamente.             |");
            printf("\n+----------------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        scanf(" %s", nome);
        j++;
    } while(verificaNome_Paragens(lista, nome, *total) == 1);

    do {
        strcpy(cod, geraCod());
    } while (verificaCod_Paragens(lista, cod, *total) == 1);

    lista = addPar(lista, nome, cod, total);

    return lista;
}

ptrPar eliminaParagem(ptrPar lista, int *total) {
    int flag = 0, i = 0;
    char cod[5];

    printf("\n+------------------+\n| Eliminar Paragem |\n+------------------+----------------------------------+");
    wprintf(L"\n| Introduza o código da paragem que pretende eliminar |");
    printf("\n|                       (Ex:L4J7).                    |");
    printf("\n+-----------------------------------------------------+");
    printf("\n->");
    do {
        if(i > 0) {
            if (flag == 1){
                printf("\n  +----------------------------------------------------+");
                wprintf(L"\n|   O código introduzido não corresponde a nenhuma   |");
                wprintf(L"\n|   paragem registada no sistema, tente novamente.   |");
                printf("\n  +----------------------------------------------------+");
                printf("\n->");
            } else {
                printf("\n+----------------------------------------------------+");
                wprintf(L"\n|                   Codigo inválido                  |");
                wprintf(L"\n| O código alfanumérico é composto por 4 caracteres, |");
                wprintf(L"\n| letras e números apenas(Ex:L4J7), tente novamente. |");
                printf("\n+----------------------------------------------------+");
                printf("\n->");
            }
        }
        flag = 0;
        fflush(stdin);
        scanf(" %s", cod);
        if (strlen(cod) == 4 && verificaCod_Paragens(lista, cod, *total) == 0) {// <- Condição necessária para escolher
            flag = 1;                                                           //escolher a mensagem de erro
        }
        i++;
    } while (strlen(cod) != 4 || verificaCod_Paragens(lista, cod, *total) == 0);

    lista = dellPar(lista, cod, total);

    return lista;
}

void listPar(ptrPar lista, int total) {
    char cod[5];
    int res = 0, i = 0, ans = 0, flag = 0;

    if (total == 0) {
        listaVazia();
        return;
    }
    printf("\n+----------------------------------------------------+");
    wprintf(L"\n| Introduza o código da paragem que pretende listar. |");
    printf("\n+----------------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            if (flag == 1) {
                printf("\n+------------------------------------------------+");
                wprintf(L"\n| O código introduzido não corresponde a nenhuma |");
                wprintf(L"\n| paragem registada no sistema, tente novamente. |");
                printf("\n+------------------------------------------------+");
                printf("\n->");
            } else {
                printf("\n+----------------------------------------------------+");
                wprintf(L"\n|                   Codigo inválido                  |");
                wprintf(L"\n| O código alfanumérico é composto por 4 caracteres, |");
                wprintf(L"\n| letras e números apenas(Ex:L4J7), tente novamente. |");
                printf("\n+----------------------------------------------------+");
                printf("\n->");
            }
        }
        fflush(stdin);
        scanf(" %s", cod);
        if (verificaCod_Paragens(lista, cod, total) == 0 && strlen(cod) == 4) {// <- Condição necessária para escolher
            flag = 1;                                                              //    escolher a mensagem de erro
        } else {
            flag = 0;
        }
        i++;
    } while (strlen(cod) != 4 || verificaCod_Paragens(lista, cod, total) == 0);

    int j;
    for (j = 0; j < total; ++j) {
        if (strcmp(tolowerString(cod), tolowerString(lista[j].cod)) == 0){
            break;
        }
    }

    printf("\n+-------------------------------------------------+");
    printf("\n|     Todas as linhas que passam em %s", lista[j].nome);
    printf("\n+---+---------------------------------------------+");
    wprintf(L"\n|   | N.º de paragens | Nome ");
    printf("\n+---+-----------------+-------------------+");
    while (lista[j].linAssoc->prox != NULL) {
        wprintf(L"\n| %d |       %d       | %s", i+1, lista[j].linAssoc->nParAssoc, lista[j].linAssoc->nome);
        printf("\n+---+-----------------+-------------------+");
        i++;
        lista[j].linAssoc = lista[j].linAssoc->prox;
    }
}

void listParAll(ptrPar lista, int total) {
    if (total == 0) {
        listaVazia();
        return;
    }
    printf("\n+-------------------------------------------------+");
    printf("\n|     Todas as paragens registadas no sistema     |");
    printf("\n+---+--------+------------+-----------------------+");
    wprintf(L"\n|   | Código | N.º linhas | Nome ");
    printf("\n+---+--------+------------+-----------------------+");
    for (int i = 0; i < total; ++i) {
        if (i < 10) {
            wprintf(L"\n| %d |  %s  |      %d     | %s", i+1, lista[i].cod, lista[i].nLinAssoc, lista[i].nome);
            if (i < 8) {
                printf("\n+---+--------+------------+-----------------------+");
            } else if (i == 8) {
                printf("\n+---++-------++-----------++----------------------+");
            }
        } else if (i < 100) {
            if (i == 10) {
                printf("\n+----+--------+------------+----------------------+");
            }
            wprintf(L"\n| %d |  %s  |      %d     | %s", i+1, lista[i].cod, lista[i].nLinAssoc, lista[i].nome);
            printf("\n+----+--------+------------+----------------------+");
        }
    }
}

void listParAllDetailed(ptrPar lista, int total) {
    printf("\n+-------------------------------------------------+");
    printf("\n|     Todas as paragens registadas no sistema     |");
    printf("\n+---+--------+------------------------------------+");
    wprintf(L"\n|   | Código | Nome ");
    for (int i = 0; i < total; ++i) {
        wprintf(L"\n| %d |  %s  | %s", i+1, lista[i].cod, lista[i].nome);
        printf("\n+---+--------+------------------------------------+");
        wprintf(L"\n| Todas as linhas que passam em %s", lista[i].nome);
        printf("\n+-------------------------------------------------+");
        while (lista[i].linAssoc->prox != NULL) {
            printf("\n| %s", lista[i].linAssoc->nome);
            printf("\n+-------------------------------------------------+");
            lista[i].linAssoc = lista[i].linAssoc->prox;
        }
    }
}


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +--------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Linhas ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

ptrLin adicionaLinha(ptrLin listaL, ptrPar listaP, int parTotal) {
    int i = 0, ans = 0, res = 0, flag = 0, nPar = 0;
    char nome[50], cod[5];

    printf("\n+------------+\n| Nova Linha |\n+------------+-------------------------------------------+");
    wprintf(L"\n| Não é possível existirem duas linhas com o mesmo nome. |");
    printf("\n+--------------------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            printf("\n+----------------------------------------------------+");
            wprintf(L"\n|                   Nome inválido                    |");
            wprintf(L"\n|  Já existe uma linha com esse nome registada no    |");
            wprintf(L"\n|              sistema, tente novamente.             |");
            printf("\n+----------------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        scanf(" %s", nome);
        i++;
    } while (verificaNome_Lin(listaL, nome) == 1);

    getCodUser(cod, listaP, parTotal);
    listaL = addLin(listaL, nome, cod, listaP, parTotal);
    res = i = ans = 0;
    do {
        printf("\n+-------------------------------------+");
        wprintf(L"\n|        Adicionar mais paragens?     |");
        wprintf(L"\n|            1.Sim    2.Não           |");
        printf("\n+-------------------------------------+");
        printf("\n->");
        ans = res = i = 0;
        do {
            if (i > 0) {
                printf("\n+-------------------------------------+");
                wprintf(L"\n| Resposta inválida, tente novamente. |");
                printf("\n+-------------------------------------+");
                wprintf(L"\n|        Adicionar mais paragens?     |");
                wprintf(L"\n|            1.Sim    2.Não           |");
                printf("\n+-------------------------------------+");
                printf("\n->");
            }
            fflush(stdin);
            res = scanf("%d", &ans);
            i++;
        } while (!res || ans != 1 && ans != 2);
        if (ans == 1) {
            getCodUser(cod, listaP, parTotal);
            addPar_Lin(listaL, nome, cod, listaP, parTotal, 1);
        }
    } while (ans != 2);

    return listaL;
}

ptrLin atualizaLinha(ptrLin p, ptrPar listaP, int parTotal) {
    int i = 0, ans = 0, res = 0, flag = 0;
    char nome[50], newName[50], cod[5];
    printf("\n+----------------+\n| Atualiza Linha |\n+----------------+----------------------------------+");
    wprintf(L"\n| Introduza o nome da linha que pretende atualizar. |");
    printf("\n+---------------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            printf("\n+----------------------------------------------------+");
            wprintf(L"\n|                   Nome inválido!                   |");
            wprintf(L"\n|  Não existe nenhuma linha com esse nome registada  |");
            wprintf(L"\n|            no sistema, tente novamente.            |");
            printf("\n+----------------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        scanf(" %s", nome);
        i++;
    } while (verificaNome_Lin(p, nome) == 0);

    i = 0;
    printf("\n+-------------------------------------------+");
    printf("\n|   1.Remover Paragem      2.Alterar Nome   |");
    printf("\n|             3.Adicionar Paragem           |");
    printf("\n+-------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            printf("\n+------------------------------------------+");
            wprintf(L"\n|    Resposta Inválida, tente novamente    |");
            printf("\n|   1.Remover Paragem     2.Alterar Nome   |");
            printf("\n|             3.Adicionar Paragem          |");
            printf("\n+------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        res = scanf("%d", &ans);
        i++;
    } while (!res || ans != 1 && ans != 2 && ans != 3);

    if (ans == 1) {
        printf("\n+-------------------------------------------------------+");
        wprintf(L"\n| Introduza o código da paragem que pretende adicionar. |");
        printf("\n+-------------------------------------------------------+");
        printf("\n->");
        do {
            if (i > 0) {
                if (flag == 1) {
                    printf("\n+------------------------------------------------+");
                    wprintf(L"\n| O código introduzido não corresponde a nenhuma |");
                    wprintf(L"\n| paragem registada no sistema, tente novamente. |");
                    printf("\n+------------------------------------------------+");
                    printf("\n->");
                } else {
                    printf("\n+----------------------------------------------------+");
                    wprintf(L"\n|                   Codigo inválido                  |");
                    wprintf(L"\n| O código alfanumérico é composto por 4 caracteres, |");
                    wprintf(L"\n| letras e números apenas(Ex:L4J7), tente novamente. |");
                    printf("\n+----------------------------------------------------+");
                    printf("\n->");
                }
            }
            fflush(stdin);
            scanf(" %s", cod);
            if (verificaCod_Paragens(listaP, cod, parTotal) == 0 && strlen(cod) == 4) {// <- Condição necessária para escolher
                flag = 1;                                                              //    escolher a mensagem de erro
            } else {
                flag = 0;
            }
            i++;
        } while (strlen(cod) != 4 || verificaCod_Paragens(listaP, cod, parTotal) == 0);
        removePar_Lin(p, nome, cod); <- Está Mal!!! precisamos de aceder à linha certa através do nome
    } else if (ans == 2) {
        printf("\n+----------------------------------+");
        wprintf(L"\n| Introduza o novo nome da paragem |");
        printf("\n+----------------------------------+");
        printf("\n->");
        do {
            if (i > 0) {
                printf("\n+----------------------------------------------------+");
                wprintf(L"\n|                   Nome inválido                    |");
                wprintf(L"\n|  Já existe uma linha com esse nome registada no    |");
                wprintf(L"\n|              sistema, tente novamente.             |");
                printf("\n+----------------------------------------------------+");
                printf("\n->");
            }
            fflush(stdin);
            scanf(" %s", newName);
            i++;
        } while (verificaNome_Lin(p, newName) == 1);
        alterName_Lin(p, nome, newName);
    } else if (ans == 3) {
        printf("\n+-------------------------------------------------------+");
        wprintf(L"\n| Introduza o código da paragem que pretende adicionar. |");
        printf("\n+-------------------------------------------------------+");
        printf("\n->");
        do {
            if (i > 0) {
                if (flag == 1) {
                    printf("\n+------------------------------------------------+");
                    wprintf(L"\n| O código introduzido não corresponde a nenhuma |");
                    wprintf(L"\n| paragem registada no sistema, tente novamente. |");
                    printf("\n+------------------------------------------------+");
                    printf("\n->");
                } else {
                    printf("\n+----------------------------------------------------+");
                    wprintf(L"\n|                   Codigo inválido                  |");
                    wprintf(L"\n| O código alfanumérico é composto por 4 caracteres, |");
                    wprintf(L"\n| letras e números apenas(Ex:L4J7), tente novamente. |");
                    printf("\n+----------------------------------------------------+");
                    printf("\n->");
                }
            }
            fflush(stdin);
            scanf(" %s", cod);
            if (verificaCod_Paragens(listaP, cod, parTotal) == 0 && strlen(cod) == 4) {// <- Condição necessária para escolher
                flag = 1;                                                              //    escolher a mensagem de erro
            } else {
                flag = 0;
            }
            i++;
        } while (strlen(cod) != 4 || verificaCod_Paragens(listaP, cod, parTotal) == 0);
        addPar_Lin(p, nome, )
    }
    return p;
}

ptrLin eliminaLinha(ptrLin p, char* nome) {
    ptrLin aux1 = p, aux2 = aux1->prox;
    while (aux1->prox != NULL) {
        if (strcmp(tolowerString(aux1->prox->nome), tolowerString(nome)) == 0) {
            aux1->prox = aux2->prox;
            free(aux1->prox);
            break;
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return p;
}

void listaLin(ptrLin p) {
    int i = 0;
    char nome[50];

    printf("\n+-------------+\n| Lista Linha |\n+-------------+----------------------------------+");
    wprintf(L"\n| Introduza o nome da linha que pretende listar. |");
    printf("\n+------------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            printf("\n+----------------------------------------------------+");
            wprintf(L"\n|                   Nome inválido!                   |");
            wprintf(L"\n|  Não existe nenhuma linha com esse nome registada  |");
            wprintf(L"\n|            no sistema, tente novamente.            |");
            printf("\n+----------------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        scanf(" %s", nome);
        i++;
    } while (verificaNome_Lin(p, nome) == 0);

    while (p != NULL) {
        if (strcmp(tolowerString(p->nome), tolowerString(nome)) == 0) {
            break;
        }
        p = p->prox;
    }

    if (p->nParAssoc == 0) {
        listaVazia();
        return;
    } else {
        printf("\n+--------------------------------------------------+");
        printf("\n| Paragens da linha %s ", p->nome);
        printf("\n+---+--------+-------------------------------------+");
        wprintf(L"\n|   | Código | Nome ");
        printf("\n+---+--------+-------------------------------------+");
        for (int j = 0; j < p->nParAssoc; ++j) {
            wprintf(L"\n| %d |  %s  | %s", j+1, p->parAssoc[j].cod, p->parAssoc[j].nome);
            printf("\n+---+--------+-------------------------------------+");
        }
    }
}

void listaLinAll(ptrLin p) {
    int i = 0;
    if (p == NULL) {
        listaVazia();
        return;
    } else {
        printf("\n+-----------------------------------------+");
        printf("\n|  Todas as linhas registadas no sistema  |");
        printf("\n+-----------------------------------------+");
        wprintf(L"\n|   | N.º de paragens | Nome ");
        printf("\n+---+-----------------+-------------------+");
        while (p != NULL) {
            wprintf(L"\n| %d |       %d       | %s", i+1, p->nParAssoc, p->nome);
            printf("\n+---+-----------------+-------------------+");
            i++;
            p = p->prox;
        }
    }
}

void listaLinAllDetailed(ptrLin p) {
    if (p == NULL) {
        listaVazia();
        return;
    } else {
        printf("\n+------------------------------------------------------------+");
        printf("\n|  Todas as linhas registadas no sistema e as suas paragens  |");
        printf("\n+------------------------------------------------------------+");
        while (p != NULL) {
            printf("\n| Paragens da linha %s ", p->nome);
            printf("\n+---+--------+-----------------------------------------------+");
            wprintf(L"\n|   | Código | Nome ");
            printf("\n+---+--------+-----------------------------------------------+");
            for (int i = 0; i < p->nParAssoc; ++i) {
                wprintf(L"\n| %d |  %s  | %s", i+1, p->parAssoc[i].cod, p->parAssoc[i].nome);
                printf("\n+---+--------+-------------------------------------------+");
            }
            p = p->prox;
        }
    }
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Linhas -> extras ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void getCodUser(char *cod, ptrPar listaP, int parTotal) {
    int res = 0, i = 0, ans = 0, flag = 0;

    printf("\n+-------------------+\n| Associar Paragens |\n+-------------------+--------------------------------------------------------------+");
    wprintf(L"\n| Para ser registada no sistema uma linha necessita de ter pelo menos uma paragem. |");
    printf("\n|               1.Adicionar Paragem     2.Vizualizar Paragens                      |");
    printf("\n+----------------------------------------------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            printf("\n+----------------------------------------------+");
            wprintf(L"\n|      Resposta inválida, tente novamente.     |");
            printf("\n| 1.Adicionar Paragem    2.Vizualizar Paragens |");
            printf("\n+----------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        res = scanf("%d", &ans);
        i++;
    } while (!res || ans != 1 && ans != 2);

    if (ans == 2) {
        listPar(listaP, parTotal);
    }

    res = i = ans = flag = 0;
    printf("\n+-------------------------------------------------------+");
    wprintf(L"\n| Introduza o código da paragem que pretende adicionar. |");
    printf("\n+-------------------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            if (flag == 1) {
                printf("\n+------------------------------------------------+");
                wprintf(L"\n| O código introduzido não corresponde a nenhuma |");
                wprintf(L"\n| paragem registada no sistema, tente novamente. |");
                printf("\n+------------------------------------------------+");
                printf("\n->");
            } else {
                printf("\n+----------------------------------------------------+");
                wprintf(L"\n|                   Codigo inválido                  |");
                wprintf(L"\n| O código alfanumérico é composto por 4 caracteres, |");
                wprintf(L"\n| letras e números apenas(Ex:L4J7), tente novamente. |");
                printf("\n+----------------------------------------------------+");
                printf("\n->");
            }
        }
        fflush(stdin);
        scanf(" %s", cod);
        if (verificaCod_Paragens(listaP, cod, parTotal) == 0 && strlen(cod) == 4) {// <- Condição necessária para escolher
            flag = 1;                                                              //    escolher a mensagem de erro
        } else {
            flag = 0;
        }
        i++;
    } while (strlen(cod) != 4 || verificaCod_Paragens(listaP, cod, parTotal) == 0);

}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
