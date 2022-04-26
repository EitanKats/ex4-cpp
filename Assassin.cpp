//
// Created by Eitan Kats on 25/04/2022.
//
#include "Assassin.hpp"

namespace coup {

    Assassin::Assassin(Game &currGame, std::string name)
    : Player{currGame, name,"Assassin"} {}

    void Assassin::coup(Player &toCoup) {}
}