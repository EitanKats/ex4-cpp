//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_CONTESSA_HPP
#define EX4_CPP_CONTESSA_HPP

#include "Player.hpp"

namespace coup {

    class Contessa : public Player {
    public:
        Contessa(Game &currGame, const std::string &name);

        void block(Player &other_player);

        std::string role() const override;
    };
}
#endif //EX4_CPP_CONTESSA_HPP
