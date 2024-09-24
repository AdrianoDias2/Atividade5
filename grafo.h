#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 100

// Estrutura para matriz de adjacência
typedef struct {
    int n_vertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
} GrafoMatriz;

// Estrutura para lista de adjacência
typedef struct No {
    int vertice;
    struct No* prox;
} No;

typedef struct {
    int n_vertices;
    No* lista[MAX_VERTICES];
} GrafoLista;

// Funções de inicialização
void inicializaGrafoMatriz(GrafoMatriz* g, int n_vertices);
void inicializaGrafoLista(GrafoLista* g, int n_vertices);

// Funções para adicionar arestas
void adicionaArestaMatriz(GrafoMatriz* g, int origem, int destino);
void adicionaArestaLista(GrafoLista* g, int origem, int destino);

// Funções de busca
void BFS(GrafoLista* g, int s, int t);
void DFSIterativo(GrafoLista* g, int s);

// Função de leitura de arquivo
void carregarGrafo(const char* arquivo, GrafoMatriz* gM, GrafoLista* gL);

#endif
