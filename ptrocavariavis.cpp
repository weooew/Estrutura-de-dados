
/*implemente a função 'troca' (recebe como parâmetro duas variáveis 
inteiras e trocar os valores destas variáveis)*/

#include <iostream>

// Implemente a função 'troca'.
void troca(int *x, int *y)
{
    int a = *x;
    *x = *y;
    *y = a;
}

int main()
{
   int x, y;
   std::cin >> x;
   std::cin >> y;
   
   // Chame a função 'troca' para trocar os valores de x e y.
    troca(&x, &y);
   
   std::cout << x << " " << y << std::endl;
   return 0;
}
