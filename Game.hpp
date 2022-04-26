//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_GAME_HPP
#define EX4_CPP_GAME_HPP

#include "vector"
#include "Player.hpp"

namespace coup {
    class Game {
    private:
        std::vector <std::string> _currPlayers;
    public:
        Game();

        std::vector <std::string> players();

        std::string turn();

        std::string winner();
    };
}

#endif //EX4_CPP_GAME_HPP