/*
 *Base class for Implentation of minimum spanning tree
 */

#include<queue>
#include "Graph.h"
#include <set>

using namespace std;

//Object to hold the vertex pair of edge and its cost
class Edge{
    public:
        //Stores the pair of vertex making the edge
        pair<int,int> vertexPair;
        double cost;
        
        //Constructor
        
        Edge(){}

        Edge(int v1, int v2, double c){
            vertexPair = pair<int,int>(v1 , v2);
            cost = c;
        }
        
};


//Comparator for comparing two edge objects 
class CompareEdges{
    
    public:
        //Gives higher priority to the edge with least cost
        bool operator()(Edge& e1 , Edge& e2){
            if(e1.cost > e2.cost)
                return true;
            return false;
        }

};

class MinSpanTree{
    
    protected:
        //Graph to store the minimum spanning tree
        Graph* mst;

        //Open set to store the edges to be considered in sorted order
        priority_queue<Edge, vector<Edge>, CompareEdges> openSet ;
        
        //Closet set
        set<int> closedSet ;

    
    public:
        
        //Method to calculate the minimum spanning tree and return the cost
        virtual double findMinSpanTree(Graph* graph) = 0;
        
        //Method to print the minimum spanning tree
        inline void printMST(){
            mst->printGraph();
        }


};

class Prim:public MinSpanTree{
    
    double findMinSpanTree(Graph* graph);

};
