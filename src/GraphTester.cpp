#include "GraphTester.h"
#include <random>
#include <iostream>
#include <fstream>
#include <chrono>
#include <climits>
#include <ostream> 

void GraphTester::generateGraph(Graph& graph, int V, int E) { 
    std::random_device rd; // Losowe ziarno
    std::mt19937 gen(rd()); // Generator liczb losowych
    std::uniform_int_distribution<> dist(0, V - 1); // Rozkład równomierny
    std::uniform_int_distribution<> weightDist(1, 100); // Rozkład równomierny

    for (int i = 0; i < E; ++i) {
        int u = dist(gen); // Losowy wierzchołek
        int v = dist(gen); // Losowy wierzchołek
        while (u == v) {  // Zapobiegamy pętlom
            v = dist(gen); 
        }
        int w = weightDist(gen); // Losowa waga
        graph.addEdge(u, v, w); // Dodajemy krawędź
    }
}

void GraphTester::testPerformance(Graph& graph, int V, int E, int iterations) {
    std::random_device rd; // Losowe ziarno
    std::mt19937 gen(rd()); // Generator liczb losowych
    std::uniform_int_distribution<> dist(0, V - 1); // Rozkład równomierny
    
    auto start = std::chrono::high_resolution_clock::now(); // Początek pomiaru czasu
    
    for (int i = 0; i < iterations; ++i) {
        int startVertex = dist(gen); // Losowy wierzchołek
        std::vector<int> distances = graph.dijkstra(startVertex); // Wywołanie algorytmu Dijkstry
    }

    auto end = std::chrono::high_resolution_clock::now(); // Koniec pomiaru czasu
    std::chrono::duration<double, std::milli> elapsed = end - start; // Obliczenie czasu trwania
    std::cout << "Elapsed time for " << iterations << " iterations: " << elapsed.count() << " ms\n"; // Wyświetlenie czasu trwania
}