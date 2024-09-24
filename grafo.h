#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 100

typedef struct {
    int n_vertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
} GrafoMatriz;

typedef struct No {
    int vertice;
    struct No* prox;
} No;

typedef struct {
    int n_vertices;
    No* adj[MAX_VERTICES];
} GrafoLista;

void inicializaGrafoMatriz(GrafoMatriz* g, int n_vertices);
void inicializaGrafoLista(GrafoLista* g, int n_vertices);
void adicionaArestaLista(GrafoLista* g, int origem, int destino);
void carregarGrafoMatrizAdjacencia(const char* arquivo, GrafoMatriz* gM);
void BFS(GrafoLista* g, int vertice_inicial, int vertice_final);
void DFSIterativo(GrafoLista* g, int vertice_inicial);

#endif
