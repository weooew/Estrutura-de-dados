Faça uma função que retorna o fatorial de um número inteiro positivo n passado como parâmetro, ou seja, retorna 1 * 2 * 3 * ... * (n-1) * n.
Chame esta função de `fatorial`.
O valor retornado, e a variável que armazena o fatorial, devem ser do tipo double, pois esta função cresce muito rápido. Uma variável do tipo int só é capaz de armazenar até 12!.

Em seguida, crie uma função chamada `euler` que recebe um inteiro N e retorna o valor da série

E=1 + 1/1! + 1/2! + 1/3! + ⋯ + 1/N!

A função euler deve chamar a função fatorial.

A função main lê o inteiro N e imprime o valor de euler(N).
----------
Entrada:

* 1a linha: valor do inteiro positivo N

Saída:

* Aproximação do número de Euler somando até 1/N!

Dica: Para esta questão, pesquise sobre as funções std::fixed e std::setprecision() da biblioteca <iomanip>
--------------
>>
10
<<
2.718282
---------
>>
5
<<
2.716667
-----------
>>
3
<<
2.666667

```cpp

#include <iostream>
#include <iomanip>
using namespace std;

double fatorial(int n){
    double fat{ 1 };
    
    //n = 3| i = 1 2 3 |em cada um, x = 1 | x = 2 1 | x= 3 2 1
        for(int x{ n }; x > 0; x--){
            fat = fat * x;
        } 
    return fat;
}

double euler(int n){
    double soma{1};
    
    
    for(int i{ 1 }; i <= n ;i++){
        double fat = (1.000000/fatorial(i));
        soma = soma + fat;
        
    }
    return soma;
}

int main(){
    int n { 0 };

    cin >> n;
    cout << fixed << setprecision(6) << euler(n);
    return 0;
}
```
