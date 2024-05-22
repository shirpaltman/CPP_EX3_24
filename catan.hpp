#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "player.hpp"
#include "board.hpp"
using namespace std;
namespace ariel{

class Catan
{
private:
    vector<Player> players;
    Board board;
public:
    Catan (Player player1,player2,player3);
    void ChooseStartingPlayer();
    Board getBoard();
    void printWinner();
};
#endif

}