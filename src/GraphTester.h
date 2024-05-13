#ifndef GRAPH_TESTER_H
#define GRAPH_TESTER_H

#include "Graph.h"
#include <chrono>
#include <random>

class GraphTester {
public:
    static void testPerformance(Graph& graph, int V, int E, int iterations); // Test wydajności
    static void generateGraph(Graph& graph, int V, int E); // Generowanie grafu
};

#endif // GRAPH_TESTER_H