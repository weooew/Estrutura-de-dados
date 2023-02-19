## Identificando elementos

Dada uma frase(max 100 char) com palavras (letras minúsculas), números, espaço e ponto, identifique os elementos como str, int ou float.

Analise cada palavra\[max 10 char na palavra\].

Regras:

Float tem o ponto.  
Int não tem ponto.  
Int e float podem ser negativos.  
Se existir pelo menos um alfabético então é string.

### Entrada

*   Uma frase(max 100 char) com palavras (letras minúsculas), números, espaço e ponto

### Saída

*   o tipo de cada palavra (str, float ou int) separado por espaço.  

## Exemplos  

```
>>>>>>>> 01
tenho 15 4nos 1.75 altur4 -15 conto p0rr4 -4.04
========
str int str float str int str str float
<<<<<<<<


>>>>>>>> 02
a proxima eleição presidencial no Brasil ocorrerá em 2 de outubro de 2018
========
str str str str str str str str int str str str int
<<<<<<<<
```

<!--
>>>>>>>> 03
aa 1 -2.0
========
str int float
<<<<<<<<


>>>>>>>> 04
02a -x1 -4.b54 p0
========
str str str str
<<<<<<<<


>>>>>>>> 05
-pato -40 -5.4
========
str int float
<<<<<<<<


>>>>>>>> 06
02 -1 -4.54 p0
========
int int float str
<<<<<<<<
-->
```

```cpp
//terminar esse código
#include <iostream>
//identificar tipo
using namespace std;
int main(){
    string frase;
    getline(cin, frase);
    int a = 0;
    
    //todo espaço -> print
    for(int x = 0; frase[x] != '\0' ;x++){
        //verificar palavra 
        if(frase[0] == frase[x] || frase[x-1] == ' '){   
            for(a = 0; frase[x] != ' '; x++){
                //uma letra string
                    if((frase[x] == 'a') || (frase[x] == 'b')||(frase[x] == 'c')||(frase[x] == 'd')||(frase[x] == 'e')||(frase[x] == 'f')||(frase[x] == 'g')||(frase[x] == 'h')||(frase[x] == 'i')||(frase[x] == 'j')||
                    (frase[x] == 'k')|| (frase[x] == 'l')|| (frase[x] == 'm')|| (frase[x] == 'n')|| (frase[x] == 'o')|| (frase[x] == 'p')|| (frase[x] == 'q')|| (frase[x] == 'r')||(frase[x] == 's')||(frase[x] == 't')||
                    (frase[x] == 'u')||(frase[x] == 'v')||(frase[x] == 'x')||(frase[x] == 'w')||(frase[x] == 'y')){
                        a = 2;
                        cout << "str ";
                        break;
                    }
                //só num e . float
                else if(frase[x] == '.'){
                        a = 3;
                }
                else if(a ==0 || a==1) {a = 1;}
            }
        }
        if(a == 3)cout << "float ";
        if(a == 1) cout << "int ";
    }
    return 0;
}
/*
#include <iostream>
using namespace std;
int main(){
    string frase;
    getline(cin, frase);
    
    for(int x = 0; frase[]; x++){
        q = 0;
        for(int i = 0; b[i] != '\0'; i++){
                //se letra 1 true
                if((b[i] == 'a')||(b[i] == 'b')||(b[i] == 'c')||(b[i] == 'd')||(b[i] == 'e')||(b[i] == 'f')||(b[i] == 'g')||(b[i] == 'h')||(b[i] == 'i')||(b[i] == 'j')||
                (b[i] == 'k')|| (b[i] == 'l')|| (b[i] == 'm')|| (b[i] == 'n')|| (b[i] == 'o')|| (b[i] == 'p')|| (b[i] == 'q')|| (b[i] == 'r')||(b[i] == 's')||(b[i] == 't')||
                (b[i] == 'u')||(b[i] == 'v')||(b[i] == 'x')||(b[i] == 'w')||(b[i] == 'y')){
                    cout << "str ";
                    q = 1;
                    break;
                }
            }
        if(q == 0){
            for(int i = 0; b[i] != '\0'; i++){
                if(b[i] == '.'){
                    cout << "float ";
                    q = 1;
                    break;
                }
            }
        }
        if(q == 0){
            cout << "int ";
        }
    }
    
    return 0;
}*/

```
