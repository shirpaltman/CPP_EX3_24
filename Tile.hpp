#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include "resources.hpp"
using namespace std;
namespace ariel{
    class Tile{
   
    public:
        
        Resources resource;
        int number;
        vector<Tile> adjTiles;


        Tile(Resources resource,int num,vector<Tile> adjTiles={})
        :resource(resource),number(num),adjTiles(adjTiles){}

        int getNumber()const {
            return number;
        }
    };
}
#endif
