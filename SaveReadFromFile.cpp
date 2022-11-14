#include <cmath>
#include "SaveReadFromFile.hpp"

std::string SaveReadFromFile::path_team = "save_team.txt";
std::string SaveReadFromFile::path_monepoke = "save_monepoke.txt";
std::string SaveReadFromFile::path_checkpoint = "save_checkpoint.txt";

/**
 * Zapisuje informacje o aktualnym teamie do pliku save_team.txt
 */
auto SaveReadFromFile::save_to_file(std::vector<Monepoke> myTeam, Monepoke actualMonepoke, int ws) -> void {
    //Pola
    auto save_team = std::fstream(path_team, std::ios::out | std::ios::trunc);
    auto save_monepoke = std::fstream(path_monepoke, std::ios::out | std::ios::trunc);
    auto save_checkpoint = std::fstream(path_checkpoint, std::ios::out | std::ios::trunc);

    //Zapisywanie informacji o druzynie
    for (Monepoke i: myTeam) {
        save_team << i.get_plain_txt_info();
    }

    //Zapisywanie informacji o aktualnym monepoku
    save_monepoke << actualMonepoke.get_name_without_space() << " ";
    save_monepoke << round(actualMonepoke.get_strength()) << " ";
    save_monepoke << round(actualMonepoke.get_dexterity()) << " ";
    save_monepoke << round(actualMonepoke.get_health()) << " ";
    save_monepoke << actualMonepoke.get_special_skill()->get_plain_info() << " ";
    save_monepoke << actualMonepoke.get_exp_for_kill() << " ";
    save_monepoke << actualMonepoke.get_exp_poll() << " ";
    save_monepoke << actualMonepoke.get_level() << " ";
    save_monepoke << Monepoke::to_string(actualMonepoke.get_type()) << "\n";

    //Zapisywanie checkpointu
    save_checkpoint << ws << " ";
}

/**
 * Pobiera informacje z plików
 */
auto SaveReadFromFile::read_from_file() -> std::vector<Monepoke> {
    //Pola
    int wich_cp = 0;

    auto tmp = std::string();
    auto read_team = std::fstream(path_team);
    auto read_monepoke = std::fstream(path_monepoke);
    auto read_checkpoint = std::fstream(path_checkpoint);

    auto name = std::string();
    auto strength = 0;
    auto dex = 0;
    auto hp = 0;
    auto skill_desc = std::string();
    auto skill_max_uses = 0;
    auto skill_usages = 0;
    auto skill_name = std::string();
    auto e4k = 0;
    auto exp_poll = 0;
    auto level = 0;
    auto type_name = std::string();
    auto type = Type();

    auto actualMonepoke = Monepoke();
    auto my_teammates = std::vector<Monepoke>();


    //Sprawdzanie, czy plik jest pusty
    if (read_team.peek() == std::ifstream::traits_type::eof()) { //peek - pierwszy znak na wejsciu. eof - koniec pliku
        std::cout << "\nNie masz zapisu!\n";
        std::cout << "Zaczynam nowa gre.\n\n";
        return {};
    }

    //Zczytywanie teamu
    for (int i = 0; i < my_team_size; ++i) {

        //Robienie miejsca w wektorze
        my_teammates.emplace_back();

        //Czytanie
        read_team >> name;
        read_team >> strength;
        read_team >> dex;
        read_team >> hp;
        read_team >> skill_desc;
        read_team >> skill_max_uses;
        read_team >> skill_usages;
        read_team >> skill_name;
        //Okreslanie, jaki typ skilla
        if (skill_name == "Pistolet na wode" ||
            skill_name == "Uderzenie kamieniem w oko" ||
            skill_name == "Dmuchniecie" ||
            skill_name == "Wybuch ognia" ||
            skill_name == "Rzut sniezka" ||
            skill_name == "Pila mechaniczna"
                ) {
            auto skill = new SkillAttack();
            std::replace(skill_desc.begin(), skill_desc.end(), '_', ' ');
            skill->set_desc(skill_desc);
            skill->set_skill_use_amount(skill_max_uses);
            skill->set_skill_usages(skill_usages);
            std::replace(skill_name.begin(), skill_name.end(), '_', ' ');
            skill->set_name(skill_name);

            //Przypoisywanie skilla
            my_teammates[i].set_special_skill(skill);

        }
        if (skill_name == "Sciana wody" ||
            skill_name == "Sciana z ziemi" ||
            skill_name == "Salto w tyl" ||
            skill_name == "Sciana ognia" ||
            skill_name == "Zbroja z lodu" ||
            skill_name == "Stalowa sciana"
                ) {
            auto skill = new SkillDefensive();
            std::replace(skill_desc.begin(), skill_desc.end(), '_', ' ');
            skill->set_desc(skill_desc);
            skill->set_skill_use_amount(skill_max_uses);
            skill->set_skill_usages(skill_usages);
            std::replace(skill_name.begin(), skill_name.end(), '_', ' ');
            skill->set_name(skill_name);

            //Przypoisywanie skilla
            my_teammates[i].set_special_skill(skill);

        }
        if (skill_name == "Woda VYTAUTAS" ||
            skill_name == "Sok ze skaly" ||
            skill_name == "Technika oddechu" ||
            skill_name == "Plonacy oddech" ||
            skill_name == "Mrozna aura"
                ) {
            auto skill = new SkillIncreaseStats();
            std::replace(skill_desc.begin(), skill_desc.end(), '_', ' ');
            skill->set_desc(skill_desc);
            skill->set_skill_use_amount(skill_max_uses);
            skill->set_skill_usages(skill_usages);
            std::replace(skill_name.begin(), skill_name.end(), '_', ' ');
            skill->set_name(skill_name);

            //Przypoisywanie skilla
            my_teammates[i].set_special_skill(skill);

        }
        if (skill_name == "Zamien w kamien" ||
            skill_name == "Zamrozenie" ||
            skill_name == "Stalowy slup"
                ) {
            auto skill = new SkillStun();
            std::replace(skill_desc.begin(), skill_desc.end(), '_', ' ');
            skill->set_desc(skill_desc);
            skill->set_skill_use_amount(skill_max_uses);
            skill->set_skill_usages(skill_usages);
            std::replace(skill_name.begin(), skill_name.end(), '_', ' ');
            skill->set_name(skill_name);

            //Przypoisywanie skilla
            my_teammates[i].set_special_skill(skill);

        }

        read_team >> e4k;
        read_team >> exp_poll;
        read_team >> level;
        read_team >> type_name;

        my_teammates[i].set_exp_for_kill(e4k);
        my_teammates[i].set_exp_poll(exp_poll);
        my_teammates[i].set_level(level);

        //Imie i staty
        std::replace(name.begin(), name.end(), '_', ' ');
        my_teammates[i].set_name(name);
        my_teammates[i].set_strength(strength);
        my_teammates[i].set_dexterity(dex);
        my_teammates[i].set_health(hp);


        //Typ
        if (type_name == "water") type = Type::water;
        if (type_name == "earth") type = Type::earth;
        if (type_name == "air") type = Type::air;
        if (type_name == "fire") type = Type::fire;
        if (type_name == "ice") type = Type::ice;
        if (type_name == "steel") type = Type::steel;
        my_teammates[i].set_type(type);

    }


    //Zczytywanie checkpointa
    read_checkpoint >> wich_cp;
    switch (wich_cp) {
        case 1:
            skip0 = true;
            break;
        case 2:
            skip0 = true;
            skip1 = true;
            break;
        case 3:
            skip0 = true;
            skip1 = true;
            skip2 = true;
            break;
        case 4:
            skip0 = true;
            skip1 = true;
            skip2 = true;
            skip3 = true;
            break;

    }

    return my_teammates;
}

SaveReadFromFile::SaveReadFromFile(int myTeamSize) : my_team_size(myTeamSize) {}









