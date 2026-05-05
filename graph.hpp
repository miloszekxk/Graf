/**
 * @file graph.hpp
 * @brief Struktury i funkcje.
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <string>
#include <vector>
#include <list>
#include <unordered_map>

 /**
  * @struct Params
  * @brief Struktura zawierajaca parametry wejscia i wyjscia.
  */
struct Params {
    std::string inputFile;  ///< Sciezka do pliku wejsciowego
    std::string outputFile; ///< Sciezka do pliku wyjsciowego
};

/**
 * @struct Graph
 * @brief Struktura przechowujaca graf nieskierowany.
 */
struct Graph {
    std::unordered_map<int, int> mapToInternal; ///< Mapowanie oryginalnych wierzcholkow na indexy wewnetrzne
    std::vector<int> mapToOriginal;             ///< Mapowanie indexsow wewnetrznych na oryginalne wierzcholki
    std::vector<std::list<int>> adjList;        ///< Lista sasiedztwa 
};

/**
 * @brief Parsuje argumenty wejsciowe programu.
 * @param argc Liczba argumentow
 * @param argv Tablica argumentow
 * @param params Struktura do przechowywania przetworzonych argumentow
 * @return true jesli argumenty sa poprawne, false w przeciwnym wypadku
 */
bool parseArguments(int argc, char* argv[], Params& params);

/**
 * @brief Wczytuje graf z pliku wejsciowego.
 * @param inputFile Sciezka pliku wejsciowego
 * @param graph Struktura przechowujaca wczytany graf
 * @return true jesli wczytywanie powiodlo sie, false ,gdy wystapil blad
 */
bool readGraph(const std::string& inputFile, Graph& graph);

/**
 * @brief Zapisuje wyniki do pliku wyjsciowego.
 * @param outputFile Sciezka do pliku wyjsciowego
 * @param graph Struktura zawierajaca graf
 * @return true jesli zapis powiodl sie, false w przypadku bledu
 */
bool saveResult(const std::string& outputFile, const Graph& graph);

/**
 * @brief Sprawdza dwudzielnosc grafu, za pomoca algorytmu BFS.
 * @param graph Graf,ktory trzeba sprawdzic
 * @param set1 Pierwszy zbior wierzcholkow
 * @param set2 Drugi zbior wierzcholkow
 * @return true jesli graf jest dwudzielny, false w przeciwnym razie
 */
bool checkBFS(const Graph& graph, std::vector<int>& set1, std::vector<int>& set2);

/**
 * @brief Dodaje wierzcholek do grafu, jesli jeszcze nie istnieje.
 * @param graph Graf, do ktorego dodawany jest wierzcholek
 * @param vertex Wierzcholek,ktory nalezy dodac
 * @param internalIndex Licznik indexow wewnetrznych
 */
void addUV(Graph& graph, int vertex, int& internalIndex);

#endif // GRAPH_HPP
