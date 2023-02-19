Motivação: Deoclécio tem o passatempo de montar filas de dominós para derruba-las depois. Para fazer um efeito mais interessante, ele usa peças de dominó com tamanhos variados, sempre colocando as menores peças no começo da fila. Para ajudar nessa importante tarefa, Deo pediu sua ajuda para verificar se uma fila de dominós está dentro do padrão, ou seja, se os tamanhos dos dominós estão ordenados de forma crescente.

Leia um vetor de tamanho n (quantidade de dominós) , e diga se ele está ordenado de forma crescente.

Entrada:
O número n ( 0 < n <= 50 ) de dominós.
A altura (inteira) de cada dominó.

Saída:
"ok" caso o vetor esteja ordenado.
"precisa de ajuste" caso vetor esteja desordenado.
------
Exemplos
>>
5
1 2 3 4 4
<<
ok
---------
>>
6
2 4 2 6 8 10
<<
precisa de ajuste
---------
>>
1
2
<<
ok

```cpp
#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    int vec[n];
    int main = 1;
    int w = 0;
    int x = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            vec[i] = x;    
            if(vec[i-1] > vec[i]){
                w = 2;
            }
        }
    if(w == 0) cout << "ok" << endl;
    if(w == 2) cout << "precisa de ajuste" << endl;
    return 0;
}

```
