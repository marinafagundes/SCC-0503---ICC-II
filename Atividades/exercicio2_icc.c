#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i;

    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
    {
        printf("Digite um valor para seu vetor: ");
        scanf("%d", &a[i]);
    }

    int ordem = 0;
    int ordenacao;

    for (i = 0; i < n-1; i++)
    {
        if (a[i] > a[i + 1])
        {
            ordem--;
        }
        else
        {
            ordem++;
        }
    }
    if (ordem == (-1) * (n-1))
    {
        ordenacao = -1;
        printf("O vetor esta em ordem decrescente: %d", ordenacao);
    }
    else if (ordem == (n-1))
    {
        ordenacao = 1;
        printf("O vetor esta em ordem crescente: %d", ordenacao);
    }
    else
    {
        ordenacao = 0;
        printf("O vetor esta desordenado: %d", ordenacao);
    }
}
