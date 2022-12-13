#include <iostream>
using namespace std;

// retorna a elevado a b
int exp(int a, int b) {
    if(b == 0)
        return 1;
    else 
        return a * exp(a, b-1);
}

int main() {
    cout << exp(3,3) << endl;
}
