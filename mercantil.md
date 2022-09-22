´´´
#include <iostream>
using namespace std;
int main(){
    int quant_prod { 0 }, win1{ 0 }, win2 { 0 };
    
    //recebe quant de produtos
    cin >> quant_prod;
    
    //recebe preco, chute e seg 
    float preco[quant_prod];
    float chute[quant_prod];
    char seg [quant_prod];
    
    for(int w { 0 }; w < quant_prod; w++){
        cin >> preco[w];
    }
    for(int w { 0 }; w < quant_prod; w++){
        cin >> chute[w];
    }
    for(int w { 0 }; w < quant_prod; w++){
        cin >> seg[w];
    }
    
    //how_many_wins 
    for(int i { 0 }; i < quant_prod; i++){
        //1°: chute = preço ou error
        /*if(chute[i] == preco[i]){
            win1 = win1 + 1;
            cout << "==";
        }
        if((preco[i] < chute[i]) && (seg[i]=='M')){
            win1 = win1 + 1;
            cout << "++";
        }
        if((preco[i] > chute[i]) && (seg[i]=='m')){
            win1 = win1 + 1;
            cout << "--";
        }*/
        //2°: acertou
        if((preco[i] < chute[i] && seg[i]=='m')||(preco[i] > chute[i] && seg[i]=='M')){
            win2 = win2 + 1;
            //cout << "+-";
        }
        else{
            win1 = win1 + 1;
        }
    }
    
    if (win1 > win2){
        cout << "primeiro";}
    else if (win1 == win2){
        cout << "empate";}
    else{
        cout << "segundo";}
    
    return 0;
}
´´´
