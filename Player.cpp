//
// Created by Eitan Kats on 25/04/2022.
//

#include "Player.hpp"
#include "Game.hpp"
#include "exception"

namespace coup {
    Player::Player(Game &currGame, const std::string &name)
            : _currGame(currGame), _name(name), _coins(0) {
        this->_currGame.addPlayer(name);
    }

    void Player::isEligibleForMove() {
        if (this->_currGame.turn() != this->_name) {
//            throw std::runtime_error("Not your turn");
        }
    }

    void Player::income() {
        this->isEligibleForMove();
        ++this->_coins;
        this->_currGame.passTurn();
    }

    int Player::coins() {
        return this->_coins;
    }

    void Player::foreign_aid() {
        this->isEligibleForMove();
        this->_coins += 2;
        this->_currGame.passTurn();
    }

    void Player::coup(Player &other_player) {
        this->isEligibleForMove();
        if (this->_coins < 7) {
//            throw std::runtime_error("insufficient amount of coins");
        }
        this->_coins -= 7;
        this->_currGame.passTurn();
    }

}
