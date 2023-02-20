Crie uma estrutura 'aluno' com: nome (máx 80 caracteres, sem espaços), matrícula (inteiro), disciplina (120, sem espaço) e nota (double).

Leia os valores dos registros de dois alunos e fazer uso da função que imprime o nome do aluno e a maior nota. Caso os dois alunos possuam a mesma nota, deve-se imprimir o nome dos dois alunos separados pela conjunção "e".

```
>>
Joao
1
FUP
10
Maria
2
FUP
8.5
<<
Joao , 10.0
-----------
>>
Rufus
3
Matematica
4
Maria
4
Matematica
8
<<
Maria , 8.0
-----
>>
Rufus
3
Matematica
4
Carlos
5
Matematica
4
<<
Rufus e Carlos , 4.0
```
```cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;

};

int main(){
    aluno aluno1;
    aluno aluno2;
    
        cin >> aluno1.nome;
        cin >> aluno1.matricula;
        cin.ignore();
        cin >> aluno1.disciplina;
        cin >> aluno1.nota;
        cin.ignore();
        
        cin >> aluno2.nome;
        cin >> aluno2.matricula;
        cin.ignore();
        cin >> aluno2.disciplina;
        cin >> aluno2.nota;
        cin.ignore();
    
        if(aluno1.nota > aluno2.nota){
            cout << fixed << setprecision(1) << aluno1.nome << " , " << aluno1.nota;
        }
        if(aluno2.nota > aluno1.nota){
            cout << fixed << setprecision(1) << aluno2.nome << " , " << aluno2.nota;
        }
        if(aluno1.nota == aluno2.nota){
            cout << fixed << setprecision(1) << aluno1.nome << " e " << aluno2.nome << " , " << aluno1.nota;
        }
    
    return 0;
}

