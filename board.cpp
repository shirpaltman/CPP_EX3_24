#include "board.hpp"
#include "cards.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <stdexcept>
#include <string>

using namespace std;
namespace ariel{


    Board::Board(){
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
            vertices[i].addAdjacentTile(tiles[tileIndex-1]);
        }
    }

    // Initialize edges
        edges.resize(72);

        // Vertex to vertex connections (example logic, should be tailored to actual game logic)
        vector<pair<int, int>> vertexConnections = {
            {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 0},
            {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14},
            {15, 16}, {16, 17}, {17, 18}, {18, 19}, {19, 20}, {20, 21}, {21, 22},
            {23, 24}, {24, 25}, {25, 26}, {26, 27}, {27, 28}, {28, 29}, {29, 30},
            {31, 32}, {32, 33}, {33, 34}, {34, 35}, {35, 36}, {36, 37}, {37, 38},
            {39, 40}, {40, 41}, {41, 42}, {42, 43}, {43, 44}, {44, 45}, {45, 46},
            {47, 48}, {48, 49}, {49, 50}, {50, 51}, {51, 52}, {52, 53}, {53, 0}
        };

        for (const auto& connection : vertexConnections) {
            edges.emplace_back(vertices[connection.first], vertices[connection.second]);
        }
    }




    // Resources stringResources (const string& Resourcestring){
    //     static unordered_map<string,Resources> mapResources={
    //         {"Wood", Resources::Wood},
    //         {"Brick", Resources::Brick},
    //         {"Ore", Resources::Ore},
    //         {"Sheep", Resources::Sheep},
    //         {"Wheat", Resources::Wheat},
    //         {"Desert", Resources::Desert},
    //         {"Sea", Resources:: Sea}

    //     }; 
    //     auto it =mapResourcesfind(Resourcestring);
    //     if(it !=mapResourcesend()){
    //         return it->second;
    //         }
    //         else{
    //             throw std::invalid_argument("Invalid Resources");
                
    //         }
    // }


    // string toString(Resources Resources){
    //     switch(Resources){
    //         case Resources::Wood:return "Wood";
    //         case Resources::Brick:return "Brick";
    //         case Resources::Ore:return "Ore";
    //         case Resources::Sheep:return "Sheep";
    //         case Resources::Wheat:return "Wheat";
    //         case Resources::Desert:return "Desert";
    //         case Resources::Sea:return "Sea";
    //         default:return "Unknown";
    //     }
    // }
    // void Board::initializeBoard(){
    //     board.clear();
    // //The amount of tiles will have for Resources        unordered_map<Resources,int> Resourcesmount ={
    //     {Resources::Brick,3},
    //     {Resources::Wood,4},
    //     {Resources::Ore,4},
    //     {Resources::Sheep,4},
    //     {Resources::Wheat,4},
    //     {Resources::Desert,1},
    // };



    // vector<Resources> Resources;
    //     for ( const auto& Resources: Resourcesmount) {
    //         for (int i = 0; i < Resourcessecond; ++i) {
    //         Resources.push_back(Resourcesfirst);
    //     }
    // }
    
    // random_device rd;
    // mt19937 g(rd());
    // shuffle(Resources.begin(), Resources.end(), g);
    // for(int i=0; i<19;++i){
    //     if (Resources.empty()){
    //         board.push_back({"Sea",0});
    //     } 
    //     else{
    //         board.push_back({toString(Resources.back()),0});
    //         Resources.pop_back();
    //     }
    // }
    //printBoard();
    
    void Board::printBoard()const{
        cout<< "Initialized board:" <<endl;
        int index = 0;
        for (const auto& tile : board) {
        cout << "[" << index << "] " << tile.first << " (" << tile.second << ")" << endl;
        ++index;
        }
    }
}

          
