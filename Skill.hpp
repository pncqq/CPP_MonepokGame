#pragma once
#include <string>

class Monepoke;

class Skill {
protected:
    std::string desc;
    int skill_use_amount;
    int skill_usages = 0;
    std::string name;
public:
    Skill();

    Skill(const std::string &n, const std::string &d, int amount);

    virtual void use_skill(Monepoke &attacking, Monepoke &offended);

    const std::string &get_name() const;

    const std::string &get_desc() const;

    auto get_desc_without_white() -> std::string;

    auto get_name_without_white() -> std::string;

    int get_skill_use_amount() const;

    int get_skill_usages() const;

    void set_skill_usages(int skillUsages);

    auto get_plain_info() -> std::string;

    void set_desc(const std::string &desc);

    void set_skill_use_amount(int skillUseAmount);

    void set_name(const std::string &name);
};



