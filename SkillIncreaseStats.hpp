#pragma once

#include "Skill.hpp"

class SkillIncreaseStats : public Skill {

public:

    SkillIncreaseStats();

    SkillIncreaseStats(const std::string &n, const std::string &d, int amount);

    void use_skill(Monepoke &attacking, Monepoke &offended) override;

};


