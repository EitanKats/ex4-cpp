//
// Created by Eitan Kats on 25/04/2022.
//

#include "Ambassador.hpp"

namespace coup {

    Ambassador::Ambassador(Game &currGame, std::string name) : Player{currGame, name, "Ambassador"} {}

    void Ambassador::block(const Player &other_player) {

    }

    void Ambassador::transfer(const Player &first_player, const Player &second_player) {

    }
}