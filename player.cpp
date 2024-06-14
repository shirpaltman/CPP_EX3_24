#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "player.hpp"
#include <random>

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

     Player::~Player() {
        for (Card* card : developmentCards) {
            delete card;
        }
    } 

    
    int Player::rollDice() const{
        static random_device rd;  // Non-deterministic generator
        static mt19937 gen(rd()); // Mersenne Twister engine
        static uniform_int_distribution<> dis(1, 6);
        int check= dis(gen) + dis(gen);
        cout<< check<<endl;
        return check ;
        }
    void Player::endTurn()
    {
        cout<<name<< " has ended their turn" <<endl;
    }
        void Player::trade(Player &other,   string give, string get, int totalGive, int totalGet)
        {
           

            Resources giveR = stringToResources(give);
            Resources getR = stringToResources(get);

            if(this->getResource(giveR)<totalGive){
                cout << "You don't have enough " << give << " to trade." << endl;
                return; 
            }
            if(other.getResource(getR)<totalGet){ 
                cout << other.getName() << " doesn't have enough " << get << " to trade." << endl;
                return;  
            }
                this->resources[giveR] -= totalGive;
                other.resources[getR] -= totalGet;

                this->resources[getR] += totalGet;
                other.resources[giveR] += totalGive;

                cout << this->getName() << " traded " << totalGive << " " << give << " with " << other.getName() << " for " << totalGet << " " << get << "." << endl;
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
            cout << name << " has " << playerPoints << " points" << endl;
        }
        void Player::printResources() const{
            cout << "Player " << name << " Resources:" << endl;
            for(const auto& resource:resources){
                cout << toString(resource.first) << ": " <<", Amount: "  << resource.second << endl;

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
        int Player::getResource(Resources resource) const
        {
            auto it =resources.find(resource);
            if(it != resources.end()){
                return it->second;
            }
            return 0;
        }
        bool Player::getIsPlaying() const
        {
            return isPlaying;
        }

        void Player::setIsPlaying(bool flag){
            isPlaying = flag;
        
        }
        void Player::decrementSettlements(){
            settlements--;
        }
       
        int Player::getSettlementCount()const{
            return settlements;
        }
        int Player::getRoadCount()const{
            return roads;
        }

    void Player::incrementKnightCount() {
        KnightCount++;
    }

  

  Resources Player::randomResource() const {
        std::vector<Resources> availableResources;

        for (const auto& pair : resources) {
            if (pair.second > 0) {
                availableResources.push_back(pair.first);
            }
        }

        if (!availableResources.empty()) {
            size_t randomIndex = static_cast<size_t>(std::rand()) % availableResources.size();
            return availableResources[randomIndex];
        }

        return Resources::None;
    }

    void Player::removeResource(Resources resource, int amount) {
        if (resources[resource] >= amount) {
            resources[resource] -= amount;
        } else {
            resources[resource] = 0;
        }
    }
    void Player::decrementRoads() {
        if (roads > 0) {
            roads--;
        }
    }

    void Player::addDevelopmentCard(Card* card) {
        developmentCards.push_back(card);
    }

    const std::vector<Card*>& Player::getDevelopmentCards() const {
        return developmentCards;
    }
    int Player::getKnightCount() const {
        return KnightCount; 
    }
    
    }