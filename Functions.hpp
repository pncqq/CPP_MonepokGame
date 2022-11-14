#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <chrono>
#include <thread>
#include <map>
#include "Monepoke.hpp"
#include "DifficultyChanger.hpp"

class Functions {
    DifficultyChanger diff_chan;
    int enemies_in_team;


public:
    int get_enemies_in_team() const;

    void start();

    static void cutscene_1();

    static void print_delay(const std::string &str);

    static void enemy_presentation(const std::string &enemy_name);

    auto create_my_team(int amount) -> std::vector<Monepoke>;

    auto create_enemy_team(int amount) -> std::vector<Monepoke>;

    static void color_text(int k);

    static auto is_number(const std::string &str) -> bool;

    auto difficulty_choice() -> void;

};

