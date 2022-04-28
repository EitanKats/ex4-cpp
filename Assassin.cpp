//
// Created by Eitan Kats on 25/04/2022.
//
#include "Assassin.hpp"

namespace coup {

    Assassin::Assassin(Game &currGame, const std::string& name)
            : Player{currGame, name} {}

    void Assassin::coup(Player &toCoup) {}

    std::string Assassin::role() const {
        return "Assassin";
    }
}