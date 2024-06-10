#include "catan.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include  <random>

using namespace std;
namespace ariel{

    Catan::Catan(Player player1,Player player2,Player player3,Player player4): currentPlayer(0){
        players.push_back(make_unique<Player>(move(player1)));
        players.push_back(make_unique<Player>(move(player2)));
        players.push_back(make_unique<Player>(move(player3)));
        players.push_back(make_unique<Player>(move(player4)));
    } 
    Catan::Catan(Player player1,Player player2,Player player3): currentPlayer(0){
        players.push_back(make_unique<Player>(move(player1)));
        players.push_back(make_unique<Player>(move(player2)));
        players.push_back(make_unique<Player>(move(player3)));
    } 

    Catan::Catan(Player player1,Player player2): currentPlayer(0){
        players.push_back(make_unique<Player>(move(player1)));
        players.push_back(make_unique<Player>(move(player2)));
    }
    void Catan::checkForWinner(){
        for(const auto& player : players){
            if(player->getPlayerPoints() >= 10){
                cout << " The winner is  " << player->getName() << endl;
                break;
            }
        }
    }

    void Catan::ChooseStartP(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, players.size() - 1);
        currentPlayer = dis(gen);
        cout<< "Starting player: " <<players[currentPlayer]->getName <<endl;
    }

    void Catan::nextTurn(){
        currentPlayer = (currentPlayer + 1) % players.size();
        cout << "Next player: " << players[currentPlayer]->getName << endl;
    }
    void Catan::printWinner(){
         for(const auto& player : players){
            if(player->getPlayerPoints() >= 10){
                cout << " The winner is  " << player->getName() << endl;
                break;
            }
        }
    }
    void Catan::printGameStatus() const{
        cout << "Current game status: " << endl;
        for (const auto& player : players){
            cout<< player ->getName()<< "has" << player->getPlayerPoints() << "points"  << endl;
        }
    }

    Player &Catan::ChooseStartingPlayer()
    {
        return *players[currentPlayer];
    }
    void Catan::addPlayer(unique_ptr<Player> player)
    {
        players.push_back(move(player));
    }
    const vector<unique_ptr<Player>> &Catan::getPlayers() const{
        return players;
    }

    
}
