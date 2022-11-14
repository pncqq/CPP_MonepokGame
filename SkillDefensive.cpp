#include <iostream>
#include "Arena.hpp"
#include "SkillDefensive.hpp"


SkillDefensive::SkillDefensive(const std::string &n, const std::string &d, int amount)
        : Skill(n, d, amount) {}


/**
 * Skill odpowiadający za zablokowanie wszelkich obrażeń w następnej rundzie.
 */

void SkillDefensive::use_skill(Monepoke &attacking, Monepoke &offended) {
    //Komunikat
    std::cout << "\nMonepok " << attacking.get_name() << " uzywa skilla "
              << name << "!";

    //Wykonanie skilla (ochrona na dwie rundy)
    attacking.set_protection_shield(true);

    //Zwieksz usages
    skill_usages++;
}

SkillDefensive::SkillDefensive() {

}


