### Node.h
```
#ifndef NODE_H
#define NODE_H

class Node {
private:
    int value;  // valor 
    Node* next;  // ponteiro para o proximo no 
public:
    /**
     * Construtor que recebe o valor que o nó irá armazenar e o ponteiro para o 
     * próximo nó da lista.
     * */
    Node(int val, Node *nextPtr);
    
    /**
    Métodos gets e sets dos atributos
    **/
    int getValue();
    Node* getNext();
    void setValue(int newValue);
    void setNext(Node* newNext);
};

#endif
```

### Node.cpp
```
#include "Node.h"
//value, next
    Node::Node(int val, Node *nextPtr){
        value = val;
        next = nextPtr;
    }

    int Node::getValue() {
        return value;
    }
    
    Node* Node::getNext() {
        return next;
    }
    
    void Node::setValue(int newValue) {
        value = newValue;
    }
    
    void Node::setNext(Node* newNext) {
        next = newNext;
    }
```


### main.cpp
```
#include "ForwardList.h"
#include <cstdio>

void print(ForwardList& list) {
    if(!list.empty()){
        printf("%d\n", list.size());
    	for(int i = 0; i < list.size(); i++) printf("%d ", list.at(i));
    	printf("\n");        
    }else printf("Lista Vazia\n");
}

int main() {
    int n, k;
    scanf("%d", &n);
	ForwardList lista;
	for(int i = 0; i < n; ++i) {
	    scanf("%d", &k); 
	    lista.push_back(k);
	}
	print(lista);
	lista.remove_duplicates();
	print(lista);
}
```
### ForwardList.h
```
#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include "Node.h"

class ForwardList {
private:
    Node* m_head; // aponta para o inicio da lista se houver, caso contrário será null
    int m_size;   // numero de elementos na lista
    
public:
    // construtor: cria lista vazia
    ForwardList();

    // construtor de copia
    ForwardList(ForwardList& lst);
    
    // destrutor: libera memoria alocada
    ~ForwardList();

    // retorna o numero de elementos na lista
    int size() const;
    
    // Retorna true se e somente se a lista estiver vazia
    bool empty() const;

    // Remove todos os elementos da lista, ou seja, deixa a lista vazia
    void clear();

    // Retorna o elemento na posicao k.
    // A funcao verifica se k esta dentro dos 
    // limites de elementos validos da lista. Caso contrário, retorna -1.
    int at(int k);
    
    //Retorna a referência para o Node que está no índice k da lista
    Node* getNode(int k);

    // Recebe um inteiro como argumento e o adiciona
    // logo apos o ultimo elemento da lista. 
    void push_back(int value); 
    
    // Remove e retorna o ultimo elemento da lista se a lista nao
    // estiver vazia. Caso contrario, retorna -1 
    int pop_back(); 
    
    // insere um elemento no indice especificado
    void insert(int value, int k);

    // remove o elemento no indice especificado
    void removeAt(int k);
    
    //Remove elementos repetidos da lista
    //A ordem relativa dos elementos que ficam se manter.
    void remove_duplicates();
};

#endif

```
### ForwardList.cpp
```
#include "Node.h"
#include "ForwardList.h"
//m_head, m_size
    // construtor: cria lista vazia
    ForwardList::ForwardList(){
        m_head = nullptr;
        m_size = 0;
    }
    
    // construtor de copia
   ForwardList::ForwardList(ForwardList& lst) {
        m_head = nullptr;
        m_size = 0;
    
        Node* current = lst.m_head;
        while(current != nullptr){
            push_back(current->getValue());
            current = current->getNext();
        }
    }   
    
    // destrutor: libera memoria alocada
    ForwardList::~ForwardList(){
        clear();
    }

    // retorna o numero de elementos na lista
    int ForwardList::size() const{
        return m_size;
    }
    
    // Retorna true se e somente se a lista estiver vazia
    bool ForwardList::empty() const{
        return (m_size == 0);
    }

    // Remove todos os elementos da lista, ou seja, deixa a lista vazia
    void ForwardList::clear(){
        while(m_head != nullptr){
            Node* temp = m_head;
            m_head = m_head->getNext();
            delete temp;
        }
        m_size = 0;
    }

    // Retorna o elemento na posicao k.
    // A funcao verifica se k esta dentro dos 
    // limites de elementos validos da lista. Caso contrário, retorna -1.
    int ForwardList::at(int k){
        if(k >= 0 && k < m_size){
            Node* node = getNode(k);
            return node->getValue();
        }
        return -1;
    }
    
    //Retorna a referência para o Node que está no índice k da lista
    Node* ForwardList::getNode(int k){
        Node* current = m_head;
        for(int i = 0; i < k; i++){
            current = current->getNext();
        }
        return current;
    }
    

    // Recebe um inteiro como argumento e o adiciona
    // logo apos o ultimo elemento da lista. 
    void ForwardList::push_back(int value){
        Node* newNode = new Node(value, nullptr);
        if(m_head == nullptr){
            m_head = newNode;
        } 
        else{
            Node* current = m_head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
        m_size++;
    }
    
    // Remove e retorna o ultimo elemento da lista se a lista nao
    // estiver vazia. Caso contrario, retorna -1 
    int ForwardList::pop_back(){
        if(m_head == nullptr){
            return -1;
        }
    
        if(m_head->getNext() == nullptr){
            int value = m_head->getValue();
            delete m_head;
            m_head = nullptr;
            m_size = 0;
            return value;
        }
    
        Node* current = m_head;
        while(current->getNext()->getNext() != nullptr){
            current = current->getNext();
        }
    
        int value = current->getNext()->getValue();
        delete current->getNext();
        current->setNext(nullptr);
        m_size--;
        return value;
    }
    
    // insere um elemento no indice especificado
    void ForwardList::insert(int value, int k){
        if(k >= 0 && k <= m_size){
            if(k == 0){
                Node* newNode = new Node(value, m_head);
                m_head = newNode;
            } 
            else{
                Node* prevNode = getNode(k - 1);
                Node* newNode = new Node(value, prevNode->getNext());
                prevNode->setNext(newNode);
            }
            m_size++;
        }
    }

    // remove o elemento no indice especificado
    void ForwardList::removeAt(int k){
        if(k >= 0 && k < m_size){
            if(k == 0){
                Node* temp = m_head;
                m_head = m_head->getNext();
                delete temp;
            } 
            else{
                Node* prevNode = getNode(k - 1);
                Node* currentNode = prevNode->getNext();
                prevNode->setNext(currentNode->getNext());
                delete currentNode;
            }
            m_size--;
        }
    }
    
    
    //Remove elementos repetidos da lista
    //A ordem relativa dos elementos que ficam se manter.
    void ForwardList::remove_duplicates(){
        Node* current = m_head;

        while(current != nullptr){
            Node* runner = current;
    
            while(runner->getNext() != nullptr){
                if(runner->getNext()->getValue() == current->getValue()) {
                    Node* duplicateNode = runner->getNext();
                    runner->setNext(duplicateNode->getNext());
                    delete duplicateNode;
                    m_size--;
                } 
                else{
                    runner = runner->getNext();
                }
            }
    
            current = current->getNext();
        }
    }
```

