## BUSCA EM GRAFOS
### Busca Largura
com grafo G = (V,E) e vértice fonte/origem s (começar busca daqui)
irá percorrer as arestas de G descobrindo todos os vértices que podem ser alcançados a partir de s
caminho obtido pela BFS será o menor (n° de arestas) de s até cada vértice que pode ser alcançado
começa-> descobre todos vertices dist 1 -> descobre todos vertices dist 2 -> descobre todos vertices dist 3...

cores p/ classificar os vertices (branco: ñ descoberto, cinza: já descobertos com seus vizinhos não descobertos, preto: vertice descoberto com vizinhança examinada)
fila Q mantem vértices cinzas (mantém ordem de descoberta e de onde ele foi descoberto [pai])
cada vertice u terá 3 atributos:
  u.cor:  representa a cor do v´ertice durante a execu¸c˜ao da busca
  u.π: representa o pai do v´ertice, ou seja, armazena o v´ertice por onde u foi descoberto na busca
  u.d: armazena a distˆancia da origem s ao v´ertice u
```

```

### Busca de Profundidade
