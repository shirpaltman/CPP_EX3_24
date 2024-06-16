/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/






#ifndef CARD_HPP
#define CARD_HPP


#include <string>
#include <memory>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <functional>
#include "resources.hpp"



using namespace std;
namespace ariel{

    class Player;
    class Board;
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
            Card(CardType type):type(type){}
            CardType getType() const;
            virtual ~Card() = default;
            virtual string getDesc() const =0;
            virtual void playEffect(Player& player, Board& board)=0;

            Card(const Card&) =delete;  //delete copy constructor
            Card& operator=(const Card&) =delete;   // delete the copy assignment operator

            Card(Card&&)=default ; //defualt move constructor
            Card& operator=(Card&&)=default;  //default move assignment operator
        };

        class VictoryPointCard : public Card{
            public:
                VictoryPointCard() : Card(CardType::VictoryPoint) {}
                string getDesc() const override;
                void playEffect(Player& player, Board& board)override;


                // VictoryPointCard(const VictoryPointCard&) = delete; // delete copy constructor
                // VictoryPointCard& operator=(const VictoryPointCard&) = delete; // delete copy assignment operator

                // VictoryPointCard(VictoryPointCard&&) = default; // default move constructor
                // VictoryPointCard& operator=(VictoryPointCard&&) = default; // default move assignment operator
    };

        class KnightCard : public Card{
            public:
                KnightCard() : Card(CardType::Knight) {}
                string getDesc() const override;
                void playEffect(Player& player, Board& board)override;

                // KnightCard(const KnightCard&) = delete; // delete copy constructor
                // KnightCard& operator=(const KnightCard&) = delete; // delete copy assignment operator
                // KnightCard(KnightCard&&) = default; // default move constructor
                // KnightCard& operator=(KnightCard&&) = default; // default move assignment operator
        };

        class ProgressCard : public Card{
            protected:
            ProgressType progressType;
            

            public:
                ProgressCard(ProgressType type) : Card(CardType::Progress), progressType(type) {}
                ProgressType getProgressType() const { return progressType; }                
                virtual void playEffect(Player& player, Board& board)override;

                string getDesc() const override;
                // ProgressCard(const ProgressCard&) = delete; // delete copy constructor
                // ProgressCard& operator=(const ProgressCard&) = delete; // delete copy assignment operator
                // ProgressCard(ProgressCard&&) = default; // default move constructor
                // ProgressCard& operator=(ProgressCard&&) = default; // default move assignment operator
        };
        class MonopolyCard : public ProgressCard {
            public:
                using ResourceChooser = std::function<Resources(Player&)>;

            private:
                ResourceChooser resourceChooser;

                
            
            public:
             MonopolyCard(ResourceChooser chooser) : ProgressCard(ProgressType::Monopoly), resourceChooser(chooser) {}
                void playEffect(Player& player, Board& board) override;
                string getDesc() const override;
            

            };

        class YearOfPlentyCard : public ProgressCard {
            
            public:    
                using ResourceChooser = function<Resources(Player&)>;

            private:
                ResourceChooser resourceChooser1;
                ResourceChooser resourceChooser2;
            public:
                YearOfPlentyCard(ResourceChooser chooser1, ResourceChooser chooser2) : ProgressCard(ProgressType::YearOfPenlty), resourceChooser1(chooser1), resourceChooser2(chooser2) {}
                void playEffect(Player& player, Board& board) override;
                string getDesc() const override;
            
            };


        class RoadBuildingCard : public ProgressCard {
            public:
                RoadBuildingCard();
                void playEffect(Player& player, Board& board) override;
                string getDesc() const override;
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