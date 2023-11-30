#include "grafo.h"
#include <iostream>

#include <queue>
#include <vector>
#include <string>
#include <stack>

using namespace std;

Grafo::Grafo(int numVertices) : numVertices(numVertices)
{
    matrizAdjacencia.resize(numVertices, vector<int>(numVertices, 0));
}

bool Grafo::contemSubstring(const string &str1, const string &str2)
{
    return str1.find(str2) != string::npos;
}

void Grafo::gerarMatrizIncidencia()
{
    bool percorre_Matriz_Dist = false;
    qtdArestas = 0;

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (matrizAdjacencia[i][j] != 1 && matrizAdjacencia[i][j] != 0)
            {
                percorre_Matriz_Dist = true;
                percorre_matriz_distancia();
                exit(0);
            }
        }
    }

    if (percorre_Matriz_Dist == false)
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = i + 1; j < numVertices; j++)
            {
                if (matrizAdjacencia[i][j] == 1)
                {
                    string resultado1 = to_string(i);
                    string resultado2 = to_string(j);
                    vetor_arestas.push_back(resultado1 + resultado2);
                    qtdArestas++;
                }
            }
        }

        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < qtdArestas; j++)
            {
                string str_i = to_string(i);
                if (contemSubstring(vetor_arestas[j], str_i))
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
}
void Grafo::percorre_matriz_distancia()
{
    qtdArestas = 0;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (matrizAdjacencia[i][j] != 0 && matrizAdjacencia[i][j] != 999)
            {
                string resultado1 = to_string(i);
                string resultado2 = to_string(j);
                vetor_arestas.push_back(resultado1 + resultado2);
                qtdArestas++;
            }
        }
    }
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < qtdArestas; j++)
        {
            string str_i = to_string(i);
            if (contemSubstring(vetor_arestas[j], str_i))
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    cout << "Quantidade de Arestas: " << qtdArestas << ";" << endl;
    cout << "Quantidade de Vertices: " << numVertices << ";" << endl;
}
void Grafo::gerarTabelaIncidencia()
{
    qtdArestas = 0;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = i + 1; j < numVertices; j++)
        {
            if (matrizAdjacencia[i][j] == 1)
            {
                string resultado1 = to_string(i);
                string resultado2 = to_string(j);
                vetor_arestas.push_back(resultado1 + resultado2);
                qtdArestas++;
            }
        }
    }
    for (int i = 0; i < numVertices; i++)
    {
        cout << "No " << i << ": ";
        {
            for (int j = 0; j < qtdArestas; j++)
            {
                string str_i = to_string(i);

                if (contemSubstring(vetor_arestas[j], str_i))
                {
                    cout << vetor_arestas[j] << " ";
                }
            }
        }
        cout << endl;
    }
}

void Grafo::buscaEmLargura(vector<vector<int>> &graph, int startNode)
{

    vector<bool> visitado(numVertices, false);
    queue<int> q;

    visitado[startNode] = true;
    q.push(startNode);

    cout << "Resultado da busca em largura a partir do no " << startNode << ":\n";

    while (!q.empty())
    {
        int no_atual = q.front();
        cout << no_atual << " ";

        for (int i = 0; i < numVertices; i++)
        {

            if (!visitado[i] && graph[no_atual][i] == 1)
            {
                visitado[i] = true;
                q.push(i);
            }
        }
        q.pop();
    }
    std::cout << std::endl;
}

void Grafo::buscaEmProfundidade(vector<vector<int>> &graph, int startNode)
{
    stack<int> s;
    s.push(startNode);
    vector<bool> visitado(numVertices, false);
    visitado[startNode] = true;

    while (!s.empty())
    {
        int no_atual = s.top();
        cout << no_atual << " ";
        s.pop();

        for (int i = numVertices - 1; i >= 0; i--)
        {
            if (graph[no_atual][i] != 0 && !visitado[i])
            {
                visitado[i] = true;
                s.push(i);
            }
        }
    }
}