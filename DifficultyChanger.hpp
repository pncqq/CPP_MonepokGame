#pragma once

enum class Difficulty {
    normal, hard, extreme
};

class DifficultyChanger {
    Difficulty difficulty;


public:
    int amount_of_enemies_in_team;

    void change_difficulty(int val);

    Difficulty getDifficulty() const;
};