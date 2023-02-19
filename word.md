## MeU WoRd QuEbRoU

## Motivação

O seu editor de texto deu problema. Seu orientador pediu que você formatasse toda uma seção do seu trabalho em caixa alta. Como você é um fantástico programador resolveu logo fazer algo mais completo.

## Ação

Dado um texto, formate como for pedido (M - Toda maiúscula, m - toda minuscula, p - primeira maiúscula, i - inverter case). Observe que no primeiro maiúscula deixa como minúscula palavras de tamanho 1 como os artigos 'a', 'e', 'o'.

Ignore pontuação, espaço e números.

A entrada é composta de minúsculas, maiúsculas, números, pontuações e espaços simples.

### Entrada

*   Texto com até 100 caracteres.
*   Caracteres representando a formatação (M, m, p, i).

### Saída

*   O texto formatado.

## Exemplos

```
>>>>>>>>
O Pato e o frango ja tao cozidos, comam!
M
========
O PATO E O FRANGO JA TAO COZIDOS, COMAM!
<<<<<<<<

>>>>>>>>
O Pato e o frango ja tao cozidos, comam!
m
========
o pato e o frango ja tao cozidos, comam!
<<<<<<<<

>>>>>>>>
O Pato e o frango ja tao cozidos, comam!
p
========
o Pato e o Frango Ja Tao Cozidos, Comam!
<<<<<<<<

>>>>>>>>
O Pato e o frango ja tao cozidos, comam!
i
========
o pATO E O FRANGO JA TAO COZIDOS, COMAM!
<<<<<<<<
```

```cpp
#include <iostream>
using namespace std;
int main(){
    string frase;
    getline(cin, frase);
    char a;
    int dif = 'A' - 'a';//pos
    cin >> a;
    
    if(a == 'M'){
        for(int i = 0; frase[i] != '\0'; i++){
            //m-> M
            if(frase[i] > 'Z' && frase[i] != ' ' && frase[i] != ',' && frase[i] != '!') frase[i] = frase[i] + dif;
        }
    }
    if(a == 'm'){
        for(int i = 0; frase[i] != '\0'; i++){
            //M -> m
            if(frase[i] < 'a' && frase[i] != ' '&& frase[i] != ',' && frase[i] != '!') frase[i] = frase[i] - dif;
        }
    }
    if(a == 'p'){
        frase[0] = frase[0] - dif;
        for(int i = 0; frase[i] != '\0'; i++){
            //primeira maiuscula
            if(frase[i] == ' ' && frase[i+1] > 'Z' && frase[i] != ',' && frase[i] != '!' && frase[i+2] != ' ') frase[i+1] = frase[i+1] + dif;
        }
    }
    if(a == 'i'){
        for(int i = 0; frase[i] != '\0'; i++){
            //inverter m-> M
            if(frase[i] > 'Z' && frase[i] != ' ' && frase[i] != ',' && frase[i] != '!') frase[i] = frase[i] + dif;
            //M-> m 
            else if(frase[i] == ' ' || frase[i] == ',' || frase[i] == '!') {}
            else{frase[i] = frase[i] - dif;}
        }
    }
    
    cout << frase;
    
    
    return 0;
}

```
