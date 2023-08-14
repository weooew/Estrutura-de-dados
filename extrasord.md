# ORDENAÇÃO VETOR 1, 2, 3

Implemente um algoritmo de complexidade O(n) para ordenar um vetor formado apenas pelos valores {1, 2, 3}.

Entrada:
10
3 3 2 3 1 1 1 2 3 1


Saída:
1 1 1 1 2 2 3 3 3 3

```
#include <stdio.h>
#include <string.h>

/**
* vet vetor contendo apenas os números 1, 2 ou 3 de tamanho n.
**/
void sort123(int vet[], int n){
    
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    select_sort(vetor, n);
    
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
}
```



# ORDENAR VETOR COM DOIS ELEMENTOS TROCADOS 
Dado um vetor de n inteiros em que todos os seus elementos em ordem crescente, exceto por dois elementos, que estão com suas posições trocadas, implemente um algoritmo que ordene esse vetor com tempo O(n).

Suponha que o vetor não tenha números repetidos.

Entrada:
6
3 8 6 7 5 9

Saída:
3 5 6 7 8 9

Entrada:
10
10 45 25 29 33 35 37 40 21 49

Saída:
10 21 25 29 33 35 37 40 45 49

Entrada:
10
4 6 7 9 11 21 15 17 19 13

Saída:
4 6 7 9 11 13 15 17 19 21

```
#include <stdio.h>
#include <string.h>

void sort_trocados(int vet[], int n){
    
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    sort_trocados(vetor, n);
    
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
}
```


# ORDENAÇÃO TRANSPOSIÇÃO PAR-IMPAR 
A ordenação por transposição de par-impar ocorre da seguinte maneira:

Percorra o vetor várias vezes. Na primeira passagem compare x[i] com x[i+1] para todo i ímpar. Na segunda passagem compare x[i] com x[i+1] para todo i par. Toda vez que x[i] > x[i+1] troque os dois. Continue alternando dessa maneira até que o vetor esteja ordenado.

Implemente esse algoritmo de ordenação e faça a analise complexidade desse algoritmo.
```
#include <stdio.h>
#include <string.h>


void transposicao_sort(int vet[], int n){
    
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    transposicao_sort(vetor, n);
    
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
}
```

# ORDENAÇÃO USANDO FUNÇÃO MIN-POSICAO
A função min_posicao abaixo busca o menor elemento de um sub-vetor e o colocar no menor índice:

void min_posicao(int vet[], int ini, int fim){}

Implemente um algoritmo que usa essa função para ordenar um vetor.
```
#include <stdio.h>
#include <string.h>

void min_posicao(int vet[], int ini, int fim){
    int min = ini;
    for(int i = ini + 1; ini <= fim; ini++) if(vet[min] > vet[i]) min = i;
    
    int aux = vet[min];
    vet[min] = vet[ini];
    vet[ini] = aux;
}

void aluno_sort(int vet[], int ini, int fim){
    
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    aluno_sort(transposicao_sort, 0, n-1);
    
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
}
```


