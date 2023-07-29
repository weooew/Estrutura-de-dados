Um palíndromo é uma sequência de caracteres cuja leitura é idêntica se feita da direita para esquerda ou vice-versa. 

Por exemplo: OSSO e OVO são palíndromos. 

Implemente uma função recursiva que recebe uma cadeia de caracteres (string para c++) e retorna verdadeiro, se for palíndromo e falso, caso contrário.

```
#include <stdio.h>
#include <string.h>

/**
A função ehPalindromo retorna true se o parâmetro palavra for um palíndromo; false, caso contrário.
A palavra é uma string que começa no índice ini e termina no índice fim.
**/
int ehPalindromo(char palavra[], int ini, int fim){
    if(ini <= fim){
        if(palavra[ini] == palavra[fim]){ 
            ehPalindromo(palavra, ini+1, fim-1);
        }
        else{
            return 0;
        }
    }
    else return 1;  
}


int main(){
    char palavra[100];
    scanf("%s", palavra);
    
    if(ehPalindromo(palavra, 0, strlen(palavra) - 1)) printf("SIM");
    else printf("NAO");
}
```
