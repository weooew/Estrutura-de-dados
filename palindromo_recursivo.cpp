#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// retorna 'true' se a string for um palíndromo.
bool palindromo(string str, int ini, int fim) {
    if(ini <= fim) { // Caso geral: tem pelo menos um caractere em str
        if(str[ini] == str[fim]) {
            return palindromo(str, ini+1, fim-1);
        }
        else return false;
    }
    else return true; // caso base: string vazia, ini > fim
}

int main() {
    string str = "sopapos";
    cout << boolalpha << palindromo(str, 0, str.size()-1) << endl;
}
