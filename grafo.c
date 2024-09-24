#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include <limits.h>

void inicializaGrafoMatriz(GrafoMatriz* g, int n_vertices) {
    g->n_vertices = n_vertices;
    for (int i = 0; i < n_vertices; i++)
        for (int j = 0; j < n_vertices; j++)
            g->adj[i][j] = 0;
}

void inicializaGrafoLista(GrafoLista* g, int n_vertices) {
    g->n_vertices = n_vertices;
    for (int i = 0; i < n_vertices; i++)
        g->lista[i] = NULL;
}

void adicionaArestaMatriz(GrafoMatriz* g, int origem, int destino) {
    g->adj[origem][destino] = 1;
    g->adj[destino][origem] = 1; // Para grafos não direcionados
}

void adicionaArestaLista(GrafoLista* g, int origem, int destino) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->vertice = destino;
    novoNo->prox = g->lista[origem];
    g->lista[origem] = novoNo;

    novoNo = (No*)malloc(sizeof(No));
    novoNo->vertice = origem;
    novoNo->prox = g->lista[destino];
    g->lista[destino] = novoNo;
}

void carregarGrafo(const char* arquivo, GrafoMatriz* gM, GrafoLista* gL) {
    FILE* fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int n_vertices, origem, destino;
    fscanf(fp, "%d", &n_vertices);

    inicializaGrafoMatriz(gM, n_vertices);
    inicializaGrafoLista(gL, n_vertices);

    while (fscanf(fp, "%d %d", &origem, &destino) != EOF) {
        adicionaArestaMatriz(gM, origem, destino);
        adicionaArestaLista(gL, origem, destino);
    }

    fclose(fp);
}

void BFS(GrafoLista* g, int s, int t) {
    int visitado[MAX_VERTICES] = {0};
    int distancia[MAX_VERTICES], predecessores[MAX_VERTICES];
    for (int i = 0; i < g->n_vertices; i++) {
        distancia[i] = INT_MAX;
        predecessores[i] = -1;
    }
    
    int fila[MAX_VERTICES], inicio = 0, fim = 0;
    fila[fim++] = s;
    visitado[s] = 1;
    distancia[s] = 0;

    while (inicio < fim) {
        int v = fila[inicio++];
        No* adj = g->lista[v];

        while (adj) {
            int u = adj->vertice;
            if (!visitado[u]) {
                visitado[u] = 1;
                distancia[u] = distancia[v] + 1;
                predecessores[u] = v;
                fila[fim++] = u;

                if (u == t) {
                    printf("Caminho: ");
                    int temp = t;
                    while (temp != -1) {
                        printf("%d ", temp);
                        temp = predecessores[temp];
                    }
                    printf("\n");
                    return;
                }
            }
            adj = adj->prox;
        }
    }
    printf("Nao ha caminho entre %d e %d\n", s, t);
}

void DFSIterativo(GrafoLista* g, int s) {
    int visitado[MAX_VERTICES] = {0};
    int pilha[MAX_VERTICES], topo = -1;

    pilha[++topo] = s;

    while (topo >= 0) {
        int v = pilha[topo--];
        if (!visitado[v]) {
            visitado[v] = 1;
            printf("%d ", v);
        }

        No* adj = g->lista[v];
        while (adj) {
            if (!visitado[adj->vertice]) {
                pilha[++topo] = adj->vertice;
            }
            adj = adj->prox;
        }
    }
    printf("\n");
}
