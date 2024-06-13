#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include <vector>
#include "Card.hpp"
#include "resources.hpp"
#include <map>
#include <unordered_map>
//#include "board.hpp"


using namespace std; 


namespace ariel{
    
    //class Deck;
    class Board;
   
    class Player{
        private:
        string name;
        int playerPoints;
        bool turn;
        unordered_map<Resources,int> resources;
        //vector<unique_ptr<Card>> deck;
        vector<Card*> developmentCards;
        
        int settlements;
        int roads;
        int cities;

        public:
        Player( const string& name) ;
        string getName() const;
        void addPoints(int amount){
            playerPoints += amount;
        }
        int getPoints() const{
            return playerPoints;
        }
        void incrementPoints(int increment){playerPoints = playerPoints + increment;}
        int rollDice()const;
        void endTurn();
        void trade(Player& other, string give ,string get,int totalGive,int totalGet);
        void buyDevelopmentCard(Deck& deck);
        void printPoints()const;
        void printResources()const;
        int getPlayerPoints()const;
        int getResource(Resources resource)const;
        void addResource(Resources resource,int amount){
            resources[resource] += amount;
        }
    };   
}
#endif 
