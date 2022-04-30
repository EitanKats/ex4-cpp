//
// Created by Eitan Kats on 25/04/2022.
//

#include "Game.hpp"
#include "exception"
#include "vector"


namespace coup {


    std::string Game::turn() {
        return this->_currPlayers[this->currPlayer];
    }

    std::vector<std::string> Game::players() {
        return this->_currPlayers;
    }

    void Game::addPlayer(const std::string &name) {
        this->_currPlayers.push_back(name);
    }

    std::string Game::winner() {
        if (this->_currPlayers.size() > 1) {
//            throw std::runtime_error("game is ongoing");
        }
        return this->_currPlayers[0];
    }

    void Game::passTurn() {
        ++this->currPlayer;
        this->currPlayer = this->currPlayer % this->_currPlayers.size();
    }
}
