#include "Card.hpp"
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

    // KnightCard class
    KnightCard::KnightCard() : Card(CardType::Knight) {}

    string KnightCard::getDesc() const {
        return "Knight Card";
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

    // Deck class
    Deck::Deck() {
        // Initialize the deck with cards
         initialize();
    }
    void Deck::initialize() {
        //Typically, there are 25 development cards: 14 Knight Cards, 6 Progress Cards, and 5 Victory Point Cards.
        for (int i = 0; i < 14; ++i) {
            cards.emplace_back(KnightCard());
        }
        for (int i = 0; i < 2; ++i) {
            cards.emplace_back(ProgressCard(ProgressType::RoadBuilding));
            cards.emplace_back(ProgressCard(ProgressType::YearOfPenlty));
            cards.emplace_back(ProgressCard(ProgressType::Monopoly));
        }
        for (int i = 0; i < 5; ++i) {
            cards.emplace_back(VictoryPointCard());
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
