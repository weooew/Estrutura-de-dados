### Motivação: 
O objetivo do jogo das torres de hanoi é mover todos os discos da torre inicial para a torre final, sem colocar disco maior sobre disco menor. Inicialmente, a torre final e a torre auxiliar estão vazias. Você pode usar a torre auxiliar para lhe ajudar a mover os discos.
```
            ++                  ++                 ++
            ||                  ||                 ||
            ||                  ||                 ||
            ||                  ||                 ||
            ||                  ||                 ||
          +-++-+                ||                 ||
          |    |                ||                 ||
        +-+----+-+              ||                 ||
        |        |              ||                 ||
      +-+--------+-+            ||                 ||
      |            |            ||                 ||
      +------------+            ++                 ++
      Torre inicial        Torre auxiliar      Torre final
            A                   B                  C
Soluções> A-> C
A -> B 

C -> B 

A -> C 

B -> A 

B -> C 

A -> C
```
Este problema parece difícil de resolver para o caso geral com n discos. Porém, como acontece em vários problemas, utilizando recursão chegamos em um algoritmo simples e elegante. Mova recursivamente os n−1 primeiros discos para a torre auxiliar, depois mova o último disco da torre inicial para a torre final, e então mova recursivamente os n−1 discos da torre auxiliar para a torre final.

### Entrada:
Número de discos para mover da torre 'A' para a torre 'C'.
### Saída
Sequência de movimentos para mover todos os discos (um movimento por linha).
Notação do movimento do disco no topo da torre:
torre de origem -> torre de destino.
```
<!-- exemplo -->
>> 
3
<<
A -> C
A -> B
C -> B
A -> C
B -> A
B -> C
A -> C
```

```cpp
#include <iostream>

using namespace std;

/*
Imprime os passos para solução da Torre de Hanoi.
Entrada:
- qte: números de discos que devem ser movidos da torre inicial para a torre final
- ini: torre que é considerada como torre inicial
- aux: torre que é considerada como torre auxiliar
- fim: torre que é considerada como torre final
Pseudocódigo:
   se existe apenas 1 disco para mover
      mova este único disco da torre inicial para a torre final
   senão
      recursivamente mova qte-1 discos da torre inicial para a torre auxiliar
      mova o disco que sobrou da torre inicial para a torre final
      recursivamente mova qte-1 discos da torre auxiliar para a torre final
*/
void hanoi(int qte, char ini, char aux, char fim)
{
   // fazer
}

int main()
{
   int qte;
   cin >> qte;
   hanoi(qte, 'A', 'B', 'C');
   return 0;
}
```
