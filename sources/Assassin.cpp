//
// Created by Eitan Kats on 25/04/2022.
//
#include "Assassin.hpp"
#include "exception"

namespace coup {

    Assassin::Assassin(Game &currGame, const std::string &name)
            : Player{currGame, name} {
    }

    void Assassin::coup(Player &otherPlayer) {
        isEligibleForMove();
        validateInteractionAction(otherPlayer);
        if (this->_coins < this->discountedCoupCost) {
            throw std::runtime_error("insufficient coins");
        }
        //executing regular coup if the coins are >= 7
        if (this->_coins >= this->coupCost) {
            return this->Player::coup(otherPlayer);
        }
        this->_blockers = {"Contessa"};
        size_t coupedPlayerIdx = this->_currGame.executeCoup(otherPlayer.getName());
        otherPlayer.setIsAlive(false);
        this->_rollbackcb = [&otherPlayer, coupedPlayerIdx, this]() {
            this->_currGame.revivePlayer(coupedPlayerIdx, otherPlayer);
        };
        this->amendCoins(-this->discountedCoupCost);
        this->coupPassTurn(coupedPlayerIdx);
    }

    std::string Assassin::role() const {
        return "Assassin";
    }
}