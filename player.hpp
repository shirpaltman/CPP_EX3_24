#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include <vector>
#include "board.hpp"
#include "cards.hpp"
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
        vector<unique_ptr<Card>> developmentCards;
        int settlements;
        int roads;
        int cities;

        public:
        Player( const string& name);
        void addPoints(int points);
        void placeSettelemnt(const vector<int>&placesNum,Board& board);
        void placeRoad(const vector<int>&placesNum,Board& board);
        int rollDice()const;
        void endTurn();
        void trade(Player& other,string give ,string get,int totalGive,int totalGet);
        void buyDevelopmentCard(Deck& deck);
        void printPoints()const;
        void printResources()const;
        const string& getName()const;
        int getPlayerPoints()const;
    };   
}
#endif
