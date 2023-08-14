Intercalar subvetores ordenados
A[c..f] = subvetores ordenados A[c..m] e A[m+1..f]
*Compara os subvetores(o menor anda) e coloca num vetor aux
*Copiamos o restante
*Copiamos o aux para o original e destruimos o aux
```cpp
/* Funcao recebe vetores crescentes A[c..m] e A[m+1.. f] e rearranja A[p..r] em ordem crescente */
void Intercala(int A[], int c, int m, int f) {
  int *aux = new int[f - c + 1];  // Vetor auxiliar
  int c2 = c;
  int m2 = m + 1;
  int cont = 0;

  // Intercala A[c..m] e A[m+1.. f]
  while (c2 <= m && m2 <= f) {  // enquanto
    if (A[c2] <= A[m2])
      aux[cont++] = A[c2++];
    else
      aux[cont++] = A[m2++];
  }
  // copiar resto:
  while (c2 <= m) aux[cont++] = A[c2++];
  while (m2 <= f) aux[cont++] = A[m2++];

  // Copia vetor ordenado W para o vetor A
  for (c2 = c; c2 <= f; c2++) A[c2] = aux[c2 - c];

  delete[] aux;  // libera memoria alocada
}
```
# MergeSort
dividir em subvetores -> ordenar subvetores -> intercalar subvetores
=>caso base tam 0 ou 1
```cpp
void mergesort(int A[], int c, int f) {
  if (c < f) {  // caso base tam = 0, só um elem
    int m = (c + f) / 2;  // Dividir
    // Conquistar
    mergesort(A, c, m);
    mergesort(A, m + 1, f);
    // Combinar
    Intercala(A, c, m, f);
  }
}
```
# Merge-sort versão 2 (dividir o vetor em três partes (aproximadamente) de igual tamanho)
Cada parte é então ordenada recursivamente e depois é feito o Intercala simultaneamente nas três partes.


Faça a analise de complexidade dessa versão. Ela é mais rápida que a versão original?

Entrada:
10
15 2 5 7 9 22 1 58 46 89


Saída:
1 2 5 7 9 15 22 46 58 89
```
#include <stdio.h>
#include <string.h>


void merge_sort3(int vet[], int ini, int fim){
    
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    merge_sort3(vetor, 0, n-1);
    
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
}
```




