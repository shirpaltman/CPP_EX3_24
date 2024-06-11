#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include <memory>
#include <string>
#include <stdexcept>
#include "player.hpp"
#include "board.hpp"
#include "Card.hpp"
using namespace std;
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
        const vector<Player*>& getPlayers()const;
        Catan (Player player1,Player player2,Player player3,Player player4);
        Catan (Player player1,Player player2,Player player3);
        Catan (Player player1,Player player2);
        void checkForWinner();
        ~Catan();
    };
}
#endif // CATAN_HPP