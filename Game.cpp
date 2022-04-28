//
// Created by Eitan Kats on 25/04/2022.
//

#include "Game.hpp"
#include "string"
#include "vector"

namespace coup {


    std::string Game::turn() {

        this->currPlayer = this->currPlayer % this->_currPlayers.size();
        return this->_currPlayers[this->currPlayer++];
    }

    std::vector<std::string> Game::players() {
        return this->_currPlayers;
    }

    void Game::addPlayer(const std::string &name) {
        this->_currPlayers.push_back(name);
    }
}
