 #include "vertex.hpp"       

namespace ariel{    
        
    Vertex::~Vertex() {
        // Clean up dynamically allocated memory, if any
        for (auto *tile : adjTiles) {
            delete tile;
        }
    }
                    

}