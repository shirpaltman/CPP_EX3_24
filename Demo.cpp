/**
 * Demo file for Ex3.
 *
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"
using namespace std;
using namespace ariel;

int main() {
    Deck deck;
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1, p2, p3);

    // Starting of the game. Every player places two settlements and two roads.
    catan.ChooseStartingPlayer(); // should print the name of the starting player, assume it is Amit.
    Board& board = catan.getBoard(); // get the board of the game.

    // p1 places two settlements and two roads
    board.placeSettlement(5, p1);
    board.placeRoad(1, p1);

    board.placeSettlement(6, p1);
    board.placeRoad(2, p1);

    // p2 places two settlements and two roads
    board.placeSettlement(9, p2);
    board.placeRoad(3, p2);

    try {
        board.placeSettlement(9, p3); // p3 tries to place a settlement in the same location as p2.
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    board.placeSettlement(10, p2);
    board.placeRoad(4, p2);

    // p3 places two settlements and two roads
    board.placeSettlement(11, p3);
    board.placeRoad(5, p3);

    board.placeSettlement(12, p3);
    board.placeRoad(6, p3);

    // Players take turns
    int roll = p1.rollDice(); // Let's say it prints 4.
    cout << "Roll: " << roll << endl;
    board.allocateResources(roll);
    p1.endTurn();

    roll = p2.rollDice(); // Let's say it prints 9.
    cout << "Roll: " << roll << endl;
    board.allocateResources(roll);
    p2.endTurn();

    roll = p3.rollDice(); // Let's say it prints 3.
    cout << "Roll: " << roll << endl;
    board.allocateResources(roll);
    p3.endTurn();

    roll = p1.rollDice(); // Let's say it prints 6.
    cout << "Roll: " << roll << endl;
    board.allocateResources(roll);
    p1.endTurn();

    roll = p2.rollDice(); // Let's say it prints 9.
    cout << "Roll: " << roll << endl;
    board.allocateResources(roll);
    p2.endTurn();

    p1.addResource(Resources::Brick,30);
    p1.addResource(Resources::Wood,30);
    p1.addResource(Resources::Sheep,30);
    p1.addResource(Resources::Wheat,30);
    p1.addResource(Resources::Ore,30);
    
    p1.buyDevelopmentCard(deck);
    p1.buyDevelopmentCard(deck);
    p1.buyDevelopmentCard(deck);
    p1.buyDevelopmentCard(deck);
    p1.buyDevelopmentCard(deck);
    p1.buyDevelopmentCard(deck);
    p1.buyDevelopmentCard(deck);

    catan.checkForWinner();
    p1.addPoints(10); // Giving p1 10 points to win the game

    catan.checkForWinner();
    
    p1.printPoints();
    p2.printPoints();
    p3.printPoints();

    p1.printResources();
    p2.printResources();
    p3.printResources();
    cout << "test" << endl;


    return 0;
}
