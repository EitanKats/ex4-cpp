//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_PLAYER_HPP
#define EX4_CPP_PLAYER_HPP

#include "string"
#include "Game.hpp"

namespace coup {

    class Player {
    protected:
        std::string _name;
        int _coins;
        Game _currGame;

        Player(Game &currGame, std::string name);

        virtual std::string role() = 0;

    public:
        int income();

        void foreign_aid();

        void coup();


    };
}

#endif //EX4_CPP_PLAYER_HPP
