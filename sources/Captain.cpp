//
// Created by Eitan Kats on 25/04/2022.
//
#include "Captain.hpp"
#include <algorithm>

namespace coup {
    Captain::Captain(Game &currGame, const std::string &name) :
            Player{currGame, name} {}

    void Captain::block(Player &otherPlayer) {
        otherPlayer.checkBlock(*this);
    }

    void Captain::steal(Player &otherPlayer) {
        this->isEligibleForMove();
        this->isCoupNecessary();
        this->validateInteractionAction(otherPlayer);
        int toSteal = std::min(otherPlayer.coins(), 2);
        otherPlayer.amendCoins(-toSteal);
        this->amendCoins(toSteal);


        this->_blockers = {"Ambassador", "Captain"};
        this->_rollbackcb = [&otherPlayer, this]() {
            otherPlayer.amendCoins(2);
            this->amendCoins(-2);
        };
        this->_currGame.passTurn();
    }

    std::string Captain::role() const {
        return "Captain";
    }
}