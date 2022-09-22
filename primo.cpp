/*
Faça uma função chamada primo que recebe um inteiro positivo n e retorna true (verdadeiro) se n é primo, ou false (falso) caso contrário.
Entrada:
* 1a linha: valor do inteiro positivo A
* 2a linha: valor do inteiro positivo B (com A≤B).

Saída:
* Todos os primos de A até B (um por linha).
---
Exemplos
>>
3
11
<<
3
5
7
11
---
>>
4
10
<<
5
7*/
#include <iostream>
using namespace std;

bool primo(int n){
    for(int i = 2; i < n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    int a, b = 0;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        if(primo(i) == true){
            if(a == b) i = a + 1;
            cout << i << endl;
        }
    }
    
}
