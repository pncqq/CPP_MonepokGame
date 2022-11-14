#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include "Functions.hpp"
#include "DifficultyChanger.hpp"
#include "SaveReadFromFile.hpp"
#include "Variables.hpp"


/**
 * Efekt pisania w konsoli.
 */
void Functions::print_delay(const std::string &str) {

    for (char i: str) {
        std::cout << i;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

}

void Functions::start() {

    print_delay("Witaj w grze Monepok!\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    difficulty_choice();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Functions::cutscene_1() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    print_delay("Twoja przygoda dopiero sie zaczyna...\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    print_delay("Przygotuj sie do pierwszej walki! \n\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void Functions::enemy_presentation(const std::string &enemy_name) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    print_delay("\n\n\n\nTwoim przeciwnikiem jest ");
    print_delay(enemy_name);
    print_delay("!");
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

/**
 * Służy do werbowania początkowej drużyny.\n
 * Zwraca wektor drużyny stworzeń.\n
 */
auto Functions::create_my_team(int amount) -> std::vector<Monepoke> {
    print_delay("Wybierz swoja druzyne. Oto lista mozliwych kompanow: \n\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    //Pola
    auto my_team = std::vector<Monepoke>();
    auto all_monepokes = std::vector<Monepoke>();
    auto used_numbers = std::vector<int>();


    //Generowanie przeciwnikow w zaleznosci od poziomu trudnosci
    switch (diff_chan.getDifficulty()) {
        case Difficulty::normal:
        case Difficulty::hard:
            //Bez zmian
            for (int i = 0; i < amount; ++i) {
                all_monepokes.emplace_back();
            }
            break;
        case Difficulty::extreme:
            //Gorsze statystyki druzyny
            for (int i = 0; i < amount; ++i) {
                all_monepokes.emplace_back();
                all_monepokes[i].worse_stats();
            }
            break;
    }


    //Wypisanie monepokow
    for (int i = 0; i < all_monepokes.size(); ++i) {
        std::cout << "Monepok #" << i << "\n";
        all_monepokes[i].show_short_info();
        std::cout << "\n";
    }

    //Wybor druzyny
    std::string number;
    std::cout << "Wybierz szesc stworzen. Podaj numer ktory chcesz zwerbowac.\n";

    while (my_team.size() < Variables::how_many_allies_in_team) {
        std::cin >> number;

        //Sprawdza, czy to numer
        if (!is_number(number)) {
            std::cout << "\nTo nie jest numer!\n";
            continue;
        }

        //Sprawdza, czy number byl juz wykorzystany
        if (std::find(used_numbers.begin(), used_numbers.end(), std::stoi(number)) != used_numbers.end()) {
            std::cout << "Juz masz to stworzenie w druzynie!\n";
            continue;
        }
        used_numbers.push_back(std::stoi(number));

        //Sprawdza, czy istnieje taki monepok
        if (std::stoi(number) < 0 || std::stoi(number) > all_monepokes.size() - 1) {
            std::cout << "Nie ma monepoka o takim numerze!\n";
            continue;
        }

        //Dodawanie do druzyny
        for (int i = 0; i < all_monepokes.size(); ++i) {
            if (i == std::stoi(number)) {
                my_team.push_back(all_monepokes[i]);
            }
        }

        //Komunikat o powodzeniu
        std::cout << "Zwerbowano!\n";
    }

    //Komunikat
    std::this_thread::sleep_for(std::chrono::seconds(1));
    print_delay("Brawo!\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    print_delay("\n\n\n\n\nOto Twoja druzyna: \n\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (const auto &x: my_team) {
        x.show_info();
        std::cout << "\n";
    }

    //Zwracanie wektora druzyny
    return my_team;
}

auto Functions::create_enemy_team(int amount) -> std::vector<Monepoke> {
    auto enemy_team = std::vector<Monepoke>();

    //Generowanie przeciwnikow w zaleznosci od poziomu trudnosci
    switch (diff_chan.getDifficulty()) {
        case Difficulty::normal:
            //Bez zmian
            for (int i = 0; i < amount; ++i) {
                enemy_team.emplace_back();
            }
            break;
        case Difficulty::hard:
        case Difficulty::extreme:
            //Lepsze staty przeciwnika
            for (int i = 0; i < amount; ++i) {
                enemy_team.emplace_back();
                enemy_team[i].better_stats();
            }
            break;
    }


    return enemy_team;
}

/**
 * Sprawdza, czy string to numer.
 */
auto Functions::is_number(const std::string &str) -> bool {
    //all_of sprawdza czy projekcja zwraca true w calym
    //podanym zakresie
    return std::ranges::all_of(str.begin(), str.end(),
                               [](char c) { return std::isdigit(c) != 0; }); //isdigit sprawdza czy char to numer
}

auto Functions::difficulty_choice() -> void {

    while (true) {
        std::cout << "Wybierz poziom trudnosci:\n"
                     "[1] - Normalny\t[2] - Trudny\t[3] - Bardzo trudny\n";

        std::string choice;
        std::cin >> choice;


        if (!is_number(choice)) {
            std::cout << "\nTo nie jest numer!\n";
            continue;
        }


        switch (std::stoi(choice)) { //stoi -> zamienia string na int
            case 1:
                diff_chan.change_difficulty(1);
                enemies_in_team = diff_chan.amount_of_enemies_in_team;
                return;
            case 2:
                diff_chan.change_difficulty(2);
                enemies_in_team = diff_chan.amount_of_enemies_in_team;
                return;
            case 3:
                diff_chan.change_difficulty(3);
                enemies_in_team = diff_chan.amount_of_enemies_in_team;
                return;
            default:
                std::cout << "Zly numer!\n";
        }
    }


}

int Functions::get_enemies_in_team() const {
    return enemies_in_team;
}

/**
 * Kolory z biblioteki WindowsAPI.\n
 * GetStdHandle pobiera handle do określonego urządzenia standardowego\n
 * (standardowego wyjścia w tym przypadku - aktywny bufor ekranu konsoli).\n
 * SetConsoleTextAttribute ustawia atrybuty znaków zapisywanych\n
 * do bufora ekranu konsoli (w tym przypadku kolory).\n
 */
void Functions::color_text(int k) {
    HANDLE colors = GetStdHandle(STD_OUTPUT_HANDLE); // -> gdzie

    /*
     * 3 - niebieski
     * 12 - czerwony
     * 7 - bialy
     */

    SetConsoleTextAttribute(colors, k); //-> co
}
