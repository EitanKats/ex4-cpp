//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_DUKE_HPP
#define EX4_CPP_DUKE_HPP

#include "Player.hpp"

namespace coup {
    class Duke : protected Player {

    public:
        Duke(Game &currGame, std::string name);

        std::string role() {
            return "Duke";
        }
    };
}
#endif //EX4_CPP_DUKE_HPP
