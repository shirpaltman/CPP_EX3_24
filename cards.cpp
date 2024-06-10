#include "cards.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

namespace ariel {

    // Cards class
    Cards::Card(CardType type) : type(type) {}

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
      srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < 10; ++i) {
            cards.push_back(make_unique<VictoryPointCard>());
            cards.push_back(make_unique<KnightCard>());
            cards.push_back(make_unique<ProgressCard>(ProgressType::RoadBuilding));
            cards.push_back(make_unique<ProgressCard>(ProgressType::YearOfPenlty));
            cards.push_back(make_unique<ProgressCard>(ProgressType::Monopoly));
        }
        // Shuffle the deck
        shuffle();
    }

    void Deck::shuffle() {
        auto rng = default_random_engine { static_cast<unsigned>(time(0)) };
        shuffle(cards.begin(), cards.end(), rng);
    }
    unique_ptr<Card> Deck::drawCard() {
        if(isEmpty()) {
            return nullptr; // No cards left in the deck
        }
        unique_ptr<Card> topCard = move(cards.back());
        cards.pop_back();
        return topCard;
    }

    bool Deck::isEmpty() const {
        return cards.empty();
    }

}
