#ifndef BOARD_HPP
#define BOARD_HPP

#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>
#include<random>
#include<algorithm>
#include "player.hpp"
#include "Card.hpp"
#include "Tile.hpp"
#include "vertex.hpp"
//#include "catan.hpp"


using namespace std;
namespace ariel{

    class catan;
    class Player;
    class Vertex;
    class Tile;
    





  class Edge{
        private:
            Vertex* vertex1;
            Vertex* vertex2;
            string owner;
        public:
            Edge() : vertex1(nullptr),vertex2(nullptr),owner(""){}
            Edge(Vertex& v1,Vertex& v2):vertex1(&v1),vertex2(&v2),owner(""){}
 
        Vertex* getVertex1()const{
            return vertex1;
        }
        Vertex* getVertex2()const{
            return vertex2;
        }
        const string& getOwner() const{
            return owner;
        }
        void setOwner(const string& owner){
            this->owner = owner;
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
    
            Board() noexcept;
            
            
            void addRoad(const string& playerName,int location, Player& player);
            void addSettlement(const string& playerName,int location,const string& settlementType,Player& player);
            bool isSettelmentValid(int location,const Player& player)const;
            bool isLocationRoadValid(int location,const Player& player)const;
            void initializeBoard();
            void printBoard()const;
            bool canPlaceSettelment(int place1,int place2,const Player& player)const;
            bool canPlaceRoad(int place1,int place2, const Player& player)const;
            void placeSettlement(int vertex, Player& player);
            void placeRoad(int edge, Player& player);
            void allocateResources(int diceRoll);
            void allocateInitialResources();
            vector<Vertex>& getVertices();
            vector<Edge>& getEdges() ;
            vector<Tile>& getTiles();
    };
}
#endif
