#ifndef RESOURCES_HPP
#define RESOURCES_HPP
#include <unordered_map>
#include <stdexcept>
#include <memory>
#include <vector>


using namespace std;
namespace ariel{
    enum class Resources{
        Wood,
        Brick,
        Wheat,
        Ore,
        Sheep,
        Desert,
        Sea,
        None
    };


 inline Resources stringToResources (const string& Resourcestring){
        static unordered_map<string,Resources> mapResources={
            {"Wood", Resources::Wood},
            {"Brick", Resources::Brick},
            {"Ore", Resources::Ore},
            {"Sheep", Resources::Sheep},
            {"Wheat", Resources::Wheat},
            {"Desert", Resources::Desert},
            {"Sea", Resources:: Sea},
            {"None", Resources::None}

        }; 
       if(mapResources.find(Resourcestring)!=mapResources.end()){
        return mapResources[Resourcestring];
        }
        else{
            throw runtime_error("Invalid Resource");
            }

    }


    inline string toString(Resources Resources){
        switch(Resources){
            case Resources::Wood:return "Wood";
            case Resources::Brick:return "Brick";
            case Resources::Ore:return "Ore";
            case Resources::Sheep:return "Sheep";
            case Resources::Wheat:return "Wheat";
            case Resources::Desert:return "Desert";
            case Resources::Sea:return "Sea";
            case Resources::None:return "None";
            default:return "Unknown";
        }
    }


}
#endif //RESOURCES_HPP