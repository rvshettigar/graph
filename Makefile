# Defining the compiler to use
CC=g++

FLAGS=-std=c++0x

CFLAGS=-Wall -Werror

all : GraphDriver


GraphDriver : Graph.h Graph.cpp GraphDriver.cpp ShortestPath.h ShortestPath.cpp PriorityQueue.h PriorityQueue.cpp
	$(CC)  Graph.cpp PriorityQueue.cpp ShortestPath.cpp  GraphDriver.cpp -o GraphDriver

MstDriver : Graph.h Graph.cpp MSTDriver.cpp MinSpanTree.h MinSpanTree.cpp
	$(CC)   Graph.cpp MSTDriver.cpp MinSpanTree.cpp  -o MstDriver

clean:
	rm -rf *o GraphDriver
