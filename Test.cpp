//
// Created by Eitan Kats on 29/04/2022.
//

#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

using namespace coup;

TEST_CASE ("Test player basic functionalities") {

    Game game_1{};

    Duke duke{game_1, "Ori"};
    Assassin assassin{game_1, "Yaniv"};
    Ambassador ambassador{game_1, "Adi"};
    Captain captain{game_1, "Eitan"};
    Contessa contessa{game_1, "Alona"};


            SUBCASE("Duke check") {
                CHECK_NOTHROW(duke.role());
                CHECK_EQ(duke.role(), "Duke");
                CHECK_EQ(duke.coins(), 0);
    }
            SUBCASE("Assassin check") {
                CHECK_NOTHROW(assassin.role());
                CHECK_EQ(assassin.role(), "Assassin");
    }
            SUBCASE("Ambassador check") {
                CHECK_NOTHROW(ambassador.role());
                CHECK_EQ(ambassador.role(), "Ambassador");
    }
            SUBCASE("Captain check") {
                CHECK_NOTHROW(captain.role());
                CHECK_EQ(captain.role(), "Captain");
    }
            SUBCASE("Contessa check") {
                CHECK_NOTHROW(contessa.role());
                CHECK_EQ(contessa.role(), "Contessa");
    }

            SUBCASE("game check") {
                CHECK_EQ(game_1.turn(), "Ori");
                CHECK_NOTHROW(duke.income());
                CHECK_EQ(duke.coins(), 1);
                CHECK_THROWS(duke.income());
                CHECK_THROWS(duke.coup(assassin));
//                this checks if the modulus works after one round trip
        for (int i = 0; i < 4; ++i) {
                    CHECK_NOTHROW(game_1.passTurn());
        }
                CHECK_EQ(game_1.turn(), "Ori");
                CHECK_THROWS(game_1.winner());

    }


}