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
8. Fa¸ca um algoritmo que verifique se os elementos de um vetor est˜ao ordenados de
forma ascendente. Qual a complexidade de pior caso e melhor caso do seu algoritmo?
Justifique suas respostas.
---------------------------------------------------------
9. Para cada uma das afirma¸c˜oes abaixo, justifique formalmente (usando defini¸c˜oes,
manipula¸c˜oes alg´ebricas e implica¸c˜oes) se for verdade ou dˆe um contraexemplo se for
falso.
(a) 3n = O(n)
(b) 2n2 − n = O(n^2)
(c) log 8n = O(log 2n)
(d) 2n+1 = O(2^n)
(e) Se f (n) = 17, ent˜ao f (n) = O(1)
(f) Se f (n) = 3n2 − n + 4, ent˜ao f (n) = O(n^2)
---------------------------------------------------------
10. O que significa dizer que um algoritmo executa em tempo proporcional a n?
---------------------------------------------------------
11. Por muitas vezes damos aten¸c˜ao apenas `a an´alise do pior caso dos algoritmos. Ex-
plique o porquˆe.
---------------------------------------------------------
12. Qual algoritmo vocˆe prefere: um algoritmo que requer n5 passos ou um que requer
2^n passos? Justifique sua resposta.
---------------------------------------------------------
13. O que significa dizer que g(n) ´e O(f (n))?
---------------------------------------------------------
14. Seja V um vetor composto por n inteiros distintos. Escreva um algoritmo de com-
plexidade O(n^2) que ordene os elementos do vetor em ordem crescente. Prove que
seu algoritmo tem a complexidade exigida.
---------------------------------------------------------
15. Nos casos a seguir proponha g(n) e h(n) tal que f (n) = O(g(n)). Encontre tamb´em
constantes positivas m e c v´alidas conforme defini¸c˜oes:
(a) f(n) = 3n^2 + 2n
(b) f(n) = log2(n^2) + 11
(c) f(n) = nlog2(n + 1)
(d) f(n) = 3^(2n) + 5^n
---------------------------------------------------------
16. A sequencia de Fibonacci ´e uma sequˆencia de elementos f0, f1, . . . , fn, definida do
seguinte modo:

f(j) = j,                 se 0 <= n <= 1
f(j) =  f(j-1) + f(j-2),  se j > 1

Elaborar um algoritmo, n˜ao recursivo, para determinar o elemento fn da sequˆencia,
cuja complexidade seja linear em n e prove este fato.

---------------------------------------------------------
17. Considere a seguinte sequencia de elementos g1, . . . , gn para um dado valor de k:
g(j) = j-1,             se 1 <= j <= k
g(j) = g(j-1) + g(j-2), se j > k

Elaborar um algoritmo para determinar o elemento gn da sequencia, cuja complexi-
dade seja O(n).

---------------------------------------------------------
18. Determine a complexidade de pior caso dos algoritmos a seguir:

Algoritmo 3 Fun¸c˜ao F
1: Fun¸c˜ao F(int L[ ], int n)
2: s ← 0
3: para i ← 0 at´e n − 2 fa¸ca
4: para j ← i + 1 at´e n − 1 fa¸ca
5: if L[i] > L[j] then
6: s ← s + 1
7: fim if
8: fim para
9: fim para
10: retorne s
11: fim Fun¸c˜ao

Algoritmo 4 Fun¸c˜ao G
1: Fun¸c˜ao G(int n)
2: k ← 0
3: enquanto n > 0 fa¸ca
4: n ← n/2
5: k ← k + 1
6: fim enquanto
7: retorne k
8: fim Fun¸c˜ao

Algoritmo 5 Fun¸c˜ao H
1: Fun¸c˜ao H(int L[ ], int n)
2: if n > 1 then
3: x ← H(L, n − 1)
4: if x > L[n] then
5: retorne x
6: else
7: retorne L[n]
8: fim if
9: else if n == 1 then
10: retorne L[1]
11: fim if
12: fim Fun¸c˜ao

---------------------------------------------------------
19. Mostrar que o algoritmo da Torre de Hanoi, visto em sala, requer exatamente 2n − 1
movimentos de disco para terminar.
---------------------------------------------------------
20. onsidere a seguinte generaliza¸c˜ao do problema Torre de Han´oi. O problema agora
consiste em n discos de tamanhos distintos e quatro pinos, respectivamente, o de
origem, o de destino e dois pinos de trabalho (auxiliares). De resto, o problema ´e
como no caso de trˆes pinos. Isto ´e, de in´ıcio, os discos se encontram todos no pino
de origem, em ordem decrescente de tamanho, de baixo para cima. O objetivo ´e
empilhar todos os discos no pino-destino, satisfazendo `as condi¸c˜oes:

(i) apenas um disco pode ser movido de cada vez;
(ii) qualquer disco n˜ao pode ser jamais colocado sobre outro de tamanho menor.

Elaborar um algoritmo para resolver essa generaliza¸c˜ao. Determinar o n´umero de
movimentos de disco efetuados.
