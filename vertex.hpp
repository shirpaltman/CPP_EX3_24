
#ifndef VERTEX_HPP
#define VERTEX_HPP

/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/
 

#include <vector>
#include <string>
#include "Tile.hpp"
#include <memory>

using namespace std;

namespace ariel {

    class Vertex {
    private:
        string owner;  // Name of the owner of this vertex
        vector<Tile*> adjTiles;  // Adjacent tiles to this vertex
        
    public:
        // Default constructor
        Vertex() : owner("") {}

        // Add an adjacent tile to this vertex
        void addAdjacentTile(Tile* tile) {
            adjTiles.push_back(tile);
        }

        // Get the owner of this vertex
        const string& getOwner() const {
            return owner;
        }

        // Set the owner of this vertex
        void setOwner(const string& ownerName) {
            owner = ownerName;
        }

        // Get the adjacent tiles of this vertex
        const vector<Tile*>& getAdjacentTiles() const {
            return adjTiles;
        }

        // Destructor
        ~Vertex() {}
    };
}

#endif // VERTEX_HPP