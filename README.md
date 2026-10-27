# Analizator Dwudzielności Grafu (Bipartite Graph Analyzer)

**🎓 Projekt akademicki przygotowany w ramach zaliczenia przedmiotu na studiach.**

Kompleksowe narzędzie analityczne napisane w języku C++. Służy do parsowania nieskierowanych grafów z plików tekstowych, budowania ich reprezentacji w pamięci za pomocą zoptymalizowanych list sąsiedztwa oraz matematycznej weryfikacji ich dwudzielności przy użyciu algorytmu Przeszukiwania Wszerz (Breadth-First Search - BFS).

---

## 📑 Spis Treści
- [Analizator Dwudzielności Grafu (Bipartite Graph Analyzer)](#analizator-dwudzielności-grafu-bipartite-graph-analyzer)
  - [📑 Spis Treści](#-spis-treści)
  - [✨ Funkcjonalności](#-funkcjonalności)
  - [🧠 Zastosowana Logika i Teoria (Matematyczna)](#-zastosowana-logika-i-teoria-matematyczna)
  - [🚀 Instrukcja Kompilacji i Uruchomienia](#-instrukcja-kompilacji-i-uruchomienia)
    - [Kompilacja](#kompilacja)
    - [Plik wejściowy](#plik-wejściowy)
    - [Uruchomienie](#uruchomienie)
    - [Przykładowy wynik (`wyjscie.txt`)](#przykładowy-wynik-wyjscietxt)
  - [📄 Licencja](#-licencja)

---

## ✨ Funkcjonalności

* **Rozpoznawanie dowolnych wierzchołków:** Program radzi sobie z wierzchołkami oznaczonymi dowolnymi liczbami (nie muszą być to wartości ciągłe, np. `1`, `15`, `999`).
* **Automatyczne tworzenie list sąsiedztwa:** Generuje i zapisuje do pliku pełną, czytelną listę połączeń dla każdego wierzchołka w grafie.
* **Detekcja cykli i badanie dwudzielności:** Weryfikuje, czy graf spełnia matematyczne założenia grafu dwudzielnego (brak cykli o nieparzystej długości).
* **Segmentacja wierzchołków:** W przypadku pozytywnej weryfikacji, precyzyjnie dzieli wszystkie wierzchołki na dwa całkowicie rozłączne zbiory.
* **Interfejs wiersza poleceń (CLI):** Bezobsługowe działanie po podaniu odpowiednich flag (`-i`, `-o`).

---

## 🧠 Zastosowana Logika i Teoria (Matematyczna)

Z matematycznego punktu widzenia graf jest dwudzielny (bipartite) wtedy i tylko wtedy, gdy **nie zawiera cykli o nieparzystej długości** (np. trójkątów, pięciokątów). Oznacza to, że jego wierzchołki można podzielić na dwa zbiory w taki sposób, aby żadne dwa wierzchołki w tym samym zbiorze nie były połączone krawędzią.

**Jak działa algorytm w tym programie?**
1. **Translacja (Mapowanie):** Z racji, że identyfikatory wierzchołków podane przez użytkownika mogą być nieregularne, struktura `std::unordered_map` przypisuje im kolejne indeksy wewnętrzne (0, 1, 2...). To pozwala na błyskawiczne zarządzanie pamięcią w wektorach reprezentujących listę sąsiedztwa.
2. **Kolorowanie BFS:** Funkcja `checkBFS` implementuje algorytm przeszukiwania wszerz. Zaczyna od dowolnego wierzchołka, przypisuje mu "kolor" (np. 0), a następnie każdemu jego sąsiadowi przypisuje kolor przeciwny (1).
3. **Detekcja kolizji:** Jeśli w trakcie propagacji BFS program natrafi na sąsiada, który został już odwiedzony i ma **ten sam kolor** co aktualny wierzchołek, oznacza to zamknięcie cyklu o nieparzystej długości. Weryfikacja natychmiast zwraca `false` (graf nie jest dwudzielny).

---

## 🚀 Instrukcja Kompilacji i Uruchomienia

### Kompilacja

**g++ (Linux / Windows z MinGW):**

```bash
g++ -Wall -Wextra -std=c++17 main.cpp graph.cpp -o graf
```

**Visual Studio:** otwórz `Graf.slnx` i zbuduj projekt (`Ctrl+Shift+B`). Plik `Graf.exe` pojawi się w folderze `x64/Debug`.

### Plik wejściowy

Każda linia to jedna krawędź grafu nieskierowanego - dwa numery wierzchołków oddzielone spacją:

```text
1 2
2 3
3 4
4 1
```

Gotowe przykłady znajdziesz w folderze [`przyklady/`](przyklady).

### Uruchomienie

```bash
./graf -i przyklady/dwudzielny.txt -o wyjscie.txt
```

W systemie Windows: `Graf.exe -i wejscie.txt -o wyjscie.txt`.

### Przykładowy wynik (`wyjscie.txt`)

```text
Lista sasiedztwa grafu:
1: 2 4
2: 1 3
3: 2 4
4: 3 1
Graf jest dwudzielny.
Zbior 1: 1 3
Zbior 2: 2 4
```

## 📄 Licencja

Projekt został stworzony w celach edukacyjnych jako zadanie na zaliczenie przedmiotu.
Kod udostępniony na licencji [MIT](LICENSE) - możesz go swobodnie wykorzystywać, modyfikować i traktować jako materiał do nauki.
