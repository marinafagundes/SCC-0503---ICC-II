#include <stdio.h>
#include <stdlib.h>

void shell(int v[], int n, int *operacoes_shell) { //operacoes = trocas + comparacoes
    int gap = 1;
    while(gap <= n) {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    while(gap > 0) {
        for (int i = gap; i < n; i++){
            int x = v[i];
            (*operacoes_shell)++; //trocas
            int j = i - gap;
            while(j >= 0) {
                (*operacoes_shell)++; //comparacoes
                if (v[j] > x) {
                    v[j + gap] = v[j];
                    (*operacoes_shell)++; //trocas
                    j -= gap;
                }
                else
                {
                    break;
                }
            }
            v[j + gap] = x;
            (*operacoes_shell)++; //trocas
        }
        gap /= 2;
    }
} //codigo fornecido pelo enunciado

void quick(int v[], int f, int l, int *operacoes_quick) {
    if (f >= l) {
        return;
    }
    int m = (l + f)/2;
    int pivot = v[m];
    (*operacoes_quick)++; //trocas
    int i = f;
    int j = l;
    while(1) {
        while(v[i] < pivot) {
            (*operacoes_quick)++; //comparacoes - considerar o verdadeiro do while
            i++;
        }

        (*operacoes_quick)++; //comparacoes - considerando o falso do while

        while(v[j] > pivot) {
            (*operacoes_quick)++; //comparacoes - considerar o verdadeiro do while
            j--;
        }

        (*operacoes_quick)++; //comparacoes - considerando o falso do while

        if (i >= j) {
            break;
        }
        int aux = v[i];
        (*operacoes_quick)++; //trocas
        v[i] = v[j];
        (*operacoes_quick)++; //trocas
        v[j] = aux;
        (*operacoes_quick)++; //trocas
        i++;
        j--;
    }
    quick(v, f, j, operacoes_quick);
    quick(v, j+1, l, operacoes_quick);
} //codigo fornecido pelo enunciado

void quicksort(int a[], int n, int *operacoes_quick)
{
    quick(a, 0, n-1, operacoes_quick);
}

int main()
{
    int n;
    scanf("%d", &n); //escanear tamanho do vetor

    int *a_shell = (int*) malloc(sizeof(int)*n); //cria o vetor para fazer o shell (completo)
    int *a_quick = (int*) malloc(sizeof(int)*n); //cria o vetor para fazer o quick (completo)

    if (a_shell == NULL || a_quick == NULL) //erro de alocacao de memoria
    {
        printf("Erro na alocacao da memoria!\n");
        return 1;
    }

    int pos; //posicao no vetor

    for (pos = 0; pos < n; pos++) //primeiro le o vetor completo
    {
        scanf("%d", &a_shell[pos]);
        a_quick[pos] = a_shell[pos];
    }

    for (pos = 0; pos < n; pos++)
    {
        int *sub_a_shell = (int*) malloc(sizeof(int)* (pos + 1)); //cria subvetores para ordenar com shell que crescem de 1 em 1
        int *sub_a_quick = (int*) malloc(sizeof(int)* (pos + 1)); //cria subvetores para ordenar com quick que crescem de 1 em 1

        if (sub_a_shell == NULL || sub_a_quick == NULL) //erro de alocacao de memoria
        {
            printf("Erro na alocacao da memoria!\n");
            return 1;
        }

        for (int j = 0; j <= pos; j++)
        {
            sub_a_shell[j] = a_shell[j];
            sub_a_quick[j] = a_quick[j];
        }

        int operacoes_shell = 0; //tem que zerar o numero de operacoes a cada loop
        int operacoes_quick = 0; //tem que zerar o numero de operacoes a cada loop

        shell(sub_a_shell, pos + 1, &operacoes_shell); //chama o metodo de ordenacao adequado
        quicksort(sub_a_quick, pos + 1, &operacoes_quick);

        if (operacoes_quick == operacoes_shell) //comparacoes para definir a saida
        {
            printf("-");
        }
        else if (operacoes_quick < operacoes_shell)
        {
            printf("Q");
        }
        else
        {
            printf("S");
        }

        free(sub_a_shell); //libera os sub vetores
        free(sub_a_quick);
    }

    free(a_shell); //libera os vetores
    free(a_quick);

    return 0;
}
