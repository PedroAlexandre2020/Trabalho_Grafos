#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>

using namespace std;

class Grafo
{
public:
    Grafo(int numVertices);
    void adicionarAresta(int origem, int destino);
    void gerarMatrizIncidencia();

    vector<vector<int>> matrizAdjacencia;
    vector<string> vetor_arestas;

    bool contemSubstring(const string &str1, const string &str2);
    void gerarTabelaIncidencia();
    void buscaEmLargura(vector<vector<int>> &graph, int startNode);
    void buscaEmProfundidade(vector<vector<int>> &graph, int startNode);
    void percorre_matriz_distancia();

private:
    int numVertices;
    int qtdArestas;
    vector<vector<int>> matrizIncidencia;
    vector<vector<int>> tabelaIncidencia;
};

#endif
