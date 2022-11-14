#pragma once
#include "Skill.hpp"

class SkillAttack : public Skill {

public:

    SkillAttack();

    SkillAttack(const std::string &n, const std::string &d, int amount);

    void use_skill(Monepoke &attacking, Monepoke &offended) override;

};
