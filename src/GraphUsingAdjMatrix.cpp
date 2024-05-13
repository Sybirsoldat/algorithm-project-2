#include "GraphUsingAdjMatrix.h"
#include <set>
#include <vector>
#include <climits>
#include <fstream> 
#include <iostream> 



GraphUsingAdjMatrix::GraphUsingAdjMatrix(int vertices) : numVertices(vertices) {
    adjMatrix.resize(vertices, std::vector<int>(vertices, INT_MAX));
    for (int i = 0; i < vertices; i++) 
        adjMatrix[i][i] = 0; // Zainicjowano przekątną macierzy
}

void GraphUsingAdjMatrix::addEdge(int u, int v, int w) {
    adjMatrix[u][v] = w; // Dodano wagę krawędzi
    adjMatrix[v][u] = w; // Dla grafu nieskierowanego
}

std::vector<int> GraphUsingAdjMatrix::dijkstra(int src) {
    std::vector<int> dist(numVertices, INT_MAX);
    
    dist[src] = 0; 
    std::set<std::pair<int, int>> queue; 
    queue.insert({0, src}); 

    while (!queue.empty()) {
        int u = queue.begin()->second; // Zmieniono pobieranie wierzchołka
        queue.erase(queue.begin()); 

        for (int v = 0; v < numVertices; ++v) {
            if (adjMatrix[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                queue.erase({dist[v], v}); 
                dist[v] = dist[u] + adjMatrix[u][v]; 
                queue.insert({dist[v], v}); 
            }
        }
    }
    return dist;
}

std::vector<std::vector<int>> GraphUsingAdjMatrix::getStructure() const {
    return adjMatrix; // Zwrócono macierz sąsiedztwa
}

void GraphUsingAdjMatrix::saveToFile(const std::string& filename) const {
    std::ofstream out(filename); // Zapisano do pliku
    if (!out) {
        std::cerr << "Cannot open file for writing: " << filename << std::endl; // Obsługa błędu
        return;
    }

    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (adjMatrix[i][j] == INT_MAX) {
                out << "INF "; //
            } else {
                out << adjMatrix[i][j] << " ";
            }
        }
        out << std::endl;
    }
    out.close();
}