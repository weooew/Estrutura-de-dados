## Gansos Gamados
## Ação

Dada uma frase, imprima "sim" se as palavras estiverem ordenadas e "nao" caso contrario.

### Entrada

- Uma frase de até 100 caracteres minúsculos e sem acento.

### Saída

- "sim" ou "nao".

## Exemplos

```
>>>>>>>>
a amora azul
========
sim
<<<<<<<<

>>>>>>>>
o rato roeu a roupa
========
nao
<<<<<<<<

>>>>>>>>
a b c d e f
========
sim
<<<<<<<<

>>>>>>>>
a b c d a f
========
nao
<<<<<<<<
```

```cpp
//frases ordenada ou nao
#include <iostream>
using namespace std;

int main(){
    string frase;
    //receber string
    getline(cin, frase);
    int a = 0, b = 0; //a = 1°letra palavra anterior
    
    //repetir numero de elementos da string
    for(int x { 0 }; frase[x] != '\0'; x++){
        if(frase[x] == ' '){
            b = x+1;//b -> 1° letra palavra proxima
        
            if(frase[a] > frase[b]){ //se a proxima letra for maior que a anterior imprima nao 
                cout << "nao";
                return 0;
            }
            
            if(frase[a] == frase[b]){ //se igual vai para a segunda letra, terceira...
                if(frase[a+1] > frase[b+1]) {cout << "nao"; return 0;}
                else if((frase[a+1] == frase[b+1]) && (frase[a+2] > frase[b+2])) {cout << "nao"; return 0;}
                else if((frase[a+1] == frase[b+1]) && (frase[a+2] == frase[b+2]) && (frase[a+3] > frase[b+3])) {cout << "nao"; return 0;}
            }
            
        }
        a = b; //1 letra da ultima palavra
    }
    cout << "sim";
    return 0;
    
}
```
