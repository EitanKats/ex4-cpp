//
// Created by Eitan Kats on 25/04/2022.
//

#include "Contessa.hpp"

namespace coup {
    Contessa::Contessa(Game &currGame, std::string name)
            : Player{currGame, name, "Contessa"} {}

    void Contessa::block(Player &other_player) {

    }
}