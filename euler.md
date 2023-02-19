´´´cpp

#include <iostream>
#include <iomanip>
using namespace std;

double fatorial(int n){
    double fat{ 1 };
    
    //n = 3| i = 1 2 3 |em cada um, x = 1 | x = 2 1 | x= 3 2 1
        for(int x{ n }; x > 0; x--){
            fat = fat * x;
        } 
    return fat;
}

double euler(int n){
    double soma{1};
    
    
    for(int i{ 1 }; i <= n ;i++){
        double fat = (1.000000/fatorial(i));
        soma = soma + fat;
        
    }
    return soma;
}

int main(){
    int n { 0 };

    cin >> n;
    cout << fixed << setprecision(6) << euler(n);
    return 0;
}
´´´
