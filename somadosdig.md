Implemente uma função recursiva que calcule a soma dos dígitos decimais de um inteiro positivo.

164 então a soma será 1 + 6 + 4 = 11

6457 então a soma é 6 + 4 + 5 + 7 = 22

Dica 1: O dígito da unidade de um inteiro é o resto da divisão desse número por 10. Por exemplo. 164 % 10 = 4, 6457 % 10 = 7.

Dica 2: Ao dividir um número inteiro por 10, você "elimina" o dígito da unidade. Exemplo, 164/10 = 16, 6457/10 = 645.

----------
Entrada:

164

Saída:

11

---------

Entrada:

6457

Saída:

22

------------

```
#include <stdio.h>
#include <string.h>

int soma_digito(int numero){
    if(numero < 10){
        return numero;
    }
        return numero % 10 + soma_digito(numero/10);   
}


int main(){
    int numero;
    scanf("%d", &numero);
    printf("%d", soma_digito(numero));
}
```
