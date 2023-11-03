#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i;

    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &n);

    int a[n];
    int pos_min = 0;

    for (i = 0; i < n; i++)
    {
        printf("Digite um valor aleatorio: ");
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (a[i] < a[pos_min])
        {
            pos_min = i;
        }
    }
    printf("Este e o indice do menor valor: %d", pos_min);
}
