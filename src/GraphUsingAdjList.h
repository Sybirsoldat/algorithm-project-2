#ifndef GRAPHUSINGADJLIST_H
#define GRAPHUSINGADJLIST_H

#include "Graph.h"
#include <list>
#include <utility>
#include <vector>
#include <fstream> 

class GraphUsingAdjList : public Graph {
private:
    std::vector<std::list<std::pair<int, int>>> adjList;
    int numVertices;

public:
    GraphUsingAdjList(int vertices); // Zmieniono konstruktor
    void addEdge(int u, int v, int w) override; // Dodano wagę krawędzi
    std::vector<int> dijkstra(int startVertex) override; // Zmieniono algorytm Dijkstry
    std::vector<std::vector<int>> getStructure() const; // Zmieniono zwracanie struktury grafu
    void saveToFile(const std::string& filename) const; //  Dodano zapis do pliku
};

#endif // GRAPHUSINGADJLIST_H