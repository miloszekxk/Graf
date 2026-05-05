/**
 * @file main.cpp
 * @brief Plik glowny programu do analizy grafu.
 */

#include "graph.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    Params params;
    if (!parseArguments(argc, argv, params)) {
        std::cerr << "Zastosowanie: " << argv[0] << " -i plik_wejsciowy -o plik_wyjsciowy\n";
        return 1;
    }

    Graph graph;
    if (!readGraph(params.inputFile, graph)) {
        std::cerr << "Wystapil error podczas wczytywania grafu.\n";
        return 1;
    }

    if (!saveResult(params.outputFile, graph)) {
        std::cerr << "Wystapil error podczas zapisywania wynikow.\n";
        return 1;
    }

    return 0;
}
