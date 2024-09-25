// main.c
#include <stdio.h>
#include <dirent.h>
#include "grafo.h"
#include <time.h>


void listarArquivos(char* caminho) {
    DIR* dir;
    struct dirent* ent;
    if ((dir = opendir(caminho)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) { // Filtra apenas arquivos regulares
                printf("%s\n", ent->d_name);
            }
        }
        closedir(dir);
    } else {
        perror("Erro ao abrir o diretorio");
    }
}

int main() {
    char caminho[100] = "instanciasGrafos";
    char arquivoEscolhido[128];
    int vertices = 6;
    GrafoLista* grafoLista = criarGrafoLista(vertices);
    GrafoMatriz* grafoMatriz = criarGrafoMatriz(vertices);
    printf("Escolha um arquivo de instância para carregar o grafo:\n");
    listarArquivos(caminho);
    printf("Digite o nome do arquivo: ");
    scanf("%s", arquivoEscolhido);
    char caminhoCompleto[200];
    sprintf(caminhoCompleto, "%s/%s", caminho, arquivoEscolhido);
    lerArquivoGrafo(caminhoCompleto, grafoLista, grafoMatriz);
    printf("Busca em Largura (caminho de 0 a 5):\n");
    buscaLargura(grafoLista, 0, 5);
    printf("Busca em Profundidade (a partir de 0):\n");
    buscaProfundidade(grafoLista, 0);

    
    return 0;
}
