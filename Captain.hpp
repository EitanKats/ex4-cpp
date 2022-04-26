//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_CAPTAIN_HPP
#define EX4_CPP_CAPTAIN_HPP

#include "Player.hpp"

namespace coup {

    class Captain : protected Player {
        std::string role() {
            return "Captain";
        }

    };
}


#endif //EX4_CPP_CAPTAIN_HPP
