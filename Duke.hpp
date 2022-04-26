//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_DUKE_HPP
#define EX4_CPP_DUKE_HPP

#include "Player.hpp"

namespace coup {
    class Duke : public Player {

    public:
        Duke(Game &currGame, std::string name);

        void tax();

        void block(Player &toBlock);
    };
}
#endif //EX4_CPP_DUKE_HPP
