/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/



#include "Card.hpp"
#include "player.hpp"
#include "board.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <memory>
#include <vector>


namespace ariel {

    // Cards class
    

    CardType Card::getType() const {
        return type;
    }

    // VictoryPointCard class
    

    string VictoryPointCard::getDesc() const {
        return "Victory Point Card";
    }
    void VictoryPointCard::playEffect(Player& player, Board&) {
        player.addPoints(1);
        cout << player.getName() << " gained 1 Victory Point!" << endl;
    }


    // KnightCard class
    

    string KnightCard::getDesc() const {
        return "Knight Card";
    }
    void KnightCard::playEffect(Player& player, Board& board) {
        player.incrementKnightCount();
        cout << player.getName() << " played a Knight Card!" << endl;
    }


    // ProgressCard class

    

    string ProgressCard::getDesc() const {
        switch(progressType) {
            case ProgressType::RoadBuilding:
                return "Progress Card: Road Building";
            case ProgressType::YearOfPenlty:
                return "Progress Card: Year of Plenty";
            case ProgressType::Monopoly:
                return "Progress Card: Monopoly";
            default:
                return "Unknown Progress Card";
        }
    }



    void ProgressCard::playEffect(Player& player, Board& board ) {
        switch (progressType) {
            case ProgressType::RoadBuilding: {
               
            }
            case ProgressType::YearOfPenlty: {
              
            }
            case ProgressType::Monopoly: {
                
            }
        }
    }

    // Deck class
    Deck::Deck() {
        // Initialize the deck with cards
         initialize();
         shuffle();
    }

    Deck::~Deck() {
        for (auto card : cards) {
            delete card;
        }
        
    }
    void Deck::initialize() {
        cards.clear();


     
        


        //Typically, there are 25 development cards: 14 Knight Cards, 6 Progress Cards, and 5 Victory Point Cards.
        for (int i = 0; i < 14; ++i) {
            cards.emplace_back(  new KnightCard());
        }
        // Adding Monopoly Cards
        for (int i = 0; i < 2; ++i) {
            cards.emplace_back(new MonopolyCard([](Player& player) {
                return player.chooseResourceToClaim(); // Assuming chooseResourceToClaim is implemented in Player
            }));
        }

        // Adding Year of Plenty Cards
        for (int i = 0; i < 2; ++i) {
            cards.emplace_back(new YearOfPlentyCard(
                [](Player& player) { return player.chooseResource(); }, // Assuming chooseResource is implemented in Player
                [](Player& player) { return player.chooseResource(); }
            ));
        }
        // Create Road Building cards
        for (int i = 0; i < 2; ++i) {
            cards.emplace_back(new RoadBuildingCard());
        }
        
        for (int i = 0; i < 5; ++i) {
            cards.emplace_back(  new VictoryPointCard());
    
    }
    }



    void MonopolyCard::playEffect(Player& player, Board& board) {
        Resources resourceToClaim = resourceChooser(player);  
        int totalClaimed = board.claimAllResources(resourceToClaim, player);  
        cout << player.getName() << " used Monopoly to claim " << totalClaimed << " " << toString(resourceToClaim) << " from all players!" << endl;
    }

    string MonopolyCard::getDesc() const {
        return "Monopoly Card: Claim all of one type of resource from all players.";
    }

    // YearOfPlentyCard Implementation

    void YearOfPlentyCard::playEffect(Player& player, Board& board) {
        Resources resource1 = resourceChooser1(player);
        Resources resource2 = resourceChooser2(player);
        player.addResource(resource1, 1);
        player.addResource(resource2, 1);
        std::cout << player.getName() << " used Year of Plenty to gain 1 " 
                  << toString(resource1) << " and 1 " << toString(resource2) << "!" << std::endl;
    }
    string YearOfPlentyCard::getDesc() const {
        return "Year of Plenty Card: Take any two resources from the bank.";
    }

    // RoadBuildingCard Implementation
    RoadBuildingCard::RoadBuildingCard() : ProgressCard(ProgressType::RoadBuilding) {}

    void RoadBuildingCard::playEffect(Player& player, Board& board) {
        int road1 = player.chooseRoadLocation();  // Assuming this method is defined in Player
        int road2 = player.chooseRoadLocation();  // Assuming this method is defined in Player
        board.placeRoad(road1, player);  // Assuming this method is defined in Board
        board.placeRoad(road2, player);  // Assuming this method is defined in Board
        cout << player.getName() << " used Road Building to place roads at " << road1 << " and " << road2 << "!" << endl;
    }

    string RoadBuildingCard::getDesc() const {
        return "Road Building Card: Place two new roads as if you had just built them.";
    }

    

    

    void Deck::shuffle() {
        auto rng = default_random_engine { static_cast<unsigned>(time(0)) };
        std::shuffle(cards.begin(), cards.end(), rng);

    }
    Card* Deck::drawCard() {
        if(isEmpty()) {
            return nullptr;
        }
        Card* topCard =cards.back();
        cards.pop_back();
        return topCard;
    }

    bool Deck::isEmpty() const {
        return cards.empty();
    }
}

