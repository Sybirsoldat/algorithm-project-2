#include "GraphUsingAdjList.h"
#include <queue>
#include <vector>
#include <climits>
#include <fstream> 
#include <iostream> 

GraphUsingAdjList::GraphUsingAdjList(int vertices) : numVertices(vertices) {
    adjList.resize(vertices); // Zmieniono rozmiar listy sąsiedztwa
}

void GraphUsingAdjList::addEdge(int u, int v, int w) {
    adjList[u].push_back({v, w}); // Dodano wagę krawędzi
    adjList[v].push_back({u, w}); // Dla grafu nieskierowanego
}

std::vector<int> GraphUsingAdjList::dijkstra(int src) {
    std::vector<int> dist(numVertices, INT_MAX); // Zmieniono wartość początkową
    dist[src] = 0; // Zmieniono wartość początkową
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq; // Zmieniono kolejkę
    pq.push({0, src}); 

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop(); // Zmieniono pobieranie wierzchołka

        for (auto& i : adjList[u]) {
            int v = i.first; 
            int weight = i.second; 
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight; 
                pq.push({dist[v], v});
            }
        }
    }
    return dist; 
}

std::vector<std::vector<int>> GraphUsingAdjList::getStructure() const {
    std::vector<std::vector<int>> structure(numVertices, std::vector<int>(numVertices, INT_MAX)); 
    for (int i = 0; i < numVertices; ++i) {
        for (const auto& p : adjList[i]) {
            structure[i][p.first] = p.second;
        }
    }
    return structure;
}

void GraphUsingAdjList::saveToFile(const std::string& filename) const { 
   
    std::ofstream out(filename); 
    if (!out) {
        std::cerr << "Cannot open file for writing: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < numVertices; ++i) {
        out << i << " -> ";
        for (const auto& edge : adjList[i]) {
            out << "(" << edge.first << ", " << edge.second << ") ";
        }
        out << std::endl;
    }
    out.close();
}