//
// Created by Eitan Kats on 25/04/2022.
//

#include "Player.hpp"
#include "Game.hpp"

namespace coup {
    Player::Player(Game &currGame,const std::string &name)
            : _currGame(currGame), _name(name), _coins(0) {
        this->_currGame.addPlayer(name);
    }

    void Player::income() {
        ++this->_coins;
    }

    int Player::coins() {
        return this->_coins;
    }

    void Player::foreign_aid() {
        this->_coins += 2;
    }

    void Player::coup(Player &other_player) {}

}
