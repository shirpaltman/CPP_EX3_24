CXX = clang++
CXXFLAGS = -std=c++17 -Werror -Wsign-conversion
VALGRIND_FLAGS = -v --leak-kinds=all --error-exitcode=99

TARGET= catan
DEMO_TARGET= demo

SRCS = Demo.cpp catan.cpp player.cpp board.cpp Card.cpp Tile.cpp vertex.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = catan.hpp player.hpp board.hpp Card.hpp resources.hpp


all:$(TARGET) $(DEMO_TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(DEMO_TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(OBJS)


%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
	
clean:
	rm -f $(OBJS )$(TARGET) $(DEMO_TARGET)

.PHONY: all clean

