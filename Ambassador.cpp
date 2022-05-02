//
// Created by Eitan Kats on 25/04/2022.
//

#include "Ambassador.hpp"
#include "set"

namespace coup {

    Ambassador::Ambassador(Game &currGame, const std::string &name) : Player{currGame, name} {}

    void Ambassador::block(Player &otherPlayer) {
        otherPlayer.checkBlock(*this);
    }

    void Ambassador::transfer(Player &firstPlayer, Player &secondPlayer) {
        this->isEligibleForMove();
        this->isCoupNecessary();
        firstPlayer.amendCoins(-1);
        secondPlayer.amendCoins(1);
        this->_currGame.passTurn();

    }

    std::string Ambassador::role() const {
        return "Ambassador";
    }
}