´´´
#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    int vec[n];
    int main = 1;
    int w = 0;
    int x = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            vec[i] = x;    
            if(vec[i-1] > vec[i]){
                w = 2;
            }
        }
    if(w == 0) cout << "ok" << endl;
    if(w == 2) cout << "precisa de ajuste" << endl;
    return 0;
}

´´´
