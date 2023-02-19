Dizemos que uma matriz quadrada inteira é um quadrado mágico se a soma dos elementos de cada linha, a soma dos elementos de cada coluna e a soma dos elementos das diagonais principal e secundária são todas iguais. Diga se a uma matriz de elementos inteiros 3x3 dada como entrada é quadrado mágico ou não. 
 
Saída: "sim" se for quadrado mágico e "nao" caso contrário. 
 
***Exemplo de Entrada:
1 2 3 

4 5 6 

7 8 9 
 
***Exemplo de Saída: 

nao

```cpp
#include <iostream>
using namespace std;
int main(){
    int matriz[3][3];
    int n {0};
    
    
    
    for(int i { 0 }; i < 3; i++){
        for(int z { 0 }; z < 3; z++){
            cin >> n;
            matriz[i][z] = n;
        }
    }
    int q { matriz[0][0]+matriz[0][1]+matriz[0][2] };
    if(
        matriz[1][0] + matriz[1][1] + matriz[1][2] == q &&
        matriz[2][0] + matriz[2][1] + matriz[2][2] == q &&
        //coluna
        matriz[0][0] + matriz[1][0] + matriz[2][0] == q &&
        matriz[0][1] + matriz[1][1] + matriz[2][1] == q &&
        matriz[0][2] + matriz[1][2] + matriz[2][2] == q &&
        //diagonais
        matriz[0][0] + matriz[1][1] + matriz[2][2] == q &&
        matriz[0][2] + matriz[1][1] + matriz[2][0] == q
    ){
        cout << "sim";
    }
    else{
        cout << "nao";
    }
    
    return 0;
}

```
