#include "Graph.h"
#include "PriorityQueue.h"
#include <vector>
#include <map>

using namespace std;

class ShortestPath{
    
    public:
        
        ~ShortestPath(){
           // delete closedMap;
           // delete openSet;
           // delete backLinkMap;
        }

        //Data structures for Dijkstra's algorithm

        //Visited nodes
        map<int,double> closedMap ;

        //Min queue of nodes with shortest path to source
        PriorityQueue openSet;

        //link to the previous node
        map<int,int> backLinkMap;

        //Calculate shortest path and return the cost
        double calculateShortestPath(Graph* g,int start, int end);

        //Print the shortest path
        void printShortestPath(int start, int end);


};


