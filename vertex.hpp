#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include <string>
#include "Tile.hpp"

using namespace std;
namespace ariel{
    class Vertex {
        public:
            string owner;
            vector<Tile> adjTiles;
            
            Vertex() :owner(""){}

            void addAdjacentTile (const vector<Tile>& tiles){
                adjTiles.insert(adjTiles.end(),tiles.begin(),tiles.end());
            }

            const string& getOwner()const{
                return owner;
            }
    };
}
#endif //VERTEX_HPP