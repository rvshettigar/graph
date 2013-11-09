# Defining the compiler to use
CC=g++

FLAGS=-std=c++0x

CFLAGS=-Wall -Werror

all : GraphDriver


GraphDriver : Graph.h Graph.cpp GraphDriver.cpp ShortestPath.h ShortestPath.cpp PriorityQueue.h PriorityQueue.cpp
	$(CC)  Graph.cpp PriorityQueue.cpp ShortestPath.cpp  GraphDriver.cpp -o GraphDriver

clean:
	rm -rf *o GraphDriver
