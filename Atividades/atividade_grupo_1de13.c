#include <stdio.h>
#include <stdlib.h>

void bolha_com_sentinela_while(int a[], int n)
{
    int c;
    int i = n - 1;
    while (i >= 1)
    {
        c = -1;
        for (int j = 0; j < i; j++)
        {
            printf("C %d %d\n", j, j+1); //imprimir as comparacoes, na ordem certa
            if (a[j] > a[j + 1])
            {
                c = j;
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                printf("T %d %d\n", j, j+1); //imprimir as trocas, na ordem certa, apenas depois de terem sido realizadas
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
            printf("C %d %d\n", m, j); //imprimir as comparacoes, na ordem certa
            if (a[j] < a[m])
            {
                m = j;
            }
        }
        int tmp = a[i];
        a[i] = a[m];
        a[m] = tmp;
        if (i != m)//Vale notar que trocas com i = m sao realizadas, mas, pelo enunciado, nao precisamos imprimi-las
        {
            printf("T %d %d\n", i, m);//imprimir as trocas, na ordem certa, apenas depois de terem sido realizadas
        }
    }
}


int main()
{
    char metodo[10];
    int n;
    int pos;

    scanf("%s", &metodo); //leitura do tipo de metodo (string)

    scanf("%d", &n); //leitura do tamanho do vetor

    int a[n]; //criacao do vetor com n elementos

    for (pos = 0; pos < n; pos++) //leitura dos elementos do vetor
    {
        scanf("%d", &a[pos]);
    }
    if (strcmp(metodo, "selecao") == 0) //funcao para comparacao de strings
    {
        selection(a, n); //chamar a funcao selection, criada no inicio do arquivo

        for (pos = 0; pos < n; pos++) //impressao do vetor ordenado
        {
            printf("%d ", a[pos]);
        }
    }
    if (strcmp(metodo, "bolha") == 0) //funcao para comparacao de strings
    {
        bolha_com_sentinela_while(a, n); //chamar a funcao bolha, criada no inicio do arquivo

        for (pos = 0; pos < n; pos++) //impressao do vetor ordenado
        {
            printf("%d ", a[pos]);
        }
    }
}
