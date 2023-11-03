#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int c, int f, int b[])
{
    if (c >= f) //tarefa basica para sair da recursao, quando necessario
    {
        return;
    }
    else
    {
        int m = (c+f)/2;

        merge(a, c, m, b); //recursao
        merge(a, m + 1, f, b); //recursao

        int i1 = c;
        int i2 = m + 1;
        int j = c;

        while (i1 <= m && i2 <= f)
        {
            if (a[i1] < a[i2])
            {
                b[j] = a[i1];
                i1++;
            }
            else
            {
                b[j] = a[i2];
                i2++;
            }
            j++;
        }
        while (i1 <= m )
        {
            b[j] = a[i1];
            i1++;
            j++;
        }
        while (i2 <= f )
        {
            b[j] = a[i2];
            i2++;
            j++;
        }
        for (i1 = c; i1 <= f; i1++)
        {
            a[i1] = b[i1];
        }
    }
}

void mergeSort(int a[], int n)
{
    int *b = (int*)malloc(sizeof(int)*n);
    merge (a, 0, n-1, b);
    free (b);
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

    printf("\n\n");
    printf("Ordenaremos o vetor com o algoritmo Merge Sort!");

    mergeSort(a, n); //chamar a funcao insertion, criada no inicio do arquivo
    printf("\n\n");

    for (pos = 0; pos < n; pos++)
    {
        printf("%d ", a[pos]);
    }
    printf("\n\nVetor ordenado!\n");
}
