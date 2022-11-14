#pragma once
#include "Skill.hpp"

class SkillDefensive : public Skill {

public:
    SkillDefensive();

    SkillDefensive(const std::string &n, const std::string &d, int amount);

    void use_skill(Monepoke &attacking, Monepoke &offended) override;

};
