#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include <vector>
#include "board.hpp"
#include <map>

using namespace std;



  
namespace ariel{
    
    enum class Resources{
        Desert,
        Brick,
        Sheep,  
        Wheat,
        Wood,
        Ore
   
    };
    class Player{
        private:
        string name;
        int playerPoints;
        map<Resources,int> resources;
        int settlements;
        int roads;
        int cities;

        public:
        Player( const string& name);
        void addPoints(int points);
        void placeSettelemnt(const vector<int>&placesNum,Board& board);
        void placeRoad(const vector<int>&placesNum,Board& board);
        void rollDice()const;
        void endTurn();
        void trade(Player& other,string give ,string get,int totalGive,int totalGet);
        void buyDevelopmentCard();
        void printPoints()const;
        void printResources()const;
        const string& getName()const;
        int getPlayerPoints()const;
    };
    #endif
}

