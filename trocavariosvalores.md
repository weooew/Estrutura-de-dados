Implemente a função 'converte_tempo', que recebe o tempo em segundos e retorna em 3 variáveis passadas por referência este tempo convertido em horas, minutos e segundos.
O arquivo de envio já terá parte do código preenchido. Você deverá:

```cpp
#include <iostream>

// Recebe tempo em 'segundos', converte para horas, minutos e seguntos, e 
// retorna o resultado através dos parâmetros 'hor', 'min' e 'seg'.
void converte_tempo(int segundos, int *hor, int *min, int *seg)
{
    
}

int main()
{
   int tempo, h, m, s;
   std::cin >> tempo;
   
   // Chame a função 'converte_tempo' para converter o valor de 'tempo' em horas
   // minutos e segundos, gravando o resultado nas variáveis 'h', 'm' e 's'.
   
   std::cout << h << ":" << m << ":" << s;
   
   return 0;
}

