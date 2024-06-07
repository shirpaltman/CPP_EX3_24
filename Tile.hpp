#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include "resources.hpp"
using namespace std;
namespace ariel{
    class Tile{
   


    private:

        Resources resource_;
        int value_;
        vector<Tile> adjTiles_;
        vector<int> vertices_;


    public:
        

        Tile(Resources resource,int value=0,initializer_list<Tile> adjTiles={},vector<int>myver={})
            :resource_(resource),value_(value){
                adjTiles_ =adjTiles;
                vertices_ = myver;
          
        }

        
        
        int getValue()const {
            return value_;
        }
    };
}
#endif
