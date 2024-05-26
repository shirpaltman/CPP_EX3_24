#ifndef CARD_HPP
#define CARD_HPP
#include <string>
#include <memory>
#include <vector>
#include <random>

using namespace std;
namespace ariel{
    enum class CardType{
        Knight,
        Progress,
        VictoryPoint
    };
    enum class ProgressType{
        RoadBuilding,
        YearOfPenlty,
        Monopoly,
    };

    class Card{
        private:
            CardType type;


        public:
            Card(CardType type);
            CardType getType() const;
            virtual ~Card() = default;
            virtual string getDesc() const =0;
        };

        class VictoryPointCard : public Card{
            public:
                VictoryPointCard();
                string getDesc() const override;
               
        };

        class KnightCard : public Card{
            public:
                KnightCard();
                string getDesc() const override;
        };

        class ProgressCard : public Card{
            private:
            ProgressType progressType;
            public:
                ProgressCard(ProgressType type);
                ProgressType getProgressType() const;
                string getDesc() const override;
        };

        class Deck{
            private:
                vector<unique_ptr<Card>> cards;
                default_random_engine randomCards;
            public:
                Deck();
                void shuffle();
                unique_ptr<Card> drawCard();
                bool isEmpty()const;
        };


}
#endif // CARD_HPP