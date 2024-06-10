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
#include "Tile.hpp"
#include "vertex.hpp"

using namespace std;
namespace ariel{

    class Vertex;
    class Tile;
    class Player;





  class Edge{
        private:
            Vertex* vertex1;
            Vertex* vertex2;
        public:
            Edge(Vertex& v1,Vertex& v2):vertex1(&v1),vertex2(&v2){}
 
        Vertex* getVertex1()const{
            return vertex1;
        }
        Vertex* getVertex2()const{
            return vertex2;
        }
    };
    class Board{
    private:
        //vector<pair<string,int>> board;
        //unordered_map<int,pair<string,int>> settlements;  //we will want to know in every location wths the player's name and wht settlement type
        unordered_map<int,string> roads;        //we will want to know in a specific location whtat's the players name 
        unordered_map<int,pair<string, string>> settlements;
        vector<Edge> edges;
        vector<Vertex> vertices;
        vector<Tile> tiles;
        
    public:
    
            Board() = default;
            void addRoad(const string& playerName,int location);
            void addSettlement(const string& playerName,int location,const string& settlementType);
            bool isSettelmentValid(int location,const Player& player)const;
            bool isLocationRoadValid(int location,const Player& player)const;
            void initializeBoard();
            void printBoard()const;
            bool canPlaceSettelment(int place1,int place2,const Player& player)const;
            bool canPlaceRoad(int place1,int place2, const Player& player)const;
            bool PlaceSettelment(int place1,int place2, Player& player);
            bool PlaceRoad(int place1,int place2,  Player& player);
            const string& getName()const;
            int getPoints()const;
  





};
}


#endif
