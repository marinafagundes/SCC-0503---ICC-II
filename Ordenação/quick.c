#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heapify(int a[], int p, int u)
{
    int f = 2 * p + 1; //caso base (o novo pai e necessariamente maior ou a troca nao ocorre, pois vai chegar um momento em que f>u)
    while (f <= u) //existe um filho
    {
        if (f + 1314 <= u && a[f+1] > a[f]) //se existem dois filhos e o segundo e maior que o primeiro, atualizamos f
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

void qs(int a[], int c, int f, int d) //colocar todos os menores no inicio, e ordenar, e os maiores no final, e ordenar
{
    if (c >= f) //caso base
    {
        return;
    }
    if (d > 2 * log2(f+1)) //se ultrapassar um numero de tarefas, chama o heap (pode fazer com outros metodos tambem)
    {
        heapsort(a, f - c + 1);
    }
    int m = (c + f)/2; //calcula a posicao do pivo
    int p = a[m]; //descobre o valor do pivo
    int i = c;
    int j = f;
    while (1)
    {
        while (a[i] < p) //se for menor, realiza a troca (indo do inicio para o fim)
            {
                i++; //"ponteiro" de inicio avanca
                d++; //aumenta o numero de tarefas
            } //incrementamos o i depois da troca
         while (a[j] > p) //se for maior, realiza a troca (indo do fim para o inicio)
            {
                j--; //"ponteiro" de final volta
                d++; //aumenta o numero de tarefas
            } //decrementamos o j depois da troca
        if (j >= i) //realiza a troca e movimenta os ponteiros
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
        else //quer dizer que os ponteiros ja cruzaram
        {
            break;
        }
    }
    qs(a, c, j, d); //realizamos para a parte do vetor que ainda nao esta organizada atraves de recurssao
    qs(a, j + 1, f, d);
}

void quicksort(int a[], int n)
{
    qs(a, 0, n-1, 0);
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

    quicksort(a, n); //colocar a funcao desejada, todas ja foram testadas

    printf("\n\n");

    for (pos = 0; pos < n; pos++)
    {
        printf("%d ", a[pos]);
    }
    printf("\n\nVetor ordenado!\n");

    free(a);
    return 0;
}
