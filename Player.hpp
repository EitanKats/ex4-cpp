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

    class Game;

    class Player {

    protected:
        std::string _name;
        int _coins;
        Game &_currGame;
    public:
        Game &getCurrGame() const;

    protected:
        int coupCost = 7;
        std::function<void()> _rollbackcb;
        std::set<std::string> _blockers;

        //the protected constructor prevents instance creation
        Player(Game &currGame, const std::string &name);

        void isEligibleForMove();

        void isCoupNecessary();


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
    };
}

#endif //EX4_CPP_PLAYER_HPP
