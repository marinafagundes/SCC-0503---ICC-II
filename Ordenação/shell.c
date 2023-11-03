#include <stdio.h>
#include <stdlib.h>

void shellsort_tradicional(int a[], int n)
{
    int g = n/2; //gap proposto pelo proprio Shell --> povou que a complexidade e O(n^2)
    while (g > 0) //algoritmo do Insertion em funcao do gap (divide em varios vetores e os deixa quase ordenados, que e o melhor caso do Insertion)
    {
        for (int i = g; i < n; i++)
        {
            int x = a[i];
            int j = i - g;
            while (j >= 0 && a[j] > x)
            {
                a[j + g] = a[j];
                j -= g;
            }
            a[j + g] = x;
        }
        g /= 2;
    }

}

void shellsort(int a[], int n)
{
    int g = 1; //gap proposto por Hibbard ((Potencias de 2) - 1) --> gera numeros primos entre si e a complexidade e de O(n^3/2)
    while (2 * g < n) //algoritmo do Insertion em funcao do gap (divide em varios vetores e os deixa quase ordenados, que e o melhor caso do Insertion)
    {
        for (int i = g; i < n; i++)
        {
            int x = a[i];
            int j = i - g;
            while (j >= 0 && a[j] > x)
            {
                a[j + g] = a[j];
                j -= g;
            }
            a[j + g] = x;
        }
        g = 2*g + 1;
    }
}


int main()
{
    int n;
    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &n);
    printf("\n");
    int *a = (int*) malloc(sizeof(int)*n);
    if (a == NULL)
    {
        printf("Erro na alocacao da memoria!\n");
        return 1;
    }
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

    shellsort(a, n); //colocar a funcao desejada, todas ja foram testadas

    printf("\n\n");

    for (pos = 0; pos < n; pos++)
    {
        printf("%d ", a[pos]);
    }
    printf("\n\nVetor ordenado!\n");

    free(a);
    return 0;
}
