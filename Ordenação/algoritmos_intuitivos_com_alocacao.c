#include <stdio.h>
#include <stdlib.h>

void bolha_sem_sentinela_versao_1(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
                if (a[j] > a[j + 1])
                {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
        }
    }
}

void bolha_sem_sentinela_final(int a[], int n)
{
    for (int i = n -1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
                if (a[j] > a[j + 1])
                {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
        }
    }
}

void bolha_com_sentinela_for(int a[], int n)
{
    int c;
    for (int i = n -1; i >= 1; i--)
    {
        c = -1;
        for (int j = 0; j < i; j++)
        {
                if (a[j] > a[j + 1])
                {
                    c = j;
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
        }
    }
}

void bolha_com_sentinela_while(int a[], int n)
{
    int c;
    int i = n - 1;
    while (i >= 1)
    {
        c = -1;
        for (int j = 0; j < i; j++)
        {
                if (a[j] > a[j + 1])
                {
                    c = j;
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
        }
        i = c;
    }
}

void selection (int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[m])
            {
                m = j;
            }
        }
        int tmp = a[i];
        a[i] = a[m];
        a[m] = tmp;
    }
}

void insertion (int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > x)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

int main()
{
    int n;
    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &n);
    printf("\n");
    int *a = (int*)malloc(sizeof(int)*n);
    int pos;

    for (pos = 0; pos < n; pos++)
    {
        printf("Digite um valor aleatorio: ");
        scanf("%d", &a[pos]);
    }

    printf("\n");

    for (pos = 0; pos < n; pos++)
    {
        printf("%d ", a[pos]);
    }

    printf("\n");

    int metodo;

    printf("\nMenu\n\n1 - Bolha sem sentinela versao 1\n2- Bolha sem sentinela versao final\n3 - Bolha com sentinela com for\n4 - Bolha com sentinela com while\n5 - Selecao\n6-Insercao\n\n");

    printf("Digite uma opcao: ");
    scanf("%d", &metodo);

    if (metodo == 1) //funcao para comparacao de strings
    {
        bolha_sem_sentinela_versao_1(a, n); //chamar a funcao bolha_sem_sentinela_versao_1, criada no inicio do arquivo
        printf("\n\n");

        for (pos = 0; pos < n; pos++)
        {
            printf("%d ", a[pos]);
        }
        printf("\n\nVetor ordenado!\n");
    }


    else if (metodo == 2) //funcao para comparacao de strings
    {
        bolha_sem_sentinela_final(a, n); //chamar a funcao bolha_sem_sentinela_final, criada no inicio do arquivo
        printf("\n\n");

        for (pos = 0; pos < n; pos++)
        {
            printf("%d ", a[pos]);
        }
        printf("\n\nVetor ordenado!\n");
    }

    else if (metodo == 3) //funcao para comparacao de strings
    {
        bolha_com_sentinela_for(a, n); //chamar a funcao bolha_com_sentinela_for, criada no inicio do arquivo
        printf("\n\n");

        for (pos = 0; pos < n; pos++)
        {
            printf("%d ", a[pos]);
        }
        printf("\n\nVetor ordenado!\n");
    }
    else if (metodo == 4) //funcao para comparacao de strings
    {
        bolha_com_sentinela_while(a, n); //chamar a funcao bolha_com_sentinela_while, criada no inicio do arquivo
        printf("\n\n");

        for (pos = 0; pos < n; pos++)
        {
            printf("%d ", a[pos]);
        }
        printf("\n\nVetor ordenado!\n");
    }


    else if (metodo == 5) //funcao para comparacao de strings
    {
        selection(a, n); //chamar a funcao selection, criada no inicio do arquivo
        printf("\n\n");

        for (pos = 0; pos < n; pos++)
        {
            printf("%d ", a[pos]);
        }
        printf("\n\nVetor ordenado!\n");
    }

    else if (metodo == 6) //funcao para comparacao de strings
    {
        insertion(a, n); //chamar a funcao insertion, criada no inicio do arquivo
        printf("\n\n");

        for (pos = 0; pos < n; pos++)
        {
            printf("%d ", a[pos]);
        }
        printf("\n\nVetor ordenado!\n");
    }

    else
    {
        printf("\n\n");
        printf("Opcao invalida! O programa sera encerrado.");
    }
}
