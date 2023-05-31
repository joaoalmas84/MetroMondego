#include "Menu.h"

// <- Função principal (só para não lhe chamar main)
void menu(ptrLin listLin, ptrPar listPar, int *parTotal) {
    int i, j, res = 0, ans = 0, flag = 0;
    char nome[50], cod[5], fileName[50];
    FILE* f;
    do {
        j = 0;
        putchar('\n');
        printf("  __  __        _                 __  __                    _                     \n"
               " |  \\/  |  ___ | |_  _ __  ___   |  \\/  |  ___   _ __    __| |  ___   ____   ___  \n"
               " | |\\/| | / _ \\| __||  __|/ _ \\  | |\\/| | / _ \\ |  _ \\  / _  | / _ \\ / _  | / _ \\ \n"
               " | |  | ||  __/| |_ | |  | (_) | | |  | || (_) || | | || (_| ||  __/| (_| || (_) | \n"
               " |_|  |_| \\___| \\__||_|   \\___/  |_|  |_| \\___/ |_| |_| \\____| \\___| \\__  | \\___/ \n"
               "                                                                     |___/   ");
        wprintf(L"\n\t\t\t\t  By João Almas");
        putchar('\n');
        printf("\n\t+--------------------------------------------------------------+");
        printf("\n\t|         1.Registar Paragem          2.Adicionar Linha        |");
        printf("\n\t|         3.Eliminar Paragem          4.Atualizar Linha        |");
        printf("\n\t|         5.Visualizar Paragens       6.Visualizar Linhas      |");
        printf("\n\t|         7.Guardar Dados             8.Carregar Dados         |");
        printf("\n\t|                   9.Carregar Ficheiro Linha                  |");
        printf("\n\t|                       10.Calcular Precurso                   |");
        printf("\n\t|                             0.Sair                           |");
        printf("\n\t+--------------------------------------------------------------+");
        printf("\n\t->");
        do {
            if (j > 0) {
                printf("\n\t              +---------------------------------+");
                wprintf(L"\n\t              | Opção inválida, tente novamente |");
                printf("\n\t+-----------+---------------------------------+----------------+");
                printf("\n\t|         1.Registar Paragem          2.Adicionar Linha        |");
                printf("\n\t|         3.Eliminar Paragem          4.Atualizar Linha        |");
                printf("\n\t|         5.Visualizar Paragens       6.Visualizar Linhas      |");
                printf("\n\t|         7.Guardar Dados             8.Carregar Dados         |");
                printf("\n\t|                   9.Carregar Ficheiro Linha                  |");
                printf("\n\t|                       10.Calcular Precurso                   |");
                printf("\n\t|                             0.Sair                           |");
                printf("\n\t+--------------------------------------------------------------+");
                printf("\n\t->");
            }
            fflush(stdin);
            res = scanf("%d", &ans);
            j++;
        } while (!res || ans < 0 || ans > 10);

        switch (ans) {
            case 0:
                saveDadosLin(listLin);
                saveDadosPar(listPar, *parTotal);
                break;
            case 1:
                listPar = registaParagem(listPar, parTotal);
                break;
            case 2:
                listLin = adicionaLinha(listLin, listPar, *parTotal);
                break;
            case 3:
                listPar = eliminaParagem(listLin, listPar, parTotal);
                break;
            case 4:
                listLin = atualizaLinha(listLin, listPar, *parTotal);
                break;
            case 5:
                i = res = ans = 0;
                printf("\n\t\t\t       +---------------------+");
                printf("\n\t\t\t       | Visualizar Paragens |");
                printf("\n\t\t\t+------+---------------------+-----+");
                printf("\n\t\t\t| 1.Todas as paragens              |");
                printf("\n\t\t\t| 2.Todas as paragens e respetivas |");
                printf("\n\t\t\t|   linhas associadas              |");
                wprintf(L"\n\t\t\t| 3.Paragem específica             |");
                printf("\n\t\t\t| 0.Voltar                         |");
                printf("\n\t\t\t+----------------------------------+");
                printf("\n\t\t\t->");
                do {
                    if (i > 0) {
                        printf("\n\t\t\t+---------------------------------+");
                        wprintf(L"\n\t\t\t\t| Opção inválida, tente novamente |");
                        printf("\n\t\t\t+----------------------------------+");
                        printf("\n\t\t\t| 1.Todas as paragens              |");
                        printf("\n\t\t\t| 2.Todas as paragens e respetivas |");
                        printf("\n\t\t\t|   linhas associadas              |");
                        wprintf(L"\n\t\t\t| 3.Paragem específica             |");
                        printf("\n\t\t\t| 0.Voltar                         |");
                        printf("\n\t\t\t+----------------------------------+");
                        printf("\n\t\t\t->");
                    }
                    fflush(stdin);
                    res = scanf("%d", &ans);
                    i++;
                } while (!res || ans < 0 || ans > 3);
                switch (ans) {
                    case 0:
                        system("cls");
                        break;
                    case 1:
                        visualizaParAll(listPar, *parTotal);
                        break;
                    case 2:
                        visualizaParAllDetailed(listPar, *parTotal);
                        break;
                    case 3:
                        i = 0;
                        printf("\n\t                  +---------------+");
                        printf("\n\t                  | Lista Paragem |");
                        printf("\n\t+-----------------+---------------+------------------+");
                        wprintf(L"\n\t| Introduza o código da paragem que pretende listar. |");
                        printf("\n\t+----------------------------------------------------+");
                        printf("\n\t->");
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
                            scanf("%[^\n]", cod);
                            if (verificaCod_Paragens(listPar, cod, *parTotal) == 0 && strlen(cod) == 4) {// <- Condição necessária para escolher
                                flag = 1;                                                                //    escolher a mensagem de erro
                            }
                            i++;
                        } while (strlen(cod) != 4 || verificaCod_Paragens(listPar, cod, *parTotal) == 0);
                        visualizaPar(listPar, *parTotal, cod);
                        break;
                }
                break;
            case 6:
                i = res = ans = 0;
                printf("\n\t\t\t       +-------------------+");
                printf("\n\t\t\t       | Visualizar Linhas |");
                printf("\n\t\t\t+------+-------------------+------+");
                printf("\n\t\t\t| 1.Todas as linhas               |");
                printf("\n\t\t\t| 2.Todas as linhas e respetivas  |");
                printf("\n\t\t\t|   paragens associadas           |");
                wprintf(L"\n\t\t\t| 3.Linha específica              |");
                printf("\n\t\t\t| 0.Voltar                        |");
                printf("\n\t\t\t+---------------------------------+");
                printf("\n\t\t\t->");
                do {
                    if (i > 0) {
                        printf("\n\t\t\t+---------------------------------+");
                        wprintf(L"\n\t\t\t| Opção inválida, tente novamente |");
                        printf("\n\t\t\t+---------------------------------+");
                        printf("\n\t\t\t| 1.Todas as linhas               |");
                        printf("\n\t\t\t| 2.Todas as linhas e respetivas  |");
                        printf("\n\t\t\t|   paragens associadas           |");
                        wprintf(L"\n\t\t\t| 3.Linha específica              |");
                        printf("\n\t\t\t| 0.Voltar                        |");
                        printf("\n\t\t\t+---------------------------------+");
                        printf("\n\t\t\t->");
                    }
                    fflush(stdin);
                    res = scanf("%d", &ans);
                    i++;
                } while (!res || ans < 0 || ans > 3);
                switch (ans) {
                    case 0:
                        system("cls");
                        break;
                    case 1:
                        visualizaLinAll(listLin);
                        break;
                    case 2:
                        visualizaLinAllDetailed(listLin);
                        break;
                    case 3:
                        i = 0;
                        printf("\n\t                  +-------------+");
                        printf("\n\t                  | Lista Linha |");
                        printf("\n\t+-----------------+-------------+----------------+");
                        wprintf(L"\n\t| Introduza o nome da linha que pretende listar. |");
                        printf("\n\t+------------------------------------------------+");
                        printf("\n\t->");
                        do {
                            if (i > 0) {
                                printf("\n\t+----------------------------------------------------+");
                                wprintf(L"\n\t|                   Nome inválido!                   |");
                                wprintf(L"\n\t|  Não existe nenhuma linha com esse nome registada  |");
                                wprintf(L"\n\t|            no sistema, tente novamente.            |");
                                printf("\n\t+----------------------------------------------------+");
                                printf("\n\t->");
                            }
                            fflush(stdin);
                            scanf("%[^\n]", nome);
                            i++;
                        } while (verificaNome_Lin(listLin, nome) == 0);
                        visualizaLin(listLin, nome);
                        break;
                }
                break;
            case 7:
                saveDadosPar(listPar, *parTotal);
                saveDadosLin(listLin);
                break;
            case 8:
                listPar = loadDadosPar(listPar, parTotal);
                listLin = loadDadosLin(listLin);
                break;
            case 9:
                i = 0;
                int flag2 = 0;
                printf("\n\t                 +-------------------------+");
                printf("\n\t                 | Carregar Ficheiro Linha |");
                printf("\n\t+----------------+-------------------------+----------------+");
                printf("\n\t| Introduza o nome do Ficheiro linha que pretende carregar. |");
                printf("\n\t+-----------------------------------------------------------+");
                printf("\n\t->");
                do{
                    if (i > 0 && flag2 == 0) {
                        printf("\n\t+-------------------------------------------------+");
                        wprintf(L"\n\t| Não existe nenhum ficheiro linha com esse nome, |");
                        printf("\n\t|                 tente novamente.                |");
                        printf("\n\t+-------------------------------------------------+");
                        printf("\n\t->");
                    } else if (i > 0 && flag2 == 1) {
                        printf("\n\t+--------------------------------------------------+");
                        wprintf(L"\n\t| Essa paragem já se encontra registada no sistema |");
                        printf("\n\t|                 tente novamente.                 |");
                        printf("\n\t+--------------------------------------------------+");
                        printf("\n\t->");
                    }
                    flag2 = 0;
                    fflush(stdin);
                    scanf("%[^\n]", fileName);
                    if (verificaNome_Lin(listLin, fileName) == 1) {
                        flag2 = 1;
                    }
                    strcat(fileName, ".txt");
                    f = fopen(fileName, "r");
                    i++;
                } while (f == NULL || flag2 == 1);
                fclose(f);

                listLin = getLinFromFile(listLin, fileName);
                listPar = getParToLinFromFile(listLin, listPar, parTotal, fileName);
                break;
            case 10:
                precursoMainFunction(listLin, listPar, *parTotal);
                break;
        }
    } while (ans != 0);
}

// +----------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Paragens |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +----------+||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

ptrPar registaParagem(ptrPar listPar, int *parTotal) {
    int i = 0, res = 0, ans = 0;
    char nome[50], cod[5];

    printf("\n\t                         +--------------+");
    printf("\n\t                         | Nova Paragem |");
    printf("\n\t  +----------------------+--------------+--------------------+");
    wprintf(L"\n\t  | Não é possível existirem duas paragens com o mesmo nome. |");
    printf("\n\t  +----------------------------------------------------------+");
    printf("\n\t  ->");
    do {
        if (i > 0) {
            printf("\n\t      +--------------------------------------------------+");
            wprintf(L"\n\t      |                   Nome inválido!                 |");
            wprintf(L"\n\t      | Já existe uma paragem com esse nome registada no |");
            wprintf(L"\n\t      |              sistema, tente novamente.           |");
            printf("\n\t      +--------------------------------------------------+");
            printf("\n\t      ->");
        }
        fflush(stdin);
        scanf("%[^\n]", nome);
        i++;
    } while(verificaNome_Paragens(listPar, nome, *parTotal) == 1);

    do {
        strcpy(cod, geraCod());
    } while (verificaCod_Paragens(listPar, cod, *parTotal) == 1);

    listPar = addPar(listPar, nome, cod, parTotal);

    printf("\n\t\t     +--------------------------------+");
    printf("\n\t\t     | Paragem adicionada com sucesso |");
    printf("\n\t\t     |    prima ENTER para voltar.    |");
    printf("\n\t\t     +--------------------------------+");
    getchar();
    getchar();
    system("cls");
    return listPar;
}

ptrPar eliminaParagem(ptrLin listLin, ptrPar listPar, int *parTotal) {
    int flag = 0, i = 0, res = 0, ans = 0;
    char cod[5];

    do {
        ans = i = 0;
        printf("\n\t                      +------------------+");
        printf("\n\t                      | Eliminar Paragem |");
        printf("\n\t     +----------------+------------------+-----------------+");
        wprintf(L"\n\t     |     1.Eliminar Paragem   2.Visualizar Paragens      |");
        printf("\n\t     |                        Aviso!!                      |");
        printf("\n\t     | Se o eliminar de  uma paragem resultar em uma linha |");
        wprintf(L"\n\t     |     ficar sem paragens, essa linha será também      |");
        printf("\n\t     |                      eliminada.                     |");
        printf("\n\t     +-----------------------------------------------------+");
        printf("\n\t     ->");
        do {
            if (i > 0) {
                printf("\n\t\t+--------------------------------------------+");
                wprintf(L"\n\t\t|      Resposta inválida, tente novamente.   |");
                printf("\n\t\t| 1.Eliminar Paragem   2.Visualizar Paragens |");
                printf("\n\t\t+--------------------------------------------+");
                printf("\n\t\t->");
            }
            fflush(stdin);
            res = scanf("%d", &ans);
            i++;
        } while (!res || ans < 1 || ans > 2);

        if (ans == 2) {
            visualizaParAll(listPar, *parTotal);
        }
    } while (ans == 2);

    printf("\n\t                      +------------------+");
    printf("\n\t                      | Eliminar Paragem |");
    printf("\n\t     +----------------+------------------+------------------+");
    printf("\n\t     | Introduza o codigo da paragem que pretende eliminar. |");
    printf("\n\t     +------------------------------------------------------+");
    printf("\n\t     ->");
    getCodUser(cod, listPar, *parTotal);

    if (checkPar_Dell(listPar, *parTotal, cod) == 1) {
        listPar = dellPar(listPar, cod, parTotal);
        printf("\n\t\t     +-------------------------------+");
        printf("\n\t\t     | Paragem eliminada com sucesso |");
        printf("\n\t\t     |    prima ENTER para voltar.   |");
        printf("\n\t\t     +-------------------------------+");
        getchar();
        getchar();
        system("cls");
    } else {
        ans = i = 0;
        printf("\n+----------------------------------------------------------------+");
        wprintf(L"\n| Para eliminar uma paragem do sistema esta não pode fazer parte |");
        wprintf(L"\n|                     de nenhuma linha.                          |");
        printf("\n|                    1.Voltar     2.Remover de todas             |");
        printf("\n|                                     as linhas                  |");
        printf("\n+----------------------------------------------------------------+");
        printf("\n->");
        do {
            if (i > 0) {
                printf("\n+----------------------------------------------------+");
                wprintf(L"\n|         Resposta inválida, tente novamente.        |");
                printf("\n|           1.Voltar     2.Remover de todas          |");
                printf("\n|                            as linhas               |");
                printf("\n+----------------------------------------------------+");
                printf("\n->");
            }
            fflush(stdin);
            res = scanf("%d", &ans);
            i++;
        } while (!res || ans != 1 && ans != 2);
        if (ans == 1) {
            system("cls");
            return listPar;
        } else {
            listLin = removePar_All(listLin, listPar, *parTotal, cod);
            listPar = dellPar(listPar, cod, parTotal);
            printf("\n\t\t     +-------------------------------+");
            printf("\n\t\t     | Paragem eliminada com sucesso |");
            printf("\n\t\t     |    prima ENTER para voltar.   |");
            printf("\n\t\t     +-------------------------------+");
            getchar();
            getchar();
            system("cls");
        }
    }
    return listPar;
}

void visualizaPar(ptrPar listPar, int parTotal, char* cod) {
    int i = 0, j = 0;

    for (i = 0; i < parTotal; ++i) {
        if (strcmp(tolowerString(cod), tolowerString(listPar[i].cod)) == 0){
            break;
        }
    }
    if (listPar[i].nLinAssoc == 0) {
        printf("\n\t\t+---------------------------------------------------------+");
        wprintf(L"\n\t\t|     Não passa nenhuma linha em %s", listPar[i].nome);
        printf("\n\t\t+---------------------------------------------------------+");
        printf("\n\t\t     +--------------------------------+");
        printf("\n\t\t     |    Prima ENTER para voltar.    |");
        printf("\n\t\t     +--------------------------------+");
        getchar();
        getchar();
        system("cls");
        return;
    }
    ptrLin aux = listPar[i].linAssoc;
    putchar('\n');
    printf("\n\t\t+---------------------------------------------------------+");
    printf("\n\t\t|     Todas as linhas que passam em %s", listPar[i].nome);
    printf("\n\t\t+---+-----------------------------------------------------+");
    while (aux != NULL) {
        wprintf(L"\n\t\t| %d |  %s", j, aux->nome);
        printf("\n\t\t+---+-----------------------------------------------------+");
        j++;
        aux = aux->prox;
    }
    printf("\n\t\t     +--------------------------------+");
    printf("\n\t\t     |    Prima ENTER para voltar.    |");
    printf("\n\t\t     +--------------------------------+");
    getchar();
    getchar();
    system("cls");
    return;
}

void visualizaParAll(ptrPar listPar, int parTotal) {
    if (parTotal == 0) {
        listaVazia();
        return;
    }
    printf("\n\t\t+-------------------------------------------------+");
    printf("\n\t\t|     Todas as paragens registadas no sistema     |");
    printf("\n\t\t+---+--------+------------+-----------------------+");
    wprintf(L"\n\t\t|   | Código | N.º linhas | Nome ");
    printf("\n\t\t+---+--------+------------+-----------------------+");
    for (int i = 0; i < parTotal; ++i) {
        if (i < 10) {
            wprintf(L"\n\t\t| %d |  %s  |      %d     | %s", i+1, listPar[i].cod, listPar[i].nLinAssoc, listPar[i].nome);
            if (i <= 8) {
                printf("\n\t\t+---+--------+------------+-----------------------+");
            } else if (i > 8) {
                printf("\n\t\t+---++-------++-----------++----------------------+");
            }
        } else if (i > 9 && i < 100) {
            wprintf(L"\n\t\t| %d |  %s  |      %d     | %s", i+1, listPar[i].cod, listPar[i].nLinAssoc, listPar[i].nome);
            printf("\n\t\t+----+--------+------------+----------------------+");
        }
    }

    printf("\n\t\t     +--------------------------------+");
    printf("\n\t\t     |    Prima ENTER para voltar.    |");
    printf("\n\t\t     +--------------------------------+");
    getchar();
    getchar();
    system("cls");

    return;
}

void visualizaParAllDetailed(ptrPar listPar, int parTotal) {
    if (parTotal == 0) {
        listaVazia();
        return;
    }
    printf("\n\t\t+--------------------------------------------------------------------+");
    printf("\n\t\t|     Todas as paragens registadas no sistema e linhas associadas    |");
    printf("\n\t\t+---+--------+-------------------------------------------------------+");
    wprintf(L"\n\t\t|   | Código | Nome da paragem                                     |");
    printf("\n\t\t+---+--------+-------------------------------------------------------+");
    for (int i = 0; i < parTotal; ++i) {
        ptrLin aux = listPar[i].linAssoc;
        wprintf(L"\n\t\t| %d |  %s  | %s", i+1, listPar[i].cod, listPar[i].nome);
        printf("\n\t\t+---+--------+-------------------------------------------------------+");
        if (listPar[i].nLinAssoc == 0) {
            wprintf(L"\n\t\t| Não passa nenhuma linha em %s", listPar[i].nome);
            printf("\n\t\t+--------------------------------------------------------------------+");
        } else {
            while (aux != NULL) {
                printf("\n\t\t| -> %s", aux->nome);
                printf("\n\t\t+--------------------------------------------------------------------+");
                aux = aux->prox;
            }
        }
    }
    printf("\n\t\t     +--------------------------------+");
    printf("\n\t\t     |    Prima ENTER para voltar.    |");
    printf("\n\t\t     +--------------------------------+");
    getchar();
    getchar();
    system("cls");
    return;
}


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +--------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Linhas ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

ptrLin adicionaLinha(ptrLin listLin, ptrPar listPar, int parTotal) {
    int i = 0, ans = 0, res = 0, flag = 0, nPar = 0;
    char nome[50], cod[5];
    ptrLin novaLin = NULL;

    printf("\n\t                         +------------+");
    printf("\n\t                         | Nova Linha |");
    printf("\n\t   +---------------------+------------+---------------------+");
    wprintf(L"\n\t   | Não é possível existirem duas linhas com o mesmo nome. |");
    printf("\n\t   +--------------------------------------------------------+");
    printf("\n\t   ->");
    do {
        if (i > 0) {
            printf("\n\t      +----------------------------------------------------+");
            wprintf(L"\n\t      |                   Nome inválido                    |");
            wprintf(L"\n\t      |  Já existe uma linha com esse nome registada no    |");
            wprintf(L"\n\t      |              sistema, tente novamente.             |");
            printf("\n\t      +----------------------------------------------------+");
            printf("\n\t      ->");
        }
        fflush(stdin);
        scanf(" %[^\n]", nome);
        i++;
    } while (verificaNome_Lin(listLin, nome) == 1);

    novaLin = createNewLin(nome);
    listLin = insereLin(listLin, novaLin);
    getCodAddPar(cod, listPar, parTotal, nome, listLin);
    listLin = addPar_Lin(listLin, nome, listPar, NULL, cod, parTotal, 0);

    res = i = ans = 0;
    do {
        printf("\n\t\t\t+----------------------------------+");
        wprintf(L"\n\t\t\t|     Adicionar mais paragens?     |");
        wprintf(L"\n\t\t\t|          1.Sim    2.Não          |");
        printf("\n\t\t\t+----------------------------------+");
        printf("\n\t\t\t->");
        ans = res = i = 0;
        do {
            if (i > 0) {
                printf("\n\t\t\t+-------------------------------------+");
                wprintf(L"\n\t\t\t| Resposta inválida, tente novamente. |");
                printf("\n\t\t\t+-------------------------------------+");
                wprintf(L"\n\t\t\t|       Adicionar mais paragens?      |");
                wprintf(L"\n\t\t\t|            1.Sim    2.Não           |");
                printf("\n\t\t\t+-------------------------------------+");
                printf("\n\t\t\t->");
            }
            fflush(stdin);
            res = scanf("%d", &ans);
            i++;
        } while (!res || ans != 1 && ans != 2);
        if (ans == 1) {
            getCodAddPar(cod, listPar, parTotal, nome, listLin);
            listLin = addPar_Lin(listLin, nome, listPar, NULL, cod, parTotal, 0);
        }
    } while (ans != 2);
    printf("\n\t\t     +------------------------------+");
    printf("\n\t\t     | Linha adicionada com sucesso |");
    printf("\n\t\t     |   prima ENTER para voltar.   |");
    printf("\n\t\t     +------------------------------+");
    getchar();
    getchar();
    system("cls");
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
        scanf("%[^\n]", nome);
        i++;
    } while (verificaNome_Lin(listLin, nome) == 0);

    listLin = dellLin(listLin, nome);
    return listLin;
}

ptrLin atualizaLinha(ptrLin listLin, ptrPar listPar, int totalPar) {
    int i = 0, ans = 0, res = 0;
    char nome[50], cod[5];
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
        scanf("%[^\n]", nome);
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
        getCodAddPar(cod, listPar, totalPar, nome, listLin);
        listLin = addPar_Lin(listLin, nome, listPar, NULL,  cod, totalPar, 0);
    } else if (ans == 2) {
        listLin = removeParagem_Lin(listLin, listPar, totalPar, nome);
    } else if (ans == 3) {
        listLin = alteraNome_Lin(listLin, nome, listPar, totalPar);
    }
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
    if (aux->nParAssoc == 1) {
        printf("\n+-----------------------------------------------------+");
        printf("\n| Aviso -> Se o eliminar de  uma paragem resultar em  |");
        wprintf(L"\n| uma linha ficar sem paragens, essa linha será também|");
        printf("\n| eliminada.                                          |");
        printf("\n+-----------------------------------------------------+");
        getchar();
        getchar();
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
        visualizaLin(listLin, nomeLin);
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
        scanf("%[^\n]", cod);
        if (verificaCod_Paragens(aux->parAssoc, cod, aux->nParAssoc) == 0 && strlen(cod) == 4) {// <- Condição necessária para escolher
            flag = 1;                                                                           //    escolher a mensagem de erro
        } else {
            flag = 0;
        }
        i++;
    } while (strlen(cod) != 4 || verificaCod_Paragens(aux->parAssoc, cod, aux->nParAssoc) == 0);
    aux = removePar_Lin(aux, cod);
    listPar = removeLin_Par(listPar, cod, parTotal, nomeLin);
    if (aux->nParAssoc == 0) {
        listLin = dellLin(listLin, nomeLin);
    }
    return listLin;
}

ptrLin alteraNome_Lin(ptrLin listLin, char *nomeLin, ptrPar listPar, int parTotal) {
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
        scanf("%[^\n]", newName);
        i++;
    } while (verificaNome_Lin(listLin, newName) == 1);
    aux = alterName_Lin(aux, newName, listPar, parTotal);
    return listLin;
}

void visualizaLin(ptrLin listLin, char* nome) {
    int i = 0;
    ptrLin aux = listLin;
    while (aux->prox != NULL) {
        if (strcmp(tolowerString(listLin->nome), tolowerString(nome)) == 0) {
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
    printf("\n\t\t     +--------------------------------+");
    printf("\n\t\t     |    Prima ENTER para voltar.    |");
    printf("\n\t\t     +--------------------------------+");
    getchar();
    getchar();
    system("cls");

}

void visualizaLinAll(ptrLin listLin) {
    int i = 0;
    if (listLin == NULL) {
        listaVazia();
        return;
    } else {
        ptrLin aux = listLin;
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
    printf("\n\t\t     +--------------------------------+");
    printf("\n\t\t     |    Prima ENTER para voltar.    |");
    printf("\n\t\t     +--------------------------------+");
    getchar();
    getchar();
    system("cls");
}

void visualizaLinAllDetailed(ptrLin listLin) {
    if (listLin == NULL) {
        listaVazia();
        return;
    } else {
        ptrLin aux = listLin;
        printf("\n+------------------------------------------------------------+");
        printf("\n|  Todas as linhas registadas no sistema e as suas paragens  |");
        printf("\n+------------------------------------------------------------+");
        while (aux != NULL) {
            printf("\n| %s ", aux->nome);
            printf("\n+---+--------+-----------------------------------------------+");
            wprintf(L"\n|   | Código | Nome da paragem                               |");
            printf("\n+---+--------+-----------------------------------------------+");
            for (int i = 0; i < aux->nParAssoc; ++i) {
                wprintf(L"\n| %d |  %s  | %s", i+1, aux->parAssoc[i].cod, aux->parAssoc[i].nome);
                printf("\n+---+--------+-----------------------------------------------+");
            }
            aux = aux->prox;
        }
    }
    printf("\n\t\t     +--------------------------------+");
    printf("\n\t\t     |    Prima ENTER para voltar.    |");
    printf("\n\t\t     +--------------------------------+");
    getchar();
    getchar();
    system("cls");
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +-------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Dados ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +-------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void saveDadosPar(ptrPar listPar, int totalPar) {
    ptrLin aux = NULL;
    FILE* f = fopen("DadosPar.dat", "wb");
    if (f == NULL) {
        if (erroFile() == 1) {
            return;
        } else {
            exit(1);
        }
    }

    fwrite(&totalPar, sizeof(int), 1, f);
    for (int i = 0; i < totalPar; ++i) {
        fwrite(&listPar[i], sizeof(par), 1, f);
        fwrite(&listPar[i].nLinAssoc, sizeof(int), 1, f);
        aux = listPar[i].linAssoc;
        while (aux != NULL) {
            fwrite(aux, sizeof(lin), 1, f);
            aux = aux->prox;
        }
    }
    printf("\nParagens guardadas com sucesso");

    fclose(f);
}

ptrPar loadDadosPar(ptrPar listPar, int* totalPar) {
    ptrLin novo, aux;
    lin l;
    FILE* f = fopen("DadosPar.dat", "rb");
    if (f == NULL) {
        if (erroFile() == 1) {
            fclose(f);
            return NULL;
        } else {
            fclose(f);
            exit(1);
        }
    }

    fread(totalPar, sizeof(int), 1, f);
    listPar = malloc(sizeof(par)*(*totalPar));
    if (listPar == NULL) {
        if (erroMemoria() == 1) {
            fclose(f);
            return NULL;
        } else {
            fclose(f);
            exit(1);
        }
    }
    for (int i = 0; i < *totalPar; ++i) {
        int j = 0;
        fread(&listPar[i], sizeof(par), 1, f);
        fread(&listPar[i].nLinAssoc, sizeof(int), 1, f);
        listPar[i].linAssoc = NULL;
        while (j < listPar[i].nLinAssoc) {
            fread(&l, sizeof(lin), 1, f);
            novo = malloc(sizeof(lin));
            if (novo == NULL) {
                if (erroMemoria() == 1) {
                    fclose(f);
                    return NULL;
                } else {
                    fclose(f);
                    exit(1);
                }
            }
            j++;
            *novo = l;
            novo->prox = NULL;
            listPar[i].linAssoc = insereLin(listPar[i].linAssoc, novo);
        }
    }
    fclose(f);

    printf("\nParagens carregadas com sucesso");

    return listPar;
}

void saveDadosLin(ptrLin listLin) {
    FILE* f = fopen("DadosLin.dat", "wb");
    if (f == NULL) {
        if (erroFile() == 1) {
            return;
        } else {
            exit(1);
        }
    }

    ptrLin aux = listLin;
    while (aux != NULL) {
        fwrite(aux, sizeof(lin), 1, f);
        fwrite(&aux->nParAssoc, sizeof(int), 1, f);
        for (int i = 0; i < aux->nParAssoc; ++i) {
            fwrite(&aux->parAssoc[i], sizeof(par), 1, f);
        }
        aux = aux->prox;
    }

    printf("\nLinhas guardadas com sucesso");

    fclose(f);
}

ptrLin loadDadosLin(ptrLin listLin) {
    ptrLin novo, aux;
    lin l;
    FILE* f = fopen("DadosLin.dat", "rb");
    if (f == NULL) {
        if (erroFile() == 1) {
            fclose(f);
            return NULL;
        } else {
            fclose(f);
            exit(1);
        }
    }

    while (fread(&l, sizeof(lin), 1, f) == 1) {
        novo = malloc(sizeof(lin));
        if (novo == NULL) {
            if (erroMemoria() == 1) {
                fclose(f);
                return NULL;
            } else {
                fclose(f);
                exit(1);
            }
        }
        fread(&l.nParAssoc, sizeof(int), 1, f);
        l.parAssoc = malloc(sizeof(par)*l.nParAssoc);
        if (l.parAssoc == NULL) {
            if (erroMemoria() == 1) {
                fclose(f);
                return NULL;
            } else {
                fclose(f);
                exit(1);
            }
        }
        for (int i = 0; i < l.nParAssoc; ++i) {
            fread(&l.parAssoc[i], sizeof(par), 1, f);
        }
        *novo = l;
        novo->prox = NULL;
        listLin = insereLin(listLin, novo);
    }

    fclose(f);

    printf("\nLinhas carregadas com sucesso");

    return listLin;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// +--------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// | Extras ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// +--------+|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void getCodUser(char* cod, ptrPar listPar, int parTotal) {
    int i = 0, flag = 0;
    do {
        if (i > 0) {
            if (flag == 1) {
                printf("\n\t\t+------------------------------------------------+");
                wprintf(L"\n\t\t| O código introduzido não corresponde a nenhuma |");
                wprintf(L"\n\t\t| paragem registada no sistema, tente novamente. |");
                printf("\n\t\t+------------------------------------------------+");
                printf("\n->");
            } else {
                printf("\n\t\t +----------------------------------------------------+");
                wprintf(L"\n\t\t |                   Codigo inválido                  |");
                wprintf(L"\n\t\t | O código alfanumérico é composto por 4 caracteres, |");
                wprintf(L"\n\t\t | letras e números apenas(Ex:L4J7), tente novamente. |");
                printf("\n\t\t +----------------------------------------------------+");
                printf("\n\t\t ->");
            }
        }
        fflush(stdin);
        scanf("%[^\n]", cod);
        if (verificaCod_Paragens(listPar, cod, parTotal) == 0 && strlen(cod) == 4) {// <- Condição necessária para escolher
            flag = 1;                                                               //    escolher a mensagem de erro
        } else {
            flag = 0;
        }
        i++;
    } while (strlen(cod) != 4 || flag == 1);
}

void getNameParUser(char* nome, ptrPar listPar, int parTotal) {
    int i = 0, flag = 0;
    do {
        if (i > 0) {
            if (flag == 1) {
                printf("\n\t\t+------------------------------------------------+");
                wprintf(L"\n\t\t|  O nome introduzido não corresponde a nenhuma  |");
                wprintf(L"\n\t\t| paragem registada no sistema, tente novamente. |");
                printf("\n\t\t+------------------------------------------------+");
                printf("\n->");
            }

            fflush(stdin);
            scanf("%[^\n]", nome);
            i++;
        }
    } while (verificaNome_Paragens(listPar, nome, parTotal) == 0);
}

void getCodAddPar(char* cod, ptrPar listPar, int parTotal, char* nomeLin, ptrLin listLin) {
    int res = 0, i = 0, ans = 0, flag = 0;
    ptrLin aux = listLin;
    while (aux->prox != NULL) {
        if (strcmp(tolowerString(aux->nome), tolowerString(nomeLin)) == 0) {
            break;
        }
        aux = aux->prox;
    }
    do {
        res = i = ans = 0;
        printf("\n                               +-------------------+");
        printf("\n                               | Adicionar Paragem |");
        printf("\n+------------------------------+-------------------+-------------------------------+");
        wprintf(L"\n| Para ser registada no sistema uma linha necessita de ter pelo menos uma paragem. |");
        printf("\n|                  1.Adicionar Paragem     2.Vizualizar Paragens                   |");
        printf("\n+----------------------------------------------------------------------------------+");
        printf("\n->");
        do {
            if (i > 0) {
                printf("\n\t\t+----------------------------------------------+");
                wprintf(L"\n\t\t|      Resposta inválida, tente novamente.     |");
                printf("\n\t\t| 1.Adicionar Paragem    2.Vizualizar Paragens |");
                printf("\n\t\t+----------------------------------------------+");
                printf("\n\t\t->");
            }
            fflush(stdin);
            res = scanf("%d", &ans);
            i++;
        } while (!res || ans < 1 || ans > 2);

        if (ans == 2) {
            visualizaParAll(listPar, parTotal);
        }
    } while (ans == 2);

    res = i = ans = flag = 0;
    printf("\n\t\t+-------------------------------------------------------+");
    wprintf(L"\n\t\t| Introduza o código da paragem que pretende adicionar. |");
    printf("\n\t\t+-------------------------------------------------------+");
    printf("\n\t\t->");
    do {
        if (i > 0) {
            if (flag == 1) {
                printf("\n\t\t+------------------------------------------------+");
                wprintf(L"\n\t\t| O código introduzido não corresponde a nenhuma |");
                wprintf(L"\n\t\t| paragem registada no sistema, tente novamente. |");
                printf("\n\t\t+------------------------------------------------+");
                printf("\n->");
            } else if (flag == 2) {
                printf("\n\t\t+------------------------------------------------------+");
                wprintf(L"\n\t\t| A paragem correspondente ao codigo introduzido já se |");
                wprintf(L"\n\t\t|  encontra adicionada a esta linha, tente novamente.  |");
                printf("\n\t\t+------------------------------------------------------+");
                printf("\n\t\t->");
            } else {
                printf("\n\t\t +----------------------------------------------------+");
                wprintf(L"\n\t\t |                   Codigo inválido                  |");
                wprintf(L"\n\t\t | O código alfanumérico é composto por 4 caracteres, |");
                wprintf(L"\n\t\t | letras e números apenas(Ex:L4J7), tente novamente. |");
                printf("\n\t\t +----------------------------------------------------+");
                printf("\n\t\t ->");
            }
        }
        fflush(stdin);
        scanf("%[^\n]", cod);
        if (verificaCod_Paragens(listPar, cod, parTotal) == 0 && strlen(cod) == 4) {// <- Condição necessária para escolher
            flag = 1;                                                               //    escolher a mensagem de erro
        } else if (verificaCod_Paragens(aux->parAssoc, cod, aux->nParAssoc) == 1) {
            flag = 2;
        } else {
            flag = 0;
        }
        i++;
    } while (strlen(cod) != 4 || verificaCod_Paragens(listPar, cod, parTotal) == 0 || verificaCod_Paragens(aux->parAssoc, cod, aux->nParAssoc) == 1);
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
