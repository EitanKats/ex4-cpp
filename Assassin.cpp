//
// Created by Eitan Kats on 25/04/2022.
//
#include "Assassin.hpp"
#include "exception"

namespace coup {

    Assassin::Assassin(Game &currGame, const std::string &name)
            : Player{currGame, name} {
        this->coupCost = 3;
    }

    void Assassin::coup(Player &otherPlayer) {
        if (this->_coins < this->coupCost) {
            throw std::runtime_error("insufficient coins");
        }
        this->_blockers = {"Contessa"};
        size_t playerIdx = this->_currGame.executeCoup(otherPlayer.getName());
        this->_rollbackcb = [&otherPlayer, playerIdx, this]() { this->_currGame.revivePlayer(playerIdx, otherPlayer); };
        this->amendCoins(-this->coupCost);
    }

    std::string Assassin::role() const {
        return "Assassin";
    }
}