//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_AMBASSADOR_HPP
#define EX4_CPP_AMBASSADOR_HPP

#include "Player.hpp"

namespace coup {

    class Ambassador : public Player {
    public:
        Ambassador(Game &currGame, std::string name);

        void transfer(const Player &first_player, const Player &second_player);

        void block(const Player &other_player);
    };
}
#endif //EX4_CPP_AMBASSADOR_HPP
