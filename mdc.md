O máximo divisor comum dos inteiros x e y é o maior inteiro que é divisível por x e y.

Implemente uma função recursiva mdc, que retorna o máximo divisor comum de x e y. O mdc de x e y é definido como segue:

se y é igual a 0, então mdc(x,y) é x; caso contrário, mdc(x,y) é mdc(y, x % y), onde % é o operador resto.

-------

Entrada:

15 20


Saída:

5

-------
Entrada:

24 16


Saída:

8

```
#include <stdio.h>


int mdc(int x, int y){
    
}


int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", mdc(x, y));
}

```
