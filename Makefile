
/*
Author:Shir Altman
ID:325168870
Email: shirpaltman@gmail.com
*/
CXX = clang++
CXXFLAGS =  -std=c++17 -Werror -Wsign-conversion -g
VALGRIND_FLAGS = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./demo--track-origins=yes --verbose

DEMO_TARGET= demo
TEST_TARGET= test

SRCS = catan.cpp player.cpp board.cpp Card.cpp 
DEMO_SRCS = Demo.cpp
TEST_SRCS = TestCounter.cpp Test.cpp

OBJS = $(SRCS:.cpp=.o)
DEMO_OBJS = $(DEMO_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
DEPS = catan.hpp player.hpp board.hpp Card.hpp resources.hpp

all: $(DEMO_TARGET) $(TEST_TARGET)

$(DEMO_TARGET): $(DEMO_OBJS) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(DEMO_OBJS) $(OBJS)

$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(DEMO_TARGET) $(TEST_TARGET)

valgrind: $(DEMO_TARGET)
	valgrind $(VALGRIND_FLAGS) ./$(DEMO_TARGET)

.PHONY: all clean valgrind