#include "doctest.hpp"
#include "player.hpp"
#include "board.hpp"
#include "catan.hpp"


/*
 * Author: Shir Altman.
 * ID: 325168870
 * Email: shirpaltman@gmail.com
 */

using namespace std;
using namespace doctest;
using namespace ariel;

TEST_CASE("Test Player Actions - Place Settlement and Road") {
    Player player("Test Player");
    Board board;

    player.addResource(Resources::Wood, 1);
    player.addResource(Resources::Brick, 1);
    player.addResource(Resources::Wheat, 1);
    player.addResource(Resources::Sheep, 1);

    board.placeSettlement(10, player);
    player.addResource(Resources::Wood, 1);
    player.addResource(Resources::Brick, 1);
    board.placeRoad(5, player);

    CHECK(board.getVertices().at(10).getOwner() == player.getName());
    CHECK(board.getEdges().at(5).getOwner() == player.getName());
}
TEST_CASE("Test Player Actions - Trade Resources") {
    Player trader1("Trader 1");
    Player trader2("Trader 2");

    trader1.addResource(Resources::Wood, 3);
    trader1.addResource(Resources::Brick, 2);
    trader2.addResource(Resources::Sheep, 2);
    trader2.addResource(Resources::Wheat, 3);

    trader1.trade(trader2, "Wood", "Sheep", 2, 2);

    CHECK(trader1.getResource(Resources::Wood) == 1);
    CHECK(trader1.getResource(Resources::Sheep) == 2);
    CHECK(trader2.getResource(Resources::Wood) == 2);
}


// TEST_CASE("Test Game Logic - Choose Starting Player") {
//     Player p1("Roey");
//     Player p2("Yael");
//     Player p3("Shir");
//     Board board;
//     Catan catan(p1, p2, p3);

//     catan.ChooseStartingPlayer();

//     CHECK(catan.getPlayers().at(catan.getPlayerByName(catan.getPlayers().at(catan.getPlayerByName("Roey"))->getName()) % 3)->getName() == p1.getName() || 
//           catan.getPlayers().at(catan.getPlayerByName(catan.getPlayers().at(catan.getPlayerByName("Yael"))->getName()) % 3)->getName() == p2.getName() || 
//           catan.getPlayers().at(catan.getPlayerByName(catan.getPlayers().at(catan.getPlayerByName("Shir"))->getName()) % 3)->getName() == p3.getName());
// }

TEST_CASE("Test Game Logic - Roll Dice") {
   Player p1("Roey");
    Player p2("Yael");
    Player p3("Shir");
    Board board;
    Catan catan(p1, p2, p3);

    catan.ChooseStartingPlayer();
    catan.rollDiceOfCurrentPlayer();
    int roll = p1.rollDice();
    CHECK(roll >= 2);
    CHECK(roll <= 12);
}

TEST_CASE("Test Board - Invalid Vertex Access") {
    Board board;
    int invalidVertexIndex = -1;
    CHECK_THROWS_AS(board.getVertices().at(static_cast<size_t>(invalidVertexIndex)), std::out_of_range);
}

TEST_CASE("Test Board - Invalid Edge Access") {
    Board board;
    int invalidEdgeIndex = -1;
    CHECK_THROWS_AS(board.getEdges().at(static_cast<size_t>(invalidEdgeIndex)), std::out_of_range);
}



TEST_CASE("Test Player - Add and Remove Resources") {
    Player player("TestPlayer");
    player.addResource(Resources::Brick, 3);
    player.addResource(Resources::Wood, 2);

    CHECK(player.getResource(Resources::Brick) == 3);
    CHECK(player.getResource(Resources::Wood) == 2);

    player.removeResource(Resources::Brick, 2);
    CHECK(player.getResource(Resources::Brick) == 1);
}

TEST_CASE("Test Player - Buy Settlements and Roads") {
    Player player("TestPlayer");
    Board board;

    player.addResource(Resources::Brick, 3);
    player.addResource(Resources::Sheep, 2);
    player.addResource(Resources::Wheat, 2);
    player.addResource(Resources::Wood, 3);
    board.placeSettlement(1, player);
    board.placeSettlement(2, player);
    board.placeRoad(1, player);

    CHECK(player.getSettlementCount() == 4); // initially 2 settlements
    CHECK(player.getRoadCount() == 3);
    CHECK(player.getPoints() == 2); // 1 point per settlement
}

TEST_CASE("Test Gameplay - Basic Actions") {
    Player player("TestPlayer");
    Board board;
    player.addResource(Resources::Wood, 1);
    player.addResource(Resources::Brick, 1);
    player.addResource(Resources::Sheep, 1);
    player.addResource(Resources::Wheat, 1);
    
    board.placeSettlement(1, player);
    player.addResource(Resources::Wood, 1);
    player.addResource(Resources::Brick, 1);
    board.placeRoad(2, player);

    CHECK(board.getVertices().at(1).getOwner() == player.getName());
    CHECK(board.getEdges().at(2).getOwner() == player.getName());
}


TEST_CASE("Test Player - End Turn") {
    Player player("TestPlayer");
    player.endTurn();
    CHECK(!player.getIsPlaying());
}

TEST_CASE("Test Game - Check Winner") {
    Player p1("Player1");
    Player p2("Player2");
    Player p3("Player3");
    Catan catan(p1, p2, p3);
    catan.addPlayer(&p1);
    catan.addPlayer(&p2);
    catan.addPlayer(&p3);

    p1.addPoints(10);
    catan.checkForWinner();
    CHECK(p1.getPlayerPoints() >= 10);
}

TEST_CASE("Test Player - Buy Development Card") {
    Player player("TestPlayer");
    Deck deck;

    player.addResource(Resources::Wheat, 1);
    player.addResource(Resources::Sheep, 1);
    player.addResource(Resources::Ore, 1);
    player.buyDevelopmentCard(deck);

    CHECK(player.getDevelopmentCards().size() == 1);
}

TEST_CASE("Test Board - Allocate Resources") {
    Player player("TestPlayer");
    Board board;
    Tile tile(Resources::Wood, 6, {}, {1, 2, 3});
    board.getTiles().push_back(tile);

    board.placeSettlement(1, player);
    board.allocateResources(6);

    CHECK(player.getResource(Resources::Wood) == 1);
}

TEST_CASE("Test Player - Knight Card") {
    Player player("TestPlayer");
    Board board;
    KnightCard knight;
    
    player.addResource(Resources::Wheat, 1);
    player.addResource(Resources::Sheep, 1);
    player.addResource(Resources::Ore, 1);
    player.addDevelopmentCard(&knight);
    
    knight.playEffect(player, board);
    CHECK(player.getKnightCount() == 1);
}


TEST_CASE("Test Player - Monopoly Card") {
    Player player("TestPlayer");
    Player other("OtherPlayer");
    Board board;
    ProgressCard monopoly(ProgressType::Monopoly);

    other.addResource(Resources::Wood, 5);
    player.addDevelopmentCard(&monopoly);
    
    monopoly.playEffect(player, board);
    CHECK(player.getResource(Resources::Wood) == 5);
    CHECK(other.getResource(Resources::Wood) == 0);
}

TEST_CASE("Test Player - Year of Plenty Card") {
    Player player("TestPlayer");
    Board board;
    ProgressCard yearOfPlenty(ProgressType::YearOfPenlty);

    player.addDevelopmentCard(&yearOfPlenty);
    
    yearOfPlenty.playEffect(player, board);
    CHECK(player.getResource(Resources::Brick) == 1);
    CHECK(player.getResource(Resources::Wood) == 1);
}

TEST_CASE("Test Player - Road Building Card") {
    Player player("TestPlayer");
    Board board;
    ProgressCard roadBuilding(ProgressType::RoadBuilding);

    player.addDevelopmentCard(&roadBuilding);
    
    roadBuilding.playEffect(player, board);
    CHECK(player.getRoadCount() == 2); // Assuming 2 roads are placed
}


TEST_CASE("Test Game - Rotate Players") {
    Player p1("Player1");
    Player p2("Player2");
    Player p3("Player3");
    Catan catan(p1, p2, p3);

    catan.nextTurn();
    CHECK(catan.getCurrentPlayer().getName() == "Player2");

    catan.nextTurn();
    CHECK(catan.getCurrentPlayer().getName() == "Player3");

    catan.nextTurn();
    CHECK(catan.getCurrentPlayer().getName() == "Player1");
}

TEST_CASE("Test Player - Multiple Trades") {
    Player trader1("Trader 1");
    Player trader2("Trader 2");

    trader1.addResource(Resources::Wood, 5);
    trader2.addResource(Resources::Brick, 5);

    trader1.trade(trader2, "Wood", "Brick", 2, 2);
    trader1.trade(trader2, "Wood", "Brick", 2, 2);

    CHECK(trader1.getResource(Resources::Wood) == 1);
    CHECK(trader1.getResource(Resources::Brick) == 4);
    CHECK(trader2.getResource(Resources::Wood) == 4);
}

TEST_CASE("Test Game - Multiple Development Cards") {
    Player player("TestPlayer");
    Deck deck;

    for (int i = 0; i < 5; ++i) {
        player.addResource(Resources::Wheat, 1);
        player.addResource(Resources::Sheep, 1);
        player.addResource(Resources::Ore, 1);
        player.buyDevelopmentCard(deck);
    }

    CHECK(player.getDevelopmentCards().size() == 5);
}

TEST_CASE("Test Player - Increment Knight Count") {
    Player player("TestPlayer");
    KnightCard knight;
    Board board;


    player.addDevelopmentCard(&knight);
    knight.playEffect(player,board);

    CHECK(player.getKnightCount() == 1);
}

TEST_CASE("Test Player - Trade and Check Resources") {
    Player trader1("Trader 1");
    Player trader2("Trader 2");

    trader1.addResource(Resources::Wood, 5);
    trader2.addResource(Resources::Brick, 5);

    trader1.trade(trader2, "Wood", "Brick", 3, 2);

    CHECK(trader1.getResource(Resources::Wood) == 2);
    CHECK(trader1.getResource(Resources::Brick) == 2);
    CHECK(trader2.getResource(Resources::Wood) == 3);
    CHECK(trader2.getResource(Resources::Brick) == 3);
}

















