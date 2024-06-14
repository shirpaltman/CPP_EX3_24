#include "catan.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include  <random>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "board.hpp"


using namespace std;
namespace ariel{

    
    Catan::Catan(Player& p1, Player& p2, Player& p3) : board() {
        board.addPlayer(p1);
        board.addPlayer(p2);
        board.addPlayer(p3);

        players.push_back(&p1);
        players.push_back(&p2);
        players.push_back(&p3);
    }                             

    

  
  

   

    size_t Catan::getPlayerByName(const string &name) const
    {
        for(size_t i=0; i<players.size();++i){
            if(players[i]->getName() == name){
                return i;
            }
        }
        throw invalid_argument("Player not found");
    }
     void Catan::rollDiceOfCurrentPlayer()
    {
        size_t i = getPlayerByName(players[static_cast<size_t>(currentPlayer)]->getName());
        Player& currentPlayerR = *players[static_cast<size_t>(currentPlayer)];
        int roll = currentPlayerR.rollDice();
        cout << currentPlayerR.getName() << " rolled a " << roll << endl;
        board.allocateResources(roll);
        printAllResources();
        nextTurn();
    }

    

    void Catan::ChooseStartP(){
        // random_device rd;
        // mt19937 gen(rd());
        size_t i=static_cast<size_t>(rand()%3 +1);
        //srand(static_cast<unsigned>(time(nullptr)));
        currentPlayer = static_cast<int>(i);
        cout << "Starting player: " << players[static_cast<size_t>(currentPlayer)]->getName() << endl;
    }

    void Catan::nextTurn(){
        currentPlayer = (currentPlayer + 1) % static_cast<int>(players.size());
        cout << "Next player: " << players[static_cast<size_t>(currentPlayer)]->getName() << endl;
    }
    void Catan::printWinner(){
         for(const auto& player : players){
            if(player->getPlayerPoints() >= 10){
                cout << player->getPlayerPoints() <<endl;
                cout << " The winner is  " << player->getName() << endl;
                return;
            }
        }
        cout <<"No winner yet." <<endl;
    }
    void Catan::printGameStatus() const{
        cout << "Current game status: " << endl;
        for (const auto& player : players){
            cout<< player ->getName()<< " has" << player->getPlayerPoints() << "points"  << endl;
        }
    }

    Player &Catan::ChooseStartingPlayer()
    {
        currentPlayer = static_cast<int>(rand() % 3+1);
        cout << "Starting player: " << players[static_cast<size_t>(currentPlayer)]->getName() << endl;
        return *players[static_cast<size_t>(currentPlayer)];
    }
    void Catan::addPlayer(Player* player)
    {
        players.push_back(player);
    }
    const vector<Player*> &Catan::getPlayers() const{
        return players;
    }  

    void Catan::printAllResources() const {
        for (const auto& player : players) {
            player->printResources();
        }
    }
        Player& Catan::getCurrentPlayer() {
        return *players[static_cast<size_t>(currentPlayer)];
    }



    
}
