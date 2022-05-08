//
// Created by Eitan Kats on 25/04/2022.
//

#include "Player.hpp"
#include "Game.hpp"
#include "exception"
#include <functional>


namespace coup {
    Player::Player(Game &currGame, const std::string &name)
            : _currGame(currGame), _name(name), _coins(0), _isAlive(true) {
        this->_currGame.addPlayer(name);
    }

    void Player::isEligibleForMove() {
        if (this->_currGame.turn() != this->_name) {
            throw std::runtime_error("Not your turn");
        }
        clearCB();
    }

    void Player::isCoupNecessary() const {
        if (this->_coins >= MUST_COUP_AMOUNT) {
            throw std::runtime_error("must execute coup");
        }
    }

    void Player::validateInteractionAction(const Player &otherPlayer) {
        if (!otherPlayer.isAlive()) {
            throw std::runtime_error("interaction is invalid, player is already out of the game");
        }
    }

    void Player::income() {
        this->isEligibleForMove();
        this->isCoupNecessary();
        this->amendCoins(1);
        this->_currGame.passTurn();
    }

    void Player::amendCoins(int diff) {
        if (this->coins() < 0) {
            throw std::runtime_error("error during coin amendment execution");
        }
        if (this->coins() + diff < 0) {
            throw std::runtime_error("error during coin amendment execution");
        }
        this->_coins += diff;
    }

    int Player::coins() const {
        return this->_coins;
    }

    void Player::foreign_aid() {
        this->isEligibleForMove();
        this->isCoupNecessary();
        this->_blockers = {"Duke"};
        this->_rollbackcb = [this]() { this->_coins -= 2; };
        this->amendCoins(2);
        this->_currGame.passTurn();
    }

    void Player::coup(Player &otherPlayer) {
        this->isEligibleForMove();
        this->validateInteractionAction(otherPlayer);
        if (this->_coins < this->coupCost) {
            throw std::runtime_error("insufficient amount of coins");
        }
        this->amendCoins(-this->coupCost);
        this->_currGame.executeCoup(otherPlayer.getName());
        otherPlayer.setIsAlive(false);
    }

    void Player::checkBlock(const Player &blockingPlayer) {
        if (&this->_currGame != &blockingPlayer.getCurrGame()) {
            throw std::runtime_error("cannot block player from different game");
        }
        if (this->_name == blockingPlayer.getName()) {
            throw std::runtime_error("cannot block same player");
        }
        if (this->_blockers.contains(blockingPlayer.role())) {
            this->_rollbackcb();
            this->clearCB();
        } else {
            throw std::runtime_error("block action didn't go through");
        }

    }

    void Player::coupPassTurn(size_t coupedPlayerIdx) {
        if (coupedPlayerIdx > this->_currGame.getCurrPlayer()) {
            this->_currGame.passTurn();
        }
    }

    void Player::clearCB() {
        this->_blockers.clear();
        this->_rollbackcb = []() {};
    }

    const std::string &Player::getName() const {
        return _name;
    }

    Game &Player::getCurrGame() const {
        return _currGame;
    }

    bool Player::isAlive() const {
        return _isAlive;
    }

    void Player::setIsAlive(bool isAlive) {
        _isAlive = isAlive;
    }

}
