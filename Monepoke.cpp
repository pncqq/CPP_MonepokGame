#include "Monepoke.hpp"
#include "Functions.hpp"
#include <vector>
#include <iostream>
#include <cmath>

const std::string &Monepoke::get_name() const {
    return name;
}

Skill *Monepoke::get_special_skill() const {
    return special_skill;
}

/**
 * Graficzne informacje
 */
void Monepoke::show_info() const {
    std::cout << "=================================\n";
    std::cout << "Nazwa: " << name << "\n";
    std::cout << "STR: " << strength << "\n";
    std::cout << "DEX: " << dexterity << "\n";
    std::cout << "HP: " << health << "\n";
    std::cout << "Specjalny Skill: " << special_skill->get_name() << "\n";
    std::cout << "Exp za killa: " << exp_for_kill << "\n";
    switch (type) {
        case Type::water:
            std::cout << "Typ: Woda\n";
            break;
        case Type::earth:
            std::cout << "Typ: Ziemia\n";
            break;
        case Type::air:
            std::cout << "Typ: Powietrze\n";
            break;
        case Type::fire:
            std::cout << "Typ: Ogien\n";
            break;
        case Type::ice:
            std::cout << "Typ: Lod\n";
            break;
        case Type::steel:
            std::cout << "Typ: Stal\n";
            break;
    }
    std::cout << "=================================\n";
}

/**
 * Graficzne info o enemy
 */
void Monepoke::show_enemy_info() const {
    std::cout << "=================================\n";
    std::cout << "Nazwa: " << name << "\n";
    std::cout << "STR: " << strength << "\n";
    std::cout << "DEX: " << dexterity << "\n";
    std::cout << "HP: " << health << "\n";
//    std::cout << "Specjalny Skill: " << special_skill->get_name() << "\n";
    switch (type) {
        case Type::water:
            std::cout << "Typ: Woda\n";
            break;
        case Type::earth:
            std::cout << "Typ: Ziemia\n";
            break;
        case Type::air:
            std::cout << "Typ: Powietrze\n";
            break;
        case Type::fire:
            std::cout << "Typ: Ogien\n";
            break;
        case Type::ice:
            std::cout << "Typ: Lod\n";
            break;
        case Type::steel:
            std::cout << "Typ: Stal\n";
            break;
    }
    std::cout << "=================================\n";
}

/**
 * Krotkie informacje
 */
void Monepoke::show_short_info() const {
    std::cout << name << ", ";
    std::cout << "STR: " << strength << ", ";
    std::cout << "DEX: " << dexterity << ", ";
    std::cout << "HP: " << health << ", ";
    std::cout << "Skill: " << special_skill->get_name() << ", ";
    std::cout << "E4K: " << exp_for_kill << ", ";
    switch (type) {
        case Type::water:
            std::cout << "Typ: Woda\n";
            break;
        case Type::earth:
            std::cout << "Typ: Ziemia\n";
            break;
        case Type::air:
            std::cout << "Typ: Powietrze\n";
            break;
        case Type::fire:
            std::cout << "Typ: Ogien\n";
            break;
        case Type::ice:
            std::cout << "Typ: Lod\n";
            break;
        case Type::steel:
            std::cout << "Typ: Stal\n";
            break;
    }
}

/**
 * Krotkie informacje o enemy
 */
void Monepoke::show_short_enemy_info() const {
    std::cout << name << ", ";
    std::cout << "STR: " << strength << ", ";
    std::cout << "DEX: " << dexterity << ", ";
    std::cout << "HP: " << health << ", ";
    switch (type) {
        case Type::water:
            std::cout << "Typ: Woda\n";
            break;
        case Type::earth:
            std::cout << "Typ: Ziemia\n";
            break;
        case Type::air:
            std::cout << "Typ: Powietrze\n";
            break;
        case Type::fire:
            std::cout << "Typ: Ogien\n";
            break;
        case Type::ice:
            std::cout << "Typ: Lod\n";
            break;
        case Type::steel:
            std::cout << "Typ: Stal\n";
            break;
    }
}

/**
 * Tekst przygotowany pod zapis
 */
auto Monepoke::get_plain_txt_info() -> std::string {
    auto str0 = std::to_string(strength);
    auto str1 = std::stoi(str0);
    auto str2 = std::to_string(str1);

    auto dex0 = std::to_string(dexterity);
    auto dex1 = std::stoi(dex0);
    auto dex2 = std::to_string(dex1);

    auto hp0 = std::to_string(health);
    auto hp1 = std::stoi(hp0);
    auto hp2 = std::to_string(hp1);

    auto e4k0 = std::to_string(exp_for_kill);
    auto e4k1 = std::stoi(e4k0);
    auto e4k2 = std::to_string(e4k1);

    auto exp_p0 = std::to_string(exp_poll);
    auto exp_p1 = std::stoi(exp_p0);
    auto exp_p2 = std::to_string(exp_p1);


    auto i_love_pjc = get_name_without_space() + " " +
                      str2 + " " +
                      dex2 + " " +
                      hp2 + " " +
                      special_skill->get_plain_info() + " " +
                      e4k2 + " " +
                      exp_p2 + " " +
                      std::to_string(level) + " " +
                      to_string(type) + "\n";


    return i_love_pjc;
}

/**
 * Generowanie wszystkich pól Monepoka
 */
Monepoke::Monepoke() {
    exp_poll = 0;

    static auto names = std::vector<std::string>{
            "Hector", "Vector", "Cetaphil", "Memphis", "Gummo",
            "Nanga", "Katalizator", "Ikea", "Kasztan",
            "Wrubel", "Goofy Crook Jackson", "Satuk Gamma", "Sznio", "Gniok",
            "Pomelo", "Kebab", "Pikaboo", "Gangrena", "Ob",
            "Rzabka", "Kunta Kinte", "Guts", "Joint", "Kiyosaki",
            "Euro G", "Sanek Ploza", "Marszczyl", "Cukierenka Smakolyk",
            "Bonobo", "Jacek Gmoch", "Conon Nowic", "Jorr", "HP EliteBook",
            "Hermes", "Kentucky", "Barbie", "Naura", "Szniok", "Klenczonowka",
            "Gaspary", "Young Leosia", "Martin Zuckerberger", "James", "Paskudny chlystek",
            "Klenczon", "Bobby", "Zanklod Jawor-Laguna", "Zungo", "MrSkarpetka800",
            "Bugo Hoss", "Borygo", "Lagun DDL", "Dawid Obserwator", "Cool P", "Mlody Gad 600",
            "Alimando", "Pan Mislaw", "Laura Dinozaura", "Massachusetts"
    };

    /**
     *picking random name for monepok
     */
    int index = rand() % names.size();
    name = names[index];
    names.erase(names.begin() + index);

    //picking type
    int index1 = rand() % 6;
    switch (index1) {
        case 0:
            type = Type::water;
            break;
        case 1:
            type = Type::earth;
            break;
        case 2:
            type = Type::air;
            break;
        case 3:
            type = Type::fire;
            break;
        case 4:
            type = Type::ice;
            break;
        case 5:
            type = Type::steel;
            break;
    }

    /**
     * PICKING STATS\n
     * Poll of stats: 120\n
     * stat= -> 30p (+- 3)\n
     * stat+ -> 40p (+- 3)\n
     * stat++ -> 50p (+- 3)\n
     * stat- -> 20p (+- 3)\n
     * stat-- -> 10p (+- 3)\n
     * Algorytm chroni przed zbyt duza roznica w ostatniej\n
     * rozdawanej statystyce (EXP).\n
     * Stastystki nie moga byc totalnie losowe,\n
     * dlatego tak male zawachania punktow.\n
     */
    int rnd2, rnd3;
    int amount_of_points = 120;
    switch (type) {
        case Type::water:
            //str-, dex+, hp=, exp=
        {
            //STR
            int rnd1 = (rand() % 7) - 3; //random number from -3 to 3
            int str = 30 + rnd1;
            amount_of_points -= str;

            //DEX
            if (abs(rnd1) == 3) {
                rnd2 = (rand() % 5) - 2;
            } else {
                rnd2 = (rand() % 7) - 3;
            }
            int dex = 40 + rnd2;
            amount_of_points -= dex;

            //HP
            if (abs(rnd1) + abs(rnd2) >= 3) {
                rnd3 = (rand() % 3) - 1;
            } else {
                rnd3 = (rand() % 7) - 3;

            }
            int hp = 30 + rnd3;
            amount_of_points -= hp;

            //EXP
            int exp = amount_of_points;

            //Initialize
            strength = str;
            dexterity = dex;
            health = hp;
            exp_for_kill = exp;
            break;
        }
        case Type::earth:
            //str+, dex-, hp=, exp=
        {
            //STR
            int rnd1 = (rand() % 7) - 3; //random number from -3 to 3
            int str = 40 + rnd1;
            amount_of_points -= str;

            //DEX
            if (abs(rnd1) == 3) {
                rnd2 = (rand() % 5) - 2;
            } else {
                rnd2 = (rand() % 7) - 3;
            }
            int dex = 20 + rnd2;
            amount_of_points -= dex;

            //HP
            if (abs(rnd1) + abs(rnd2) >= 3) {
                rnd3 = (rand() % 3) - 1;
            } else {
                rnd3 = (rand() % 7) - 3;

            }
            int hp = 30 + rnd3;
            amount_of_points -= hp;

            //EXP
            int exp = amount_of_points;

            //Initialize
            strength = str;
            dexterity = dex;
            health = hp;
            exp_for_kill = exp;
            break;
        }
        case Type::air:
            //str-, dex++, hp--, exp+
        {
            //STR
            int rnd1 = (rand() % 7) - 3; //random number from -3 to 3
            int str = 20 + rnd1;
            amount_of_points -= str;

            //DEX
            if (abs(rnd1) == 3) {
                rnd2 = (rand() % 5) - 2;
            } else {
                rnd2 = (rand() % 7) - 3;
            }
            int dex = 50 + rnd2;
            amount_of_points -= dex;

            //HP
            if (abs(rnd1) + abs(rnd2) >= 3) {
                rnd3 = (rand() % 3) - 1;
            } else {
                rnd3 = (rand() % 7) - 3;

            }
            int hp = 10 + rnd3;
            amount_of_points -= hp;

            //EXP
            int exp = amount_of_points;

            //Initialize
            strength = str;
            dexterity = dex;
            health = hp;
            exp_for_kill = exp;
            break;
        }
        case Type::fire:
            //str++, dex-, hp=, exp-
        {
            //STR
            int rnd1 = (rand() % 7) - 3; //random number from -3 to 3
            int str = 50 + rnd1;
            amount_of_points -= str;

            //DEX
            if (abs(rnd1) == 3) {
                rnd2 = (rand() % 5) - 2;
            } else {
                rnd2 = (rand() % 7) - 3;
            }
            int dex = 20 + rnd2;
            amount_of_points -= dex;

            //HP
            if (abs(rnd1) + abs(rnd2) >= 3) {
                rnd3 = (rand() % 3) - 1;
            } else {
                rnd3 = (rand() % 7) - 3;

            }
            int hp = 30 + rnd3;
            amount_of_points -= hp;

            //EXP
            int exp = amount_of_points;

            //Initialize
            strength = str;
            dexterity = dex;
            health = hp;
            exp_for_kill = exp;
            break;
        }
        case Type::ice:
            //str-, dex+, hp+, exp-
        {
            //STR
            int rnd1 = (rand() % 7) - 3; //random number from -3 to 3
            int str = 20 + rnd1;
            amount_of_points -= str;

            //DEX
            if (abs(rnd1) == 3) {
                rnd2 = (rand() % 5) - 2;
            } else {
                rnd2 = (rand() % 7) - 3;
            }
            int dex = 40 + rnd2;
            amount_of_points -= dex;

            //HP
            if (abs(rnd1) + abs(rnd2) >= 3) {
                rnd3 = (rand() % 3) - 1;
            } else {
                rnd3 = (rand() % 7) - 3;

            }
            int hp = 40 + rnd3;
            amount_of_points -= hp;

            //EXP
            int exp = amount_of_points;

            //Initialize
            strength = str;
            dexterity = dex;
            health = hp;
            exp_for_kill = exp;
            break;
        }
        case Type::steel:
            //str=, dex=, hp=, exp=
        {
            //STR
            int rnd1 = (rand() % 7) - 3; //random number from -3 to 3
            int str = 30 + rnd1;
            amount_of_points -= str;

            //DEX
            if (abs(rnd1) == 3) {
                rnd2 = (rand() % 5) - 2;
            } else {
                rnd2 = (rand() % 7) - 3;
            }
            int dex = 30 + rnd2;
            amount_of_points -= dex;

            //HP
            if (abs(rnd1) + abs(rnd2) >= 3) {
                rnd3 = (rand() % 3) - 1;
            } else {
                rnd3 = (rand() % 7) - 3;

            }
            int hp = 30 + rnd3;
            amount_of_points -= hp;

            //EXP
            int exp = amount_of_points;

            //Initialize
            strength = str;
            dexterity = dex;
            health = hp;
            exp_for_kill = exp;
            break;
        }
    }


    /**
     * PICKING SKILLS\n
     * Water: Wiecej atakow\n
     * Earth: Roznorodne skille\n
     * Air: Uniki\n
     * Fire: Roznorodne skille\n
     * Ice: Stun\n
     * Steel: Balanced\n
     */
    //Water skills
    auto water_skills = std::vector<Skill *>{
            new SkillAttack("Pistolet na wode", "Wyglada groznie", 3),
            new SkillDefensive("Sciana wody", "Broni przed dwoma nastepnymi atakami", 1),
            new SkillIncreaseStats("Woda VYTAUTAS", "Zwieksza statystki na dwie rundy, dodaje zycia.", 1)
    };
    //Earth skills
    auto earth_skills = std::vector<Skill *>{
            new SkillAttack("Uderzenie kamieniem w oko", "Trafia prosto w rogowke", 2),
            new SkillDefensive("Sciana z ziemi", "Broni przed dwoma nastepnymi atakami", 2),
            new SkillIncreaseStats("Sok ze skaly", "Zwieksza statystki na dwie rundy, dodaje zycia.", 1),
            new SkillStun("Zamien w kamien", "Zamienia przeciwnika w kamien na 2 rundy i oslabia go trwale", 1)
    };
    //Air skills
    auto air_skills = std::vector<Skill *>{
            new SkillAttack("Dmuchniecie", "Dmucha w przeciwnika", 2),
            new SkillDefensive("Salto w tyl", "Broni przed dwoma nastepnymi atakami", 3),
            new SkillIncreaseStats("Technika oddechu", "Zwieksza statystki na dwie rundy, dodaje zycia.", 2)
    };
    //Fire skills
    auto fire_skills = std::vector<Skill *>{
            new SkillAttack("Wybuch ognia", "Salwa ognia w przeciwnika", 1),
            new SkillDefensive("Sciana ognia", "Broni przed dwoma nastepnymi atakami", 1),
            new SkillIncreaseStats("Plonacy oddech", "Zwieksza statystki na dwie rundy, dodaje zycia.", 1)
    };
    //Ice skills
    auto ice_skills = std::vector<Skill *>{
            new SkillAttack("Rzut sniezka", "Rzuca sniezka w przeciwnika", 2),
            new SkillDefensive("Zbroja z lodu", "Broni przed dwoma nastepnymi atakami", 2),
            new SkillIncreaseStats("Mrozna aura", "Zwieksza statystki na dwie rundy, dodaje zycia.", 2),
            new SkillStun("Zamrozenie", "Zamraza przeciwnika i oslabia go na 2 rundy i oslabia go trwale", 2)
    };
    //Steel skills
    auto steel_skills = std::vector<Skill *>{
            new SkillAttack("Pila mechaniczna", "Atak ostra pila", 2),
            new SkillDefensive("Stalowa sciana", "Broni przed dwoma nastepnymi atakami", 2),
            new SkillStun("Stalowy slup", "Zamienia przeciwnika w slupek stali na 2 rundy i oslabia go trwale", 2)
    };


    switch (type) {
        case Type::water: {
            int rnd = rand() % water_skills.size();
            special_skill = water_skills[rnd];
            break;
        }
        case Type::earth: {
            int rnd = rand() % earth_skills.size();
            special_skill = earth_skills[rnd];
            break;
        }
        case Type::air: {
            int rnd = rand() % air_skills.size();
            special_skill = air_skills[rnd];
            break;
        }
        case Type::fire: {
            int rnd = rand() % fire_skills.size();
            special_skill = fire_skills[rnd];
            break;
        }
        case Type::ice: {
            int rnd = rand() % ice_skills.size();
            special_skill = ice_skills[rnd];
            break;
        }
        case Type::steel: {
            int rnd = rand() % steel_skills.size();
            special_skill = steel_skills[rnd];
            break;
        }
    }


}

/**
 * Wywoluje use_skill na aktualnym skillu
 */
void Monepoke::use_skill(Monepoke &attacking, Monepoke &offended) {
    special_skill->use_skill(attacking, offended);
}

/**
 * Zabiera sobie HP, ale z komentarzem atakujacym
 */
void Monepoke::attack(double amount, bool is_it_skill) {
    std::this_thread::sleep_for(std::chrono::milliseconds(900));

    if (is_it_skill) {
        Functions::print_delay("\n*BOOM!, BOOM!*\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        Functions::print_delay("*Odglosy specjalnej umiejetnosci*");
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::cout << "\nSkill rani " << get_name() << " z sila "
                  << round(amount / 3) << "!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(900));
    } else {
        std::cout << "Atakuje Monepoka " << get_name()
                  << " z sila " << round(amount / 3) << "!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(900));
    }

    get_hurt(amount);

    //Sprawdzam, czy zabilem
    if (!is_alive()) {
        dead_comunicate();
        return;
    }

    std::cout << get_name() << " HP: " << get_health() << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(900));
}

/**
 * Otrzymuje obrazenia
 */
void Monepoke::get_hurt(double amount) {
    health -= amount / 3;
}

double Monepoke::get_strength() const {
    return strength;
}

int Monepoke::get_dexterity() const {
    return dexterity;
}

double Monepoke::get_health() const {
    return health;
}

int Monepoke::get_exp_for_kill() const {
    return exp_for_kill;
}

Type Monepoke::get_type() const {
    return type;
}

bool Monepoke::is_alive() {
    if (health > 0) return true;
    else return false;
}

void Monepoke::dead_comunicate() {
    std::cout << name << " zemdlal! :(\n";
}

void Monepoke::set_protection_shield(bool protectionShield) {
    protection_shield = protectionShield;
}

bool Monepoke::is_protection_shield() const {
    return protection_shield;
}

void Monepoke::increase_stats() {
    strength = strength + 7;
    dexterity = dexterity + 7;
    health = health + (health * 0.25) + 5;
    stats_increased = true;
}

void Monepoke::decrease_stats() {
    strength = strength - 7;
    dexterity = dexterity - 7;
    stats_increased = false;
}

bool Monepoke::is_stats_increased() const {
    return stats_increased;
}

bool Monepoke::get_is_stuned() const {
    return is_stuned;
}

void Monepoke::set_is_stuned(bool isStuned) {
    is_stuned = isStuned;
}

auto Monepoke::better_stats() -> void {
    strength = strength + (strength * 0.20);
    dexterity = dexterity + (dexterity * 0.15);
    health = health + (health * 0.20);
    exp_for_kill = exp_for_kill + (exp_for_kill * 0.25);
}

auto Monepoke::worse_stats() -> void {
    strength = strength - (strength * 0.35);
    dexterity = dexterity - (dexterity * 0.35);
    health = health - (health * 0.35);
    exp_for_kill = exp_for_kill - (exp_for_kill * 0.35);
}

void Monepoke::set_health(double h) {
    health = h;
}

auto Monepoke::evolve() -> void {
    auto multiplier = 1.0;

    if (exp_poll < (exp_to_evo * level)) {
        std::cout << "Nie masz wystarczajaco expa do tej operacji! ("
                  << exp_poll << "/" << exp_to_evo * level << ")\n";
        return;
    }

    if (level == 1) multiplier = 1.2;
    if (level == 2) multiplier = 1.6;
    if (level == 3) multiplier = 2.0;
    if (level > 3) return;


    std::cout << "\nCos sie dzieje z Monepokiem " << name << "!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(600));
    std::cout << "\nON EWOLUUJE :OO!!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2));

    std::string choice;

    for (int i = 0; i < 2; ++i) {

        while (true) {
            std::cout << "\nCo chcesz ulepszyc?\n";
            std::cout << "[1] - Sila\t[2] - Zrecznosc\t[3] - Zycie\t[4] - EXP za killa\n";

            std::cin >> choice;

            if (!Functions::is_number(choice)) {
                std::cout << "To nie jest numer!\n";
                continue;
            }

            if (std::stoi(choice) < 1 || std::stoi(choice) > 4) {
                std::cout << "Nie ma takiego numeru!\n";
                continue;
            }

            break;
        }

        switch (std::stoi(choice)) {
            case 1:
                strength = strength + (7 * multiplier);
                break;
            case 2:
                dexterity = dexterity + (7 * multiplier);
                break;
            case 3:
                health = health + (7 * multiplier);
                break;
            case 4:
                exp_for_kill = exp_for_kill + (7 * multiplier);
                break;
            default:
                std::cout << "Nie ma takiego numeru!\n";
                break;
        }
        std::cout << "Jeszcze raz!\n";
    }


    ++level;
    name = name + "(I)";
    std::cout << "\nStatystyki zwiekszone!\n";
}

auto Monepoke::add_exp() -> void {
    exp_poll = exp_poll + exp_for_kill;
}

auto Monepoke::to_string(const Type &t) -> std::string {
    switch (t) {
        case Type::water:
            return "water";
        case Type::earth:
            return "earth";
        case Type::air:
            return "air";
        case Type::fire:
            return "fire";
        case Type::ice:
            return "ice";
        case Type::steel:
            return "steel";
    }
}

double Monepoke::get_exp_poll() const {
    return exp_poll;
}

int Monepoke::get_level() const {
    return level;
}

std::string &Monepoke::get_name_without_space() {
    std::replace(name.begin(), name.end(), ' ', '_');
    return name;
}

void Monepoke::set_name(const std::string &name) {
    Monepoke::name = name;
}

void Monepoke::set_strength(double strength) {
    Monepoke::strength = strength;
}

void Monepoke::set_dexterity(double dexterity) {
    Monepoke::dexterity = dexterity;
}

void Monepoke::set_special_skill(Skill *specialSkill) {
    special_skill = specialSkill;
}

void Monepoke::set_exp_for_kill(double expForKill) {
    exp_for_kill = expForKill;
}

void Monepoke::set_exp_poll(double expPoll) {
    exp_poll = expPoll;
}

void Monepoke::set_level(int level) {
    Monepoke::level = level;
}

void Monepoke::set_type(Type type) {
    Monepoke::type = type;
}








