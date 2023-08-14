Faça um teste de performance dos algoritmos de ordenação vistos em sala de aula: Bouble-sort, Select-sort, Insert-sort, Merge-sort, Merge-sort V2 e Quick-sort.

Para isso, gere 10 vetores aleatoriamente de tamanhos {1.000, 5.000, 10.000, 50.000, 100.000, 200.000, 300.000, 500.000, 800.000, 1.000.000}.

Execute os 6 algoritmos de ordenação nesses 10 vetores armazenando o tempo computacional em segundos que cada algoritmo precisou para ordenar. Para cada algoritmo, calcule a média dos tempos.

Os 10 vetores devem ser os mesmos para cada algoritmo, e como o algoritmo modifica o vetor, tome o cuidado de fazer cópias dos vetores.

Gere uma tabela com os resultados do teste de performance, contendo as médias dos tempos para cada algoritmo de ordenação. Coloque como comentário em seu código. 
Repetindo no pior caso

Quase todos os algoritmos de ordenação, o pior caso ocorre quando o vetor se encontra ordenado. Repita o teste anterior usando os vetores ordenados.

Para isso, basta no for que gera o vetor, ao invés de usar a função ranValor, fazer:

for(int i = 0; i < n; i++) vet[i] = i;
Gerando números aleatórios

Um gerador de números pseudoaleatórios (PRNG - Pseudo Random Number Generator) é um algoritmo que gera uma sequência de valores aparentemente aleatórios. A sequência de números gerada por um PRNG não é realmente aleatória, porque pode ser reproduzida caso seja usado o mesmo valor inicial, usualmente chamado de "semente" (seed). 

Diversas linguagem possuem bibliotecas que geram números pseudo-aleatórios. Nos códigos abaixo, temos funções que geram números pseudo-aleatórios dentro de um intervalo:
Linguagem C/C++

#include <stdio.h>
#include <stdlib.h>

int randValor(int linf, int lsup){
   #ifdef __linux__
          return(linf + (lrand48() % (lsup - linf + 1)));
   #elif _WIN32
          return (linf + (rand() % (lsup - linf + 1)));
   #else
         #error "OS not supported!"
   #endif
}
Linguagem Java

import java.util.Random;
class Rand {
     public static int randValor(int linf, int lsup){
         Random r = new Random();
         return linf + (r.nextInt(lsup) % (lsup - linf + 1));
     }
}
Linguagem Python

import random
def randValor(linf, lsup):
      return random.randint(linf, lsup)

Computando o tempo em segundos de um programa

Pesquise na internet!!!!!!!!!!!!!!!
