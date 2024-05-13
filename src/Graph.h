#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph { // Dodano klasę bazową
public:
    virtual void addEdge(int u, int v, int w) = 0; // Dodano wagi krawędzi
    virtual std::vector<int> dijkstra(int startVertex) = 0; //  Dodano algorytm Dijkstry
    virtual std::vector<std::vector<int>> getStructure() const = 0; // Dodano zwracanie struktury grafu
    virtual ~Graph() {} // Dodano destruktor wirtualny
};

#endif // GRAPH_H