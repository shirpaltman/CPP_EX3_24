/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
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
    catan.addPlayer(&p1);
    catan.addPlayer(&p2);
    catan.addPlayer(&p3);

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

    p1.printResources();
    p2.printResources();
    p3.printResources();
  

  // Players gather resources
    p1.addResource(Resources::Ore, 1);
    p1.addResource(Resources::Wheat, 1);
    p1.addResource(Resources::Sheep, 1);

    // Player 1 buys development cards
    try {
        p1.buyDevelopmentCard(deck,board);
        p1.buyDevelopmentCard(deck,board);
        p1.buyDevelopmentCard(deck,board);
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    }



        // Player 1 plays development cards
    for (Card* card : p1.getDevelopmentCards()) {
        if (card->getType() == CardType::VictoryPoint) {
            cout << "Victory Point card played!" << endl;
            p1.addPoints(1);
        } else if (card->getType() == CardType::Knight) {
            cout << "Knight card played!" << endl;
            static_cast<KnightCard*>(card)->playEffect(p1, board);
        } else if (card->getType() == CardType::Progress) {
            ProgressCard* progressCard = static_cast<ProgressCard*>(card);
            if (progressCard->getProgressType() == ProgressType::RoadBuilding) {
                cout << "Road Building card played!" << endl;
                // Logic for placing 2 roads
            } else if (progressCard->getProgressType() == ProgressType::YearOfPenlty) {
                cout << "Year of Plenty card played!" << endl;
                // Logic for drawing 2 resource cards of choice
            } else if (progressCard->getProgressType() == ProgressType::Monopoly) {
                cout << "Monopoly card played!" << endl;
                // Logic for claiming all resource cards of a specific type
            }
        }
    }
   
        p1.trade(p2, "Brick", "Wood", 2, 2);
  
    p1.printResources();
    p2.printResources();
    p3.printResources();


   

    p1.addResource(Resources::Brick,30);
    p1.addResource(Resources::Wood,30);
    p1.addResource(Resources::Sheep,30);
    p1.addResource(Resources::Wheat,30);
    p1.addResource(Resources::Ore,30);



    

    
    p1.buyDevelopmentCard(deck,board);
    p1.buyDevelopmentCard(deck,board);
    p1.buyDevelopmentCard(deck,board);
    p1.buyDevelopmentCard(deck,board);
    p1.buyDevelopmentCard(deck,board);
    p1.buyDevelopmentCard(deck,board);
    p1.buyDevelopmentCard(deck,board);

    catan.printWinner();
    p1.addPoints(10); // Giving p1 10 points to win the game

    catan.printWinner();
    
    p1.printPoints();
    p2.printPoints();
    p3.printPoints();

    p1.printResources();
    p2.printResources();
    p3.printResources();
    cout << "test" << endl;    
    cout << "End of the game." << endl;

    return 0;
}
