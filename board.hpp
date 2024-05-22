#ifndef BOARD_HPP
#define BOARD_HPP
#include<vector>
#include<string>

using namespace std;
namespace ariel{
    class Board{
        private:
        vector<vector<String>> board;
       
        public:
            Board();
            void initializeBoard();

            void printBoard()const;
    };

    enum class Resources{
        Desert,
        Brick,
        Sheep,  
        Wheat,
        Wood,
        Ore
   
    };

    struct Tile{
        Resources resource;
        int number;
        bool hasthief;
        Tile(Resources res,int num);
    };
    
#endif
}