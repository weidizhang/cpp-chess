CXXFLAGS=-std=c++11 -Wall -pedantic

main: main.cpp board.cpp piece.cpp headers/*
	g++ $(CXXFLAGS) -o main main.cpp board.cpp piece.cpp