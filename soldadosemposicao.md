Os soldados se colocaram em formação no quartel. 
Na formação eles formaram uma matriz 3x3. 
 
Cada soldado tem uma numeração na sua farda, logo 
o Comandante querendo tripudiar de você, mandou 
você contar quantas vezes um soldado com numeração de fardamento menor está 
atrás de um maior. 
 
Você que não é besta, fez um código pra isso. 
 
Obs: Você tem que conferir as numerações verticalmente. 
 
***Exemplo de Entrada:

    2 4 6 
    3 8 9 
    1 0 5 
 
***Exemplo de Saída: 3

A saída foi 3 pois o 3 está na frende do 1, o 8 na frente do 0, e o 9 na frente do 5.

```cpp
#include <iostream>
using namespace std;
int main(){
    int soma { 0 }, n { 0 };
    int matriz[3][3];
    
    for(int i { 0 }; i < 3; i++){
        for(int z { 0 }; z < 3; z++){
            cin >> n;
            matriz[i][z] = n;
        }
    }
    
    for(int x { 0 }; x < 3; x++){
        for(int i { 0 }; i < 2; i++){
            if(matriz[i][x] > matriz[i + 1][x])
                soma++;
        }
    }
    cout << soma;
    
    
    return 0;
}
```
