#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vet[n], i;
    int dec = 0;
    int cres = 0;

    for(i = 0; i < n; i++){
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }

    for (i = 0; i < n-1; i++){
        if (vet[i]>vet[i+1]){
            dec = -1;
        }
        else if (vet[i]<vet[i+1]){
            cres = 1;
        }
    }

    if (cres){
        printf("1");
    }
    else if (dec){
        printf("-1");
    }
    else {
        printf("0");
    }
    
    return 0;
}