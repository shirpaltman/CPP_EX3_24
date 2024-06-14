#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include "Card.hpp"
#include "resources.hpp"
#include "board.hpp"
#include "player.hpp"

using namespace std;

// namespace ariel{
//     class Player;
//     class Board;
// }



namespace ariel{

    class Catan{
    private:
        vector<Player*> players;  //check?
        Board board;
        int currentPlayer;
    public:
    
        void ChooseStartP(); 
          //choose who will be the first player to play
        Board& getBoard(){return board;}
        void nextTurn();
        void printWinner();
        void printGameStatus()const;
        Player& ChooseStartingPlayer();
        void addPlayer(Player* player);
        const std::vector<Player*>& getPlayers()const;
        Catan (Player &player1,Player &player2,Player &player3);
        void checkForWinner();
        void rollDiceOfCurrentPlayer();
        size_t getPlayerByName(const string& name)const;
        void printAllResources()const;
        Player& getCurrentPlayer();
        //~Catan();
    };
}
#endif // CATAN_HPP