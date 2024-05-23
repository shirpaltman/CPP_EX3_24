#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "player.hpp"

using namespace std;
namespace ariel{

    Player::Player(const string& playerName)
        :name(playerName),settlements(2),cities(0),roads(2),playerPoints(2){
            resources[Resources::Wood]=1;
            resources[Resources::Sheep]=1;
            resources[Resources::Wheat]=1;
            resources[Resources::Brick]=1;
            resources[Resources::Ore]=1;

        }
        



}