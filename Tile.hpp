#ifndef TILE_HPP
#define TILE_HPP
#include <vector>
#include "resources.hpp"
#include <unordered_map>
#include "player.hpp"
#include <memory>


/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/
using namespace std;

namespace ariel {
    
    class Tile {
    private:
        Resources resource_;  // Resource type of the tile
        int value_;           // Value of the tile, used for resource allocation
        vector<Tile*> adjTiles_;  // Adjacent tiles
        vector<int> vertices_;    // Vertices associated with the tile
        unordered_map<int, pair<Player*, string>> settlements_;  // Settlements on the tile, mapping vertex to player and settlement type

    public:
        // Constructor to initialize tile with resource type, value, adjacent tiles, and vertices
        Tile(Resources resource, int value = 0, initializer_list<Tile> adjTiles = {}, vector<int> myver = {})
            : resource_(resource), value_(value) {
            vertices_ = myver;
        }

        // Getter for tile value
        int getValue() const {
            return value_;
        }

        // Getter for tile resource type
        Resources getResource() const {
            return resource_;
        }

        // Getter for settlements on the tile
        const unordered_map<int, pair<Player*, string>>& getSettlements() const {
            return settlements_;
        }

        // Add a settlement to the tile
        void addSettlement(int vertex, Player* player, const string& type) {
            settlements_[vertex] = make_pair(player, type);
        }

        // Add an adjacent tile
        void addAdjacentTile(Tile* tile) {
            adjTiles_.push_back(tile);
        }

        // Destructor (no specific cleanup needed)
        ~Tile() {}
    };
}

#endif
