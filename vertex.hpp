#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include <string>
#include "Tile.hpp"

using namespace std;
namespace ariel{
    class Vertex {
        private:
        string owner;
        vector<Tile> adjTiles;
        vector< Vertex*>adjVertices;
            
        
        public:
            
            Vertex() :owner(""){}

            void addAdjacentTile(const Tile& tile) {
            adjTiles.push_back(tile);
            }

            void addAdjacentVertex(Vertex& vertex) {
                adjVertices.push_back(&vertex);
            }

            const vector<Tile>& getAdjacentTiles() const {
                return adjTiles;
            }

            const vector<Vertex*>& getAdjacentVertices() const {
                return adjVertices;
            }
            const string& getOwner()const{
                return owner;
            }
    };
}
#endif //VERTEX_HPP