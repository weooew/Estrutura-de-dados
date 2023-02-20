Crie uma estrutura 'aluno' com: nome (máx 80 caracteres, sem espaços), matrícula (inteiro), disciplina (120, sem espaço) e nota (double).

Uma função de leitura, e outra função que receba um registro de um aluno e imprima "[Nome_Aluno] aprovado(a) em [Nome_Disciplina]" se o aluno passou por média (nota maior ou igual a 7) e "[Nome_Aluno] reprovado(a) em [Nome_Disciplina]" caso contrário.

Obs: Um dos problemas que pode acontecer ao ler uma string, é que o buffer de leitura pode conter lixo na hora de ler a string do usuário. (std::cin.ignore())

```
<<
Joao
1
FUP
8.5
>>
Joao aprovado(a) em FUP
----------
<<
Rufus
2
Matematica
4
>>
Rufus reprovado(a) em Matematica
```

```c
#include <iostream>
#include <istream>
#include <string>
using namespace std;
/*função de leitura dos valores do registro de um aluno, lidos do usuário, 
função que receba um registro de um aluno e imprima "[Nome_Aluno] aprovado(a)/reprovado em [Nome_Disciplina]" (nota maior ou igual a 7) ou 

Seu programa deve então ler os dados de um aluno usando registro e fazer uso da 
função que determina se o aluno foi aprovado ou não, gerando o resultado correto.
*/

struct aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;

} aluno1;

int main(){
    
        cin >> aluno1.nome;
        cin >> aluno1.matricula;
        cin.ignore();
        cin >> aluno1.disciplina;
        cin >> aluno1.nota;
        cin.ignore();
    
        cout <<  aluno1.nome;
        if(aluno1.nota >= 7){
            cout << " aprovado(a) em ";
        }
        else{
            cout << " reprovado(a) em ";
        }
        cout << aluno1.disciplina;
    
    return 0;
}
```
