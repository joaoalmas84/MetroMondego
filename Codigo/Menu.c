#include "Menu.h"

// <- Função principal (só para não lhe chamar main)
void menu(ptrLin listLin, ptrPar listPar, int parTotal) {
    /*
     * if (ans == listaLin) {
     *
     *   printf("\n+-------------+\n| Lista Linha |\n+-------------+----------------------------------+");
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
     * }
     */
}

// +----------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Paragens |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +----------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

ptrPar adicionaParagem(ptrPar lista, int *total) {
    int i = 0, j = 0, res = 0, ans = 0;
    char nome[50], cod[5];

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
                printf("\n+----------------------------------------------------+");
                wprintf(L"\n|   O código introduzido não corresponde a nenhuma   |");
                wprintf(L"\n|   paragem registada no sistema, tente novamente.   |");
                printf("\n+----------------------------------------------------+");
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

void visualizaPar(ptrPar lista, int total, char* cod) {
    int i = 0, j = 0;

    if (total == 0) {
        listaVazia();
        return;
    }
    for (i = 0; i < total; ++i) {
        if (strcmp(tolowerString(cod), tolowerString(lista[i].cod)) == 0){
            break;
        }
    }
    putchar('\n');
    printf("\n+---------------------------------------------------------+");
    printf("\n|     Todas as linhas que passam em %s", lista[i].nome);
    printf("\n+---+-----------------------------------------------------+");
    wprintf(L"\n|   | N.º de paragens | Nome ");
    printf("\n+---+-----------------+-----------------------------------+");
    while (lista[i].linAssoc != NULL) {
        wprintf(L"\n| %d |        %d        | %s", j+1, lista[i].linAssoc->nParAssoc, lista[i].linAssoc->nome);
        printf("\n+---+-----------------+-----------------------------------+");
        j++;
        lista[i].linAssoc = lista[i].linAssoc->prox;
    }
}

void visualizaParAll(ptrPar lista, int total) {
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
        } else if (i > 9 && i < 100) {
            if (i == 10) {
                printf("\n+----+--------+------------+----------------------+");
            }
            wprintf(L"\n| %d |  %s  |      %d     | %s", i+1, lista[i].cod, lista[i].nLinAssoc, lista[i].nome);
            printf("\n+----+--------+------------+----------------------+");
        }
    }
}

void visualizaParAllDetailed(ptrPar lista, int total) {
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

ptrLin adicionaLinha(ptrLin listLin, ptrPar listPar, int totalPar) {
    int i = 0, ans = 0, res = 0, flag = 0, nPar = 0;
    char nome[50], cod[5];
    ptrLin novaLin = NULL;

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
    } while (verificaNome_Lin(listLin, nome) == 1);

    novaLin = createNewLin(nome);
    getCodUser(cod, listPar, totalPar);
    listLin = insereLin(listLin, novaLin);
    listLin = addPar_Lin(novaLin, listPar, cod, totalPar);
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
            getCodUser(cod, listPar, totalPar);
            listLin = addPar_Lin(novaLin, listPar, cod, totalPar);
        }
    } while (ans != 2);
    return listLin;
}

ptrLin eliminaLinha(ptrLin listLin) {
    int i = 0;
    char nome[50];

    printf("\n+---------------+\n| Elimina Linha |\n+---------------+--------------------------------+");
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
    } while (verificaNome_Lin(listLin, nome) == 0);

    listLin = dellLin(listLin, nome);
    return listLin;
}

ptrLin atualizaLinha(ptrLin listLin, ptrPar listPar, int totalPar) {
    int i = 0, ans = 0, res = 0;
    char nome[50];
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
    } while (verificaNome_Lin(listLin, nome) == 0);

    i = 0;
    printf("\n+--------------------------------------------+");
    printf("\n|  1.Adicionar Paragem   2.Remover Paragem   |");
    printf("\n|               3.Alterar Nome               |");
    printf("\n+--------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            printf("\n+--------------------------------------------+");
            wprintf(L"\n|    Resposta Inválida, tente novamente.     |");
            printf("\n|  1.Adicionar Paragem   2.Remover Paragem   |");
            printf("\n|               3.Alterar Nome               |");
            printf("\n+--------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        res = scanf("%d", &ans);
        i++;
    } while (!res || ans != 1 && ans != 2 && ans != 3);

    if (ans == 1) {
        printf("\n+-------------------+\n| Adicionar Paragem |\n+-------------------+---------------------------+");
        printf("\n| 1.Adicionar Paragem     2.Vizualizar Paragens |");
        printf("\n+-----------------------------------------------+");
        printf("\n->");
        listLin = addParagem_Lin(listLin, listPar, totalPar, nome);
    } else if (ans == 2) {
        listLin = removeParagem_Lin(listLin, listPar, totalPar, nome);
    } else if (ans == 3) {
        listLin = alteraNome_Lin(listLin, nome);
    }
    return listLin;
}

ptrLin addParagem_Lin(ptrLin listLin, ptrPar listPar, int totalPar, char *nomeLinha) {
    int ans = 0, i = 0, res = 0, flag = 0;
    char cod[5];

    ptrLin aux = listLin;
    while (aux->prox != NULL) {
        if (strcmp(tolowerString(aux->nome), tolowerString(nomeLinha)) == 0) {
            break;
        }
        aux = aux->prox;
    }
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
        visualizaParAll(listPar, totalPar);
    }
    i = 0;
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
            } else if (flag == 2) {
                printf("\n+------------------------------------------------------+");
                wprintf(L"\n| A paragem correspondente ao codigo introduzido já se |");
                wprintf(L"\n|  encontra adicionada a esta linha, tente novamente.  |");
                printf("\n+------------------------------------------------------+");
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
        if (verificaCod_Paragens(listPar, cod, totalPar) == 0 && strlen(cod) == 4) {// <- Condição necessária para escolher
            flag = 1;                                                               //    escolher a mensagem de erro
        } else if (verificaCod_Paragens(aux->parAssoc, cod, aux->nParAssoc) == 1) {
            flag = 2;
        } else {
            flag = 0;
        }
        i++;
    } while (strlen(cod) != 4 || verificaCod_Paragens(listPar, cod, totalPar) == 0 || verificaCod_Paragens(aux->parAssoc, cod, aux->nParAssoc) == 1);
    aux = addPar_Lin(aux, listPar, cod, totalPar);

    return listLin;
}

ptrLin removeParagem_Lin(ptrLin listLin, ptrPar listPar, int parTotal, char *nomeLin) {
    int ans = 0, i = 0, flag = 0, res = 0;
    char cod[5];
    ptrLin aux = listLin;
    while (aux->prox != NULL) {
        if (strcmp(tolowerString(aux->nome), tolowerString(nomeLin)) == 0) {
            break;
        }
        aux = aux->prox;
    }

    printf("\n+-----------------+\n| Remover Paragem |\n+-----------------+----------------------------+");
    printf("\n| 1.Remover Paragem    2.Vizualizar Paragens   |");
    printf("\n|                             da linha         |");
    printf("\n+----------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            printf("\n+----------------------------------------------+");
            wprintf(L"\n|      Resposta inválida, tente novamente.     |");
            printf("\n| 1.Remover Paragem    2.Vizualizar Paragens   |");
            printf("\n|                             da linha         |");
            printf("\n+----------------------------------------------+");
            printf("\n->");
        }
        fflush(stdin);
        res = scanf("%d", &ans);
        i++;
    } while (!res || ans != 1 && ans != 2);

    if (ans == 2) {
        visualizaLin(aux, nomeLin);
    }
    i = 0;
    printf("\n+-----------------------------------------------------+");
    wprintf(L"\n| Introduza o código da paragem que pretende remover. |");
    printf("\n+-----------------------------------------------------+");
    printf("\n->");
    do {
        if (i > 0) {
            if (flag == 1) {
                printf("\n+------------------------------------------------+");
                wprintf(L"\n| O código introduzido não corresponde a nenhuma |");
                printf("\n|      paragem desta linha, tente novamente.     |");
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
        if (verificaCod_Paragens(aux->parAssoc, cod, aux->nParAssoc) == 0 && strlen(cod) == 4) {// <- Condição necessária para escolher
            flag = 1;                                                                           //    escolher a mensagem de erro
        } else {
            flag = 0;
        }
        i++;
    } while (strlen(cod) != 4 || verificaCod_Paragens(aux->parAssoc, cod, aux->nParAssoc) == 0);
    aux = removePar_Lin(aux, cod);
    visualizaPar(listPar, parTotal, cod);
    listPar = removeLin_Par(listPar, cod, parTotal, nomeLin);
    visualizaPar(listPar, parTotal, cod);
    return listLin;
}

ptrLin alteraNome_Lin(ptrLin listLin, char *nomeLin) {
    int ans = 0, i = 0;
    char newName[50];
    ptrLin aux = listLin;
    while (aux->prox != NULL) {
        if (strcmp(tolowerString(aux->nome), tolowerString(nomeLin)) == 0) {
            break;
        }
        aux = aux->prox;
    }
    printf("\n+--------------------------------+");
    wprintf(L"\n| Introduza o novo nome da linha |");
    printf("\n+--------------------------------+");
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
    } while (verificaNome_Lin(listLin, newName) == 1);
    aux = alterName_Lin(aux, newName);
    return listLin;
}

void visualizaLin(ptrLin p, char* nome) {
    int i = 0;
    ptrLin aux = p;
    while (aux->prox != NULL) {
        if (strcmp(tolowerString(p->nome), tolowerString(nome)) == 0) {
            break;
        }
        aux = aux->prox;
    }

    if (aux->nParAssoc == 0) {
        listaVazia();
        return;
    } else {
        printf("\n+--------------------------------------------------+");
        printf("\n| Paragens da linha %s ", aux->nome);
        printf("\n+---+--------+-------------------------------------+");
        wprintf(L"\n|   | Código | Nome ");
        printf("\n+---+--------+-------------------------------------+");
        for (int j = 0; j < aux->nParAssoc; ++j) {
            wprintf(L"\n| %d |  %s  | %s", j+1, aux->parAssoc[j].cod, aux->parAssoc[j].nome);
            printf("\n+---+--------+-------------------------------------+");
        }
    }
}

void visualizaLinAll(ptrLin p) {
    int i = 0;
    if (p == NULL) {
        listaVazia();
        return;
    } else {
        ptrLin aux = p;
        printf("\n+-----------------------------------------+");
        printf("\n|  Todas as linhas registadas no sistema  |");
        printf("\n+---+-----------------+-------------------+");
        wprintf(L"\n|   | N.º de paragens | Nome ");
        printf("\n+---+-----------------+-------------------+");
        while (aux != NULL) {
            wprintf(L"\n| %d |       %d         | %s", i+1, aux->nParAssoc, aux->nome);
            printf("\n+---+-----------------+-------------------+");
            i++;
            aux = aux->prox;
        }
    }
}

void visualizaLinAllDetailed(ptrLin p) {
    if (p == NULL) {
        listaVazia();
        return;
    } else {
        ptrLin aux = p;
        printf("\n+------------------------------------------------------------+");
        printf("\n|  Todas as linhas registadas no sistema e as suas paragens  |");
        printf("\n+------------------------------------------------------------+");
        while (aux != NULL) {
            printf("\n| Paragens da linha %s ", aux->nome);
            printf("\n+---+--------+-----------------------------------------------+");
            wprintf(L"\n|   | Código | Nome ");
            printf("\n+---+--------+-----------------------------------------------+");
            for (int i = 0; i < aux->nParAssoc; ++i) {
                wprintf(L"\n| %d |  %s  | %s", i+1, aux->parAssoc[i].cod, aux->parAssoc[i].nome);
                printf("\n+---+--------+-----------------------------------------------+");
            }
            aux = aux->prox;
        }
    }
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Linhas -> extras ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +------------------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void getCodUser(char* cod, ptrPar listaP, int parTotal) {
    int res = 0, i = 0, ans = 0, flag = 0;

    printf("\n+-------------------+\n| Adicionar Paragem |\n+-------------------+--------------------------------------------------------------+");
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
        visualizaParAll(listaP, parTotal);
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
