#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include "resources.hpp"
#include <unordered_map>
#include "player.hpp"
using namespace std;
namespace ariel{
    class Tile{
   
    private:

        Resources resource_;
        int value_;
        vector<Tile*> adjTiles_;
        vector<int> vertices_;
        unordered_map <int,pair<Player*, string>> settlements_;



    public:
        


        Tile(Resources resource,int value=0,initializer_list<Tile> adjTiles={},vector<int>myver={})
            :resource_(resource),value_(value) {
                vertices_ = myver;
                value_ =value;
          
        }

        
        int getValue()const {
            return value_;
        }

        Resources getResource()const{
            return resource_;
        }
        const unordered_map<int,pair<Player*,string>>& getSettlements() const{
            return settlements_;
        }

        void addSettlement(int vertex,Player* player,const string& type){
            settlements_[vertex] = make_pair(player,type);
        }

        void addAdjacentTile(Tile* tile) {
            adjTiles_.push_back(tile);
        }        

        ~Tile(){
            for(auto& tile : adjTiles_){
                delete tile;
            }
        }  

        
      
    };
}
#endif
