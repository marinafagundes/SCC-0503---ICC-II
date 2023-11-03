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

void heapSort(int a[], int n)
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

int busca (int a[], int n, int x, int *p){
    *p = 0;
    for (int i = 0; i < n; i++){
        (*p)++;
        if (a[i] == x){
            return 1;
        }
    }
    return 0;
}

int buscaOrdenada1 (int a[], int n, int x, int *p){
    int i;
    *p = 0;
    for (i = 0; i < n && a[i] < x; i++){
        (*p)++;
    }
    if (i < n && a[i] == x){
        (*p)++;
        return 1;
    }
    return 0;
}

int buscaOrdenada (int a[], int n, int x, int *p){
    int i = 0;
    *p = 0;
    while (i < n && a[i] < x){
        (*p)++;
        i++;
    }
    if (i < n && a[i] == x){
        (*p)++;
        return 1;
    }
    return 0;
}

int buscaBinaria (int a[], int n, int x, int *p){
    int c = 0;
    int f = n - 1;
    *p = 0;
    while (c <= f){
        (*p)++;
        int m = (c + f)/2;
        printf("c = %d f = %d m = %d\n", c, f, m);
        if(a[m] == x){
            return 1;
        } else if (a[m] > x) {
            f = m - 1;
        } else {
            c = m + 1;
        }
    }
    return 0;
}

int buscaInterpolacao (int a[], int n, int x, int *p){
    int c = 0;
    int f = n - 1;
    int m;
    *p = 0;
    while ((a[f] != a[c]) && (x >= a[c]) && (x <= a[f])){
        (*p)++;
        m = c + ((double)(x - a[c]) * (f - c) / (a[f] - a[c]));
        printf("c = %d f = %d m = %d\n", c, f, m);
        if(a[m] < x){
            c = m + 1;
        } else if (a[m] > x) {
            f = m - 1;
        } else {
            return 1;
        }
    }
    if (x == a[c]){
        return 1;
    } else {
        return 0;
    }
}


int main(void) {
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
    
    int *p = (int*) malloc(sizeof(int));
    if (p == NULL) {
        printf("Erro na alocacao da memoria para p!\n");
        return 1;
    }
    
    int tipo_busca;
    printf("\n(1) Busca\n(2) Busca ordenada com for\n(3) Busca Ordenada\n(4) Busca Binaria\n(5) Busca por Interpolacao\n\n");
    printf("Digite o tipo de busca: ");
    scanf("%d", &tipo_busca);
    printf("\n");
    
    int x;
    printf("Digite o elemento que deseja buscar: ");
    scanf("%d", &x);
    printf("\n");
    
    switch (tipo_busca) {
        case 1:
            busca(a, n, x, p);
            break;
        
        case 2:
            heapSort(a, n);
            buscaOrdenada1(a, n, x, p);
            break;
            
        case 3:
            heapSort(a, n);
            buscaOrdenada(a, n, x, p);
            break;
            
        case 4:
            heapSort(a, n);
            buscaBinaria(a, n, x, p);
            break;
            
        case 5:
            heapSort(a, n);
            buscaInterpolacao(a, n, x, p);
            break;
            
        default:
            printf("\nOperacao invalida!\n");
            break;
    }

    printf("\nEncontrou o elemento com %d operacoes!\n", *p);

    free(a);
    free(p);
    return 0;
}
