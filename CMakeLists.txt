cmake_minimum_required(VERSION 3.21)
project(Monepok)

set(CMAKE_CXX_STANDARD 20)

add_executable(Monepok Main.cpp Functions.cpp Functions.hpp Monepoke.cpp Monepoke.hpp Skill.cpp Skill.hpp Arena.cpp Arena.hpp SkillDefensive.cpp SkillDefensive.hpp SkillAttack.cpp SkillAttack.hpp SkillIncreaseStats.cpp SkillIncreaseStats.hpp SkillStun.cpp SkillStun.hpp DifficultyChanger.cpp DifficultyChanger.hpp SaveReadFromFile.cpp SaveReadFromFile.hpp Variables.cpp Variables.hpp)
