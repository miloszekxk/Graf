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
    - [Krok 1: Znajdź gotowy program](#krok-1-znajdź-gotowy-program)
    - [Krok 2: Przygotuj plik wejściowy](#krok-2-przygotuj-plik-wejściowy)
    - [Krok 3: Otwórz CMD bezpośrednio tutaj](#krok-3-otwórz-cmd-bezpośrednio-tutaj)
    - [Krok 4: Uruchom program](#krok-4-uruchom-program)
    - [Gotowe! W tym samym folderze pojawi się plik wyjscie.txt z gotowym wynikiem.](#gotowe-w-tym-samym-folderze-pojawi-się-plik-wyjscietxt-z-gotowym-wynikiem)
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
### Krok 1: Znajdź gotowy program
1. Otwórz folder swojego projektu w systemie Windows.
2. Wejdź do folderu o nazwie **`x64`**, a następnie do folderu **`Debug`**.
3. Powinieneś tam znaleźć plik z ikonką aplikacji (np. `Graf.exe`).

### Krok 2: Przygotuj plik wejściowy
Upewnij się, że w tym samym folderze (w którym jesteś teraz, czyli `Debug`) znajduje się Twój plik z danymi, np. **`wejscie.txt`**. Jeśli go tam nie ma – przeklej go tam.

### Krok 3: Otwórz CMD bezpośrednio tutaj
1. Będąc w folderze `Debug`, kliknij myszką w puste miejsce na **pasku adresu** na samej górze okna Windows (tam, gdzie wyświetla się ścieżka do folderu).
2. Skasuj to, co tam jest, wpisz po prostu słowo **`cmd`** i wciśnij **Enter**.
3. Od razu otworzy się czarne okno konsoli, ustawione idealnie w Twoim folderze.

### Krok 4: Uruchom program
W czarnym oknie wpisz poniższą komendę i wciśnij Enter:

```cmd
Graf.exe -i wejscie.txt -o wyjscie.txt
```

### Gotowe! W tym samym folderze pojawi się plik wyjscie.txt z gotowym wynikiem.

## 📄 Licencja

Projekt został stworzony w celach edukacyjnych jako zadanie na zaliczenie przedmiotu. 
Kod jest udostępniony publicznie – możesz z niego swobodnie korzystać, modyfikować go i traktować jako materiał do nauki.