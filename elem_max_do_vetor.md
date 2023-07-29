Implemente uma função recursiva para encontrar o valor do elemento máximo de um vetor de tamanho n.

Entrada:

4

7 9 1 4

Saída:

9

DADO: 
´´´
#include <stdio.h>

int maior(int vet[], int n){
    
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    printf("%d", maior(vetor, n));
}
´´´
```
#include <stdio.h>

int maior(int vet[], int n){
    if(n==1){
        return vet[0];
    }
    else{
        int alfa = maior(vet, n-1);
        if(alfa > vet[n-1]){
            return alfa;
        }
        else{
            return vet[n-1];
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    printf("%d", maior(vetor, n));
    return 0;
}
```
