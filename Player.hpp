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
        std::string _role;

        //the protected constructor prevents instance creation
        Player(Game &currGame, std::string name, std::string currRole);


    public:


        void income();

        void foreign_aid();

        virtual void coup(Player &other_player);

        std::string role();

        int coins();
    };
}

#endif //EX4_CPP_PLAYER_HPP
