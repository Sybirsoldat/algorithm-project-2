#include "GraphUsingAdjList.h"
#include "GraphUsingAdjMatrix.h"
#include "GraphTester.h"
#include <iostream>
#include <iomanip>

void printGraph(Graph& graph) {
    std::vector<std::vector<int>> data = graph.getStructure(); // Pobranie struktury grafu
    for (const auto& row : data) {
        for (int val : row) {
            if (val == INT_MAX) {
                std::cout << std::setw(5) << "INF"; 
            } else {
                std::cout << std::setw(5) << val; 
            }
        }
        std::cout << "\n";
    }
}

void performTests(bool displayGraph) {
    const int vertexCounts[5] = {10, 50, 100, 500, 1000}; // Liczba wierzchołków
    const int density[4] = {25, 50, 75, 100}; // Gęstość grafu

    for (int V : vertexCounts) {
        for (int D : density) {
            int E = (D * V * (V - 1)) / 200; // Liczba krawędzi dla danej gęstości (dla grafu nieskierowanego)

            std::cout << "Testing graph with " << V << " vertices and " << D << "% density.\n"; // Wyświetlenie informacji o grafie

            GraphUsingAdjList listGraph(V); // Graf na liście sąsiedztwa
            GraphUsingAdjMatrix matrixGraph(V); // Graf na macierzy sąsiedztwa

            // Generowanie grafów
            GraphTester::generateGraph(listGraph, V, E); // Generowanie grafu na liście sąsiedztwa
            GraphTester::generateGraph(matrixGraph, V, E); // Generowanie grafu na macierzy sąsiedztwa

            if (displayGraph) {
                std::cout << "Adjacency List:\n"; // Wyświetlenie listy sąsiedztwa
                printGraph(listGraph);
                std::cout << "Adjacency Matrix:\n"; // Wyświetlenie macierzy sąsiedztwa
                printGraph(matrixGraph);
            }

            std::cout << "Performance Testing Adjacency List:\n"; // Testowanie wydajności listy sąsiedztwa
            GraphTester::testPerformance(listGraph, V, E, 100); //  Wywołanie testu wydajności

            std::cout << "Performance Testing Adjacency Matrix:\n"; // Testowanie wydajności macierzy sąsiedztwa
            GraphTester::testPerformance(matrixGraph, V, E, 100); // Wywołanie testu wydajności
        }
    }
}

int main() {
    int option;

    std::cout << "Select an option:\n";
    std::cout << "1. Display Graph Structures and Test Performance\n";
    std::cout << "2. Test Performance Only\n";
    std::cin >> option;

    switch (option) {
        case 1:
            performTests(true); // Wyświetlenie grafów
            break;
        case 2:
            performTests(false); // Nie wyświetlanie grafów
            break;
        default:
            std::cout << "Invalid option selected.\n";
            break;
    }

    return 0;
}