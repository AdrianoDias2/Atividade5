// grafo.h
#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 100

// Estrutura para Lista de Adjacência
typedef struct No {
    int vertice;
    struct No* proximo;
} No;

typedef struct GrafoLista {
    int numVertices;
    No** listaAdj;
} GrafoLista;

// Estrutura para Matriz de Adjacência
typedef struct GrafoMatriz {
    int numVertices;
    int matrizAdj[MAX_VERTICES][MAX_VERTICES];
} GrafoMatriz;

// Funções para Grafo usando Lista de Adjacência
GrafoLista* criarGrafoLista(int vertices);
No* criarNo(int vertice);
void adicionarArestaLista(GrafoLista* grafo, int origem, int destino);

// Funções para Grafo usando Matriz de Adjacência
GrafoMatriz* criarGrafoMatriz(int vertices);
void adicionarArestaMatriz(GrafoMatriz* grafo, int origem, int destino);

// Leitor de Arquivo
void lerArquivoGrafo(char* nomeArquivo, GrafoLista* grafoLista, GrafoMatriz* grafoMatriz);

// Funções de Busca
void buscaLargura(GrafoLista* grafo, int verticeInicial, int verticeFinal);
void buscaProfundidade(GrafoLista* grafo, int verticeInicial);

#endif
