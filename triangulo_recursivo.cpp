/*Quantos triangulos(de tamanhos variados) podemos encontrar em uma grade de triˆangulos com altura n
  /\
 /\/\  -> ex: f(1) = 1; f(2) = 4; f(3) = 10;
/\/\/\ -> f(4) = 4 + f(3) + f(3) - f(2) = 20
*/
#include <iostream>
using namespace std;

int triangulos(int h) {
    if(h == 0 || h == 1) 
        return h;
    else 
        return h + 2*triangulos(h-1) - triangulos(h-2);
}

int main() {
    int h = 5;
    cout << "numero de triangulos numa grade de altura " << h << ": "
         << triangulos(h) << endl;
}
