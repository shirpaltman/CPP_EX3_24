#ifndef BOARD_HPP
#define BOARD_HPP
#include<vector>
#include<string>
#include<unordered_map>


using namespace std;
namespace ariel{
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
            bool islocationVaild(int location)const;
            void initializeBoard();
            void printBoard()const;
    };

  

    struct Tile{
        Resources resource;
        int number;
        bool hasthief;
        Tile(Resources res,int num);
    };
    
#endif
}