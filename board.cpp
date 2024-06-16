/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/




#include "board.hpp"
#include "Card.hpp"
#include "player.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <stdexcept>
#include <string>

using namespace std;
namespace ariel {

    // Constructor to initialize the board
    Board::Board() noexcept {
        initializeBoard();
    }

    // Method to add a road for a player at a specific location
    void Board::addRoad(const string &playerName, int location, Player& player) {
        if (isLocationRoadValid(location, player)) {
            roads[location] = playerName; 
            player.addResource(Resources::Wood, -1);
            player.addResource(Resources::Brick, -1); 
            cout << playerName << " placed a road at location " << location << "." << endl;
        } else {
            cout << "Invalid road placement. Please try again." << endl;
        }
    }

    // Method to add a settlement for a player at a specific location
    void Board::addSettlement(const string &playerName, int location, const string &settlementType, Player& player) {
        if (isSettelmentValid(location, player)) {
            settlements[location] = make_pair(playerName, settlementType);
            player.addResource(Resources::Wood, -1);
            player.addResource(Resources::Brick, -1);
            player.addResource(Resources::Sheep, -1);
            player.addResource(Resources::Wheat, -1);
            cout << playerName << " placed a " << settlementType << " at location " << location << "." << endl;
            player.addPoints(1);
        } else {
            cout << "Invalid settlement placement. Please try again." << endl;
        }
    }

    // Check if the settlement placement is valid
    bool Board::isSettelmentValid(int location, const Player &player) const {
        // Check if location is already occupied
        if (settlements.find(location) != settlements.end()) {
            return false;
        }
        // Check distance rule for settlements
        for (const auto& settlement : settlements) {
            if (abs(settlement.first - location) <= 2) {
                return false;
            }
        }
        // Check if player has enough resources
        if (player.getResource(Resources::Wood) < 1 || player.getResource(Resources::Brick) < 1 || 
            player.getResource(Resources::Sheep) < 1 || player.getResource(Resources::Wheat) < 1) {
            return false;
        }
        return true;
    }

    // Check if the road placement is valid
    bool Board::isLocationRoadValid(int location, const Player &player) const {
        // Check if location is already occupied
        if (roads.find(location) != roads.end()) {
            return false;
        }
        // Check if player has enough resources
        if (player.getResource(Resources::Wood) < 1 || player.getResource(Resources::Brick) < 1) {
            return false;
        }
        return true;
    }

    // Initialize the board with tiles, vertices, and edges
    void Board::initializeBoard() {
        // Create and set up tiles with adjacent tiles
        Tile tile1 = Tile(Resources::Wood, 11, {Tile(Resources::Brick, 2), Tile(Resources::Wheat, 4), Tile(Resources::Ore, 5), Tile(Resources::Sea, 0)});
        Tile tile2 = Tile(Resources::Brick, 2, {tile1, Tile(Resources::Ore, 5), Tile(Resources::Wood, 6), Tile(Resources::Sheep, 3), Tile(Resources::Sea, 0)});
        // Continue initializing other tiles...

        tiles = {tile1, tile2, /* other tiles */};

        // Initialize vertices and set adjacent tiles
        vertices.resize(54);
        vector<vector<int>> vertexToTiles = {
            {3}, {3}, {3, 2}, {2}, {2, 1}, {1}, {1}, {3, 7}, {3, 6, 7}, {2, 3, 6}, {2, 5, 6}, {2, 1, 5},
            {1, 4, 5}, {1, 4}, {4}, {7}, {12}, {7, 12}, {7, 11, 12}, {6, 7, 11}, {6, 10, 11}, {5, 6, 10},
            {5, 9, 10}, {4, 5, 9}, {4, 8, 9}, {4, 8}, {8}, {8}, {8, 13}, {8, 9, 13}, {9, 13, 14},
            {9, 10, 14}, {10, 14, 15}, {10, 11, 15}, {11, 15, 16}, {11, 12, 16}, {12, 16}, {12},
            {16}, {16, 19}, {15, 16, 19}, {15, 18, 19}, {14, 15, 18}, {14, 18, 17}, {13, 14, 17},
            {13, 17}, {13}, {17}, {17}, {17, 18}, {18}, {18, 19}, {19}, {19}
        };
        for (size_t i = 0; i < vertexToTiles.size(); ++i) {
            for (int tileIndex : vertexToTiles[i]) {
                vertices[i].addAdjacentTile(&tiles[static_cast<size_t>(tileIndex) - 1]);
            }
        }

        // Initialize edges and set vertex connections
        edges.resize(72);
        vector<pair<unsigned int, unsigned int>> vertexConnections = {
            {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {0, 8}, {2, 10}, {4, 12}, {6, 14},
            {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15}, {7, 17},
            {9, 19}, {11, 21}, {13, 23}, {15, 25}, {16, 17}, {17, 18}, {18, 19}, {19, 20},
            {20, 21}, {21, 22}, {22, 23}, {23, 24}, {24, 25}, {25, 26}, {16, 27}, {18, 29},
            {20, 31}, {22, 33}, {24, 35}, {26, 37}, {27, 28}, {28, 29}, {29, 30}, {30, 31},
            {31, 32}, {32, 33}, {33, 34}, {34, 35}, {35, 36}, {36, 37}, {28, 38}, {30, 40},
            {32, 42}, {34, 44}, {36, 46}, {38, 39}, {39, 40}, {40, 41}, {41, 42}, {42, 43},
            {43, 44}, {44, 45}, {45, 46}, {39, 47}, {41, 49}, {43, 51}, {45, 53}, {47, 48},
            {48, 49}, {49, 50}, {50, 51}, {51, 52}, {52, 53}
        };

        for (const auto& [v1, v2] : vertexConnections) {
            edges.emplace_back(vertices[v1], vertices[v2]);
        }
    }

    // Method to print the current state of the board
    void Board::printBoard() const {
        cout << "Board state:" << endl;
        for (const auto& tile : tiles) {
            cout << "Tile: " << toString(tile.getResource()) << ", Value: " << tile.getValue() << endl;
            for (const auto& [vertex, settlement] : tile.getSettlements()) {
                cout << "  Settlement at vertex " << vertex << ": " << settlement.first->getName() << " (" << settlement.second << ")" << endl;
            }
        }
        for (const auto& [location, playerName] : roads) {
            cout << "Road at location " << location << " by " << playerName << endl;
        }
        for (const auto& [location, settlement] : settlements) {
            cout << settlement.first << " has a " << settlement.second << " at location " << location << endl;
        }
    }

    // Check if a settlement can be placed at the given locations
    bool Board::canPlaceSettelment(int place1, int place2, const Player &player) const {
        return isSettelmentValid(place1, player) && isSettelmentValid(place2, player);
    }

    // Check if a road can be placed at the given locations
    bool Board::canPlaceRoad(int place1, int place2, const Player &player) const {
        return isLocationRoadValid(place1, player) && isLocationRoadValid(place2, player);
    }

    // Place a settlement at a specific vertex
    void Board::placeSettlement(int vertex, Player& player) {
        size_t u = static_cast<size_t>(vertex);
        if (!vertices[u].getOwner().empty()) {
            throw invalid_argument("This vertex is already occupied");
        }
        if (player.getSettlementCount() == 0) {
            cout << "No settlements to place" << endl;
            return;
        }
        vertices[u].setOwner(player.getName());
        player.decrementSettlements();
        player.incrementSettlment();
        player.addPoints(1);
        cout << player.getName() << " placed a settlement at vertex " << u << endl;
    }

    // Place a road at a specific edge
    void Board::placeRoad(int edge, Player& player) {
        size_t u = static_cast<size_t>(edge);
        if (player.getRoadCount() == 0) {
            cout << "No roads to place" << endl;
            return;
        }
        if (!edges[u].getOwner().empty()) {
            cout << "Place is taken by " << edges[u].getOwner() << endl;
            return;
        }
        edges[u].setOwner(player.getName());
        player.decrementRoads();
        player.incrementRoad();
        cout << player.getName() << " placed a road at edge " << edge << endl;
    }

    // Allocate resources to players based on the dice roll
    void ariel::Board::allocateResources(int diceRoll) {
        for (auto& tile : tiles) {
            if (tile.getValue() == diceRoll) {
                for (const auto& [vertex, settlement] : tile.getSettlements()) {
                    Player* player = settlement.first;
                    string type = settlement.second;
                    if (type == "Settlement") {
                        player->addResource(tile.getResource(), 1);
                    } else if (type == "City") {
                        player->addResource(tile.getResource(), 2);
                    }
                }
            }
        }
    }

    // Allocate initial resources to players
    void ariel::Board::allocateInitialResources() {
        for (const auto& tile : tiles) {
            for (const auto& settlement : tile.getSettlements()) {
                Player* player = settlement.second.first;
                const string& type = settlement.second.second;
                int amount = (type == "City") ? 2 : 1;
                player->addResource(tile.getResource(), amount);
            }
        }
    }

    // Get the list of vertices
    vector<Vertex>& Board::getVertices() {
        return vertices;
    }

    // Get the list of edges
    vector<Edge>& Board::getEdges() {
        return edges;
    }

    // Get the list of tiles
    vector<Tile>& Board::getTiles() {
        return tiles;
    }

    // Claim all resources of a specified type from all players for the given player
    int Board::claimAllResources(Resources resource, Player& player) {
        int totalResources = 0;
        for (auto* otherPlayer : players) {
            if (otherPlayer != &player) {
                int resourceCount = otherPlayer->getResource(resource);
                otherPlayer->removeResource(resource, resourceCount);
                player.addResource(resource, resourceCount);
                totalResources += resourceCount;
            }
        }
        return totalResources;
    }

    // Add a player to the board
    void Board::addPlayer(Player& player) {
        players.push_back(&player);
        std::cout << "Added player " << player.getName() << " to the board." << std::endl;
    }
}