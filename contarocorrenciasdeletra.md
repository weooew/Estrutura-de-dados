Implemente um função recursiva que recebe uma frase e uma letra e retorna o números de vezes que essa letra aparece na frase. 

------
Entrada:

A Andreia alimentou a avestruz com alcaparras

a

Saída:

8

-----------

Entrada:

A Andreia alimentou a avestruz com alcaparras

A

Saída:

2

----------------

Entrada:

A Andreia atirou alcachofras no leao

e

Saída:

2

----------------

Entrada:

A Andreia atirou alcachofras no leao

x

Saída:

0

---------------
```
#include <stdio.h>
#include <string.h>

/**
n é o tamanho do texto contido em frase.
**/
int contar_letra(char frase[], int n, char letra){
    
}


int main(){
    char frase[100];
    scanf("%[^\n]", frase);
    char letra;
    scanf(" %c", &letra);
    
    printf("%d", contar_letra(frase, strlen(frase), letra));
}
```
