obs: #include <iostream> //serve para cin cout
obs: using namespace std; //serve para se não achar essa função ou obj olha se tá no std
obs: std::endl é mais lento que '\n'
obs: operadores de resolução do escopo ::
  
## Variáveis e const / identificadores
Variável é uma posição da memória. Nome da variável é chamado identificador(nome pode conter '\_', mas não deve iniciar com '\').
Escopo serve como identação e tempo de vida (saí do escopo é detruido).
  
  **FORMAS DE INICIALIZAÇÃO:** normalmente inicia minúsculo
    int x = 5; // assignment/atribuição
    int x(5); //direct initialization
    int x{ 5 }; //uniform initialization -> recomendado

  ps: buffer (ponteiro) de entrada???
**CONSTANTES:** normalmente usam só letras maiúsculas. 
    const int LADO = 6;
Obs: muda forma de acesso aos parâmetros
  
  STATIC??
  
## Tipos de dados
tipos inteiros: char(1 byte), int(4 bytes), short(2 bytes), long(8 bytes)-> podem usar unsigned
  + float(4 bytes), double(8 bytes), void, bool
  
  LITERAIS: unamed values inserted directly into the code -> type deduced from the literal's value
  ```
  bool myNameIsAlex { true }; // true is a boolean literal
  float num = 3.4;           // 3.4 is a double literal
  ```
  
  
  LITERAL SUFFIXES: to change a literal default value you can use a suffix
  |DATA TYPE     |SUFFIX            |MEANING                      |
  |--------------|------------------|-----------------------------|
  |integral      |'u'or'U'          |unsigned int                 |
  |integral      |'l'or'L'          |long int                     |
  |integral      |variações de 'UL' |unsigned long                |
  |integral      |variações de 'LL' |long long                    |
  |integral      |variações de 'LLU'|unsigned long long           |
  |integral      |'z'or'Z'          |signed version of std::size_t|
  |integral      |variações de'UZ'  |std::size_t                  |
  |floating point|'f'or'F'          |float                        |
  |floating point|'l'or'L'          |long double                  |
  |string        |'s'               |std::string                  |
  |string        |'sv'              |std::string_view             |
  
  Scientific notation for floating points -> ex: double avogadro {6.02e23};
  
  
- Modificador: sizeof(<nome da variável>); -> mostra quantos bits usados 
- Precisão de float e zeros a esquerda
  printf("%02d", hora);  //só 2 Dígitos
  printf("%.2f", peso); //depois do ponto só 2 Dígitos 
  Obs: #include <cstdio> 

- Auto (tipo do valor recebido no lado direito)
  auto x = 5;
  NÃO-> auto y;
  Obs: vector<int>::iterator y = vet.begin();
  auto y { 6.54 }; //double
  auto y { 6.54f }; //float 
CASTING 
  int <-> char 
     std::cout << (int) 'a';
     std::cout << static_cast<int>( 'a' ); 

     int num { 6 };
     std::cout << (char) ( '0' + num); 

  float <-> int 
     int -> float divisão 
     float a = 5/6; //dois inteiros 
     float a = 5.0/6;
     float a = (double)x/y;
     float a = static_casting<double>(x) / y; //avisa quando Conversão não faz sentido 

  string <-> int, 
  float -> ver 
      stringstream 

    Math operatores: 
      int valor = 5 * 1.3 + 'a'
      Então:  valor = 103 

std::cout << std::string("") + "eu" +  "vou" + '\n'; //concatenar strings
std::cout << "eu" +  "vou" + '\n'; //assim não dá certo //ñ somar 2 vetores primitivos 

Em etapas: 
std::string saída {""};
saída += "eu";
saida += "vou";
std::cout << saída ; 

Concatenação???? 
OBS: "" use more storage and cause slower functions to be called then ''

## Namespace
  é uma região declarativa que fornece um escopo para os identificadores (nome de tipos, fuinções, variáveis) dentro dele
  usada para declarar um escopo que contém um conjunto de objetos relacionados
  ´´´
  //definindo seu proprio namespace
  //Arquivo  mymath.h
  namespace  math {
  int  sum(int x, int y) {   return x+y; }
  }
  
  // prog61.cpp
  #include  <iostream> 
  #include "mymath.h"
  
  int  main() {
  int a{ 5 }, b = 10;
  std::cout  << math::sum(a,b) << std::endl;
  return  0;
  }
  ´´´
  ´´´
  //declarações using
  #include  <iostream > // prog62.cpp2
  using  std::cout;
  using  std::endl;
  namespace  math {
  int  sum(int x, int y) { return x+y; }
  }
  
  int  main() {
  using  namespace  math;
  int a{ 5 }, b{ 4 };
  cout  << sum(a,b) << endl;
  return  0;
  }
  ´´´
  ´´´
  //declarações using
  #include  <iostream > // prog63.cpp
  namespace  math {
  int  sum(int x, int y) { return x+y; }
  }
  
  int  main() {
  using  std::cout; //  using  declaration
  using  std::endl; //  using  declaration
  
  int a{ 5 }, b{ 4 };
  cout  << math::sum(a,b) << endl;
  return  0;
  }
  ´´´
  #include  <iostream > // prog64.cpp23
  namespace  math {
  int  sum(int x, int y) { return x+y; }
  }
  
  using  namespace  math;
  int  main() {
  using  namespace  std;
  int a{ 5 }, b{ 4 };
  cout  << sum(a,b) << endl; // Erro de  compilacao
  return  0;
  }
  //divt div(int numer, int denom);retorna um struct e est ́a definidosob o namespacestd
  ´´´
  
## / representacao num / vetores, strings, ponteiros, estruturas e enumeração, estruturas de controle de fluxo, funções...

## Structs
  conj de variáveis sob o mesmo nome
```
struct Empregado {
  short id;
  string nome;
};
int main(){
  Empregado carlos; //inicializei
  carlos.id = 10;
  carlos.nome = "Carlos Gomes";
  
  cout << "ID: "<< carlos.id
        << "\nNome: " << carlos.nome << endl;
  }
```
** A partir do C++11: **
```
struct Empregado {
  short id;
  string nome;
};
  
void imprime_empregado(Empregado c){
  cout << "ID: "<< carlos.id
        << "\nNome: " << carlos.nome << endl;
  }
  
int main(){
  Empregado c {10, "Carlos"}; //inicializei
  imprime_empregado(c);
  }  
```
   

  
## Ponteiros

Aplicações:

  - Passar arg por referência -> Propósitos: Trocar valor de 2 variáveis ou passar dado grande para função de forma que não envolva cópia de dados
  
  - Acessar elementos de um array (compilador usa ponteiros para acessar elementos de um array)  
  
  - Permitir que uma função retorne vários elementos
  
  - Usar endereços de memória
  
  - Alocação dinâmica de memória
  
  - São usados na implementação eficiente de diversas estrutura de dados
  
  Ponteiros: são variáveis que armazena o endereço de memória de outras variáveis
  (declaração: int *nome;)
  
        * acessa variavél cujo endereço é fornecido
        & fornece endereço de memória de uma variável
  
  '''c
  int a = 1;
  int *p;
  p = &a;
    cout << "Endereço de memória de a: " << p << endl;    
    cout << "Valor armazenado no local apontado: " << *p << endl;
  int b = 2 + *p; //b recebe 2 + 1
  *p = 5; //modifica valor da variável a
  
  '''
APLICAÇÃO DE PONTEIROS: PASSAGEM POR REFERÊNCIA
Para uma função modificar o valor passado como parâmetro, devemos passar o endereço de memória da variável que deve ser modificada (ponteiro). Chamamos este procedimento de passagem de parâmetro por referência.
```
#include <iostream>
using namespace std;

void f(int *x)
{
   *x = 2;
}

int main()
{
   int y = 1;
   f(&y);
   cout << y;  // Imprime o valor 2.
   return 0;
}
```

PONTEIROS PARA ESTRUTURAS
```
#include <iostream>
#include <iomanip>
using std::cout;

struct tupla {
   int x;
   float y;
};

void f(tupla *p)
{
   (*p).y = 3;  //o que tiver na struct  //para + legibilidade p->y = 3;
}

int main()
{
   tupla t = {1, 2.0};
   f(&t);       //passa endereço da struct
   cout << std::fixed;
   cout << t.x << std::setprecision(1) << t.y;  // Imprime "1 3.0"
   return 0;
}
```
IDENTIFICADORES DE VETORES SÃO PONTEIROS
Quando um vetor é declarado, o nome do vetor é tratado como um ponteiro. Internamente, a compilador reserva um espaço contíguo de memória capaz de armazenar todos os elementos do vetor, e faz o nome da variável ser um ponteiro para o início deste espaço de memória. Isto implica que 
todo vetor passado como parâmetro para uma função na verdade é passado por referência: se a função alterar o vetor, esta mudança ocorrerá no vetor passado como parâmetro.
```
#include <iostream>

void f(int v[], int n)
{
   int i;
   for (i = 0; i < n; i++)
      v[i] += 1;
}

int main()
{
   int v[3] = {1,2,3};

   f(v,3);

   int i;
   for (i = 0; i < 3; i++)
      std::cout << v[i] << " "; // Imprime "2 3 4"
   return 0;
}
```
