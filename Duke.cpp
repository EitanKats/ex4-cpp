//
// Created by Eitan Kats on 25/04/2022.
//

#include "Duke.hpp"
#include "Game.hpp"
#include "string"
#include "Player.hpp"

namespace coup {
    Duke::Duke(Game &currGame, std::string name) : Player{currGame, name} {

    }
}
