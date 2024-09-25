#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"


// Funções para Grafo usando Lista de Adjacência
GrafoLista* criarGrafoLista(int vertices) {
    GrafoLista* grafo = (GrafoLista*) malloc(sizeof(GrafoLista));
    grafo->numVertices = vertices;
    grafo->listaAdj = (No**) malloc(vertices * sizeof(No*));
    for (int i = 0; i < vertices; i++)
        grafo->listaAdj[i] = NULL;
    return grafo;
}

No* criarNo(int vertice) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->vertice = vertice;
    novoNo->proximo = NULL;
    return novoNo;
}

void adicionarArestaLista(GrafoLista* grafo, int origem, int destino) {
    No* novoNo = criarNo(destino);
    novoNo->proximo = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novoNo;

    novoNo = criarNo(origem);
    novoNo->proximo = grafo->listaAdj[destino];
    grafo->listaAdj[destino] = novoNo;
}

// Funções para Grafo usando Matriz de Adjacência
GrafoMatriz* criarGrafoMatriz(int vertices) {
    GrafoMatriz* grafo = (GrafoMatriz*) malloc(sizeof(GrafoMatriz));
    grafo->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            grafo->matrizAdj[i][j] = 0;
    return grafo;
}

void adicionarArestaMatriz(GrafoMatriz* grafo, int origem, int destino) {
    grafo->matrizAdj[origem][destino] = 1;
    grafo->matrizAdj[destino][origem] = 1;
}


// Função otimizada de leitura de arquivos para matriz de adjacência ponderada
void lerArquivoGrafo(char* nomeArquivo, GrafoLista* grafoLista, GrafoMatriz* grafoMatriz) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    int vertices;
    fscanf(arquivo, "%d", &vertices);  // Lê o número de vértices
    grafoLista->numVertices = vertices;
    grafoMatriz->numVertices = vertices;

    // Inicializa a estrutura da matriz de adjacência e da lista de adjacência
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            int peso;
            fscanf(arquivo, "%d", &peso);  // Lê o peso da aresta entre i e j

            if (peso != 0) {  // Se houver uma conexão (peso diferente de 0)
                // Verificar se a aresta já foi adicionada em grafos não direcionados
                if (grafoMatriz->matrizAdj[i][j] == 0) {
                    adicionarArestaLista(grafoLista, i, j);  // Adiciona aresta na lista
                    adicionarArestaMatriz(grafoMatriz, i, j);  // Adiciona aresta na matriz
                }
            }
        }
    }

    fclose(arquivo);
}

// Função de Busca em Largura (BFS)
void buscaLargura(GrafoLista* grafo, int verticeInicial, int verticeFinal) {
    bool visitado[MAX_VERTICES] = {false};
    int fila[MAX_VERTICES], inicio = 0, fim = 0;
    int pai[MAX_VERTICES];

    for (int i = 0; i < grafo->numVertices; i++)
        pai[i] = -1;

    visitado[verticeInicial] = true;
    fila[fim++] = verticeInicial;

    while (inicio != fim) {
        int verticeAtual = fila[inicio++];
        
        if (verticeAtual == verticeFinal) {
            int caminho[MAX_VERTICES], count = 0;
            int percurso = verticeFinal;
            while (percurso != -1) {
                caminho[count++] = percurso;
                percurso = pai[percurso];
            }

            printf("Caminho: ");
            for (int i = count - 1; i >= 0; i--)
                printf("%d ", caminho[i]);
            printf("\n");
            return;
        }

        No* temp = grafo->listaAdj[verticeAtual];
        while (temp) {
            int verticeAdj = temp->vertice;

            if (!visitado[verticeAdj]) {
                visitado[verticeAdj] = true;
                pai[verticeAdj] = verticeAtual;
                fila[fim++] = verticeAdj;
            }
            temp = temp->proximo;
        }
    }

    printf("nao ha caminho entre os vertices.\n");
}

// Função de Busca em Profundidade (DFS) com Pilha
void buscaProfundidade(GrafoLista* grafo, int verticeInicial) {
    bool visitado[MAX_VERTICES] = {false};
    int pilha[MAX_VERTICES], topo = -1;

    pilha[++topo] = verticeInicial;

    while (topo != -1) {
        int verticeAtual = pilha[topo--];

        if (!visitado[verticeAtual]) {
            visitado[verticeAtual] = true;
            printf("%d ", verticeAtual);
        }

        No* temp = grafo->listaAdj[verticeAtual];
        while (temp) {
            int verticeAdj = temp->vertice;
            if (!visitado[verticeAdj])
                pilha[++topo] = verticeAdj;
            temp = temp->proximo;
        }
    }
    printf("\n");
}
