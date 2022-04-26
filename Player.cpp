//
// Created by Eitan Kats on 25/04/2022.
//

#include "Player.hpp"
#include "Game.hpp"

namespace coup {
    Player::Player(Game &currGame, std::string name) : _currGame(Game), _name(name), _coins(0) {

    }
}
