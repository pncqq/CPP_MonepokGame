#include "DifficultyChanger.hpp"


/**
 * Stopnie trudności:\n
 * 1. Normalny - bez zmian\n
 * 2. Trudny - Lepsze statystyki przeciwnika, wiecej przeciwnikow w druzynie\n
 * 3. Bardzo trudny - Lepsze statystki przeciwnika, gorsze gracza, wiecej przeciwnikow w druzynie\n
 */

void DifficultyChanger::change_difficulty(int val) {
    switch (val) {
        case 1:
            difficulty = Difficulty::normal;
            amount_of_enemies_in_team = 4;
            break;
        case 2:
            difficulty = Difficulty::hard;
            amount_of_enemies_in_team = 5;
            break;
        case 3:
            amount_of_enemies_in_team = 6;
            difficulty = Difficulty::extreme;
            break;
    }
}

Difficulty DifficultyChanger::getDifficulty() const {
    return difficulty;
}
