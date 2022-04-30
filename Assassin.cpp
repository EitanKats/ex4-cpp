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

    void Assassin::coup(Player &other_player) {
        if (this->_coins < this->coupCost) {
//            throw std::runtime_error("insufficient cost");
        }
    }

    std::string Assassin::role() const {
        return "Assassin";
    }
}