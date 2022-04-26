//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_CONTESSA_HPP
#define EX4_CPP_CONTESSA_HPP

#include "Player.hpp"

namespace coup {

    class Contessa : protected Player {
        std::string role() {
            return "Contessa";
        }
    };
}
#endif //EX4_CPP_CONTESSA_HPP
