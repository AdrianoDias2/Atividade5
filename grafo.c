#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void inicializaGrafoMatriz(GrafoMatriz* g, int n_vertices) {
    g->n_vertices = n_vertices;
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void inicializaGrafoLista(GrafoLista* g, int n_vertices) {
    g->n_vertices = n_vertices;
    for (int i = 0; i < n_vertices; i++) {
        g->adj[i] = NULL;
    }
}

void adicionaArestaLista(GrafoLista* g, int origem, int destino) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->vertice = destino;
    novoNo->prox = g->adj[origem];
    g->adj[origem] = novoNo;
}

void carregarGrafoMatrizAdjacencia(const char* arquivo, GrafoMatriz* gM) {
    FILE* fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int n_vertices;
    fscanf(fp, "%d", &n_vertices);  // Lê o número de vértices

    inicializaGrafoMatriz(gM, n_vertices);  // Inicializa a matriz de adjacência

    // Lê a matriz de adjacência do arquivo
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            fscanf(fp, "%d", &(gM->adj[i][j]));
        }
    }

    fclose(fp);
}

void BFS(GrafoLista* g, int vertice_inicial, int vertice_final) {
    bool visitado[MAX_VERTICES] = {false};
    int fila[MAX_VERTICES];
    int caminho[MAX_VERTICES];
    int frente = 0, traseira = 0;
    
    visitado[vertice_inicial] = true;
    fila[traseira++] = vertice_inicial;
    caminho[vertice_inicial] = -1;

    while (frente < traseira) {
        int vertice = fila[frente++];

        No* temp = g->adj[vertice];
        while (temp != NULL) {
            int adj = temp->vertice;
            if (!visitado[adj]) {
                visitado[adj] = true;
                caminho[adj] = vertice;
                fila[traseira++] = adj;
                if (adj == vertice_final) {
                    int atual = vertice_final;
                    printf("Caminho BFS: ");
                    while (atual != -1) {
                        printf("%d ", atual);
                        atual = caminho[atual];
                    }
                    printf("\n");
                    return;
                }
            }
            temp = temp->prox;
        }
    }
    printf("Nao ha caminho entre os vertices %d e %d\n", vertice_inicial, vertice_final);
}

void DFSIterativo(GrafoLista* g, int vertice_inicial) {
    bool visitado[MAX_VERTICES] = {false};
    int pilha[MAX_VERTICES];
    int topo = -1;
    
    pilha[++topo] = vertice_inicial;

    while (topo >= 0) {
        int vertice = pilha[topo--];

        if (!visitado[vertice]) {
            printf("%d ", vertice);
            visitado[vertice] = true;
        }

        No* temp = g->adj[vertice];
        while (temp != NULL) {
            int adj = temp->vertice;
            if (!visitado[adj]) {
                pilha[++topo] = adj;
            }
            temp = temp->prox;
        }
    }
    printf("\n");
}
