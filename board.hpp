#ifndef BOARD_HPP
#define BOARD_HPP
#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
#include<random>
#include<algorithm>
#include "player.hpp"
#include "cards.hpp"



using namespace std;
namespace ariel{


 enum class Resources{
        Desert,
        Brick,
        Sheep,  
        Wheat,
        Wood,
        Ore,
        Sea
   
    };
    

    class Vertex;
    class Edge;
    class Tile;
    class Player;

    class Board{
    private:
        vector<pair<string,int>> board;
        unordered_map<int,pair<string,int>> settlements;  //we will want to know in every location wths the player's name and wht settlement type
        unordered_map<int,string> roads;        //we will want to know in a specific location whtat's the players name 
        unordered_map<int, string> tiles;
        vector<Edge> edges;
        vector<Vertex> vertices;
        
    public:
            Board();
            void addRoad(const string& playerName,int location);
            void addSettlement(const string& playerName,int location,const string& settlementType);
            bool isLocationSettelmentValid(int location)const;
            bool isLocationRoadValid(int location)const;
            void initializeBoard();
            void printBoard()const;
            bool canPlaceSettelment(int place1,int place2,const Player& player)const;
            bool canPlaceRoad(int place1,int place2, const Player& player)const;
            bool PlaceSettelment(int place1,int place2, Player& player);
            bool PlaceRoad(int place1,int place2,  Player& player);
            const string& getName()const;
            int getPoints()const;
  


        class Tile{
        public:
            Resources resource;
            int number;
            bool hasThief;
            Tile(Resources res,int num) : resource(res), number(num) ,hasThief(false){}
        };
    }; 

    Resources stringResource(const string& resourceString);

    class Vertex{
        public:
        string owner;
        vector<vector<Tile>> adjTiles;
        Vertex(string owner = "",vector<vector<Tile>> adjTiles ={}):owner(owner),adjTiles(adjTiles){}
        
        void addAdjTile(vector<Tile> tile){
            adjTiles.push_back(tile);
        }
    };


    class Edge{
        public:
        int id;
        int vertex1;
        int vertex2;

        Edge(int id,int ver1,int ver2) : id(id),vertex1(ver1),vertex2(ver2){}
 
    };
}
#endif
