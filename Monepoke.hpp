#pragma once

#include <iostream>
#include "Skill.hpp"
#include "SkillDefensive.hpp"
#include "SkillAttack.hpp"
#include "SkillIncreaseStats.hpp"
#include "SkillStun.hpp"

enum class Type {
    water, earth, air, fire, ice, steel
};


class Monepoke {
    std::string name;
    double strength;
    double dexterity;
    double health;
    Skill *special_skill;
    double exp_for_kill;
    double exp_poll;
    double exp_to_evo = 60;
    int level = 1;
    Type type;
    bool protection_shield = false;
    bool stats_increased = false;
    bool is_stuned = false;


public:
    Monepoke();

    void show_info() const;

    void show_short_info() const;

    void show_enemy_info() const;

    void show_short_enemy_info() const;

    auto get_plain_txt_info() -> std::string;

    const std::string &get_name() const;

    Skill *get_special_skill() const;

    double get_strength() const;

    int get_dexterity() const;

    double get_health() const;

    int get_exp_for_kill() const;

    Type get_type() const;

    void set_protection_shield(bool protectionShield);

    bool is_protection_shield() const;

    void attack(double amount, bool is_it_skill);

    void get_hurt(double amount);

    void use_skill(Monepoke &attacking, Monepoke &offended);

    void increase_stats();

    void decrease_stats();

    bool is_alive();

    void dead_comunicate();

    bool is_stats_increased() const;

    bool get_is_stuned() const;

    void set_is_stuned(bool isStuned);

    auto better_stats() -> void;

    auto worse_stats() -> void;

    void set_health(double d);

    auto evolve() -> void;

    auto add_exp() -> void;

    static auto to_string(const Type &t) -> std::string;

    double get_exp_poll() const;

    int get_level() const;

    std::string &get_name_without_space();

    void set_name(const std::string &name);

    void set_strength(double strength);

    void set_dexterity(double dexterity);

    void set_special_skill(Skill *specialSkill);

    void set_exp_for_kill(double expForKill);

    void set_exp_poll(double expPoll);

    void set_level(int level);

    void set_type(Type type);


};
