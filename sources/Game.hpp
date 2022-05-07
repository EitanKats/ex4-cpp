//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_GAME_HPP
#define EX4_CPP_GAME_HPP

#include "vector"
#include "string"
#include "Player.hpp"

namespace coup {
    class Player;

    class Game {

    private:
        std::vector<std::string> _currPlayers;
        size_t currPlayer = 0;
        bool hasStarted = false;

        //returns the index of the player that was couped


    public:

        void addPlayer(const std::string &name);

        std::vector<std::string> players();

        std::string turn();

        std::string winner();

        size_t getCurrPlayer() const;

        void passTurn();

        size_t executeCoup(const std::string &playerName);

        void revivePlayer(size_t playerIdx, const Player &toRevive);
    };
}

#endif //EX4_CPP_GAME_HPP
