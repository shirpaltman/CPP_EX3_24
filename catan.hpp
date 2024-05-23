#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "player.hpp"
#include "board.hpp"
#include <memory>
using namespace std;
namespace ariel{

class Catan{
private:
    vector<unique_ptr<Player>> players;  //check?
    Board board;
    int currentPlayer;
public:
  
    void ChooseStartP();       //choose who will be the first player to play
    Board getBoard();
    void nextTurn();
    void printWinner();
    void printGameStatus()const;
    void addPlayer(unique_ptr<Player> player);
    const vector<unigue_ptr<Player>>& getPlayers()const;
        Catan (Player player1,Player player2,Player player3,Player player4);
    Catan (Player player1,Player player2,Player player3);
    Catan (Player player1,Player player2);
};
#endif

}