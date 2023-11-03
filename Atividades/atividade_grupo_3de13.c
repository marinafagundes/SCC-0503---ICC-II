#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertion (int a[], int n, int *trocas_insertion, int *comparacoes_insertion)
{
    *trocas_insertion = 0;
    *comparacoes_insertion = 0;

    for (int i = 1; i < n; i++)
    {

        int x = a[i];
        (*trocas_insertion)++; //trocas aqui tambem!!!
        int j = i - 1;

        while (j >= 0) //separa o && em ifs dentro do while
        {
            (*comparacoes_insertion)++; //sempre vai comparar a medida que percorre o vetor
            if (a[j] > x)
            {
                a[j + 1] = a[j];
                (*trocas_insertion)++; //troca
                j--;
            }
            else
            {
                break;
            }

        }

        a[j + 1] = x;
        (*trocas_insertion)++; //troca
    }

    printf("I %d %d %d\n", n, *trocas_insertion, *comparacoes_insertion);
}

void merge(int a[], int c, int f, int b[], int *trocas_merge, int *comparacoes_merge)
{
    int i1; //precisou declarar i1 aqui ao inves de dentro do else

    if (c >= f) //comeco = fim
    {
        return;
    }
    else
    {
        int m = (c + f)/2;

        merge(a, c, m, b, trocas_merge, comparacoes_merge); //recursao
        merge(a, m + 1, f, b, trocas_merge, comparacoes_merge); //recursao

        i1 = c;
        int i2 = m + 1;
        int j = c;

        while (i1 <= m)
        {
            if (i2 <= f)
            {
                if (a[i1] <= a[i2])
                {
                    b[j] = a[i1];
                    (*trocas_merge)++; //troca
                    i1++;
                }
                else
                {
                    b[j] = a[i2];
                    (*trocas_merge)++; //troca
                    i2++;
                }
                j++;
            }
            else
            {
                break;
            }
            (*comparacoes_merge)++; //sempre compara, exceto quando o i2 > f, ou seja, uma das condicoes e falsa, conforme o enunciado
        }

        while (i1 <= m)
        {
            b[j] = a[i1];
            (*trocas_merge)++; //troca
            i1++;
            j++;
        }

        while (i2 <= f)
        {
            b[j] = a[i2];
            (*trocas_merge)++; //troca
            i2++;
            j++;
        }
    }

    for (i1 = c; i1 <= f; i1++)
    {
        a[i1] = b[i1];
        (*trocas_merge)++; //troca aqui tambem, para colocar no vetor real
    }
}

void mergesort(int a[], int n, int *trocas_merge, int *comparacoes_merge)
{
    int *b = (int*) malloc(sizeof(int)*n);
    if (b == NULL)
    {
        printf("Erro na alocacao da memoria!\n");
        return;
    }
    merge(a, 0, n - 1, b, trocas_merge, comparacoes_merge);
    free(b);
    printf("M %d %d %d\n", n, *trocas_merge, *comparacoes_merge);
}

int main(){
    int nvetores;
    scanf("%d", &nvetores);

    int i;
    int **vetores = (int **)malloc(nvetores*sizeof(int *)); //primeiro cria um ponteiro de ponteiros para cada vetor que sera criado
    int **vetores_copia = (int **)malloc(nvetores*sizeof(int *));

    int *vet_tamanhos = (int *)malloc(nvetores*sizeof(int));//vetor que armazene os tamanhos

    for (i = 0; i < nvetores; i++) //agora coloca o tamanho de cada vetor criado
    {
        int tam_vetor;
        scanf("%d", &tam_vetor);
        vetores[i] = (int *)malloc(tam_vetor*sizeof(int));
        vetores_copia[i] = (int *)malloc(tam_vetor*sizeof(int));
        vet_tamanhos[i] = tam_vetor;

    }

    for (int i = 0; i < nvetores; i++) // por fim, le os elementos de cada vetor
    {
        for (int j = 0; j < vet_tamanhos[i]; j++)
        {
            scanf("%d", &vetores[i][j]);
            vetores_copia[i][j] = vetores[i][j];
        }
    }

    for (int i = 0; i < nvetores; i++) // por fim, le os elementos de cada vetor
    {
        int trocas_insertion = 0; //sempre zerar as trocas e comparacoes, para reinicializarem a cada vetor
        int trocas_merge = 0;
        int comparacoes_insertion = 0;
        int comparacoes_merge = 0;
        insertion(vetores[i], vet_tamanhos[i], &trocas_insertion, &comparacoes_insertion); //usei o vetor de tamanhos como o modo mais facil para recuperar o tamanho de cada vetor
        mergesort(vetores_copia[i], vet_tamanhos[i], &trocas_merge, &comparacoes_merge);
    }
}

