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
        void Player::rollDice() const
        {
        }
        void Player::endTurn()
        {
        }
        void Player::trade(Player &other, string give, string get, int totalGive, int totalGet)
        {
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
        const string &Player::getName() const
        {
            return name;
        }
        int Player::getPlayerPoints() const
        {
            return playerPoints;
        }
}