#ifndef BOARD_HPP
#define BOARD_HPP
#include<vector>
#include<string>
#include<unordered_map>
#include "player.hpp"



using namespace std;
namespace ariel{
    class Player;
    class Board{
        private:
        vector<vector<string>> board;
        unordered_map<int,pair<string,int>> settlements;  //we will want to know in every location wths the player's name and wht settlement type
        unordered_map<int,string> roads;        //we will want to know in a specific location whtat's the players name 
        unordered_map<int, string> tiles;
        public:
            Board();
            void addRoad(const string& playerName,int location);
            void addSettlement(const string& playerName,int location,const string& settlementType);
            bool isLocationSettelmentValid(int location)const;
            bool isLocationRoadValid(int location)const;
            void initializeBoard();
            void printBoard()const;
            bool canPlaceSettelment(int place1,int place2,const Player& player)const;
            bool canPlaceRoad(int place1,int place2, const Player& player)const;
            bool PlaceSettelment(int place1,int place2, Player& player);
            bool PlaceRoad(int place1,int place2,  Player& player);
            const string& getName()const;
            int getPoints()const;





    };

    struct Tile{
        Resources resource;
        int number;
        bool hasthief;
        Tile(Resources res,int num);
    };
    
#endif
}