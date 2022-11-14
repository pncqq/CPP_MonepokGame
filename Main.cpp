#include <iostream>
#include "Arena.hpp"
#include "Functions.hpp"
#include "SkillIncreaseStats.hpp"
#include "SaveReadFromFile.hpp"
#include "Variables.hpp"

auto main() -> int {

    srand(time(NULL));
    Functions fun;
    std::vector<Monepoke> my_team;
    SaveReadFromFile srff(Variables::how_many_allies_in_team);




    //Poczatek
    {
        //Start gry, poczatkowe komunikaty
        fun.start();

        //Nowa gra lub zapis
        std::cout << "Wybierz:\n";
        std::string choice;

        //Komunikaty
        while (true) {
            std::cout << "[1] - Nowa gra\t[2] - Wczytaj zapis z pliku\n";

            std::cin >> choice;

            if (!Functions::is_number(choice)) {
                std::cout << "\nTo nie jest numer!\n";
                continue;
            }

            if (std::stoi(choice) < 1 || std::stoi(choice) > 2) {
                std::cout << "\nZly numer!\n";
                continue;
            }

            break;
        }

        //Wybor
        switch (std::stoi(choice)) {
            case 1:
                break;
            case 2:
                my_team = srff.read_from_file();
                std::cout << "\nWczytano!\n";
                break;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    auto enemies_amount = fun.get_enemies_in_team();

    //Wektor druzyny gracza - wybor z 15 monepokow
    if (!srff.skip0) {
        my_team = fun.create_my_team(15);

        //Cutscene
        Functions::cutscene_1();
    }


    //Dodawanie do areny
    Arena arena(my_team[0], my_team);


    if (!srff.skip0) {
        //Runda pierwsza - pierwszy przeciwnik (4 stworzenia)
        auto enemy_team0 = fun.create_enemy_team(enemies_amount);
        arena.fight_start("Adam Malamysz", enemy_team0);

        //Komunikat (zapis lub wyjscie)
        {
            std::string choice;
            std::cout << "\nCo chcesz zrobic?\n";
            while (true) {
                std::cout << "[1] - Zapisz i graj dalej\t[2] - Zapisz i wyjdz\n";

                //Zapis
                srff.save_to_file(arena.get_my_team(), arena.get_my_team()[0], 1); //skip w miejscu 1

                std::cin >> choice;

                if (!Functions::is_number(choice)) {
                    std::cout << "\nTo nie jest numer!\n";
                    continue;
                }
                if (std::stoi(choice) < 1 || std::stoi(choice) > 2) {
                    std::cout << "\nZly numer!\n";
                    continue;
                }

                break;
            }

            switch (std::stoi(choice)) {
                case 1:
                    break;
                case 2:
                    return 0;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }


    if (!srff.skip1) {
        //Runda druga - drugi przeciwnik (4 stworzenia)
        auto enemy_team1 = fun.create_enemy_team(enemies_amount);
        arena.fight_start("Pinkie the Mouse", enemy_team1);

        //Komunikat (zapis lub wyjscie)
        {
            std::string choice;
            std::cout << "\nCo chcesz zrobic?\n";
            while (true) {
                std::cout << "[1] - Zapisz i graj dalej\t[2] - Zapisz i wyjdz\n";
                srff.save_to_file(my_team, my_team[0], 2);
                std::cin >> choice;

                if (!Functions::is_number(choice)) {
                    std::cout << "\nTo nie jest numer!\n";
                    continue;
                }

                if (std::stoi(choice) < 1 || std::stoi(choice) > 2) {
                    std::cout << "\nZly numer!\n";
                    continue;
                }

                break;
            }

            switch (std::stoi(choice)) {
                case 1:
                    break;
                case 2:
                    return 0;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }


    if (!srff.skip2) {
        //Runda trzecia - trzeci przeciwnik (4 stworzenia)
        auto enemy_team2 = fun.create_enemy_team(enemies_amount);
        arena.fight_start("Karp Diem", enemy_team2);

        //Komunikat (zapis lub wyjscie)
        {
            std::string choice;
            std::cout << "\nCo chcesz zrobic?\n";
            while (true) {
                std::cout << "[1] - Zapisz i graj dalej\t[2] - Zapisz i wyjdz\n";
                srff.save_to_file(my_team, my_team[0], 3);
                std::cin >> choice;

                if (!Functions::is_number(choice)) {
                    std::cout << "\nTo nie jest numer!\n";
                    continue;
                }

                if (std::stoi(choice) < 1 || std::stoi(choice) > 2) {
                    std::cout << "\nZly numer!\n";
                    continue;
                }

                break;
            }

            switch (std::stoi(choice)) {
                case 1:
                    break;
                case 2:
                    return 0;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }


    if (!srff.skip3) {
        //Runda czwarta - czwarty przeciwnik (4 stworzenia)
        auto enemy_team3 = fun.create_enemy_team(enemies_amount);
        arena.fight_start("Kinia Candy", enemy_team3);

        std::cout << "\n\n\nTo byl ostatni przeciwnik! Wygrales!!!!!!!!!!\n\n\n";

        //Komunikat (zapis lub wyjscie)
        {
            std::string choice;
            std::cout << "\nCo chcesz zrobic?\n";
            while (true) {
                std::cout << "[1] - Zapisz i wyjdz\t[2] - To samo, ale pod innym numerkiem\n";
                srff.save_to_file(my_team, my_team[0], 4);
                std::cin >> choice;

                if (!Functions::is_number(choice)) {
                    std::cout << "\nTo nie jest numer!\n";
                    continue;
                }
                if (std::stoi(choice) < 1 || std::stoi(choice) > 2) {
                    std::cout << "\nZly numer!\n";
                    continue;
                }

                break;
            }

            switch (std::stoi(choice)) {
                case 1:
                    return 0;
                case 2:
                    return 0;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    std::cout << "Skonczyles gre!!! :>\n";


}

/*
 * TODO:
 * 1.Meow
 */