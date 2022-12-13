//fatoral recursiva
#include <iostream>
#include <iomanip>
using namespace std;

unsigned long factorial( unsigned long number){
  if(number <= 1 )//testa caso básico
    return 1; // casos básicos: 0! = 1 e 1! = 1
  else//passo de recursão
    return number * factorial(number – 1);
}

int main(){
// calcula o fatorial de 0 a 10
for ( int counter = 0; counter <= 10; counter++ )
  cout << setw( 2 ) << counter << “! = “ << factorial( counter )<< endl;

  return 0; //terminação bem-sucedida
}
