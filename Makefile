CXX = clang++
CXXFLAGS = -std=c++17 -Werror -Wsign-conversion -g
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose
TARGET= catan
DEMO_TARGET= demo

SRCS =  Demo.cpp catan.cpp player.cpp board.cpp Card.cpp Tile.cpp vertex.cpp TestCounter.cpp Test.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = catan.hpp player.hpp board.hpp Card.hpp resources.hpp


all:$(TARGET) $(DEMO_TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(DEMO_TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(OBJS)

test: TestCounter.o Test.o $(filter-out Demo.o, $(OBJECTS))
	$(CXX) $(CXXFLAGS) -v $^ -o $@



%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
	
clean:
	rm -f $(OBJS )$(TARGET) $(DEMO_TARGET)

valgrind: $(DEMO_TARGET) 
	valgrind $(VALGRIND_FLAGS) ./$(DEMO_TARGET)



.PHONY: all clean valgrind test

