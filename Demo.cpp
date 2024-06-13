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

int main()
{
    Deck deck;
    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");
    Catan catan(p1, p2, p3);
    // Starting of the game. Every player places two settlements and two roads.
    catan.ChooseStartingPlayer(); // should print the name of the starting player, assume it is Amit.
    Board& board = catan.getBoard(); // get the board of the game.
    board.printBoard();

    // p1 places two settlements and two roads
    vector<string> places1 = {"Forest", "Hills"};
    vector<int> placesNum1 = {5, 6};
    board.placeSettelemnt(p1, places1, placesNum1);
    board.placeRoad(p1, places1, placesNum1);

    vector<string> places2 = {"Agricultural Land", "Desert"};
    vector<int> placesNum2 = {3, 4};
    board.placeSettelemnt(p1, places2, placesNum2);
    board.placeRoad(p1, places2, placesNum2);

    // p2 places two settlements and two roads
    vector<string> places3 = {"Mountains", "Pasture Land"};
    vector<int> placesNum3 = {4, 9};
    board.placeSettelemnt(p2, places3, placesNum3);
    board.placeRoad(p2, places3, placesNum3);

    try {
        board.placeSettelemnt(p3, places3, placesNum3); // p3 tries to place a settlement in the same location as p2.
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    vector<string> places4 = {"Forest", "Pasture Land"};
    vector<int> placesNum4 = {5, 9};
    board.placeSettelemnt(p2, places4, placesNum4);
    board.placeRoad(p2, places4, placesNum4);

    // p3 places two settlements and two roads
    vector<string> places5 = {"Mountains", "Pasture Land"};
    vector<int> placesNum5 = {3, 8};
    board.placeSettelemnt(p3, places5, placesNum5);
    board.placeRoad(p3, places5, placesNum5);

    vector<string> places6 = {"Agricultural Land", "Pasture Land"};
    vector<int> placesNum6 = {3, 9};
    board.placeSettelemnt(p3, places6, placesNum6);
    board.placeRoad(p3, places6, placesNum6);

    // Players take turns
    p1.rollDice(); // Let's say it prints 4. Then, p2 gets ore from the mountains.
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    p1.rollDice();
    board.placeRoad(p1, places1, placesNum1); // p1 continues to build a road.
    p1.endTurn(); // p1 ends his turn.


    p2.rollDice(); // Let's say it prints 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    p2.endTurn(); // p2 ends his turn.

    p3.rollDice(); // Let's say it prints 3. Then, p3 gets wheat from the Agricultural Land and ore from the mountains, p1 gets wheat from the Agricultural Land.
    p3.endTurn(); // p3 ends his turn.

    try {
        p2.rollDice(); // p2 tries to roll the dice again, but it's not his turn.
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }

    p1.rollDice(); // Let's say it prints 6. Then, p1 gets bricks from the hills.
    p1.trade(p2, "Wood", "Brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    p1.endTurn(); // p1 ends his turn.

    p2.rollDice(); // Let's say it prints 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    p2.buyDevelopmentCard(deck); // p2 buys a development card. Let's say it is a bonus points card.
    p2.endTurn(); // p2 ends his turn.

    p1.printPoints(); // p1 has 2 points because he has two settlements.
    p2.printPoints(); // p2 has 3 points because he has two settlements and a bonus points card.
    p3.printPoints(); // p3 has 2

    return 0;
}
