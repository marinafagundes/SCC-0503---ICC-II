#include <stdio.h>
#include <stdlib.h>

int getMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void countingsort(int a[], int n, int exp)
{
    const int k = 10; // Número de dígitos (0-9)

    int output[n];
    int count[k];

    for (int i = 0; i < k; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }

    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

int* radixSort(int a[], int n)
{
    int max = getMax(a, n);

    int* sorted = (int*)malloc(n * sizeof(int));
    if (sorted == NULL) {
        printf("Erro na alocação de memória!\n");
        return NULL;
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingsort(a, n, exp);
    }

    for (int i = 0; i < n; i++) {
        sorted[i] = a[i];
    }

    return sorted;
}

int main(void)
{
    int n;
    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &n);
    printf("\n");

    if (n <= 0) {
        printf("Valor inválido para n. Deve ser positivo.\n");
        return 1;
    }

    int *a = (int*) malloc(sizeof(int) * n);
    if (a == NULL)
    {
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    int pos;
    for (pos = 0; pos < n; pos++)
    {
        printf("Digite um valor aleatório: ");
        scanf("%d", &a[pos]);
    }

    printf("\nVetor não ordenado:\n");
    for (pos = 0; pos < n; pos++)
    {
        printf("%d ", a[pos]);
    }

    int* sorted = radixSort(a, n);

    if (sorted == NULL) {
        free(a);
        return 1;
    }

    printf("\n\nVetor ordenado:\n");

    for (pos = 0; pos < n; pos++)
    {
        printf("%d ", sorted[pos]);
    }
    printf("\n\nVetor ordenado!\n");

    free(a);
    free(sorted);
    return 0;
}
