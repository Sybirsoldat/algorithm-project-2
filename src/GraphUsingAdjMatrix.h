#ifndef GRAPHUSINGADJMATRIX_H
#define GRAPHUSINGADJMATRIX_H

#include "Graph.h"
#include <vector>
#include <climits>
#include <fstream> // Dodano obsługę plików

class GraphUsingAdjMatrix : public Graph {
private:
    std::vector<std::vector<int>> adjMatrix; 
    int numVertices; // Dodano pole przechowujące liczbę wierzchołków

public:
    GraphUsingAdjMatrix(int vertices); 
    void addEdge(int u, int v, int w) override; // Dodano wagę krawędzi
    std::vector<int> dijkstra(int startVertex) override; // Zmieniono algorytm Dijkstry
    std::vector<std::vector<int>> getStructure() const; // Zmieniono zwracanie struktury grafu
    void saveToFile(const std::string& filename) const; // Dodano zapis do pliku
};

#endif // GRAPHUSINGADJMATRIX_H