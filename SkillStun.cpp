#include "SkillStun.hpp"
#include "Arena.hpp"

SkillStun::SkillStun(const std::string &n, const std::string &d, int amount)
        : Skill(n, d, amount) {}

/**
 * Stunuje przeciwnika i osłabia go trwale
 */
void SkillStun::use_skill(Monepoke &attacking, Monepoke &offended) {
    //Komunikat
    std::cout << "\nMonepok " << attacking.get_name() << " uzywa skilla "
              << name << "!\n";

    //Wykonanie skilla (stunuje + oslabia trwale)
    offended.set_is_stuned(true);
    offended.decrease_stats();

    //Zwieksz usages
    skill_usages++;
}

SkillStun::SkillStun() {

}


