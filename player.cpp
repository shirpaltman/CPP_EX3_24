

/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "player.hpp"
#include <random>

using namespace std;
namespace ariel {

    // Constructor to initialize player with name, default resources, and initial settlements and roads
    Player::Player(const string& playerName)
        : name(playerName), playerPoints(0), KnightCount(0), isPlaying(true),
          settlements(2), roads(2), cities(0), settlementCount(2), roadCount(2) {
        resources[Resources::Wood] = 1;
        resources[Resources::Sheep] = 1;
        resources[Resources::Wheat] = 1;
        resources[Resources::Brick] = 1;
        resources[Resources::Ore] = 1;
    }

    // Destructor to clean up dynamically allocated development cards
    Player::~Player() {
        for (auto card : developmentCards) {
            delete card;
        }
    }

    // Roll two dice and return the sum
    int Player::rollDice() const {
        static random_device rd;  // Non-deterministic generator
        static mt19937 gen(rd()); // Mersenne Twister engine
        static uniform_int_distribution<> dis(1, 6);
        int check = dis(gen) + dis(gen);
        cout << check << endl;
        return check;
    }

    // End the player's turn
    void Player::endTurn() {
        cout << name << " has ended their turn" << endl;
        isPlaying = false;
    }

    // Trade resources with another player
    void Player::trade(Player &other, string give, string get, int totalGive, int totalGet) {
        Resources giveR = stringToResources(give);
        Resources getR = stringToResources(get);

        if (this->getResource(giveR) < totalGive) {
            cout << "You don't have enough " << give << " to trade." << endl;
            return;
        }
        if (other.getResource(getR) < totalGet) {
            cout << other.getName() << " doesn't have enough " << get << " to trade." << endl;
            return;
        }

        // Execute the trade
        this->resources[giveR] -= totalGive;
        other.resources[getR] -= totalGet;
        this->resources[getR] += totalGet;
        other.resources[giveR] += totalGive;

        cout << this->getName() << " traded " << totalGive << " " << give << " with " << other.getName() << " for " << totalGet << " " << get << "." << endl;
    }

    // Buy a development card
    void Player::buyDevelopmentCard(Deck& deck, Board& board) {
        if (resources[Resources::Wheat] >= 1 && resources[Resources::Sheep] >= 1 && resources[Resources::Ore] >= 1) {
            if (!deck.isEmpty()) {
                resources[Resources::Wheat]--;
                resources[Resources::Ore]--;
                resources[Resources::Sheep]--;
                Card* newCard = deck.drawCard();
                if (newCard) {
                    developmentCards.push_back(newCard);
                    std::cout << "Player " << name << " drew a card: " << newCard->getDesc() << std::endl;
                } else {
                    std::cerr << "Error: No card was drawn!" << std::endl;
                }
            } else {
                throw invalid_argument("Insufficient resources to buy a development card.");
            }
        }
    }

    // Print the player's points
    void Player::printPoints() const {
        cout << name << " has " << playerPoints << " points" << endl;
    }

    // Print the player's resources
    void Player::printResources() const {
        cout << "Player " << name << " Resources:" << endl;
        for (const auto& resource : resources) {
            cout << toString(resource.first) << ": " << ", Amount: " << resource.second << endl;
        }
    }

    // Get the player's name
    string Player::getName() const {
        return name;
    }

    // Get the player's points
    int Player::getPlayerPoints() const {
        return playerPoints;
    }

    // Get the amount of a specific resource
    int Player::getResource(Resources resource) const {
        auto it = resources.find(resource);
        if (it != resources.end()) {
            return it->second;
        }
        return 0;
    }

    // Check if the player is currently playing
    bool Player::getIsPlaying() const {
        return isPlaying;
    }

    // Set the player's playing status
    void Player::setIsPlaying(bool flag) {
        isPlaying = flag;
    }

    // Decrement the player's settlements count
    void Player::decrementSettlements() {
        settlements--;
    }

    // Get the number of settlements the player has
    int Player::getSettlementCount() const {
        return settlementCount;
    }

    // Get the number of roads the player has
    int Player::getRoadCount() const {
        return roadCount;
    }

    // Increment the player's knight count
    void Player::incrementKnightCount() {
        cout << "Incrementing knight count for player: " << name << endl;
        KnightCount++;
    }

    // Choose a random resource from the player's available resources
    Resources Player::randomResource() const {
        std::vector<Resources> availableResources;
        for (const auto& pair : resources) {
            if (pair.second > 0) {
                availableResources.push_back(pair.first);
            }
        }
        if (!availableResources.empty()) {
            size_t randomIndex = static_cast<size_t>(std::rand()) % availableResources.size();
            return availableResources[randomIndex];
        }
        return Resources::None;
    }

    // Remove a specific amount of a resource
    void Player::removeResource(Resources resource, int amount) {
        if (resources.find(resource) != resources.end() && resources[resource] >= amount) {
            resources[resource] -= amount;
        }
    }

    // Decrement the player's roads count
    void Player::decrementRoads() {
        if (roads > 0) {
            roads--;
        }
    }

    // Add a development card to the player's collection
    void Player::addDevelopmentCard(Card* card) {
        if (card) {
            std::cout << "Adding card: " << card->getDesc() << " to player: " << name << std::endl;
            developmentCards.push_back(card);
        } else {
            std::cerr << "Attempted to add a null card to player: " << name << std::endl;
        }
    }

    // Get the player's development cards
    vector<Card*>& Player::getDevelopmentCards() {
        return developmentCards;
    }

    // Get the player's knight count
    int Player::getKnightCount() const {
        cout << "Returning knight count for player: " << name << endl;
        return KnightCount;
    }

    // Increment the player's settlement count
    void Player::incrementSettlment() {
        settlementCount++;
    }

    // Increment the player's road count
    void Player::incrementRoad() {
        roadCount++;
    }

    // Allow the player to choose a resource to claim (for Monopoly card)
    Resources Player::chooseResourceToClaim() {
        std::cout << "Choose a resource to claim (1: Wood, 2: Brick, 3: Wheat, 4: Ore, 5: Sheep): ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: return Resources::Wood;
            case 2: return Resources::Brick;
            case 3: return Resources::Wheat;
            case 4: return Resources::Ore;
            case 5: return Resources::Sheep;
            default: return Resources::None;
        }
    }

    // Allow the player to choose a resource (for Year of Plenty card)
    Resources Player::chooseResource() {
        std::cout << "Choose a resource (1: Wood, 2: Brick, 3: Wheat, 4: Ore, 5: Sheep): ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1: return Resources::Wood;
            case 2: return Resources::Brick;
            case 3: return Resources::Wheat;
            case 4: return Resources::Ore;
            case 5: return Resources::Sheep;
            default: return Resources::None;
        }
    }

    // Allow the player to choose a location for the road (for Road Building card)
    int Player::chooseRoadLocation() {
        std::cout << "Choose a location for the road: ";
        int location;
        std::cin >> location;
        return location;
    }

}