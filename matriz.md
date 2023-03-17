O objetivo desta atividade é implementar um TAD chamado Matriz usando obrigatoriamente Programação Orientada a Objetos. O TAD Matriz encapsula uma matriz com m linhas e n colunas, sobre a qual podemos fazer as seguintes operações:

1. criar matriz com m linhas e n colunas, alocada dinamicamente e com todos os elementos iguais a zero
2. liberar(deletar) a matriz que foi alocada dinamicamente
3. acessar valor na posição (i,j) da matriz
4. atribuir valor ao elemento na posição (i,j) da matriz
5. retornar o número de linhas da matriz
6. retornar o número de colunas da matriz
7. imprimir a matriz
8. multiplicar a matriz atual por uma matriz passada por parâmetro e retornar a matriz resultante
9. somar a matriz atual com uma matriz passada por parâmetro e retornar a matriz resultante

obs: lembre-se de que nem sempre é possível multiplicar ou somar duas matrizes
obs: código do programa cliente main.cpp já está feito. Você precisa apenas implementar as funções-membro da classe Matriz no arquivo Matriz.cpp, que está incompleto.

---
Entrada:
```
creatematrix 5 5
0 2 0 3 1 9 -8 23 0 1 -33 87 2 6 7 0 1 4 0 9 0 3 0 1 3
nlinhas 0
ncolunas 0
printmatrix 0
exit
```
Saída:
```
linhas: 5
colunas: 5
      0      2      0      3      1
      9     -8     23      0      1
    -33     87      2      6      7
      0      1      4      0      9
      0      3      0      1      3
matriz liberada
```

---

## main.cpp
```
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Matriz.h"
using namespace std;

int main()
{
	vector<Matriz*> matrizes; // Vector de ponteiros para matrizes
	
	while(true) {
		string line;
		string comando;
		
		getline(cin, line);
		stringstream ss { line };
		
		ss >> comando;

		if(comando == "exit") {
			for(int i = 0; i < matrizes.size(); ++i) {
				delete matrizes[i];
			}
			return 0;
		}
		// creatematrix [l] [c]
		else if(comando == "creatematrix") {
			int l, c;
			ss >> l;
			ss >> c;
            Matriz *m = new Matriz(l, c);
            for(int i = 0; i < l; ++i) {
                for(int j = 0; j < c; ++j) {
                    int val = 0;
                    cin >> val;
                    cin.ignore();
                    m->setValor(val, i, j);
                }
            }
			matrizes.push_back( m );
		}
		// printmatrix [k]
		else if(comando == "printmatrix") {
			int k;
			ss >> k;
			matrizes[k]->print();
		}
		// nlinhas [k]
		else if(comando == "nlinhas") {
			int k;
			ss >> k;
			cout << "linhas: " << (matrizes[k])->linhas() << endl;
		}
        // ncolunas [k]
		else if(comando == "ncolunas") {
			int k;
			ss >> k;
			cout << "colunas: " << matrizes[k]->colunas() << endl;
		}
        // getvalor [i] [j] [k]
		else if(comando == "getvalor") {
			int i, j, k;
			ss >> i >> j >> k;
			cout << "valor: " << matrizes[k]->getValor(i,j) << endl;
		}
		// sum [p] [q] 
		else if(comando == "sum") {
            int p, q;
			ss >> p >> q;
			Matriz *C = matrizes[p]->soma(*(matrizes[q]));
			if(C == nullptr) 
                cout << "nao foi possivel somar" << endl;
            else {
                C->print();
                delete C;
            }
		}
        // multiply [p] [q] 
		else if(comando == "multiply") {
            int p, q;
			ss >> p >> q;
			Matriz *C = matrizes[p]->multiplica(*(matrizes[q]));
			if(C == nullptr) 
                cout << "nao foi possivel multiplicar" << endl;
            else {
                C->print();
                delete C;
            }
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}

```
## Matriz.h
```
#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
private:
    int lin;     // numero de linhas da matriz
    int col;    // numero de colunas da matriz
    int **mat;   // ponteiro para matriz de inteiros (deve ser alocada dinamicamente)
    
public:
    // Construtor: aloca matriz com m linhas e n colunas
    Matriz(int m, int n);

    // Destrutor: libera memoria alocada
    ~Matriz(); 

    // Retorna o numero de linhas da matriz
    int linhas();

    // Retorna o numero de colunas da matriz
    int colunas();  

    // Retorna o valor contido na celula [i][j] da matriz
    int getValor(int i, int j); 

    // Atribui o valor v a celula [i][j] da matriz
    void setValor(int v, int i, int j); 

    // Imprimir a matriz 
    void print();

    // Recebe uma referencia para o objeto B do tipo Matriz que possui
    // m linhas e n colunas e soma a matriz B com a matriz atual.
    // Lembre que a soma de uma matriz A com uma matriz B so eh possivel  
    // se o numero de linhas e de colunas de A for igual ao numero de 
    // linhas e de colunas de B, respectivamente. 
    // Se for possivel fazer a soma, um ponteiro para uma nova matriz C
    // contendo o resultado da soma deve ser retornado (note que a matriz C 
    // deve ser alocada dinamicamente dentro da funcao-membro).
    // Caso contrario, retorna nullptr indicando que nao foi possivel 
    // fazer a soma das matrizes. 
    Matriz *soma(Matriz& B); 

    // Recebe uma referencia para o objeto B do tipo Matriz que possui
    // m linhas e n colunas e multiplica a matriz que chamar essa funcao-membro pela matriz B.
    // Lembre que a multiplicacao de uma matriz A por uma matriz B so eh possivel  
    // se o numero de colunas de A for igual ao numero de linhas de B. 
    // Se for possivel fazer a multiplicacao, um ponteiro para uma nova matriz C
    // contendo o resultado da multiplicacao deve ser retornado (note que a matriz C 
    // deve ser alocada dinamicamente dentro da funcao-membro).
    // Caso contrario, retorna nullptr indicando que nao foi possivel 
    // fazer a multiplicacao das matrizes. 
    Matriz *multiplica(Matriz& B); 

    // Com a linha abaixo, eu estou dizendo para o C++ nao criar
    // o construtor de copia default. Ou seja, nao quero que seja possivel
    // instanciar uma matriz passando outra matriz como argumento pelo construtor
    Matriz(const Matriz& m) = delete;  
};

#endif
```
## Matriz.cpp
```
// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"
using namespace std;

// Aloca espaco dinamicamente para matriz com m linhas e n colunas
Matriz::Matriz(int m, int n) {

}   

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz() {

}   

// Retorna o numero de linhas da matriz
int Matriz::linhas() {

} 

// Retorna o numero de colunas da matriz
int Matriz::colunas() { 

}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j) {

} 

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j) {

}

// Imprimir a matriz 
void Matriz::print() {
    for(int i = 0; i < lin; ++i) {
		for(int j = 0; j < col; ++j) {
			cout << setw(7) << mat[i][j];
		}
		cout << "\n";
	}
} 

// Soma matrizes
Matriz *Matriz::soma(Matriz& B) {

}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz& B) {

}
```
