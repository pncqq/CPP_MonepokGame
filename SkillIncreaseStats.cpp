#include <iostream>
#include "SkillIncreaseStats.hpp"
#include "Arena.hpp"

/**
 * Skill odpowiadający za powiększenie statystyk na 2 następne rundy.
 */

void SkillIncreaseStats::use_skill(Monepoke &attacking, Monepoke &offended) {
    //Komunikat
    std::cout << "\nMonepok " << attacking.get_name() << " uzywa skilla "
              << name << "!\n";
    std::cout << "Twoje statystyki wzrastaja na dwie rundy!\n";

    //Wykonanie skilla (staty lepsze na dwie rundy)
    attacking.increase_stats();

    //Zwieksz usages
    skill_usages++;

}


SkillIncreaseStats::SkillIncreaseStats(const std::string &n, const std::string &d, int amount)
        : Skill(n, d, amount) {}

SkillIncreaseStats::SkillIncreaseStats() {

}
