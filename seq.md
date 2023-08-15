Implemente a interface da lista sequencial vista em sala de aula.

Vector.h
```
#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    int* m_list {nullptr}; // ponteiro para a lista
    int  m_size {0};       // numero de elementos na lista
    int  m_capacity {0};   // capacidade total da lista

public:
    Vector();
    Vector(int n);
    Vector(Vector& vector);
    
    ~Vector(); 

    int capacity(); 
    int size(); // O(1)
    bool empty(); // O(1)
    int at(int k); // O(1)
    void resize(int n); // O(n)
    void push_back(int value); // tempo medio O(1)
    int pop_back(); // O(1)
    void replaceAt(int value, int k);
    void removeAt(int k);
    void insert(int value, int k);
    void removeAll(int value);
    void push_front(int value);  
    int pop_front();
    void remove_duplicates();
};

#endif
```

Vector.cpp
```
#include "Vector.h"
//m_list, m_size, m_capacity


    // Construtor default: capacidade = 16 e size = 0
    Vector::Vector(){
        m_capacity = 16;
        m_size = 0;
        m_list = new int[m_capacity];
    } // O(1)
    
    // Construtor: capacidade = n e size = 0
    Vector::Vector(int n){
        m_capacity = n;
        m_size = 0;
        m_list = new int[m_capacity];
    } // O(1)
    
    // Copy constructor
    Vector::Vector(const Vector& vector){
        this->m_capacity = vector.m_capacity;
        this->m_size = vector.m_size;
        this->m_list = new int[m_size];
        for(int i = 0; i < m_size; i++){
            this->m_list[i] = vector.m_list[i];//legal!!!
        }
    } // O(n)
    
    // Destrutor: libera memoria alocada
    Vector::~Vector(){
        delete m_list;
    } // O(1)

    // Retorna a capacidade atual da lista
    int Vector::capacity() const{
        return m_capacity;
    } // O(1)

    // Retorna o numero de elementos na lista
    int Vector::size() const{
        return m_size;
    } // O(1)
    
    // Retorna true se e somente se a lista estiver vazia
    bool Vector::empty() const{
        return m_size == 0;
    } // O(1)

    // Retorna o elemento na posicao k.
    // A funcao verifica se k esta dentro dos 
    // limites de elementos validos no vetor. Caso contrário, retorna -1.
    int Vector::at(int k) const{
        if(k >= 0 && k < m_size){
            return m_list[k];
        }
        return -1;
    } // O(1)

    //Redimensiona a capacidade para tamanho n. 
    // n for maior que a capacidade: aumente sua capacidade 
    // realocando os elementos para o novo vetor
    // n for menor que a capacidade: reduzido aos seus primeiros  
    // n elementos, removendo aqueles além.
    void Vector::resize(int n){
        if(n != m_capacity && n > 0){
            int* Data = new int[n];
            
            for(int i = 0; i < m_size && i < n; i++){
                Data[i] = m_list[i];
            }
            delete[] m_list;
            m_list = Data;
            m_capacity = n;
            if(n < m_size){m_size = n;}
        }
    }// O(n)
    
    // Recebe um inteiro como argumento e o adiciona
    // logo apos o ultimo elemento da lista. 
    // Se por acaso a lista estiver cheia, chame a função
    // resize duplicando sua capacidade atual. 
    void Vector::push_back(int value){
        if(m_size == m_capacity){
            resize(2*m_capacity);
        }
        m_list[m_size] = value;
        m_size++;
    }// tempo medio O(1)
    
    // Remove e retorna o ultimo elemento da lista se a lista nao
    // estiver vazia. Caso contrario, retorna -1 
    int Vector::pop_back(){
        if(empty()){
            return -1;
        }
        int value = at(m_size);
        removeAt(m_size);
        return value;
    } // O(1)
    
    //########################################################
    
    
    // Substitui o elemento no índice k pelo elemento 
    // value (somente se 0 <= k <= m_size -1)
    void Vector::replaceAt(int value, int k){
        if(0 <= k && k < m_size){
            m_list[k] = value;
        }
    }

    // Remove o elemento com índice k na lista. 
    // Deve-se ter 0 <= k <= m_size -1; 
    // caso contrário, a remoção não é realizada.
    // Será necessário fazer um deslocamento de uma posição 
    // para a esquerda dos elementos de k+1 até m_size-1
    void Vector::removeAt(int k){
        if(0 <= k && k < m_size){
            for(int i = k; i < m_size - 1; i++){
                m_list[i] = m_list[i+1];
            }
            m_size--;
        }
    }

    // Adiciona o elemento value no índice k 
    // (somente se 0 <= k <= m_size). 
    // Antes de fazer a inserção, todos os elementos do 
    // índice k em diante são deslocados uma posição para a direita.
    // Se não houve espaço, será necessário chamar a função resize duplicando a capacidade.
    void Vector::insert(int value, int k){
        if(k >= 0 && k < m_size){
            if(m_size == m_capacity) {
                resize(m_capacity * 2); // Double the capacity if the vector is full
            }
            
            for(int i = m_size - 1; i >= k; i--) {
                m_list[i + 1] = m_list[i];
            }
            m_list[k] = value;
            m_size++;
        }
    }
    
    // Remove todas as ocorrências do elemento value na lista.
    void Vector::removeAll(int value){
        int contador = 0;
        for(int i = 0; i < m_size; i++){
            if(m_list[i] != value) {
                m_list[contador] = m_list[i];
                contador++;
            }
        }
        m_size = contador;
    }
    
    
    //Semelhante a função push_back só que adiciona
    // o elemento na primeira posição
    void Vector::push_front(int value){
        insert(value, 0);
    }
    
    
    //Semelhante a função pop_back só que remove e retorna o primeiro elemento
    // se a lista nao estiver vazia. Caso contrario, retorna -1 
    int Vector::pop_front(){
        if(m_size > 0) {
            int value = m_list[0];
            removeAt(0);
            return value;
        }
        return -1;
    }
    
    //Remove elementos repetidos da lista
    //A ordem relativa dos elementos que ficam se manter.
    void Vector::remove_duplicates(){
        for(int i = 0; i < m_size; i++){
            int valor = m_list[i];
            for(int j = i + 1; j < m_size; j++) {
                if (m_list[j] == valor) {
                    removeAt(j);
                    j--; 
                }
            }
        }
    }
```

main.cpp
```
#include <iostream>
#include "Vector.h"
void print(Vector& list) {
    if(list.size()!=0 && !list.empty()){
        printf("%d\n", list.size());
    	for(int i = 0; i < list.size(); i++) printf("%d ", list.at(i));
    	printf("\n");        
    }else printf("Lista Vazia\n");
}
void remove(Vector& list) {
    if(list.size()!=0 && !list.empty()){
    	while(list.size()!=0 && !list.empty()) printf("%d ", list.pop_back());
    	printf("\n"); 
    }
}
int main() {
    int n, k;
    scanf("%d", &n);
	Vector listaPares, listaImpares;
	for(int i = 0; i < n; ++i) {
	    scanf("%d", &k); 
	    if(k % 2 == 0) listaPares.push_back(k);
		else listaImpares.push_back(k);
	}
	print(listaPares);
	print(listaImpares);
	remove(listaPares);
	remove(listaImpares);
	return 0;
}
```
