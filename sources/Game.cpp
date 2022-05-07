//
// Created by Eitan Kats on 25/04/2022.
//

#include "Game.hpp"
#include "exception"
#include "vector"
#include "Player.hpp"

namespace coup {


    std::string Game::turn() {
        if (this->_currPlayers.size() < 2) {
            throw std::runtime_error("not enough players in game");
        }
        this->hasStarted = true;
        return this->_currPlayers[this->currPlayer];
    }

    std::vector<std::string> Game::players() {
        return this->_currPlayers;
    }

    void Game::addPlayer(const std::string &name) {
        if (this->_currPlayers.size() > 6) {
            throw std::runtime_error("invalid amount of players");
        }
        if (this->hasStarted) {
            throw std::runtime_error("game has started");
        }
        this->_currPlayers.push_back(name);
    }

    std::string Game::winner() {
        if (this->_currPlayers.size() == 1) {
            return this->_currPlayers[0];
        }
        throw std::runtime_error("game is not yet finished");
    }

    void Game::passTurn() {
        ++this->currPlayer;
        this->currPlayer = this->currPlayer % this->_currPlayers.size();
    }

    void Game::revivePlayer(size_t playerIdx, const Player &toRevive) {
        this->_currPlayers.insert(this->_currPlayers.begin() + (int) playerIdx, toRevive.getName());
        if (playerIdx < this->currPlayer) {
            this->currPlayer++;
        }
    }

    size_t Game::executeCoup(const std::string &playerName) {
        for (size_t i = 0; i < this->_currPlayers.size(); ++i) {
            if (this->_currPlayers[i] == playerName) {
                this->_currPlayers.erase(this->_currPlayers.begin() + (int) i);
                this->currPlayer = this->currPlayer % this->_currPlayers.size();
                return i;
            }
        }
        throw std::runtime_error("player doesn't exist in game");
    }

    size_t Game::getCurrPlayer() const {
        return currPlayer;
    }

}
