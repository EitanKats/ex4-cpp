//
// Created by Eitan Kats on 25/04/2022.
//

#include "Player.hpp"
#include "Game.hpp"

namespace coup {
    Player::Player(Game &currGame, std::string name, std::string currRole)
            : _currGame(currGame), _name(name), _role(currRole), _coins(0) {

    }

    std::string Player::role() {
        return this->_role;
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
