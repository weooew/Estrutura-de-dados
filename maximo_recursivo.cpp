//Ao receber vetor e n >= 1, funcao devolve elemento com valor maximo 
#include <iostream>
using namespace std;

int maximo(int n, int v[]) {
   if (n == 1)
      return v[0];
   else {
      int max;
      max = maximo(n-1, v);
	   
      if (max > v[n-1])
         return max;
      else
         return v[n-1];
//return (maior > v[n-1]) ? maior : v[n-1];
   }
}

int main () {
	int v[] = {34,35,36,37,38};
	int n = sizeof(v) / sizeof(int);
	cout << maximo(n, v) << endl;
	return 0;
}
/*ou 
int maximo1(int ini, int fim, int v[]) {
    if(ini == fim) {
        return v[ini];
    }
    else {
        int x = (ini + fim) / 2;
        int max1 = maximo1(ini, x, v);
        int max2 = maximo1(x+1, fim, v);
        return (max1 > max2) ? max1 : max2;
    }
}
*/
