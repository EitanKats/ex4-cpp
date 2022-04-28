//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_ASSASSIN_HPP
#define EX4_CPP_ASSASSIN_HPP

#include "Player.hpp"

namespace coup {
    class Assassin : public Player {
    public:
        Assassin(Game &currGame,const std::string& name);

        virtual void coup(Player& other_player) override;

        std::string role() const override;
    };

}


#endif //EX4_CPP_ASSASSIN_HPP
