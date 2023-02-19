Motivação: Pedro e João foram no Silvio Santos. O programa era aquele que o Silvio mostrava um produto do mercantil e a pessoa que chegasse mais próximo do preço real ganhava.

João e Pedro são concorrentes. O objetivo do seu programa é informar quem ganhou a disputa.

O primeiro jogador informa o preço e o segundo jogador informa maior ou menor.
Quem vencer mais disputas ganha o jogo. Se o valor do produto for igual ao chute, ganha o primeiro concorrente.

Se ambos vencerem a mesma quantidade então acontece o empate. 

Se ambos tiverem igualmente próximos do preço então nenhum dos dois ganha a disputa.

Dica para esta questão: A leitura de caracteres e strings em C++ é sempre algo complicado para iniciantes.

Um dos problemas que pode acontecer ao ler uma string ou um caractere, é que o buffer de leitura pode conter lixo na hora de ler os caracteres do usuário.

Se isso ocorrer, o terminal não espera o usuário digitar a string e lê o lixo do buffer e o coloca na string. Isso geralmente causa muita confusão e horas de análise de código.

A fim de evitar esse problema, limpe o buffer após ler outros tipos de dados que não sejam string. Para isso, use a função std::cin.ignore(). Pesquise sobre ela.

Entrada: 
linha 1: a quantidade de produtos (1 a 50)
linha 2: o valor dos produtos (0.01 até 1000.0)
linha 3: os chutes do Primeiro (float)
linha 4: as escolhas do segundo (m para menor, M para maior)

Saída: "primeiro" ou "segundo" ou "empate"

>>
1
1.0
1.0
M
<<
primeiro

---------------
>>
2
1.0 2.0
1.0 2.1
m m
<<
empate

------------------
>>
2
1.0 2.0
1.0 2.1
m M
<<
primeiro

-----------------
>>
2
1.0 2.0
1.1 2.1
m M
<<
empate

-------------------
>>
3
1.0 2.0 4.0
1.1 2.1 4.0
m M m
<<
primeiro

-----------------
>>
3
1.0 2.0 4.02
1.1 2.1 4.1
M m m
<<
segundo


```
#include <iostream>
using namespace std;
int main(){
    int quant_prod { 0 }, win1{ 0 }, win2 { 0 };
    
    //recebe quant de produtos
    cin >> quant_prod;
    
    //recebe preco, chute e seg 
    float preco[quant_prod];
    float chute[quant_prod];
    char seg [quant_prod];
    
    for(int w { 0 }; w < quant_prod; w++){
        cin >> preco[w];
    }
    for(int w { 0 }; w < quant_prod; w++){
        cin >> chute[w];
    }
    for(int w { 0 }; w < quant_prod; w++){
        cin >> seg[w];
    }
    
    //how_many_wins 
    for(int i { 0 }; i < quant_prod; i++){
        //1°: chute = preço ou error
        /*if(chute[i] == preco[i]){
            win1 = win1 + 1;
            cout << "==";
        }
        if((preco[i] < chute[i]) && (seg[i]=='M')){
            win1 = win1 + 1;
            cout << "++";
        }
        if((preco[i] > chute[i]) && (seg[i]=='m')){
            win1 = win1 + 1;
            cout << "--";
        }*/
        //2°: acertou
        if((preco[i] < chute[i] && seg[i]=='m')||(preco[i] > chute[i] && seg[i]=='M')){
            win2 = win2 + 1;
            //cout << "+-";
        }
        else{
            win1 = win1 + 1;
        }
    }
    
    if (win1 > win2){
        cout << "primeiro";}
    else if (win1 == win2){
        cout << "empate";}
    else{
        cout << "segundo";}
    
    return 0;
}
```
