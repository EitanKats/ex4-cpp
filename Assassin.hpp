//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_ASSASSIN_HPP
#define EX4_CPP_ASSASSIN_HPP

#include "Player.hpp"
namespace coup {
    class Assassin: protected Player{
        std::string role() {
            return "Assassin";
        }
    };

}


#endif //EX4_CPP_ASSASSIN_HPP
