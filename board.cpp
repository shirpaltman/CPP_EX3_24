#include "board.hpp"
#include "cards.hpp"
#include <iostream>
#include <random>
#include <algorithm>


namespace ariel{


    Resources stringResource(const string& resourceString){
        static unordered_map<string,Resources> mapResource ={
            {"Wood", Resources::Wood},
            {"Brick", Resources::Brick},
            {"Ore", Resources::Ore},
            {"Sheep", Resources::Sheep},
            {"Wheat", Resources::Wheat},
            {"Desert", Resources::Desert},
            {"Sea", Resources:: Sea}

        };   
    }


    string toString(Resources resource){
        switch(resource){
            case Resources::Wood:return "Wood";
            case Resources::Brick:return "Brick";
            case Resources::Ore:return "Ore";
            case Resources::Sheep:return "Sheep";
            case Resources::Wheat:return "Wheat";
            case Resources::Desert:return "Desert";
            case Resources::Sea:return "Sea";
            default:return "Unknown";
        }
    }
    void Board::initializeBoard(){
        board.clear();
    //The amount of tiles will have for resource
    unordered_map<Resources,int> resourceAmount ={
        {Resources::Brick,3},
        {Resources::Wood,4},
        {Resources::Ore,4},
        {Resources::Sheep,4},
        {Resources::Wheat,4},
        {Resources::Desert,1},
    };



    vector<Resources> resources;
    for ( const auto& resource : resourceAmount) {
        for (int i = 0; i < resource.second; ++i) {
            resources.push_back(resource.first);
        }
    }
    
    random_device rd;
    mt19937 g(rd());
    shuffle(resources.begin(), resources.end(), g);
    for(int i=0; i<19;++i){
        if (resources.empty()){
            board.push_back({"Sea",0});
        } 
        else{
            board.push_back({toString(resources.back()),0});
            resources.pop_back();
        }
    }
    printBoard();
    }
    void Board::printBoard()const{
        cout<< "Initialized board:" <<endl;
        int index = 0;
        for (const auto& tile : board) {
        cout << "[" << index << "] " << tile.first << " (" << tile.second << ")" << endl;
        ++index;
        }
    }
}

