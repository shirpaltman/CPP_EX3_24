/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/



#include "catan.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "board.hpp"

using namespace std;
namespace ariel {

    // Constructor to initialize the game with three players and add them to the board
    Catan::Catan(Player& p1, Player& p2, Player& p3) : board() {
        board.addPlayer(p1);
        board.addPlayer(p2);
        board.addPlayer(p3);

        players.push_back(&p1);
        players.push_back(&p2);
        players.push_back(&p3);
    }

    // Get the index of a player by their name
    size_t Catan::getPlayerByName(const string &name) const {
        for (size_t i = 0; i < players.size(); ++i) {
            if (players[i]->getName() == name) {
                return i;
            }
        }
        throw invalid_argument("Player not found");
    }

    // Roll the dice for the current player, allocate resources, and move to the next turn
    void Catan::rollDiceOfCurrentPlayer() {
        size_t i = getPlayerByName(players[static_cast<size_t>(currentPlayer)]->getName());
        Player& currentPlayerR = *players[static_cast<size_t>(currentPlayer)];
        int roll = currentPlayerR.rollDice();
        cout << currentPlayerR.getName() << " rolled a " << roll << endl;
        board.allocateResources(roll);
        printAllResources();
        nextTurn();
    }

    // Choose a random starting player
    void Catan::ChooseStartP() {
        size_t i = static_cast<size_t>(rand() % 3 + 1);
        currentPlayer = static_cast<int>(i);
        cout << "Starting player: " << players[static_cast<size_t>(currentPlayer)]->getName() << endl;
    }

    // Move to the next player's turn
    void Catan::nextTurn() {
        currentPlayer = (currentPlayer + 1) % static_cast<int>(players.size());
        cout << "Next player: " << players[static_cast<size_t>(currentPlayer)]->getName() << endl;
    }

    // Print the winner if a player has at least 10 points
    void Catan::printWinner() {
        for (const auto& player : players) {
            if (player->getPlayerPoints() >= 10) {
                cout << player->getPlayerPoints() << endl;
                cout << " The winner is  " << player->getName() << endl;
                return;
            }
        }
        cout << "No winner yet." << endl;
    }

    // Print the current game status including each player's points
    void Catan::printGameStatus() const {
        cout << "Current game status: " << endl;
        for (const auto& player : players) {
            cout << player->getName() << " has " << player->getPlayerPoints() << " points" << endl;
        }
    }

    // Choose and return a random starting player
    Player &Catan::ChooseStartingPlayer() {
        currentPlayer = static_cast<int>(rand() % 3 + 1);
        cout << "Starting player: " << players[static_cast<size_t>(currentPlayer)]->getName() << endl;
        return *players[static_cast<size_t>(currentPlayer)];
    }

    // Add a player to the game
    void Catan::addPlayer(Player* player) {
        players.push_back(player);
    }

    // Get the list of players in the game
    const vector<Player*> &Catan::getPlayers() const {
        return players;
    }

    // Print the resources of all players
    void Catan::printAllResources() const {
        for (const auto& player : players) {
            player->printResources();
        }
    }

    // Get the current player
    Player& Catan::getCurrentPlayer() {
        return *players[static_cast<size_t>(currentPlayer)];
    }

}
