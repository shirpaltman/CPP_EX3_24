#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include <vector>
#include "board.hpp"

using namespace std;
namespace ariel{
    class Player{
        private:
        string name;

        public:
        Player(string name);
        void placeSettelemnt(vector<string> places,vector<int>placesNum,Board& board);
        void placeBoard(vector<string>,vector<int>,Board& board);
        void rollDice();
        void endTurn();
        void trade(Player& other,string give ,string get,int totalGive,int totalGet);
        void buyDevelopmentCard();
        void printPoints();
    
    };
    #endif
}

