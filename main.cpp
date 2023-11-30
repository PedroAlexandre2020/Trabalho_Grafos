#include "grafo.h"
#include <fstream>
#include <iostream>

int main()
{
    int numVertices;
    std::ifstream inputFile("grafo.txt");

    if (inputFile.is_open())
    {
        inputFile >> numVertices;
        Grafo grafo(numVertices);

        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                inputFile >> grafo.matrizAdjacencia[i][j];
            }
        }

        std::cout << "Matriz de Incidencia" << std::endl;
        grafo.gerarMatrizIncidencia();

        std::cout << std::endl;
        std::cout << "Tabela de Incidencia" << std::endl;
        grafo.gerarTabelaIncidencia();

        /*int noEntrada;
        std::cout << "Digite o no inicial para a busca em largura: ";
        std::cin >> noEntrada;
        grafo.buscaEmLargura(grafo.matrizAdjacencia, noEntrada);
        std::cout << std::endl;*/

        /*int noEntrada;
        std::cout << "Digite o no inicial para a busca em profundidade: ";
        std::cin >> noEntrada;

        cout << "Resultado da busca em profundidade a partir do no " << noEntrada << ":\n";
        grafo.buscaEmProfundidade(grafo.matrizAdjacencia, noEntrada);*/

        inputFile.close();
    }
    else
    {
        std::cout << "Erro ao abrir o arquivo grafo.txt." << std::endl;
    }

    return 0;
}
