#pragma once

#include <vector>
#include "Functions.hpp"

class Arena {
    std::string enemy_name;
    Monepoke actual_monepoke;
    Monepoke actual_enemy;
    std::vector<Monepoke> my_team;
    std::vector<Monepoke> enemy_team;
    std::vector<double> health_values;
    std::vector<int> skills_usages;
    bool is_my_team_alive = true;
    bool is_enemy_team_alive = true;
    bool tmp1 = true;
    bool tmp2 = true;
    bool tmp3 = true;
    bool tmp4 = true;
    int number_of_rounds = 0;
    int this_round1;
    int this_round2;
    int this_round3;


public:
    Arena(const Monepoke &actualMonepoke, const std::vector<Monepoke> &myTeam);

    void fight_start(const std::string &enemy_name, std::vector<Monepoke> &enemies);

    void attack();

    void default_menu();

    void monepoke_choice();

    void enemy_move();

    void set_first_enemy();

    void auto_exchange_ally();

    void auto_exchange_enemy();

    void you_lose();

    void you_win();

    bool is_actual_have_shield();

    static double check_efficiency(const Monepoke &attacking, const Monepoke &offended);

    static void efficiency_communicate(double efficiency);

    bool is_dodge(const Monepoke &monepoke);

    auto heal_the_dead() -> void;

    const std::vector<Monepoke> &get_my_team() const;
};
