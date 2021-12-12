/******************************************************************************/
/**                                                    ,---------------.     **/
/**    METODOS DE PROGRAMACAO I                        |        .-.    |     **/
/**    LIC MATEMATICA - FCTUC                          |        !o|    |     **/
/**                                                    |>-,   ,-' | ,-<|     **/
/**    AUTORES: - NUNO RODRIGUES.....                  |  `---'   `-'  |     **/
/**             - ALICE CONCEICAO....                  `---------------'     **/
/******************************************************************************/
/* DESCRICAO: Desenvolvimento de um projeto informático cuja principal       **/
/*            função é apoiar a atividade de uma empresa comercial na        **/
/*            venda de 5 tipos de flores                                     **/
/******************************************************************************/
//
//	Bibliotecas a incluir   ////////////////////////////////////////////////////
//
#include <stdio.h>
#include <stdlib.h>
//
//  Variaveis Continuas     ////////////////////////////////////////////////////
//
#define MAX_ATRIBUTOS 5
#define DIM_NOME 50
//
//  Estrutura               ////////////////////////////////////////////////////
//
typedef struct
{
    int ID;
    char nome[DIM_NOME];
    int quantidade;
    float preco_indivi;

} tipo_flor;
//
//  Variaveis Globais       ////////////////////////////////////////////////////
//
tipo_flor flores[MAX_ATRIBUTOS];
//
//  Funcoes a definir       ////////////////////////////////////////////////////
//
void PressKey()
{
    char c;
    scanf("%c",&c);
    fflush(stdin);
}

void MsgWrongOption()
{
    printf("***************************************\n");
    printf("* Opcao incorreta                     *\n");
    printf("* Pressione enter para voltar ao menu *\n");
    printf("***************************************\n");
    PressKey();
}

void MsgMaxArticle()
{
    printf("***************************************\n");
    printf("* Atingiu o maximo de tipo de flores  *\n");
    printf("* Pressione enter para voltar ao menu *\n");
    printf("***************************************\n");
    PressKey();
}

void MsgExistArticle()
{
    printf("***************************************\n");
    printf("* Flor ja existente                   *\n");
    printf("* Pressione enter para voltar ao menu *\n");
    printf("***************************************\n");
    PressKey();
}

void MsgNotExistArticle()
{
    printf("***************************************\n");
    printf("* Flor inexistente                    *\n");
    printf("* Pressione enter para voltar ao menu *\n");
    printf("***************************************\n");
    PressKey();
}

void MsgQtdNegative()
{
    printf("***************************************\n");
    printf("* Nao e permitido stock negativo      *\n");
    printf("* Pressione enter para voltar ao menu *\n");
    printf("***************************************\n");
    PressKey();
}

int Existe_Artigo(int id_artigo)
{
    int existe = 0, indice = 0;
    while(flores[indice].ID != 0 && indice < MAX_ATRIBUTOS && existe == 0)
    {
        if(id_artigo == flores[indice].ID)
            existe = 1;
        else
            indice ++;
    }
    return existe;
}

int Indice_Artigo(int id_artigo)
{
    int existe = 0, indice = 0;
    while(flores[indice].ID != 0 && indice < MAX_ATRIBUTOS && existe == 0)
    {
        if(id_artigo == flores[indice].ID)
            existe = 1;
        else
            indice ++;
    }
    return indice;
}

void Inserir_Novo_Artigo()
{
    int i = 0;
    int id_artigo;
    system("cls");
    printf("******* INSERIR ARTIGOS ********************************\n");
    printf("ID: ");
    scanf("%d",&id_artigo);
    fflush(stdin);
    if(Existe_Artigo(id_artigo) == 1)
        MsgExistArticle();
    else
    {
        while(flores[i].ID != 0)
            i ++;
        if(i < MAX_ATRIBUTOS)
        {
            flores[i].ID = id_artigo;
            printf("Nome: ");
            scanf("%s",*(&flores[i].nome)); fflush(stdin);
            printf("Quantidade de flores: ");
            scanf("%d",&flores[i].quantidade); fflush(stdin);
            printf("Preco Individual: ");
            scanf("%f",&flores[i].preco_indivi); fflush(stdin);
            printf("\n");
            printf("Pressione ENTER para voltar ao menu\n");
            PressKey();
        }
        else
            MsgMaxArticle();
    }
}

void Lista_de_Artigos()
{
    int i;
    system("cls");
    printf("***** LISTA DE ARTIGOS ***************************\n");
    for(i = 0; flores[i].ID != 0 && i < MAX_ATRIBUTOS; i ++)
    {
        printf("                    ID: %d \n",flores[i].ID);
        printf("                  Nome: %s\n",flores[i].nome);
        printf("  Quantidade de flores: %d\n",flores[i].quantidade);
        printf("        Preco Unitario: %.2f\n",flores[i].preco_indivi);
        printf("**************************************************\n");
    }
    printf("Pressione ENTER para voltar ao menu\n");
    PressKey();
}

void Lista_de_Artigos_Simples()
{
    int i;
    system("cls");
    printf("***** LISTA DE ARTIGOS *******************************\n");
    for(i = 0; flores[i].ID != 0 && i < MAX_ATRIBUTOS; i ++)
        printf("%d --> %s\n",flores[i].ID,flores[i].nome);
    printf("******************************************************\n");
}

void Modificar_Stock()
{
    int id_artigo, nova_qt,stock;
    int indice;
    Lista_de_Artigos_Simples();
    printf("\t\tID da flor: ");
    scanf("%d",&id_artigo);
    fflush(stdin);
    if(Existe_Artigo(id_artigo) == 0)
        MsgNotExistArticle();
    else
    {
        indice = Indice_Artigo(id_artigo);
        printf("                Nome: %s\n",flores[indice].nome);
        printf("         Stock atual: %d\n",flores[indice].quantidade);
        printf("Stock a acrescentar ou a abater: ");
        scanf("%d",&stock); fflush(stdin);
        nova_qt = flores[indice].quantidade + stock;
        if(nova_qt > 0)
        {
            flores[indice].quantidade = nova_qt;
            printf("                Nova quantidade: %d\n",flores[indice].quantidade);
            printf("Pressione ENTER para voltar ao menu\n");
            PressKey();
        }
        else
            MsgQtdNegative();
    }
}

void Apagar_Artigo()
{
    int id_artigo;
    int indice;
    Lista_de_Artigos_Simples();
    printf("ID de flor a apagar: "),
    scanf("%d",&id_artigo);
    fflush(stdin);
    if(Existe_Artigo(id_artigo) == 0)
        MsgNotExistArticle();
    else
    {
        indice = Indice_Artigo(id_artigo);
        if(flores[indice + 1].ID != 0)
        {
            do
            {
                flores[indice] = flores[indice + 1];
                indice ++;
            }while(flores[indice].ID != 0 && indice < MAX_ATRIBUTOS);
        }
        else
            flores[indice].ID = 0;
    }
}

void QuickSortID(int n, int m)
{
    int pivot, i, j, meio;
    tipo_flor aux;
    i = n;
    j = m;
    meio = (i + j) / 2;
    pivot = v[meio].ID;
    do
    {
        while(v[i].ID < pivot) i++;
        while(v[j].ID > pivot) j--;
        if(i <= j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);
    if(n < j)
        QuickSortID(n,j);
    if(m > i)
        QuickSortID(i,m);
}

void BubbleSortQTD(tipo_flor v[], int n)
{/*
    int i, troca;
    tipo_flor aux;
    do
    {
        n--;
        troca = 0;
        for(i = 0; i < n; i++)
            if(v[i].quantidade > v[i+1].quantidade)
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troca = 1;
            }
    }while(troca);*/
}

void Lista_Stock_Total()
{
    int i = 0;
    float valorTotal = 0, valorstock;
    int QTDstock = 0;
    system("cls");
    printf("******* LISTA DE STOCK VALORIZADO ****************************************\n");
    do
    {
        valorstock = flores[i].quantidade * flores[i].preco_indivi;
        printf("Flor[%d--%s]\tStock[%d]\tPreco[%.2f EUR]\tTotal:[%.2f EUR]        **\n",flores[i].ID,flores[i].nome,flores[i].quantidade,flores[i].preco_indivi,valorstock);
        valorTotal = valorTotal + valorstock;
        QTDstock = QTDstock + flores[i].quantidade;
        i ++;
    }while(flores[i].ID != 0 && i < MAX_ATRIBUTOS);
    printf("**************************************************************************\n");
    printf("**    Valor Total do Stock: %.2f EUR                                    **\n",valorTotal);
    printf("**    Total de artigos em Stock: %d                                      **\n",QTDstock);
    printf("**************************************************************************\n");
    printf("Pressione ENTER para voltar ao menu\n");
    PressKey();
}

void Guardar_Ficheiro()
{
    int i;
    FILE *fp;
    fp = fopen("DADOS.txt","w");
    for(i = 0; flores[i].ID != 0 && i < MAX_ATRIBUTOS; i ++)
    {
        fprintf(fp,"%d \n",flores[i].ID);
        fprintf(fp,"%s \n",flores[i].nome);
        fprintf(fp,"%d \n",flores[i].quantidade);
        fprintf(fp,"%.2f \n",flores[i].preco_indivi);
    }
    fclose(fp);
}

void Ler_Ficheiro()
{
    int i;
    FILE *fp;
    fp = fopen("DADOS.txt","r");
    if(fp == NULL)
    {
        printf("\nFicheiro nao encontrado\n");
        printf("Pressione ENTER para ir para o menu\n");
        PressKey();
    }
    else
    {
        printf("***************************************\n");
        for(i = 0; i < MAX_ATRIBUTOS; i ++)
        {
            fscanf(fp,"%d\n",&flores[i].ID);
            fscanf(fp,"%s\n",*(&flores[i].nome));
            fscanf(fp,"%d\n",&flores[i].quantidade);
            fscanf(fp,"%f\n",&flores[i].preco_indivi);
            printf("  A importar %d %s...\n",flores[i].ID,flores[i].nome);
        }
        printf("***************************************\n");
        printf("\nPressione Enter para ir para o menu\n");
        PressKey();
    }
    fclose(fp);
}

void Menu()
{
    int opcao;
    do
    {
        system("cls");
        printf("***************************** FLORES DE COIMBRA ****************************\n");
        printf("**                            GESTAO DE FLORES                            **\n");
        printf("*********************************** MENU ***********************************\n");
        printf("** 1. Listagem de artigos                                                 **\n");
        printf("** 2. Inserir novo artigo                                                 **\n");
        printf("** 3. Modificar stock de flores                                           **\n");
        printf("** 4. Apagar artigo                                                       **\n");
        printf("** 5. Listagem dos artigos ordenados                                      **\n");
        printf("** 6. Valor total dos artigos em armazem                                  **\n");
        printf("** 0. Encerrar e Guardar programa                                         **\n");
        printf("****************************************************************************\n");
        printf("Opcao: ");
        scanf("%d",&opcao);
        fflush(stdin);
        switch(opcao)
        {
        case(1):
            Lista_de_Artigos();
            break;
        case(2):
            Inserir_Novo_Artigo();
            break;
        case(3):
            Modificar_Stock();
            break;
        case(4):
            Apagar_Artigo();
            break;
        case(5):
            Lista_de_Artigos();
            break;
        case(6):
            Lista_Stock_Total();
            break;
        case(0):
            Guardar_Ficheiro();
            printf("0. Programa ENCERRADO\n");
            break;
        default:
            MsgWrongOption();
        }
    }while(opcao != 0);
}
//
//	Programa Principal /////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int main()
{
    system("color 6");
    Ler_Ficheiro();
    Menu();

    fflush(stdin);
    printf("\n\nPressione ENTER para encerrar tudo\n");
    getchar();
    return EXIT_SUCCESS;
}
