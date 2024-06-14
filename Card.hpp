#ifndef CARD_HPP
#define CARD_HPP
#include <string>
#include <memory>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>



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

            Card(const Card&) =delete;  //delete copy constructor
            Card& operator=(const Card&) =delete;   // delete the copy assignment operator

            Card(Card&&)=default ; //defualt move constructor
            Card& operator=(Card&&)=default;  //default move assignment operator
        };

        class VictoryPointCard : public Card{
            public:
                VictoryPointCard();
                string getDesc() const override;

                VictoryPointCard(const VictoryPointCard&) = delete; // delete copy constructor
                VictoryPointCard& operator=(const VictoryPointCard&) = delete; // delete copy assignment operator

                VictoryPointCard(VictoryPointCard&&) = default; // default move constructor
                VictoryPointCard& operator=(VictoryPointCard&&) = default; // default move assignment operator
    };

        class KnightCard : public Card{
            public:
                KnightCard();
                string getDesc() const override;
                KnightCard(const KnightCard&) = delete; // delete copy constructor
                KnightCard& operator=(const KnightCard&) = delete; // delete copy assignment operator
                KnightCard(KnightCard&&) = default; // default move constructor
                KnightCard& operator=(KnightCard&&) = default; // default move assignment operator
        };

        class ProgressCard : public Card{
            private:
            ProgressType progressType;
            public:
                ProgressCard(ProgressType type);
                ProgressType getProgressType() const;
                string getDesc() const override;
                ProgressCard(const ProgressCard&) = delete; // delete copy constructor
                ProgressCard& operator=(const ProgressCard&) = delete; // delete copy assignment operator
                ProgressCard(ProgressCard&&) = default; // default move constructor
                ProgressCard& operator=(ProgressCard&&) = default; // default move assignment operator
        };

        class Deck{
            private:
                vector<Card*> cards;
                default_random_engine randomCards;

            public:
                Deck();
                ~Deck();
                void initialize();
                void shuffle();
                Card* drawCard();
                bool isEmpty()const;


                Deck(const Deck&) = delete; // delete copy constructor
                Deck& operator=(const Deck&) = delete; // delete copy assignment operator

                Deck(Deck&&) = default; // default move constructor
                Deck& operator=(Deck&&) = default; // default move assignment operator


        };
}
#endif // CARD_HPP