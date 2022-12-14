Dado um vetor com n inteiros A=[a0,a1,…,an−1], n≥0, imprima um triângulo de números tal que:


- na base do triângulo estejam todos os elementos do vetor original, ou seja: [a0,a1,…,an−1];

- o número de elementos em cada nível acima da base é um a menos que no nível inferior;

- e cada elemento no i-ésimo nível é a soma de dois elementos consecutivos do nível inferior.

Entrada:

1°: tamanho n do vetor

2°: deve ler os n elementos do vetor, separados por espaço simples.

Saída:

O triângulo de somas.

        [48]
        
        [20, 28] -->(20 + 28 = 48)
        
        [8, 12, 16] -->(8 + 12 = 20, 12 + 16 = 28)
        
        [3, 5, 7, 9] -->(3 + 5 = 8, 5 + 7 = 12, 7 + 9 = 16)
        
        [1, 2, 3, 4, 5] -->(1 + 2 = 3, 2 + 3 = 5, 3 + 4 = 7, 4 + 5 = 9)

-----------------------------------------
Entrada: 

5

1 2 3 4 5


Saída: 

[48]

[20, 28] 

[8, 12, 16] 

[3, 5, 7, 9] 

[1, 2, 3, 4, 5] 

------------------------------------------

Entrada: 

7

2 0 -7 8 45 0 33


Saída:

[765]

[237, 528]

[37, 200, 328]

[-11, 48, 152, 176]

[-5, -6, 54, 98, 78]

[2, -7, 1, 53, 45, 33]

[2, 0, -7, 8, 45, 0, 33]

------------------------------------------

```cpp
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matriz;//matriz

int triang(int linha, int coluna, int n){
    if(linha == n - 1){//caso base, retornar elementos da ultima linha
        return matriz[linha][coluna];
    }
    else{
        matriz[linha][coluna] = triang(linha + 1, coluna, n) + triang(linha + 1, coluna + 1, n);//soma
        return matriz[linha][coluna];
    }    
}

int main(){
    int n;
    cin >> n;
    int vetor[n];
    
    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }
    //matriz vai ter n linhas
    matriz.resize(n);
    for(int b = 0; b < n; b++){
        matriz[b].resize(n);
    }
    
    //colocar vetor na ultima linha de 2d
    for(int a = 0; a < n; a++ ){
        matriz[n-1][a] = vetor[a];
    }
    
    triang(0, 0, n);//chamar função do elemento do topo para a função fazer todo o triangulo
    
    //imprimir só elementos que formam o triangulo
    for (int c = 0; c < n; c++){
    cout << '[';
        for(int d = 0; d <= c; d++){
            if(d != 0){cout << ", ";}
            cout << matriz[c][d];
        }
    cout << ']' << '\n';
   }
    
    return 0;
}
```
