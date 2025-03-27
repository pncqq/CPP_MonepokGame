# 🎮 CPP_MonepokGame

Konsolowa gra RPG inspirowana uniwersum Pokémon, napisana w C++. Gracz wybiera 6 stworzeń z puli losowo generowanych potworków i prowadzi je do zwycięstwa w serii starć.

## 📂 Zawartość repozytorium

- `Main.cpp` – wejście do gry, obsługa pętli głównej
- `Arena.*` – logika walki i przebiegu rund
- `Monepoke.*` – klasa bazowa stworzeń (statystyki, ataki, ewolucja)
- `Skill*.cpp/hpp` – różne typy umiejętności: ofensywne, defensywne, paraliżujące, buffujące
- `DifficultyChanger.*` – zmiana poziomu trudności
- `SaveReadFromFile.*` – zapisywanie i wczytywanie stanu gry
- `Functions.*`, `Variables.*` – narzędzia pomocnicze i stałe
- `CMakeLists.txt` – konfiguracja budowania projektu

## ⚙️ Technologie

- C++
- Programowanie obiektowe
- CMake

## 🌟 Główne mechaniki gry

- Wybór 6 stworzeń spośród losowo wygenerowanych
- Walka turowa: możliwość ataku, użycia skilla, zmiany stworzenia, ewolucji
- Typy stworzeń (np. Fire, Water, Ice) mają wpływ na efektywność ataków
- Ewolucja: wybór 2 atrybutów do zwiększenia
- Zarządzanie HP, EXP, statusami

## ▶️ Jak uruchomić

1. Sklonuj repozytorium:
```bash
git clone https://github.com/pncqq/CPP_MonepokGame.git
cd CPP_MonepokGame
```

2. Zbuduj projekt z użyciem CMake:
```bash
mkdir build
cd build
cmake ..
make
```

3. Uruchom grę:
```bash
./MonepokGame
```

## 👨‍💼 Autor
**Filip Michalski**  
Projekt zrealizowany w ramach kursu z C++. Pokazuje zaawansowaną organizację kodu, podejście obiektowe oraz obsługę rozgrywki w stylu klasycznych gier RPG.
