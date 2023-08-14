
Defina uma classe para essa TAD contendo as n coordenadas, onde o valor de n será fornecido no construtor da classe. Defina também as operações de soma e produto escalar entre dois vetores. Também defina a operação de cálculo do módulo (comprimento de um vetor). Também defina um método que calcula o cosseno do ângulo entre dois vetores.

Respeite todas as "regras" vistas em sala de aula sobre visibilidade dos atributos das classes, ou seja, todos os atributos devem ser private. Defina os métodos gets e sets dos atributos.

Depois implemente a função principal num arquivo separado, de nome main.cpp, onde esse arquivo irá importar essa classe Vetor. Nesse arquivo, implemente a função principal que irá receber dois vetores do Rn e depois aplica-se as operações de produto escalar, módulos dos dois vetores e o vetor resultante da soma.

Depois calcule o valor do cosseno do ângulo entre os dois vetores e imprima.

Entrada
4
1.0 2.0 3.0 4.0
4.0 3.0 2.0 1.0

Saída:

Produto Escalar: 20.00
Modulos: 30.00 e 30.00
Soma: 5.00 5.00 5.00 5.00
Cosseno: 0.02

Códigos Exemplos

C++

### ponto.h
```
#ifndef PONTO_H
#define PONTO_H
class Ponto{
    private:
        int n;
        double *pont;
    public:
        Ponto(int n, double v[]);
        ~Ponto();
        
        void somavet(double v2[], double vet3[]);
        void produto_escalar(double vet3[]);
        void modulo(double v2[]);
};
#endif
```
### ponto.cpp
```
/*
Soma de 2 vetores (if tam ==) -> cria 3° vetor (1°a+1°b),(2°a,2°b)...

Soma
produto escalar (soma dos elem do 3° vetor)
modulo (soma dos quadrados dos elem de A).. B
*/

#include "ponto.h"
#include <iostream>
using namespace std;

int main(){
    int quant_elem;
    cin >> quant_elem;
    
    double aux1[quant_elem];
    double aux2[quant_elem];
    
    for(int i = 0; i < quant_elem; i++){
        cin >> aux1[i];
    }
    for(int i = 0; i < quant_elem; i++){
        cin >> aux2[i];
    }
    
    Ponto v1 = {quant_elem, aux1};
    Ponto v2 = {quant_elem, aux2};
    
    double vet3[quant_elem];
    v1.somavet(aux2, vet3);
    v1.produto_escalar(vet3);
    v1.modulo(aux2);
}
```
### main.cpp
```
#include "ponto.h"
#include <iostream>
using namespace std;

Ponto::Ponto(int n, double v[]){
    this->n = n;
    this->pont = new double[n];
    for(int i = 0; i < n; i++){
        this->pont[i] = v[i];
    }
}

Ponto::~Ponto(){
    delete[] this->pont;
}

void Ponto::somavet(double v2[], double vet3[]){
    cout << "Soma: ";
    cout.precision(2);
    for(int a = 0; a < this->n; a++){
        vet3[a] = this->pont[a] + v2[a];
        cout << vet3[a] << " ";
    }
    cout << endl;
}

void Ponto::produto_escalar(double vet3[]){
    double aux = 0;
    
    for(int b = 0; b < n; b++){
        aux = aux + vet3[b]; 
    }
    cout << "Produto escalar: " << aux << endl;
}

void Ponto::modulo(double v2[]){
    int aux = 0;
    int aux2 = 0;
    
    for(int a = 0; a < this->n; a++){
        aux = aux + (this->pont[a])*(this->pont[a]); 
    }
    
    for(int a = 0; a < this->n; a++){
        aux2 = aux2 + (v2[a])*(v2[a]); 
    }
    cout << "Modulo: " << aux << " e " << aux2;
}
```
