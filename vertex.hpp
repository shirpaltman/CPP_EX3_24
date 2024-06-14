#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include <string>
#include "Tile.hpp"
#include <memory>

using namespace std;
namespace ariel{
    class Vertex {
        private:
        string owner;
        vector<Tile*> adjTiles;
        //vector< Vertex*>adjVertices;
            
        
        public:
            
            Vertex() :owner(""){
            }
            
        
            

            void addAdjacentTile(Tile* tile) {
                adjTiles.push_back(tile);
            }

           
            const string& getOwner()const{
                return owner;
            }

            void setOwner (const string& ownerName){
                owner = ownerName;
            }

            const vector<Tile*>& getAdjacentTiles()const{
                return adjTiles;
            }

        ~Vertex() {
            //Clean up dynamically allocated memory, if any
            // for (auto *tile : adjTiles) {
            //     delete tile;
            // }
            //cout << "Vertex destructor called" << endl;
        } 
    };
}
#endif //VERTEX_HPP