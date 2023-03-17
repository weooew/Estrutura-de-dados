As listas lineares estão entre os tipos abstratos de dados de manipulação mais simples. 

O tipo de armazenamento de uma lista linear pode ser classificado de acordo com a posição relativa na memória de dois nós consecutivos na lista. Continuas na memória-> alocação sequencial de memória. Quando não é garantido que estejam em posições contı́guas é alocação encadeada. 

A maneira mais simples de manter uma lista linear na memória do computador é alocar seus nós em posições contı́guas (alocação sequencial). 

No exemplo de sala: a estrutura de dados (vetor) é encapsulada na classe List por meio da utilização do modificador private, enquanto as interfaces das funções tornam-se visı́veis por meio do modificador public. Deste modo, graças ao encapsulamento, o programador pode modificar tanto a estrutura de dados quanto a implementação das operações sem provocar alterações nos programas que utilizam a classe List, desde que as interfaces das funções sejam preservadas.

A implementação de listas lineares por meio de vetores tem como vantagem a economia de memória, já que não gasta-se bytes com ponteiros. Uma segunda vantagem consiste no tempo constante para acessar um nó da lista, dado que sua posição seja conhecida. Porém, como desvantagem citamos o custo para inserir ou retirar itens da lista, que pode causar um deslocamento de todos os itens, no pior caso. Além disso, em aplicações em que não existe previsão sobre o crescimento da lista, a utilização de vetores pode exigir realocação de memória. Essa é uma operação de alto custo em termos de tempo e memória, pois é preciso alocar uma nova área com mais posições do que a atual e copiar todos os itens para ela. Apesar dessa desvantagem, listas sequenciais apresentam melhor performance no caso em que operações de acesso a um nó são frequentemente executadas.

PROBLEMA
Uma caracterı́stica limitante da estrutura de dados List é que a capacidade total da lista é fixa (não muda) uma vez que ela foi criada.

Com o intuito de eliminar essa limitação, reimplemente a estrutura de dados List vista em aula para sempre permitir a inserção de novos itens na lista. Para isso é preciso modificar a operação de inserção push_back(int elemento) da seguinte forma: toda vez que a inserção de um novo item esgotar a memória disponı́vel no vetor, uma nova área de memória com capacidade maior deve ser alocada e o conteúdo do vetor anterior deve ser copiado para ela.

Uma ideia para essa implementação é: toda vez que a lista ficar cheia, criar um novo array de inteiros com o dobro da capacidade do array antigo e, então, copiar todos os dados do array antigo para o array novo. Não esquecendo claro de liberar a memória que foi alocada para o array antigo (sempre certifique-se de que não haja vazamento de memória na sua estrutura de dados e no seu programa como um todo).

Após sucessivas operações de retirada pop_back(), a razão do número de itens no vetor pela sua capacidade pode se tornar muito pequena. Nesse caso, uma operação para diminuir a quantidade de memória total utilizada pelo vetor também deve ser implementada.

Ideia: a fim de diminuir a capacidade do array, uma operação inversa a operação descrita no caso anterior pode ser executada aqui. Certifique-se de liberar a memória do array antigo.

## Atividade
Implementar uma lista usando alocação sequencial (array). Sua lista deve ser redimensionável, ou seja, deve aumentar de tamanho automaticamente sempre que for necessário incluir um elemento e ela estiver cheia.

Ela deve ser iniciada utilizando alocação dinâmica e conter além do vetor de dados, os atributos size e capacity que definem o tamanho atual e a capacidade da lista.
 
 ---
 EXEMPLO
 ´´´
 #__case create
$init 3
$status
size:0 capacity:3
$end

#__case push_back
$init 5
$show
[ ]
$push_back 3 4 5 1
$show
[ 3 4 5 1 ]

#__case tentar inserir mais do que a capacidade atual
$push_back 7 3 2 1
$show
[ 3 4 5 1 7 3 2 1 ]

#__case pop_back retirar os últimos 3 elementos
$pop_back 3
popped 1 2 3
$show
[ 3 4 5 1 7 ]
$end
 ´´´
 
 ---
## main.cpp
```
#include <iostream>
#include <sstream>
using namespace std;

// classe que implementa uma lista redimensionável
class Vector {
private:
    int m_capacity {0}; //esse {} é o modo de inicializar default do c++ a partir do c++11
    int m_size {0};
    int * m_data {nullptr}; //inicializar pra não conter lixo

public:
	// construtor vazio
    Vector(){
        //inicialize this->m_capacity com 10
        //inicialize this->m_size com 0
        //crie memória dinamicamente para this->m_data com tamanho m_capacity
    }

	// construtor
    Vector(int capacity){
		//se capacity <= 0, entao inicialize this->m_capacity com 10
        //caso contrario, inicialize this->m_capacity com capacity.
        //inicialize this->m_size com 0
        //crie memória dinamicamente para this->m_data com tamanho m_capacity
    }

	// destrutor
    ~Vector(){
        //libere this->m_data
    }

	int size() {
		//retorna size
	}

	int capacity() {
		//retorna capacity
	}

    //como seu vector tem atritutos do tipo ponteiros, você precisa criar um
    //construtor de cópia e um operador de atribuição ou terá erros do tipo double-free

	// construtor de cópia
	//aqui você ensina seu vector a ser criado a partir de outro vector
    //Ex: 
    //Vector v(4);
    //Vector v2(v);
    Vector(Vector& other){
        //inicialize this->m_capacity com other.m_capacity
		//inicialize this->m_size com other.m_size
		//libere a memória em this->m_data
		//crie memória dinamicamente para this->m_data com tamanho m_capacity
		//copie os elementos de other.data para this->m_data 
    }

    //O operador de atribuição será invocado quando você fizer um Vector receber outro
    //Ex:
    //Vector vec(4);
    //vec = Vector(6);
    //nesse ponto, os atributos de this já foram inicializados, 
    //mas você precisa alterá-los para copiar os valores de other
    const Vector& operator = (const Vector& other){
		if(this != &other) {
			//inicialize this->m_capacity com other.m_capacity
			//inicialize this->m_size com other.m_size
			//se this->m_data não for nulo, devolva a memória com delete
			//crie nova memória para this->m_data do tamanho de other.m_capacity
			//copie os dados de other.m_data para this->m_data
		}
		return *this;
    }

    //adiciona um valor ao final da lista
    void push_back(int value){
        //se vector estiver cheio, aumenta o tamanho para o dobro do tamanho anterior
		//depois, adiciona value ao final do vector
		//incrementa m_size
    }

	//remove um valor do final da lista
    int pop_back(){
		//se a lista estiver vazia, então lance um erro do tipo std::runtime_error
		//caso contrário:
		//1. remova o valor do final do vector e guarde-o em uma variavel auxiliar
		//2. decremente m_size
        //3. se m_size < m_capacity/2, diminua m_capacity para m_capacity/2
		//4. diminua o tamanho de m_data para m_capacity/2 e realoque os elementos
		//5. retorne o valor removido
    }

    //esse é o toString 
	//retorna uma string contendo a lista formatada
	//Ex: uma lista com elementos 2,3,4,5 deve ser
	// retornada como a string: "[2,3,4,5]"
    std::string toString(){
        // fazer
    }
};


/* NAO MEXA DAQUI PRA BAIXO */
int main(){
    string line, cmd;
    int value;
    Vector v(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            v = Vector(value);
        } else if(cmd == "status"){
            cout << "size:" << v.size() << " capacity:" << v.capacity() << "\n";
        } else if(cmd == "push_back"){
            while(ss >> value)
                v.push_back(value);
        } else if(cmd == "pop_back"){
            ss >> value;
            cout << "popped: ";
            for(int i = 0; i < value; ++i)
                cout << v.pop_back() << " ";
            cout << endl;
        } else if(cmd == "show"){
            cout << v.toString() << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}

```

