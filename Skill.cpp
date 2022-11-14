#include "Skill.hpp"


Skill::Skill(const std::string &name, const std::string &desc, int skillUseAmount)
        : name(name), desc(desc), skill_use_amount(skillUseAmount) {}

Skill::Skill() {

}

void Skill::use_skill(Monepoke &attacking, Monepoke &offended) {

}

const std::string &Skill::get_name() const {
    return name;
}

const std::string &Skill::get_desc() const {
    return desc;
}

int Skill::get_skill_use_amount() const {
    return skill_use_amount;
}

int Skill::get_skill_usages() const {
    return skill_usages;
}

void Skill::set_skill_usages(int skillUsages) {
    skill_usages = skillUsages;
}

auto Skill::get_plain_info() -> std::string {
    auto _desc = get_desc_without_white();
    auto _name = get_name_without_white();


    auto i_love_pjc = _desc + " "
                      + std::to_string(skill_use_amount) + " "
                      + std::to_string(skill_usages) + " "
                      + _name;
    return i_love_pjc;
}

auto Skill::get_desc_without_white() -> std::string {
    auto desc_tmp = desc;

    std::replace(desc_tmp.begin(), desc_tmp.end(), ' ', '_');
    return desc_tmp;
}

auto Skill::get_name_without_white() -> std::string {
    auto name_tmp = name;

    std::replace(name_tmp.begin(), name_tmp.end(), ' ', '_');
    return name_tmp;
}

void Skill::set_desc(const std::string &desc) {
    Skill::desc = desc;
}

void Skill::set_skill_use_amount(int skillUseAmount) {
    skill_use_amount = skillUseAmount;
}

void Skill::set_name(const std::string &name) {
    Skill::name = name;
}



