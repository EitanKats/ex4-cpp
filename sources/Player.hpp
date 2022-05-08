//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_PLAYER_HPP
#define EX4_CPP_PLAYER_HPP

#include "string"
#include "Game.hpp"
#include <functional>
#include "set"
#include "string"

namespace coup {
    const int MUST_COUP_AMOUNT = 10;
    const int REGULAR_COUP_COST = 7;

    class Game;

    class Player {

    protected:
        std::string _name;
        int _coins;
        Game &_currGame;
    public:
        Game &getCurrGame() const;

    protected:
        int coupCost = REGULAR_COUP_COST;
        std::function<void()> _rollbackcb;
        std::set<std::string> _blockers;
        bool _isAlive = false;

        //the protected constructor prevents instance creation
        Player(Game &currGame, const std::string &name);

        void isEligibleForMove();

        void isCoupNecessary() const;

        void coupPassTurn(size_t coupedPlayerIdx);

        void validateInteractionAction(const Player &otherPlayer);

    public:
        bool isAlive() const;

    private:
        void clearCB();

    public:


        void income();

        void foreign_aid();

        virtual void coup(Player &otherPlayer);

        virtual std::string role() const = 0;

        int coins() const;

        void checkBlock(const Player &blockingPlayer);

        void amendCoins(int diff);

        const std::string &getName() const;

        void setIsAlive(bool isAlive);
    };
}

#endif //EX4_CPP_PLAYER_HPP
