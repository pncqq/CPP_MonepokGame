#pragma once

#include "Skill.hpp"

class SkillStun : public Skill {

public:

    SkillStun();

    SkillStun(const std::string &n, const std::string &d, int amount);

    void use_skill(Monepoke &attacking, Monepoke &offended) override;

};

