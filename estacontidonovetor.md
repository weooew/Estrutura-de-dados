Implemente uma função recursiva que recebe um vetor ordenado com n números inteiros e um outro número inteiro x, determine se x está contido no vetor.

Use o fato que o vetor está ordenado para fazer com que sua função seja mais eficiente em relação a tempo computacional.

Entrada:

5

5 9 12 18 19

12

Saída:

SIM

--------

Entrada:

4

15 25 35 45

12

Saída:

NAO

--------

Entrada:

6

15 25 35 45 55 75

90

Saída:

NAO

--------
```
#include <stdio.h>
#include <string.h>


int estar_contido(int vet[], int n, int x){
    
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    if(estar_contido(vetor, n, x)) printf("SIM");
    else printf("NAO");
}
```
