CXX = clang++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS = -v --leak-kinds=all --error-exitcode=99

TARGET= catan
DEMO_TARGET= demo

SRCS= Demo.cpp main.cpp catan.cpp player.cpp board.cpp cards.cpp
OBJS= $(SRCS:.cpp=.o)
DEPS= catan.hpp player.hpp board.hpp cards.hpp

all:$(TARGET) $(DEMO_TARGET)

$(TARGET):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
	
clean:
	rm -f $(OBJS )$(TARGET)

.PHONY: all clean

