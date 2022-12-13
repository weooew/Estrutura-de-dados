// Retorna o somatorio dos n primeiros inteiros positivos
int soma(int n) {
    if(n == 1) {  // Caso base ou caso de parada
        return 1;
    }
    else {
        return soma(n-1) + n;
    }
}

int main() {
    int vetor[] = {70,-1,0,9,7,5,6,10,20,30};
    int n = sizeof(vetor) / sizeof(int);
    cout << maximo1(0, n-1, vetor) << endl;
}
