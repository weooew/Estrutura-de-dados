Com a proximidade da Copa do Mundo, o fluxo de pessoas nas filas para compra de ingressos aumentou consideravelmente. Como as filas estão cada vez maiores, pessoas menos pacientes tendem a desistir da compra de ingressos e acabam deixando as filas, liberando assim vaga para outras pessoas. Quando uma pessoa deixa a fila, todas as pessoas que estavam atrás dela dão um passo a frente, sendo assim nunca existe um espaço vago entre duas pessoas. A fila inicialmente contém N pessoas, cada uma com um identificador diferente.

Joãozinho sabe o estado inicial dela e os identificadores em ordem das pessoas que deixaram a fila. Sabendo que após o estado inicial nenhuma pessoa entrou mais na fila, Joãozinho deseja saber o estado final da fila.

Entrada

    A primeira linha contém um inteiro N representando a quantidade de pessoas inicialmente na fila.
    A segunda linha contém N inteiros representando os identificadores das pessoas na fila. O primeiro identificador corresponde ao identificador da primeira pessoa na fila. É garantido que duas pessoas diferentes não possuem o mesmo identificador.
    A terceira linha contém um inteiro M representando a quantidade de pessoas que deixaram a fila.
    A quarta linha contém M inteiros representando os identificadores das pessoas que deixaram a fila, na ordem em que elas saíram. É garantido que um mesmo identificador não aparece duas vezes nessa lista.

Saída

Seu programa deve imprimir uma linha contedo N-M inteiros com os identificadores das pessoas que permaneceram na fila, em ordem de chegada.

--------------------------------------
>>>>>>>> 01
4
10 9 6 3
1
3
========
10 9 6 
<<<<<<<<

-------------------------------------
>>>>>>>> 02
8
5 100 9 81 70 33 2 1000
3
9 33 5
========
100 81 70 2 1000 
<<<<<<<<



```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    //criando
    int nfila; 
    int nsaiu;
    int input;
    vector <int> vf;
    vector <int> vs;
    vector <int> tt;
    
    //entrada
    cin >> nfila;
    
    for(int i = 0; i < nfila; i++){
        cin >> input;
        vf.push_back(input);//Adds a new element at the end of the vector. Increases the container size by one.
    }
    
    cin >> nsaiu;
    for(int i = 0; i < nsaiu; i++){
        cin >> input;
        vs.push_back(input);//Adds a new element at the end of the vector. Increases the container size by one.
    }

    //operações, copiando...
    for(int i = 0; i < vf.size(); i++){
        for(int a = 0; a < vs.size(); a++){
            if(vf[i] == vs[a]){
                vf[i] = 0;
            }
        }
    }
        for(int b = 0; b <= (vf.size()-1); b++){
            if(vf[b] != 0){
                cout << vf[b] << " ";
            }
        }
cout << "\n";
}
```
