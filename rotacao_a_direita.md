Uma rotação desloca os elementos do vetor em uma determinada direção. Uma rotação à direita equivale a pegar o último elemento e inserí-lo na primeira posição.

Implemente a operação de rotação. Observe que calculando as posições finais corretamente você fará uma única operação de transposição das posições do vetor.

    Entrada
        Linha 1: tamanho do vetor T e número de elementos rotacionados R
        Linha 2: elementos do vetor
    Saída
        Vetor rotacionado
 
---------------------------------------------
>>>>>>>>
5 0
1 2 3 4 5
========
[ 1 2 3 4 5 ]
<<<<<<<<

----------------------------------------------
>>>>>>>>
5 1
1 2 3 4 5
========
[ 5 1 2 3 4 ]
<<<<<<<<

-------------------------------------------------
>>>>>>>>
5 4
1 2 3 4 5
========
[ 2 3 4 5 1 ]
<<<<<<<<

-----------------------------------------------
>>>>>>>>
5 9
1 2 3 4 5
========
[ 2 3 4 5 1 ]
<<<<<<<<

----------------------------------------------

```cpp
#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    int b = 0;
    //ultimo vai para o 1° e realocar outros
    for(int i = 0; i < nrot; i++){//rodar quantas vezes
        b = vet[vet.size()-1];//guardar ultimo elemento em b
        for(int a = (vet.size()-1); a > 0; a--){
                vet[a] = vet[a-1];//movendo para direita
        }
        vet[0] = b;//
    }
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;//quantidade de numeros para rodar
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);//imprime vetor?
}
```
