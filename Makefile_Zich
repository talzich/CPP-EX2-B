#!make -f

CXX=clang++
CXXFLAGS=-std=c++2a -Werror -Wsign-conversion

.PHONY: all
all: board

board: Board.cpp Board.hpp Direction.hpp
	$(CXX) $(CXXFLAGS) board.cpp -o board

.PHONY: clean
clean:
	rm -f board