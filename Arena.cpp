#include <cmath>
#include "Arena.hpp"


Arena::Arena(const Monepoke &actualMonepoke, const std::vector<Monepoke> &myTeam)
        : actual_monepoke(actualMonepoke),
          my_team(myTeam) {}


/**
 * Metoda rozpoczynająca walkę:\n
 * 1. Ustawia początkowego przeciwnika\n
 * 2. Wyświetla informacje w konsoli\n
 * 3. Pętla walki\n
 */
void Arena::fight_start(const std::string &enemy_n, std::vector<Monepoke> &enemies) {
    enemy_team = enemies;
    enemy_name = enemy_n;
    set_first_enemy();
    heal_the_dead();

    //Kopiowanie zycia i uzyc skilli Monepokow
    if (tmp4) {
        for (int i = 0; i < my_team.size(); ++i) {
            health_values[i] = my_team[i].get_health();
            tmp4 = false;
        }
    }


    Functions::enemy_presentation(enemy_name);
    Functions::print_delay("\nAktualnie walczysz z Monepokiem: \n");
    actual_enemy.show_enemy_info();

    //while (przeciwnik zyje lub ja zyje)
    while (is_my_team_alive && actual_enemy.is_alive()) {
        ++number_of_rounds;
        default_menu();
    }

    //Komikaty o wyniku calej walki
    if (!is_enemy_team_alive) {
        you_win();
        return;
    } else {
        you_lose();
    }
}

/**
 * Domyślne menu wyboru podczas walki
 */
void Arena::default_menu() {
    std::string choice;
    bool skip_enemy_move = false;

    while (true) {
        //Komunikat
        Functions::color_text(3);
        std::cout << "\nAktualny Monepok: " << actual_monepoke.get_name()
                  << " (" << actual_monepoke.get_health() << " HP)\n";
        std::cout << "[1]. Atak\n";
        std::cout << "[2]. Skill - " << actual_monepoke.get_special_skill()->get_name()
                  << " (" << actual_monepoke.get_special_skill()->get_desc() << ") (" <<
                  actual_monepoke.get_special_skill()->get_skill_use_amount() -
                  actual_monepoke.get_special_skill()->get_skill_usages()
                  << ")\n";
        std::cout << "[3]. Wymiana\n";
        std::cout << "[4]. Ewolucja\n";
        Functions::color_text(7);

        std::cin >> choice;

        //Sprawdza, czy to numer
        if (!Functions::is_number(choice)) {
            std::cout << "\nTo nie jest numer!\n";
            continue;
        }
        if (std::stoi(choice) < 1 || std::stoi(choice) > 4) {
            std::cout << "\nNie ma takiego numeru!\n";
            continue;
        }
        break;
    }


    //Sprawdzam, czy trzeba wylaczyc buffa
    if (actual_monepoke.is_stats_increased() && number_of_rounds - this_round2 >= 3) {
        actual_monepoke.decrease_stats();
        tmp1 = true;
    }

    //Sprawdzam, czy trzeba wylaczyc stuna
    if (actual_enemy.get_is_stuned() && number_of_rounds - this_round3 >= 2) {
        actual_enemy.set_is_stuned(false);
        tmp3 = true;
    }

    //Jedna tura:
    switch (std::stoi(choice)) {
        case 1: { //Zwykly atak
            //Sprawdz, czy ally zyje
            if (!actual_monepoke.is_alive()) {
                Functions::print_delay("\nTen monepok zemdlal i nie moze walczyc!\n");
                return;
            }
            attack();
            break;
        }
        case 2: { //Skill

            //Sprawdz, czy ally zyje
            if (!actual_monepoke.is_alive()) {
                Functions::print_delay("\nTen monepok zemdlal i nie moze walczyc!\n");
                return;
            }

            //Sprawdza, czy ten skill ma jeszcze uzycia
            if (actual_monepoke.get_special_skill()->get_skill_usages() <
                actual_monepoke.get_special_skill()->get_skill_use_amount()) {

                //Uzyj skilla
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                actual_monepoke.use_skill(actual_monepoke, actual_enemy);

                //Jesli skill to buff
                if (Skill *actual_skill = dynamic_cast<SkillIncreaseStats *>(actual_monepoke.get_special_skill())) {
                    //Przypisanie rundy uzycia do zmiennej
                    if (tmp1) {
                        this_round2 = number_of_rounds;
                        tmp1 = false;
                    }
                }

                //Jesli skin to stun
                if (Skill *actual_skill = dynamic_cast<SkillStun *>(actual_monepoke.get_special_skill())) {
                    //Przypisanie rundy uzycia do zmiennej
                    if (tmp3) {
                        this_round3 = number_of_rounds;
                        tmp3 = false;
                    }
                }


                //Sprawdzanie, czy przeciwnik zyje
                if (!actual_enemy.is_alive()) {
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    Functions::color_text(12);
                    Functions::print_delay("\nPokonales Monepoka " + actual_enemy.get_name() + "!\n");
                    Functions::color_text(7);
                    std::this_thread::sleep_for(std::chrono::seconds(1));

                    //Dodawanie expa do aktualnego i do kopii w wektorze
                    actual_monepoke.add_exp();
                    for (auto &i: my_team) {
                        if (i.get_name() == actual_monepoke.get_name()) {
                            i.add_exp();
                        }
                    }
                }
            } else {
                std::cout << "\nTen skill nie ma juz uzyc...\n";
                skip_enemy_move = true;
            }

            break;
        }
        case 3: {
            monepoke_choice();
            return;
        }
        case 4: {
            actual_monepoke.evolve();

            //Aktualizacja
            for (auto &i: my_team) {
                if (i.get_name() + "(I)" == actual_monepoke.get_name() ||
                    i.get_name() + "(I)(I)" == actual_monepoke.get_name()
                        ) {
                    i = actual_monepoke;
                }
            }
            return;
        }
    }


    //Sprawdz, czy przeciwnik zyje
    if (!actual_enemy.is_alive()) {
        //Ustawianie nowego przeciwnika do walki
        auto_exchange_enemy();
        return;
    }

    if (!skip_enemy_move) {
        enemy_move();
    }
}

/**
 * Wymiana Monepoka\n
 */
void Arena::monepoke_choice() {

    std::cout << "\nWybierz, kto bedzie walczyl:\n\n";

    //Prezentacja druzyny
    for (int i = 0; i < my_team.size(); ++i) {
        //Aktualizacja starych monepokow (z pierwotnymi statystykami)
        if (my_team[i].get_name() == actual_monepoke.get_name()) {
            my_team[i] = actual_monepoke;
        }

        if (my_team[i].is_alive()) {
            std::cout << i << ". ";
            my_team[i].show_short_info();
        }
    }

    //Wybor pokemona
    std::string choice;

    while (true) {
        std::cin >> choice;

        if (!Functions::is_number(choice)) {
            std::cout << "\nTo nie jest numer!\n";
            continue;
        }
        break;
    }


    for (int i = 0; i < my_team.size(); ++i) {
        if (std::stoi(choice) == i) {
            //Sprawdzamy, czy nie mam go aktualnie
            if (my_team[i].get_name() == actual_monepoke.get_name()) {
                std::cout << "\nTo jest twoj aktualny monepok!\n";
                return;
            }

            //Sprawdzamy, czy zyje
            if (!my_team[i].is_alive()) {
                std::cout << "\nTen Monepok zemdlal!\n";
                return;
            }

            actual_monepoke = my_team[i];
        }
    }
}

/**
 * Atak w stronę przeciwnika
 */
void Arena::attack() {

    //Sprawdza, czy enemy ma stuna (jak ma - nie uniknie ciosu)
    if (!actual_enemy.get_is_stuned()) {
        //Sprawdza dodge
        if (is_dodge(actual_enemy)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
            Functions::print_delay("\n" + actual_enemy.get_name() + " unika ataku!\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            return;
        }
    }

    double efficiency = check_efficiency(actual_monepoke, actual_enemy);
    efficiency_communicate(efficiency);

    //Ja atakuje przeciwnika
    actual_enemy.attack(actual_monepoke.get_strength() * efficiency, false);


    //Sprawdzanie, czy przeciwnik zyje
    if (!actual_enemy.is_alive()) {
        Functions::color_text(12);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Functions::print_delay("\nPokonales Monepoka " + actual_enemy.get_name() + "!\n");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        Functions::color_text(7);

        //Dodawanie expa do aktualnego i do kopii w wektorze
        actual_monepoke.add_exp();
        for (auto &i: my_team) {
            if (i.get_name() == actual_monepoke.get_name()) {
                i.add_exp();
            }
        }
        return;
    }

}

/**
 * Atak w naszą stronę
 */
void Arena::enemy_move() {
    //Sprawdza, czy enemy ma stuna
    if (actual_enemy.get_is_stuned()) {
        std::cout << "\nMonepok " << actual_enemy.get_name() << " jest zestunowany!\n";
        return;
    }

    //Sprawdza czy jest shield
    if (is_actual_have_shield()) return;

    //Sprawdza dodge
    if (is_dodge(actual_monepoke)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        Functions::print_delay("\n" + actual_monepoke.get_name() + " unika ataku!\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        return;
    }

    //Efektywnosc komunikat
    double efficiency = check_efficiency(actual_enemy, actual_monepoke);
    efficiency_communicate(efficiency);


    //Narazie samo bicie, potem dodam skille
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Przeciwnik atakuje Cie z sila " << round((actual_enemy.get_strength() / 3.0) * efficiency) << "!\n";
    actual_monepoke.get_hurt(actual_enemy.get_strength() * efficiency);
    std::this_thread::sleep_for(std::chrono::milliseconds(900));

    //Sprawdzam, czy moj dalej zyje
    if (!actual_monepoke.is_alive()) {
        Functions::print_delay("...\n");
        Functions::color_text(12);
        Functions::print_delay("Twoj Monepok zemdlal!\n");
        Functions::color_text(7);
        auto_exchange_ally();
        return;
    }

    //Komunikat
    std::cout << "Twoje HP: " << round(actual_monepoke.get_health()) << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(900));
}

/**
 * Wyszukiwanie aktualnego przeciwnika (biore po kolei).\n
 */
void Arena::set_first_enemy() {
    actual_enemy = enemy_team[0];
}

/**
 * Gdy nasz pokemon umiera to autmatycznie wchodzi drugi z listy\n
    Gdy nie ma zadnego -> is_my_team_alive = false
 */
void Arena::auto_exchange_ally() {

    for (auto &i: my_team) {
        //Sprawdzam, czy napewno mamy trupa
        if (!actual_monepoke.is_alive()) {

            //Aktualizacja martwego monepoka z wektorem
            for (auto &j: my_team) {
                if (j.get_name() == actual_monepoke.get_name()) {
                    j = actual_monepoke;
                }
            }

            //Zamiana Monepoka na zyjacego
            if (i.is_alive()) {
                actual_monepoke = i;
                Functions::print_delay("\nTwoj nowy Monepok to: " + actual_monepoke.get_name() + "\n");
                std::this_thread::sleep_for(std::chrono::seconds(1));
                return;
            }
        }
    }

    //Jesli petla sie skonczy, i nie bedzie zadnego zywego ziomka:
    is_my_team_alive = false;
    Functions::print_delay("\nTo byl Twoj ostatni Monepok!\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));

}

/**
 * Bierze kolejne stworzenie przeciwnika\n
 */
void Arena::auto_exchange_enemy() {
    for (int i = 0; i < enemy_team.size(); ++i) {
        //Sprawdzam, czy napewno mamy trupa
        if (!actual_enemy.is_alive()) {

            //Jesli tak, znajduje jego referencje w wektorze i usuwam ją
            if (actual_enemy.get_name() == enemy_team[i].get_name()) {
                enemy_team.erase(enemy_team.begin() + i);
            }

            //Jesli to byl ostatni, przeciwnika druzyna dead
            if (enemy_team.empty()) {
                is_enemy_team_alive = false;
                Functions::print_delay("\nTo byl ostatni Monepok przeciwnika!\n");
                std::this_thread::sleep_for(std::chrono::seconds(1));
                return;
            } else {
                //Jesli nie, biore nastepnego pokemona
                actual_enemy = enemy_team[i];
                Functions::print_delay("Nastepny Monepok przeciwnika to: " + actual_enemy.get_name() + "!\n");
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        }
    }
    std::cout << "\nAktualnie walczysz z Monepokiem: ";
    actual_enemy.show_short_enemy_info();
}

void Arena::you_lose() {
    Functions::print_delay("\n:oo :((( :<<<. Przegrales!!!!!!!!!!!:((\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Functions::print_delay("Pokonal Cie " + enemy_name + "...\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    exit(420);
}

void Arena::you_win() {
    Functions::print_delay("\nUdalo ci sie pokonac przeciwnika " + enemy_name + "!!\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

double Arena::check_efficiency(const Monepoke &attacking, const Monepoke &offended) {
    double efficiency = 1;
    double better = 1.43;
    double worse = 0.68;

    switch (attacking.get_type()) {
        case Type::water:
            switch (offended.get_type()) {
                case Type::water:
                    efficiency = worse;
                    break;
                case Type::earth:
                case Type::fire:
                    efficiency = better;
                    break;
            }
            break;
        case Type::earth:
            switch (offended.get_type()) {
                case Type::air:
                    efficiency = worse;
                    break;
                case Type::fire:
                case Type::ice:
                case Type::steel:
                    efficiency = better;
                    break;
            }
            break;
        case Type::air:
            switch (offended.get_type()) {
                case Type::earth:
                case Type::steel:
                    efficiency = worse;
                    break;
                case Type::ice:
                    efficiency = better;
                    break;
            }
            break;
        case Type::fire:
            switch (offended.get_type()) {
                case Type::water:
                case Type::earth:
                    efficiency = worse;
                    break;
                case Type::steel:
                case Type::ice:
                    efficiency = better;
                    break;
            }
            break;
        case Type::ice:
            switch (offended.get_type()) {
                case Type::water:
                case Type::fire:
                case Type::ice:
                    efficiency = worse;
                    break;
                case Type::earth:
                    efficiency = better;
                    break;
            }
            break;
        case Type::steel:
            switch (offended.get_type()) {
                case Type::water:
                case Type::air:
                    efficiency = better;
                    break;
                case Type::fire:
                case Type::steel:
                    efficiency = worse;
                    break;
            }
            break;
    }

    return efficiency;
}

void Arena::efficiency_communicate(double efficiency) {
    //Sprawdzam efficiency
    if (efficiency > 1) {
        Functions::print_delay("\nTen atak bedzie efektywniejszy!\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    } else if (efficiency < 1) {
        Functions::print_delay("\nTen atak bedzie oslabiony!\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    } else {
        Functions::print_delay("\nEfektywnosc tego ataku nie zmienia sie!\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }


}

/**
 *Czy atkualny monepoke ma shielda
 */
bool Arena::is_actual_have_shield() {
    //Sprawdzam, czy byl uzyty skill na tarcze
    if (actual_monepoke.is_protection_shield()) {

        //Przypisanie rundy uzycia do zmiennej
        if (tmp2) {
            this_round1 = number_of_rounds;
            tmp2 = false;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        std::cout << "\nTwoja tarcza skutecznie broni przed atakiem przeciwnika!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(700));

        //Wylaczanie tarczy po drugiej obronie
        if (number_of_rounds - this_round1 >= 1) {
            actual_monepoke.set_protection_shield(false);
            tmp2 = true;
        }

        return true;
    }
    return false;
}

/**
 * Czy wystapil unik
 */
bool Arena::is_dodge(const Monepoke &monepoke) {
    //Probuje zrobic unik
    int num = rand() % 100;

    if (num <= monepoke.get_dexterity()) {
        return true;
    }
    return false;
}

/**
 * Leczy omdlone Monepoki, resetuje skille
 */
auto Arena::heal_the_dead() -> void {

    //Rezerwuje miejsce w wektorach
    if (health_values.empty() && skills_usages.empty()) {
        for (int i = 0; i < my_team.size(); ++i) {
            health_values.push_back(420);
            skills_usages.push_back(420);
        }
        return;
    }


    for (int i = 0; i < my_team.size(); ++i) {
        //Sprawdzam, czy skill byl uzyty
        if (my_team[i].get_special_skill()->get_skill_usages() != 0) {
            my_team[i].get_special_skill()->set_skill_usages(0);
        }

        //Leczenie
        my_team[i].set_health(health_values[i]);

        //Leczenie aktualnego
        if (actual_monepoke.get_name() == my_team[i].get_name()) {
            actual_monepoke.set_health(health_values[i]);
        }
    }
    actual_monepoke.get_special_skill()->set_skill_usages(0);

}

const std::vector<Monepoke> &Arena::get_my_team() const {
    return my_team;
}









