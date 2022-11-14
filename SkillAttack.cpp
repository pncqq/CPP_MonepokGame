#include "SkillAttack.hpp"
#include "Arena.hpp"

SkillAttack::SkillAttack(const std::string &n, const std::string &d, int amount)
        : Skill(n, d, amount) {}


void SkillAttack::use_skill(Monepoke &attacking, Monepoke &offended) {
    //Oblicz efficiency
    double eff = Arena::check_efficiency(attacking, offended);
    Arena::efficiency_communicate(eff);

    //Komunikat
    std::cout << "Monepok " << attacking.get_name() << " uzywa skilla "
              << name << "!";

    //Wykonanie skilla
    offended.attack(attacking.get_strength() * 1.5 * eff, true);

    //Zwieksz usages
    skill_usages++;
}

SkillAttack::SkillAttack() {

}

