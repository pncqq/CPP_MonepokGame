#pragma once

#include <vector>
#include "Monepoke.hpp"
#include <fstream>

class SaveReadFromFile {
    Monepoke actual_monepoke;
    std::vector<Monepoke> my_team;
    static std::string path_team;
    static std::string path_monepoke;
    static std::string path_checkpoint;
    int my_team_size;


public:
    bool skip0;
    bool skip1;
    bool skip2;
    bool skip3;

    SaveReadFromFile(int myTeamSize);

    auto save_to_file(std::vector<Monepoke> myTeam, Monepoke actualMonepoke, int ws) -> void;

    auto read_from_file() -> std::vector<Monepoke>;


};

