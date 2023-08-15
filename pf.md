## Implemente as interfaces da Pilha e Fila usando a implementação encadeada.
### main.cpp
```
#include <cstdio>
#include "queue.h"
#include "stack.h"

template<typename T>
void printQueue(Queue<T>& fila) {
    printf("%d\n", fila.size());
    while(!fila.empty()){
        printf("%d ", fila.pop());
    }
}
template<typename T>
void printStack(Stack<T>& pilha) {
    printf("%d\n", pilha.size());
    while(!pilha.empty()){
        printf("%d ", pilha.pop());
    }
}
int main() {
    int n, k;
	Queue<int> fila;
	Stack<int> pilha;
	
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
	    scanf("%d", &k); 
	    if(i % 2 == 0) fila.push(k);
		else pilha.push(k);
	}
	printQueue(fila);
	printStack(pilha);
	return 0;
}
```

### node.h
```
#ifndef NODE_H
#define NODE_H

template<typename T>
class Node{
private:
    T value;  // valor 
    Node<T>* next;  // ponteiro para o proximo no 
public:
    /**
     * Construtor que recebe o valor que o nó irá armazenar e o ponteiro para o 
     * próximo nó da lista.
     * */
    Node(T val, Node<T> *nextPtr);
    
    /**
    Métodos gets e sets dos atributos
    **/
    T getValue();
    Node<T>* getNext();
    void setValue(T newValue);
    void setNext(Node<T>* newNext);
};
#include "node.cpp"
#endif
```

### node.cpp
```
#ifndef NODE_CPP
#define NODE_CPP
#include "node.h"

template<typename T>
Node<T>::Node(T val, Node<T> *nextPtr){
    value = val;
    next = nextPtr;
}
template<typename T>
T Node<T>::getValue(){
    return this->value;
}
template<typename T>
void Node<T>::setValue(T newValue){
    this->value = newValue;
}
template<typename T>
Node<T>* Node<T>::getNext(){
    return this->next;
}
template<typename T>
void Node<T>::setNext(Node<T>* newNext){
    this->next = newNext;
}
//templaate -> gera classes genericas p/ 
#endif
```

### queue.h
```
#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

template<typename T>
class Queue{
private:
    Node<T>* m_first; // Aponta para o inicio da fila se houver, caso contrário será null
    Node<T>* m_last; // Aponta para o final da fila se houver, caso contrário será null
    int m_size;   // numero de elementos na lista
    
public:
    // construtor: cria uma fila vazia
    Queue();

    // construtor de copia. A pilha lst deve se manter com os mesmo valores.
    Queue(Queue<T>& lst);
    
    // destrutor: libera memoria alocada
    ~Queue();

    // retorna o numero de elementos na fila
    int size();
    
    // Retorna true se e somente se a fila estiver vazia
    bool empty();

    // Remove todos os elementos da fila, ou seja, deixa a fila vazia
    void clear();

    //Insere no final da fila
    void push(T value); 

    // Remove e retorna o primeiro elemento da fila.
    // Se a fila estiver vazia lança a exceção throw std :: runtime_error("Empty queue.")
    T pop(); 

};
#include "queue.cpp"
#endif
```
### queue.cpp
```
#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "node.h"
#include "queue.h"
#include <stdexcept>

    //Node<T>* m_first; // Aponta para o inicio da fila se houver, caso contrário será null
    //Node<T>* m_last; // Aponta para o final da fila se houver, caso contrário será null
    //m_size;  
    template<typename T>
    Queue<T>::Queue(){//criar lista vazia
        m_first = nullptr;
        m_last = nullptr;
        m_size = 0;
    }
    
    template<typename T>
    Queue<T>::Queue(Queue<T>& lst){//// construtor de copia.
        m_first = nullptr;
        m_last = nullptr;
        m_size = 0;
        
        Node<T>* current = lst.m_first;//construi current, dif da onde lst.m_first está
        m_first = current;
        while(current != nullptr){
            push(current->getValue());//push ajeita m_size e m_last
            current = current->getNext();
        }
    }
    
    template<typename T>
    Queue<T>::~Queue(){//destrutor: libera memoria alocada
        clear();
    }

    // retorna o numero de elementos na fila
    template<typename T>
    int Queue<T>::size(){
        return m_size;
    }
    
    // Retorna true se e somente se a fila estiver vazia
    template<typename T>
    bool Queue<T>::empty(){
        return (m_size == 0);
    }

    // Remove todos os elementos da fila, ou seja, deixa a fila vazia
    template<typename T>
    void Queue<T>::clear(){
        while(m_first != nullptr){
            Node<T>* temp = m_first;
            m_first = m_first->getNext();
            delete temp;
        }
        m_first = nullptr;//precisa
        m_last = nullptr; //mesmo disso?
        m_size = 0;//posso só fazer m_first == nullptr e m_last == nullptr
    }

    //Insere no final da fila
    template<typename T>
    void Queue<T>::push(T value){
        Node<T>* newNode = new Node<T>(value, nullptr);
        if(m_first == nullptr){
            m_first = newNode;
            m_last = newNode;
        } 
        else{
            m_last->setNext(newNode);
            m_last = newNode;
        }
        m_size++;
    } 

    // Remove e retorna o primeiro elemento da fila.
    // Se a fila estiver vazia lança a exceção throw std :: runtime_error("Empty queue.")
    template<typename T>
    T Queue<T>::pop(){
        if(empty()){
            throw std::runtime_error("Empty queue.");
        }
        
        T value = m_first->getValue();
        Node<T>* current = m_first;
        m_first = current->getNext();
        delete[] current;
        m_size--;
        
        return value;
    }

#endif
```


### stack.h
```
#ifndef STACK_H
#define STACK_H
#include "node.h"

template<typename T>
class Stack{
private:
    Node<T>* m_top; // Ponteiro para o topo da pilha se houver, caso contrário será null
    int m_size;   // numero de elementos na lista
    
public:
    // construtor: cria pilha vazia
    Stack();

    // construtor de copia. A fila lst deve se manter com os mesmo valores.
    Stack(Stack<T>& lst);
    
    // destrutor: libera memoria alocada
    ~Stack();

    // retorna o numero de elementos na lista
    int size();
    
    // Retorna true se e somente se a pilha estiver vazia
    bool empty();

    // Remove todos os elementos da pilha, ou seja, deixa a pilha vazia
    void clear();

    // Insere no topo da pilha
    void push(T value); 
    
    // Remove elemento do topo da pilha
    // Se a pilha estiver vazia lança a exceção throw std :: runtime_error("Empty queue.")
    T pop(); 
    
    // Consulta o elemento no topo da pilha sem remove-lo.
    T top(); 
};
#include "stack.cpp"
#endif
```
## Implemente um programa que recebe uma frase e inverta cada palavra sem alterar a ordem das palavras na frase. 

Entrada:

lua de cristal que me faz sonhar

Saída:

aul ed latsirc euq em zaf rahnos

OBS: Considere que as palavras estão separadas por UM espaço e não temos virgulas e nenhuma outra pontuação.
### main.cpp
```
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main() {
    string frase;
	getline(cin, frase);
	
	Stack<char> pilha;
	for(int i = 0 ; i < frase.length(); i++){
	    if(frase[i] != ' ')
    	    pilha.push(frase[i]);
    	
    	else{
    	    while(!pilha.empty()){
    	        cout << pilha.pop();
    	    }
    	    
    	    cout << ' ';
	    }
	}
	
	while(!pilha.empty()){
        cout << pilha.pop();
    }
	
	return 0;
}
```
### node.h
```
#ifndef NODE_H
#define NODE_H

template<typename T>
class Node{//nós para lista encadeada que será usada compor a pilha
private:
    T value;  //valor 
    Node<T>* next;  //ponteiro para o proximo no 
public:
    Node(T val, Node<T> *nextPtr);

    T getValue();
    Node<T>* getNext();
    void setValue(T newValue);
    void setNext(Node<T>* newNext);
};
#include "node.cpp"
#endif
```
### node.cpp
```
#ifndef NODE_CPP
#define NODE_CPP
#include "node.h"

template<typename T>
Node<T>::Node(T val, Node<T> *nextPtr){
    value = val;
    next = nextPtr;
}
template<typename T>
T Node<T>::getValue(){
    return this->value;
}
template<typename T>
void Node<T>::setValue(T newValue){
    this->value = newValue;
}
template<typename T>
Node<T>* Node<T>::getNext(){
    return this->next;
}
template<typename T>
void Node<T>::setNext(Node<T>* newNext){
    this->next = newNext;
}
//templaate -> gera classes genericas p/ 
#endif
```
### stack.h
```
#ifndef STACK_H
#define STACK_H
#include "node.h"

template<typename T>
class Stack{
private:
    Node<T>* m_top; // Ponteiro para o topo da pilha se houver, caso contrário será null
    int m_size;   // numero de elementos na lista
    
public:
    Stack();
    ~Stack();
    bool empty();
    void push(T value); //Insere no topo da pilha
    T pop(); //Remove do topo da pilha, se lista vazia -> throw std :: runtime_error("Empty queue.")
};
#include "stack.cpp"
#endif
```
### stack.cpp
```
#ifndef STACK_CPP
#define STACK_CPP
#include "node.h"
#include "stack.h"
#include <stdexcept>

//Node<T>* m_top; // Ponteiro para o topo da pilha se houver, caso contrário será null
//m_size;   // numero de elementos na lista
    
    template<typename T>
    Stack<T>::Stack(){// construtor: cria pilha vazia
        m_top = nullptr;
        m_size = 0;
    }
    
    // destrutor: libera memoria alocada
    template<typename T>
    Stack<T>::~Stack(){
        while(!empty()){
            pop();
        }
    }

    // Retorna true se e somente se a pilha estiver vazia
    template<typename T>
    bool Stack<T>::empty(){
        return (m_size == 0);
    }
    
    // Insere no topo da pilha
    template<typename T>
    void Stack<T>::push(T value){
        Node<T>* newNode = new Node<T>(value, m_top);
        m_top = newNode;
        m_size++;
    }
    
    // Remove elemento do topo da pilha-> Se vazia throw std :: runtime_error("Empty queue.")
    template<typename T>
    T Stack<T>::pop(){
         if(empty()){
            throw std::runtime_error("Empty stack.");
        }
    
        T value = m_top->getValue();
        Node<T>* temp = m_top;
        m_top = m_top->getNext();
        delete temp;
        m_size--;
    
        return value;
    }

#endif
```


