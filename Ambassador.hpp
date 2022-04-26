//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_AMBASSADOR_HPP
#define EX4_CPP_AMBASSADOR_HPP

#include "Player.hpp"

namespace coup {

    class Ambassador : protected Player {
        std::string role() {
            return "Ambassador";
        }
    };
}
#endif //EX4_CPP_AMBASSADOR_HPP
