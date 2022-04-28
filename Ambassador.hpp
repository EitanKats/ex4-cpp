//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_AMBASSADOR_HPP
#define EX4_CPP_AMBASSADOR_HPP

#include "Player.hpp"

namespace coup {

    class Ambassador : public Player {
    public:
        Ambassador(Game &currGame, const std::string& name);

        void transfer(const Player &first_player, const Player &second_player);

        void block(const Player &other_player);

        std::string role() const override;
    };
}
#endif //EX4_CPP_AMBASSADOR_HPP
