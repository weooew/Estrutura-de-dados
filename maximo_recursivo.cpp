//Ao receber vetor e n >= 1, funcao devolve elemento com valor maximo 
#include <iostream>
using namespace std;

int maximo(int n, int v[]) {
	if (n == 1)
		return v[0];
	else {
		int max;
		max = maximo(n-1, v); // max eh o maximo de v[0..n-2]
		if (max > v[n-1])
			return max;
		else
			return v[n-1];
	}
}

int main () {
	int v[] = {34,35,36,37,38};
	int n = sizeof(v) / sizeof(int);
	cout << maximo(n, v) << endl;
	return 0;
}
