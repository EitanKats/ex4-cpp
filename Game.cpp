//
// Created by Eitan Kats on 25/04/2022.
//

#include "Game.hpp"
#include "string"
#include "vector"

namespace coup {


    std::string Game::turn() {
        std::string test = "";
        return test;
    }

    std::vector<std::string> Game::players() {
        return this->_currPlayers;
    }

    void Game::addPlayer(std::string name) {
        this->_currPlayers.push_back(name);
    }
}
