# Complexidade

1. algoritmo que testa se uma vetor de tamanho n estar ordenado. Depois determine a complexidade desse seu algoritmo em
relac¸˜ao ao melhor e pior caso

---------------------------------------------------------
2. Problema do Teto em um Vetor: Dado um vetor ordenado de tamanho n e um inteiro k, encontrar o teto de k dentro do vetor. O teto de
um n´umero k no vetor, ´e o menor n´umero do vetor que ´e maior ou igual k. Mostre um algoritmo Recursivo que resolve esse problema com
tempo O(log n) no pior caso.

---------------------------------------------------------
3. Considere o seguinte Algoritmo 1 que apresenta a fun¸c˜ao Soma-matrizes, que cal-
cula a matriz quadrada C de dimens˜ao n × n que ´e a soma de duas matrizes A e
B ambas de mesma dimens˜ao n × n. Determine a fun¸c˜ao f (n) que d´a o n´umero de
passos que esse algoritmo executa em fun¸c˜ao do parˆametro n. Qual a complexidade
deste algoritmo? Justifique a sua resposta?

Algoritmo 1 Soma de duas matrizes quadradas
1: Fun¸c˜ao Soma-Matrizes(int *A, int *B, int *C, int n)
2: para i ← 0 at´e n − 1 fa¸ca
3: para j ← 0 at´e n − 1 fa¸ca
4: C[i][j] ← A[i][j] + B[i][j]
5: end para
6: end para
7: Retorne C
8: end Fun¸c˜ao

---------------------------------------------------------
5. Considere o Algoritmo 2 que multiplica duas matrizes quadradas A e B. Determine
a fun¸c˜ao f (n) que d´a o n´umero de passos que esse algoritmo executa em fun¸c˜ao do
parˆametro n. Qual a complexidade deste algoritmo? Justifique a sua resposta?
Algoritmo 2 Multiplica¸c˜ao de duas matrizes quadradas
1: Fun¸c˜ao Multiplica-Matrizes(int *A, int *B, int *C, int n)
2: para i ← 0 at´e n − 1 fa¸ca
3: para j ← 0 at´e n − 1 fa¸ca
4: C[i][j] ← 0
5: para i ← 0 at´e n − 1 fa¸ca
6: C[i][j] ← C[i][j] + A[i][j] × B[i][j]
7: end para
8: end para
9: end para
10: Retorne C
11: end Fun¸c˜ao
---------------------------------------------------------
6. Sejam as fun¸c˜oes de complexidade a(n) = n2 − n + 549 e b(n) = 49n + 49 referentes
a certos algoritmos A e B, respectivamente. Para que valores de n ´e melhor aplicar
o Algoritmo A?

---------------------------------------------------------
7. O que ´e a complexidade de pior caso de uma algoritmo? E o que ´e a complexidade
de melhor caso? Qual a diferen¸ca entre elas?

---------------------------------------------------------



---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------


