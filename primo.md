```
#include <iostream>
using namespace std;

bool primo(int n){
    for(int i = 2; i < n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}


int main(){
    int a, b = 0;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        if(primo(i) == true){
            if(a == b) i = a + 1;
            cout << i << endl;
        }
    }
    
}
```
