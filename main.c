#include "grafo.h"
#include <stdio.h>

int main() {
    GrafoMatriz gMatriz;

    // Carregar o grafo a partir do arquivo que contém a matriz de adjacência
    carregarGrafoMatrizAdjacencia("grafo.txt", &gMatriz);

    // Exemplo de como acessar e usar a matriz de adjacência
    printf("Matriz de adjacencia carregada:\n");
    for (int i = 0; i < gMatriz.n_vertices; i++) {
        for (int j = 0; j < gMatriz.n_vertices; j++) {
            printf("%d ", gMatriz.adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
