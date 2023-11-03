#include <stdio.h>
#include <stdlib.h>

void heapify(int a[], int p, int u)
{
    int f = 2 * p + 1; //caso base (o novo pai e necessariamente maior ou a troca nao ocorre, pois vai chegar um momento em que f>u)
    while (f <= u) //existe um filho
    {
        if (f + 1 <= u && a[f+1] > a[f]) //se existem dois filhos e o segundo e maior que o primeiro, atualizamos f
            {
                f++;
            } //possuimos o maior dos dois filhos
        if (a[f] > a[p]) //se o filho for maior que o pai, tem que realizar a troca
        {
            int tmp = a[f];
            a[f] = a[p];
            a[p] = tmp;
            heapify(a, f, u);
        }
        else
        {
            break;
        }
    }
}


void heapify_com_ifs(int a[], int p, int u)
{
    int f = 2 * p + 1; //caso base (o novo pai e necessariamente maior ou a troca nao ocorre, pois vai chegar um momento em que f>u)
    if (f <= u) //existe um filho
    {
        if (f + 1 <= u) //existem dois filhos e os filhos sao comparados
        {
            if (a[f+1] > a[f]) //se o segundo filho e maior que o primeiro, f se torna o filho maior
            {
                f++;
            } //possuimos o maior dos dois filhos
        } //existe pelo menos um filho e f e o maior deles
        if (a[f] > a[p]) //se o filho for maior que o pai, tem que realizar a troca
        {
            int tmp = a[f];
            a[f] = a[p];
            a[p] = tmp;
            heapify_com_ifs(a, f, u);
        }
    }
}


void heapsort(int a[], int n)
{
    for (int i = (n - 1)/2; i >= 0; i--)
    {
        heapify(a, i, n-1);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        heapify(a, 0, i - 1);
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

    heapsort(a, n); //colocar a funcao desejada, todas ja foram testadas

    printf("\n\n");

    for (pos = 0; pos < n; pos++)
    {
        printf("%d ", a[pos]);
    }
    printf("\n\nVetor ordenado!\n");

    free(a);
    return 0;
}
