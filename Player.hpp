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
        Game &_currGame;

        //the protected constructor prevents instance creation
        Player(Game &currGame, const std::string& name);


    public:


        void income();

        void foreign_aid();

        virtual void coup(Player &other_player);

        virtual std::string role() const = 0;

        int coins();
    };
}

#endif //EX4_CPP_PLAYER_HPP
