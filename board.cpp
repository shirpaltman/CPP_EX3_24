#include "board.hpp"
#include "Card.hpp"
#include "player.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <stdexcept>
#include <string>

using namespace std;
namespace ariel{

    
    Board::Board() noexcept {
        initializeBoard();
    }




    
    void Board::addRoad(const string &playerName, int location, Player& player)
    {
        if(isLocationRoadValid(location,player)){
            roads[location]=playerName; 
            player.addResource(Resources::Wood, -1);
            player.addResource(Resources::Brick, -1); 
            cout<<playerName<< "placed a road at location" << location << "."<<endl;
        }
        else{
            cout << "Invalid road placement. Please try again." << endl;
        }
    }

    void Board::addSettlement(const string &playerName, int location, const string &settlementType, Player& player){
        if(isSettelmentValid(location,player)){
            settlements[location]=make_pair(playerName,settlementType);
            player.addResource(Resources::Wood, -1);
            player.addResource(Resources::Brick, -1);
            player.addResource(Resources::Sheep, -1);
            player.addResource(Resources::Wheat, -1);
            cout<<playerName<< "placed a " << settlementType << " at location" << location << "."<<endl;
            player.addPoints(1);
        }else{
            cout << "Invalid settlement placement. Please try again." << endl;
        }
    }

    bool Board::isSettelmentValid(int location, const Player &player) const{
        //we want to check if the location is vaild for palcing a settlement
        if(settlements.find(location) != settlements.end()){
            return false; //The location is already occupied
        }
        for(const auto& settlement : settlements){
            if(abs(settlement.first - location)<=2){
                return false; //Catan's distance rule must be at least two intersections away
            } 
        }
        if(player.getResource(Resources::Wood) < 1  || player.getResource(Resources::Brick) <1 || player.getResource(Resources::Sheep) || player.getResource(Resources::Wheat) ){
            return false;
        }
        return true;
    }


   bool Board::isLocationRoadValid(int location, const Player &player) const{
    //we want to check if the location is vaild for palcing a road
        if(roads.find(location) != roads.end()){
            return false; //The location is already occupied
        }
        // Check if the player has enough resources (1 Wood, 1 Brick)
        if(player.getResource(Resources::Wood)< 1 || player.getResource(Resources::Brick)< 1){
            return false;
        }
        return true;
   }

    
    void Board::initializeBoard()
    {
        Tile tile1 = Tile(Resources::Wood, 11,{Tile(Resources::Brick, 2),Tile(Resources::Wheat, 4),Tile(Resources::Ore, 5),Tile(Resources::Sea,0)});
    Tile tile2 = Tile(Resources::Brick, 2,{tile1,Tile(Resources::Ore, 5),Tile(Resources::Wood, 6),Tile(Resources::Sheep, 3),Tile(Resources::Sea,0)});
    Tile tile3 = Tile(Resources::Sheep, 3,{tile2,Tile(Resources::Ore, 5),Tile(Resources::Wood, 6),Tile(Resources::Brick, 11),Tile(Resources::Sea,0)});
    Tile tile4 = Tile(Resources::Wheat, 4,{tile1,Tile(Resources::Ore, 5),Tile(Resources::Wheat, 9),Tile(Resources::Sheep, 8)});
    Tile tile5 = Tile(Resources::Ore, 5,{tile1,tile2,tile4,Tile(Resources::Wood, 6),Tile(Resources::Wheat, 9),Tile(Resources::Desert, 7)});
    Tile tile6 = Tile(Resources::Wood, 6,{tile5,tile2,tile3,Tile(Resources::Brick, 11),Tile(Resources::Wood, 10),Tile(Resources::Desert, 7)});
    Tile tile7 = Tile(Resources::Brick, 11,{tile6,tile3,Tile(Resources::Wood, 10),Tile(Resources::Wood, 10),Tile(Resources::Sea, 0)});
    Tile tile8 = Tile(Resources::Sheep, 8,{tile4,Tile(Resources::Wheat, 9),Tile(Resources::Wheat, 3),Tile(Resources::Sea, 0)});
    Tile tile9 = Tile(Resources::Wheat, 9,{tile4,tile5,tile8,Tile(Resources::Wheat, 3),Tile(Resources::Ore, 4),Tile(Resources::Desert, 7)});
    Tile tile10 = Tile(Resources::Desert, 7,{tile9,tile5,tile6,Tile(Resources::Wood, 10),Tile(Resources::Wood, 5),Tile(Resources::Ore, 4)});
    Tile tile11 = Tile(Resources::Wood, 10,{tile6,tile7,tile10,Tile(Resources::Sheep, 12),Tile(Resources::Ore, 6),Tile(Resources::Wood, 5)});
    Tile tile12 = Tile(Resources::Sheep, 12,{tile7,tile11,Tile(Resources::Brick, 6),Tile(Resources::Sea, 0)});
    Tile tile13 = Tile(Resources::Wheat, 3,{tile8,tile9,Tile(Resources::Ore, 4),Tile(Resources::Sheep, 8),Tile(Resources::Sea, 0)});
    Tile tile14 = Tile(Resources::Ore, 4,{tile13,tile9,tile10,Tile(Resources::Wood, 5),Tile(Resources::Wheat, 9),Tile(Resources::Sheep, 8)});
    Tile tile15 = Tile(Resources::Wood, 5,{tile14,tile10,tile11,Tile(Resources::Brick, 6),Tile(Resources::Brick, 10),Tile(Resources::Wheat, 9)});
    Tile tile16 = Tile(Resources::Brick, 6,{tile15,tile11,tile12,Tile(Resources::Brick, 10),Tile(Resources::Sea, 0)});
    Tile tile17 = Tile(Resources::Sheep, 8,{tile13,tile14,Tile(Resources::Wheat, 9),Tile(Resources::Sea, 0)});
    Tile tile18 = Tile(Resources::Wheat, 9,{tile17,tile14,tile15,Tile(Resources::Brick, 10),Tile(Resources::Sea, 0)});
    Tile tile19 = Tile(Resources::Brick, 10,{tile18,tile15,tile16,Tile(Resources::Sea, 0)});
        

    tiles = {tile1,tile2,tile3,tile4,tile5,tile6,tile7,
                tile8,tile9,tile10,tile11,tile12,tile13,
                tile14,tile15,tile16,tile17,tile18,tile19};


    
    vertices.resize(54);
    vector<vector<int>> vertexToTiles ={
        {3},{3},{3,2},{2},{2,1},{1},{1},{3,7},{3,6,7},{2,3,6},{2,5,6},{2,1,5},
        {1,4,5},{1,4},{4},{7},{12},{7,12},{7,11,12},{6,7,11},{6,10,11},{5,6,10},
        {5,9,10},{4,5,9},{4,8,9},{4,8},{8},{8},{8,13},{8,9,13},{9,13,14},
        {9,10,14},{10,14,15},{10,11,15},{11,15,16},{11,12,16},{12,16},{12},
        {16},{16,19},{15,16,19},{15,18,19},{14,15,18},{14,18,17},{13,14,17},
        {13,17},{13},{17},{17},{17,18},{18},{18,19},{19},{19}
    };
    for(size_t i=0 ; i<vertexToTiles.size(); ++i){
        for(int tileIndex : vertexToTiles[i]){
            vertices[i].addAdjacentTile(&tiles[static_cast<size_t>(tileIndex)-1]);
        }
    }

    // Initialize edges
        edges.resize(72);

        // Vertex to vertex connections (example logic, should be tailored to actual game logic)
        vector<pair<unsigned int,unsigned int>> vertexConnections = {
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

        for (const auto& [v1,v2] : vertexConnections) {
            edges.emplace_back(vertices[v1],vertices[v2]);
        }
    }

    void Board::printBoard() const
    {
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

       
    bool Board::canPlaceSettelment(int place1, int place2, const Player &player) const
    {
        return isSettelmentValid(place1,player) && isSettelmentValid(place2,player);
    }
    bool Board::canPlaceRoad(int place1, int place2, const Player &player) const
    {
        return isLocationRoadValid(place1,player) && isLocationRoadValid(place2,player);
    }


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
        cout << player.getName() << " placed a settlement at vertex " << u << endl;

    }

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
        cout << player.getName() << " placed a road at edge " << edge << endl;
    }
  
    
    void ariel::Board::allocateResources(int diceRoll)
    {
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
    void ariel::Board::allocateInitialResources()
    {

        for (const auto& tile : tiles) {
            for (const auto& settlement : tile.getSettlements()) {
                Player* player = settlement.second.first;
                const string& type = settlement.second.second;
                int amount = (type == "City") ? 2 : 1;
                player->addResource(tile.getResource(), amount);
            }
        }   
    }
    vector<Vertex> &Board::getVertices() 
    {
        return vertices;
    }
    
    vector<Edge>& Board::getEdges() {

        return edges;
    }

    vector<Tile>& Board::getTiles() {
        return tiles;
    }

}