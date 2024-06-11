#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<string>
#include <vector>
#include "Card.hpp"
#include "resources.hpp"
#include <map>
#include <unordered_map>
#include "board.hpp"


using namespace std; 
namespace ariel{
    
   
    class Player{
        private:
        string name;
        int playerPoints;
        bool turn;
        unordered_map<Resources,int> resources;
        //vector<unique_ptr<Card>> deck;
        
        int settlements;
        int roads;
        int cities;

        public:
        Player( const string& name) :name(name),playerPoints(0){}
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
        int getResource(const string& resource)const;
        void addResource(const string& resource,int amount){
            resources[resource] += amount;
        }
    };   
}
#endif 
