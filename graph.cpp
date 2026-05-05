/**
 * @file graph.cpp
 * @brief Implementacja funkcji, ktore obsluguja graf.
 */



#include "graph.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>

void addUV(Graph& graph, int vertex, int& internalIndex) {

    if (graph.mapToInternal.find(vertex) == graph.mapToInternal.end()) {
        graph.mapToInternal[vertex] = internalIndex++;
        graph.mapToOriginal.push_back(vertex);
        graph.adjList.emplace_back();
    }
}

bool parseArguments(int argc, char* argv[], Params& params) {
    if (argc != 5) {
        return false;
    }
    for (int i = 1; i < argc; i += 2) {
        if (std::string(argv[i]) == "-i") {
            params.inputFile = argv[i + 1];
        }
        else if (std::string(argv[i]) == "-o") {
            params.outputFile = argv[i + 1];
        }
        else {
            return false;
        }
    }
    return true;
}

bool readGraph(const std::string& inputFile, Graph& graph) {
    std::ifstream inFile(inputFile);
    if (!inFile) {
        std::cerr << "Nie mozna otworzyc pliku wejsciowego: " << inputFile << "\n";
        return false;
    }

    std::string line;
    int internalIndex = 0;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        int u, v;
        if (!(iss >> u >> v)) {
            continue;
        }

        addUV(graph, u, internalIndex);
        addUV(graph, v, internalIndex);

        graph.adjList[graph.mapToInternal[u]].push_back(graph.mapToInternal[v]);
        graph.adjList[graph.mapToInternal[v]].push_back(graph.mapToInternal[u]);
    }
    return true;
}

bool saveResult(const std::string& outputFile, const Graph& graph) {
    std::ofstream outFile(outputFile);
    if (!outFile) {
        std::cerr << "Nie mozna otworzyc pliku wyjsciowego: " << outputFile << "\n";
        return false;
    }

    outFile << "Lista sasiedztwa grafu:\n";
    for (size_t i = 0; i < graph.adjList.size(); ++i) {
        outFile << graph.mapToOriginal[i] << ":";
        for (int neighbor : graph.adjList[i]) {
            outFile << " " << graph.mapToOriginal[neighbor];
        }
        outFile << "\n";
    }

    std::vector<int> set1, set2;
    if (checkBFS(graph, set1, set2)) {
        outFile << "Graf jest dwudzielny.\n";
        outFile << "Zbior 1: ";
        for (int v : set1) {
            outFile << v << " ";
        }
        outFile << "\nZbior 2: ";
        for (int v : set2) {
            outFile << v << " ";
        }
        outFile << "\n";
    }
    else {
        outFile << "Graf nie jest dwudzielny.\n";
    }
    return true;
}

bool checkBFS(const Graph& graph, std::vector<int>& set1, std::vector<int>& set2) {
    std::vector<int> color(graph.adjList.size(), -1);
    std::queue<int> q;

    for (size_t start = 0; start < graph.adjList.size(); ++start) {
        if (color[start] != -1) continue;

        color[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int neighbor : graph.adjList[u]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[u];
                    q.push(neighbor);
                }
                else if (color[neighbor] == color[u]) {
                    return false;
                }
            }
        }
    }

    for (size_t i = 0; i < color.size(); ++i) {
        if (color[i] == 0) {
            set1.push_back(graph.mapToOriginal[i]);
        }
        else if (color[i] == 1) {
            set2.push_back(graph.mapToOriginal[i]);
        }
    }
    return true;
}
