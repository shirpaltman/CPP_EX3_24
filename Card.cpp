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
    Card::Card(CardType type) : type(type) {}

    CardType Card::getType() const {
        return type;
    }

    // VictoryPointCard class
    VictoryPointCard::VictoryPointCard() : Card(CardType::VictoryPoint) {}

    string VictoryPointCard::getDesc() const {
        return "Victory Point Card";
    }
    void VictoryPointCard::playEffect(Player& player, Board&) {
        player.addPoints(1);
        cout << player.getName() << " gained 1 Victory Point!" << endl;
    }


    // KnightCard class
    KnightCard::KnightCard() : Card(CardType::Knight) {}

    string KnightCard::getDesc() const {
        return "Knight Card";
    }
    void KnightCard::playEffect(Player& player, Board&) {
        player.incrementKnightCount();
        cout << player.getName() << " played a Knight Card!" << endl;
    }


    // ProgressCard class
    ProgressCard::ProgressCard(ProgressType type) : Card(CardType::Progress), progressType(type) {}

    ProgressType ProgressCard::getProgressType() const {
        return progressType;
    }

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



    void ProgressCard::playEffect(Player& player, Board& board) {
        switch (progressType) {
            case ProgressType::RoadBuilding: {
                player.decrementRoads();
                player.decrementRoads();
                std::cout << player.getName() << " used Road Building to place 2 roads!" << std::endl;
                break;
            }
            case ProgressType::YearOfPenlty: {
                // Choose any 2 resources to add
                player.addResource(Resources::Brick, 1);
                player.addResource(Resources::Wheat, 1);
                std::cout << player.getName() << " used Year of Plenty to gain 1 Brick and 1 Wheat!" << std::endl;
                break;
            }
            case ProgressType::Monopoly: {
                // Take all resources of a specific type from all other players
                int total = board.claimAllResources(Resources::Brick, player);
                std::cout << player.getName() << " used Monopoly to claim " << total << " Brick from all players!" << std::endl;
                break;
            }
        }
    }

    // Deck class
    Deck::Deck() {
        // Initialize the deck with cards
         initialize();
    }

    Deck::~Deck() {
        for (auto card : cards) {
            delete card;
        }
    }
    void Deck::initialize() {
        //Typically, there are 25 development cards: 14 Knight Cards, 6 Progress Cards, and 5 Victory Point Cards.
        for (int i = 0; i < 14; ++i) {
            cards.emplace_back(  new KnightCard());
        }
        for (int i = 0; i < 2; ++i) {
            cards.emplace_back( new ProgressCard(ProgressType::RoadBuilding));
            cards.emplace_back(  new ProgressCard(ProgressType::YearOfPenlty));
            cards.emplace_back(  new ProgressCard(ProgressType::Monopoly));
        }
        for (int i = 0; i < 5; ++i) {
            cards.emplace_back(  new VictoryPointCard());
        }
    }

    

    

    void Deck::shuffle() {
        auto rng = default_random_engine { static_cast<unsigned>(time(0)) };
        std::shuffle(cards.begin(), cards.end(), rng);

    }
    Card* Deck::drawCard() {
        if(isEmpty()) {
            throw runtime_error("no cards left in the deck"); // No cards left in the deck
        }
        Card* topCard =cards.back();
        cards.pop_back();
        return topCard;
    }

    bool Deck::isEmpty() const {
        return cards.empty();
    }
}
