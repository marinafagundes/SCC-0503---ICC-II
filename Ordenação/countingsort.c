#include <stdio.h>
#include <stdlib.h>

void countingsort(int a[], int n, int k) {
    int c[k];
    for (int i = 0; i < k; i++) {
        c[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }

    for (int i = 1; i < k; i++) {
        c[i] += c[i - 1];
    }

    int b[n];

    for (int i = n - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

int main(void) {
    int n;
    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &n);
    printf("\n");

    int k;
    printf("Digite o número de elementos distintos: ");
    scanf("%d", &k);
    printf("\n");
    
    if (n <= 0) {
        printf("Valor inválido para n. Deve ser positivo.\n");
        return 1;
    }

    int *a = (int *)malloc(sizeof(int) * n);
    if (a == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    int pos;
    for (pos = 0; pos < n; pos++) {
        printf("Digite um valor aleatório: ");
        scanf("%d", &a[pos]);
    }

    printf("\nVetor não ordenado:\n");
    for (pos = 0; pos < n; pos++) {
        printf("%d ", a[pos]);
    }

    countingsort(a, n, k);  // O terceiro argumento deve ser um valor maior ou igual ao maior elemento do vetor

    printf("\n\nVetor ordenado:\n");

    for (pos = 0; pos < n; pos++) {
        printf("%d ", a[pos]);
    }
    printf("\n\nVetor ordenado!\n");

    free(a);
    return 0;
}
