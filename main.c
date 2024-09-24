#include "grafo.h"
#include <stdio.h>

int main() {
    GrafoMatriz gMatriz;
    GrafoLista gLista;
    
    carregarGrafo("grafo.txt", &gMatriz, &gLista);

    printf("BFS entre vertices 0 e 3:\n");
    BFS(&gLista, 0, 3);

    printf("\nDFS iterativo a partir do vertice 0:\n");
    DFSIterativo(&gLista, 0);

    return 0;
}
