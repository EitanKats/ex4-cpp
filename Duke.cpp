//
// Created by Eitan Kats on 25/04/2022.
//

#include "Duke.hpp"
#include "Game.hpp"
#include "string"
#include "Player.hpp"

namespace coup {

    Duke::Duke(Game &currGame, const std::string &name) : Player{currGame, name} {

    }

    void Duke::tax() {
        this->_coins += 3;
    }

    void Duke::block(Player &toBlock) {

    }

    std::string Duke::role() const {
        return "Duke";
    }

}
