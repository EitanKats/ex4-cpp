//
// Created by Eitan Kats on 25/04/2022.
//
#include "Captain.hpp"

namespace coup {
    Captain::Captain(Game &currGame, std::string name) :
            Player{currGame, name, "Captain"} {}

    void Captain::block(Player &other_player) {

    }

    void Captain::steal(Player &other_player) {

    }
}