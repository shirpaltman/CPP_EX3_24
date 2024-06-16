
###Author:Shir Altman###
###ID:325168870###
###Email: shirpaltman@gmail.com###





---

# 🎓 Welcome to Shir's Catan Game Simulation! 🚀

Get ready to embark on an exciting journey through the fascinating Catan game simulation implemented in this assignment. Here you have a README for what's to come in this project. 🌟

---

## Overview ##

This project simulates a game of Catan, a popular board game where players collect resources, build settlements and roads, and compete to earn victory points. The simulation includes key game mechanics such as resource allocation, development card usage, and trading between players.

---

## Project Structure ##
.
├── src
│ ├── board.cpp
│ ├── catan.cpp
│ ├── player.cpp
│ ├── Card.cpp
│ ├── Deck.cpp
│ ├── Tile.cpp
│ ├── Vertex.cpp
│ ├── Demo.cpp
│ ├── Test.cpp
│ └── TestCounter.cpp
├── include
│ ├── board.hpp
│ ├── catan.hpp
│ ├── player.hpp
│ ├── Card.hpp
│ ├── Deck.hpp
│ ├── Tile.hpp
│ ├── Vertex.hpp
│ ├── resources.hpp
├── Makefile
├── README.md
└── .gitignore

---

## Classes and Their Responsibilities ##

### `Board` ###

The `Board` class handles the main game board logic, including the placement of roads and settlements, resource allocation, and initialization of the game board.

#### Key Methods:
- `addRoad`: Adds a road to the board.
- `addSettlement`: Adds a settlement to the board.
- `isSettelmentValid`: Checks if a settlement placement is valid.
- `isLocationRoadValid`: Checks if a road placement is valid.
- `initializeBoard`: Sets up the initial state of the board.
- `printBoard`: Prints the current state of the board.
- `canPlaceSettelment`: Checks if a settlement can be placed at specific locations.
- `canPlaceRoad`: Checks if a road can be placed at specific locations.
- `placeSettlement`: Places a settlement on the board.
- `placeRoad`: Places a road on the board.
- `allocateResources`: Allocates resources to players based on dice rolls.
- `allocateInitialResources`: Allocates initial resources to players.
- `claimAllResources`: Claims all resources of a specified type from all players.
- `addPlayer`: Adds a player to the board.

### `Catan` ###

The `Catan` class manages the overall game flow, including player turns, dice rolls, and determining the winner.

#### Key Methods:
- `ChooseStartP`: Chooses the starting player.
- `nextTurn`: Moves to the next player's turn.
- `printWinner`: Prints the winner of the game.
- `printGameStatus`: Prints the current game status.
- `ChooseStartingPlayer`: Chooses and returns the starting player.
- `addPlayer`: Adds a player to the game.
- `getPlayers`: Returns the list of players.
- `rollDiceOfCurrentPlayer`: Rolls the dice for the current player.
- `getPlayerByName`: Retrieves a player by name.
- `printAllResources`: Prints all players' resources.
- `getCurrentPlayer`: Returns the current player.

### `Player` ###

The `Player` class represents a player in the game, managing resources, points, and development cards.

#### Key Methods:
- `rollDice`: Simulates rolling the dice.
- `endTurn`: Ends the player's turn.
- `trade`: Facilitates trading resources between players.
- `buyDevelopmentCard`: Allows the player to buy a development card.
- `printPoints`: Prints the player's points.
- `printResources`: Prints the player's resources.
- `getName`: Returns the player's name.
- `getPlayerPoints`: Returns the player's points.
- `getResource`: Retrieves the quantity of a specific resource.
- `getIsPlaying`: Returns whether the player is currently playing.
- `setIsPlaying`: Sets the playing status of the player.
- `decrementSettlements`: Decreases the player's settlement count.
- `getSettlementCount`: Returns the player's settlement count.
- `getRoadCount`: Returns the player's road count.
- `incrementKnightCount`: Increases the player's knight count.
- `randomResource`: Chooses a random resource from the player's resources.
- `removeResource`: Removes a specific amount of a resource from the player.
- `decrementRoads`: Decreases the player's road count.
- `addDevelopmentCard`: Adds a development card to the player's collection.
- `getDevelopmentCards`: Returns the player's development cards.
- `getKnightCount`: Returns the player's knight count.
- `incrementSettlment`: Increases the player's settlement count.
- `incrementRoad`: Increases the player's road count.
- `chooseResourceToClaim`: Prompts the player to choose a resource to claim.
- `chooseResource`: Prompts the player to choose a resource.
- `chooseRoadLocation`: Prompts the player to choose a location for a road.

### `Card` ###

The `Card` class and its derived classes represent different types of development cards (Knight, Progress, VictoryPoint) and their effects.

#### Key Classes:
- `Card`: Base class for all cards.
- `VictoryPointCard`: Represents a victory point card.
- `KnightCard`: Represents a knight card.
- `ProgressCard`: Base class for all progress cards.
- `MonopolyCard`: Represents a Monopoly card.
- `YearOfPlentyCard`: Represents a Year of Plenty card.
- `RoadBuildingCard`: Represents a Road Building card.

### `Deck` ###

The `Deck` class manages a collection of development cards and provides functionality to draw and shuffle cards.

#### Key Methods:
- `initialize`: Initializes the deck with a predefined set of cards.
- `shuffle`: Shuffles the deck.
- `drawCard`: Draws a card from the deck.
- `isEmpty`: Checks if the deck is empty.

### `Tile` ###

The `Tile` class represents a hexagon tile on the game board, which produces resources based on dice rolls.

#### Key Methods:
- `getValue`: Returns the value of the tile.
- `getResource`: Returns the resource produced by the tile.
- `getSettlements`: Returns the settlements on the tile.
- `addSettlement`: Adds a settlement to the tile.
- `addAdjacentTile`: Adds an adjacent tile.

### `Vertex` ###

The `Vertex` class represents an intersection on the game board where settlements can be built.

#### Key Methods:
- `addAdjacentTile`: Adds an adjacent tile to the vertex.
- `getOwner`: Returns the owner of the vertex.
- `setOwner`: Sets the owner of the vertex.
- `getAdjacentTiles`: Returns the adjacent tiles.

---

## Testing ##

The project includes a comprehensive set of tests using the `doctest` framework. The tests cover various game scenarios, including resource allocation, development card usage, and player actions.



---

## Game Mechanics ##

### Resource Allocation ###
Resources are allocated to players based on the dice roll. Each tile produces a specific resource when its number is rolled. Settlements adjacent to the tile receive one resource, while cities receive two.

### Development Cards ###
Players can purchase development cards using specific resources. These cards provide various benefits, such as gaining extra victory points, moving the robber, or gaining resources.

### Trading ###
Players can trade resources with each other to obtain the resources they need to build roads, settlements, and cities.

### Winning the Game ###
The first player to reach 10 victory points wins the game. Points are earned by building settlements and cities, as well as by holding certain development cards.



---

Feel free to contribute to this project by submitting pull requests or opening issues. Enjoy playing Catan!

