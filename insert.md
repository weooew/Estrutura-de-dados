# Insert sort

<img align= "right" width = "250" height = "250" src = "https://user-images.githubusercontent.com/102996679/235319347-70e3dac1-267a-4e16-9999-25c2c26e89d8.png" >
Comece do início e vá comparando os elem de 2 em 2: 

* quando da ok mova para a próxima comparação 
* quando não da ok vá movendo o elem até sua posição 'correta' até o momento

```
#include <stdio.h>
#include <string.h>


void insertion_sort(int vet[], int ini, int fim){ //versão recursiva    
}

void insertionsort ( int A [] , int l , int r ) {
    for ( int j = l +1; j <= r ; j ++) {
        int key = A [ j ];
        int i = j -1;
        while ( i >= l && A [ i ] > key ) {
            A [ i +1] = A [ i ];
            i - -;
        }
        A [ i +1] = key ;
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    insertion_sort(vetor, 0, n-1);
    
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
}
```
