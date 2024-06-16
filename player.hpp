/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/


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
    
    class Deck;
    class Board;
   
    class Player{
        private:
        string name;
        int playerPoints;
        int KnightCount;
        bool isPlaying;
        unordered_map<Resources,int> resources;
        vector<Card*> developmentCards;
        int settlements;
        int roads;
        int cities;
        int settlementCount;
        int roadCount;

        public:
        Player( const string& name) ;
        ~Player();
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
        void buyDevelopmentCard(Deck& deck,Board& board);
        void printPoints()const;
        void printResources()const;
        int getPlayerPoints()const;
        int getResource(Resources resource)const;
        void addResource(Resources resource,int amount){
            resources[resource] += amount;
        }
        void removeResource(Resources resource, int amount);
        void incrementKnightCount();
        Resources randomResource() const;
        bool getIsPlaying()const;
        void setIsPlaying(bool playing);
        void decrementSettlements();
        void decrementRoads();
        int getSettlementCount() const;
        int getRoadCount() const;
        void addDevelopmentCard(Card* card);
        vector<Card*>& getDevelopmentCards() ;
        int getKnightCount() const;
        void incrementSettlment();
        void incrementRoad();
        Resources chooseResourceToClaim();  // Allows the player to choose a resource to claim
        Resources chooseResource();         // Allows the player to choose a resource
        int chooseRoadLocation();           // Allows the player to choose a location for a road

  
    };   
}
#endif 
