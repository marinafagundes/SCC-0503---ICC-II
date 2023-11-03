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
    int a[n], pos;

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

    insertion(a, n); //colocar a funcao desejada, todas ja foram testadas

    printf("\n\n");

    for (pos = 0; pos < n; pos++)
    {
        printf("%d ", a[pos]);
    }
    printf("\n\nVetor ordenado!\n");
}
