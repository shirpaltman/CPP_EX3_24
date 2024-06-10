#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "player.hpp"

using namespace std;
namespace ariel{

    Player::Player(const string& playerName)
        :name(playerName),settlements(2),cities(0),roads(2),playerPoints(2){
            resources[Resources::Wood]=1;
            resources[Resources::Sheep]=1;
            resources[Resources::Wheat]=1;
            resources[Resources::Brick]=1;
            resources[Resources::Ore]=1;

        }

        void Player::addPoints(int points){
            playerPoints = playerPoints+points;
        }
        
        void Player::placeSettelemnt(const vector<int> &placesNum, Board &board){
            if(placesNum.size() !=2){
                throw invalid_argument("you need exactly 2 place to place a settelment");
            }
            //checking if the settement cand be placed and if it vaild place it 
            if(board.canPlaceSettelment(placesNum[0],placesNum[1],this->name)){
                board.PlaceSettelment(placesNum[0],placesNum[1],*this);
            }
            else{
                throw invalid_argument("you can't place a settelment here");
            }
        }
        void Player::placeRoad(const vector<int> &placesNum, Board &board)
        {
            if(placesNum.size() !=2){
                throw invalid_argument("you need exactly 2 place to place a Road");
            }
            //checking if the settement cand be placed and if it vaild place it 
            if(board.canPlaceRoad(placesNum[0],placesNum[1],this->name)){
                board.PlaceRoad(placesNum[0],placesNum[1],*this);
            }
            else{
                throw invalid_argument("you can't place a road here");
            }
        }
        int Player::rollDice() const
        {
          return (rand() % 6 + 1) +(rand() % 6 + 1);
        }
        void Player::endTurn()
        {
            cout<<name<< "has ended their turn" <<endl;
        }
        void Player::trade(Player &other,   string give, string get, int totalGive, int totalGet)
        {
            if(give == "Wood" && resources[Resources::Wood] >= totalGive){
                resources[Resources::Wood] -= totalGive;
                other.resources[Resources::Wood] += totalGet;
                }
            else if(give == "Brick" && resources[Resources::Brick] >= totalGive){
                resources[Resources::Brick] -= totalGive;
                other.resources[Resources::Brick] += totalGet;
            }
            else if(give == "Sheep" && resources[Resources::Sheep] >= totalGive){
                resources[Resources::Sheep] -= totalGive;
                other.resources[Resources::Sheep] += totalGet;
            }
            else if(give == "Wheat" && resources[Resources::Wheat] >= totalGive){
                resources[Resources::Wheat] -= totalGive;
                other.resources[Resources::Wheat] += totalGet;
            }
            else if(give == "Ore" && resources[Resources::Ore] >= totalGive){
                resources[Resources::Ore] -= totalGive;
                other.resources[Resources::Ore] += totalGet;
            }
            else{
                throw invalid_argument("you don't have enough resources to trade");
            }
            if(get == "Wood" && other.resources[Resources::Wood] >= totalGet){
                resources[Resources::Wood] += totalGet;
                other.resources[Resources::Wood] -= totalGive;
            }
            else if(get == "Brick" && other.resources[Resources::Brick] >= totalGet){
                resources[Resources::Brick] += totalGet;
                other.resources[Resources::Brick] -= totalGive;
            }
            else if(get == "Sheep" && other.resources[Resources::Sheep] >= totalGet){
                resources[Resources::Sheep] += totalGet;
                other.resources[Resources::Sheep] -= totalGive;
                }
                else if(get == "Wheat" && other.resources[Resources::Wheat] >= totalGet){
                    resources[Resources::Wheat] += totalGet;
                    other.resources[Resources::Wheat] -= totalGive;
                }
                else if(get == "Ore" && other.resources[Resources::Ore] >= totalGet){
                    resources[Resources::Ore] += totalGet;
                    other.resources[Resources::Ore] -= totalGive;
                }
                else{
                    throw invalid_argument("the other player doesn't have enough resources to trade");
                }
                
                           
                                
                                            
                
        }
        
        void Player::buyDevelopmentCard(Deck& deck){
            if(resources[Resources::Wheat] >= 1 && resources[Resources::Sheep] >= 1 && resources[Resources::Ore]){
                if(!deck.isEmpty()) {  
          
                    resources[Resources::Wheat]--;    
                    resources[Resources::Ore]--;
                    resources[Resources::Sheep]--;
                    developmentCards.push_back(deck.drawCard());
                }
                else{
                    throw invalid_argument("there are no more cards in the deck");
                }
            } 
            else{
                throw invalid_argument("you don't have enough resources to buy a development card");
            }
        }

        
        void Player::printPoints() const
        {
        }
        void Player::printResources() const{
            cout << "Player " << name << " Resources:" << endl;
            for(const auto& resource:resources){
                cout << static_cast<int>(resource.first) << ": " <<", Amount: "  << resource.second << endl;

            }
        }
        string Player::getName() const
        {
            return name;
        }
        int Player::getPlayerPoints() const
        {
            return playerPoints;
        }
}