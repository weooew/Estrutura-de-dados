Implemente uma função recursiva que recebe um vetor de inteiros de tamanho n e inverte o vetor.

Imprima o vetor após a inversão.

Entrada:

6

4 9 25 41 7 3

Saída:

3 7 41 25 9 4

------------

Entrada:

4

8 94 5 78

Saída:

78 5 94 8

--------------

```
#include <stdio.h>

/**
ini e fim são os índices do subvetor que a função irá inverter, 
ou seja, o subvertor de índices no intervalo [ini, fim].
**/
void inverter(int vet[], int ini, int fim){//implemente
    if(ini < fim){
        int c = vet[ini]; 
        vet[ini] = vet[fim];
        vet[fim] = c;
        
        inverter(vet, ini+1, fim-1);
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    
    inverter(vetor, 0, n- 1);
    
    for(int i = 0; i < n; i++) printf("%d ", vetor[i]);
}
```

