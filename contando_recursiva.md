Forneça um algoritmo recursivo para contar quantas vezes um determinado caractere ocorre em uma 
string. Não é permitido usar comandos de repetição nesta função.

ENTRADA: 1° a string 2° caractere

SAÍDA: Númerro de ocorrências do caractere na string

----------------------------------------------------------------------
>>>>>>>>
fundamentos de programacao

a

========

4

<<<<<<<<

-----------------------------

```cpp
#include <iostream>
#include <string>
using namespace std;
//contar quantas vezes caractere aparece na string
// string (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string frase, int n, char letra)
{
    if(n == 1 && frase[n-1] != letra){
        return 0;
    }
    if(n == 1 && frase[n-1] == letra){
        return 1;
    }
    if(n > 1 && frase[n-1] == letra){
        return 1 + contaCaracteres(frase, n-1, letra);
    }
    //n > 1 && frase[n] != letra){
        return 0 + contaCaracteres(frase, n-1, letra);
    
}

int main() 
{
    string frase;
    char letra;
    
    getline(cin, frase);
    cin >> letra;
    
    cout << contaCaracteres(frase, frase.length(), letra); 
    return 0;
}
```
