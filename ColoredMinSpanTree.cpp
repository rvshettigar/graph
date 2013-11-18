#include "ColoredMinSpanTree.h"

using namespace std;


double ColoredPrim::findMinSpanTree(HexGraph<VertexValue>* graph, VertexValue color){
    int numV = graph->getNumVertices();
    int size = graph->getHexBoardSize();
    //Start and End nodes based on the color
    int start , end;
    if( color == RED ){
        start = size*size;
        end = size*size +1;
    }else if(color ==BLUE){
        start = size*size +2;
        end = size*size + 3;
    }
    bool debug = false ;

    
    //Initialize the minimum spanning tree
    mst = new Graph( numV );

    int currentNode = start;
    double currentCost = 0.0;

    //Start node is visited by default
    closedSet.insert(currentNode);
    while( closedSet.find(end) == closedSet.end() ){
        
        //Get the neighbors of current node
        map<int,double>* ecMap = graph->neighbors(currentNode);
        if(ecMap != NULL){
            
            for( map<int,double>::iterator it= ecMap->begin(); it!= ecMap->end(); it++  ){

                if( closedSet.find(it->first) == closedSet.end()){
                    //This neighbor has not been visited yet

                    //Check the color of the neighbor 
                    if( graph->getVertexValue(it->first) == color){
                        openSet.push( Edge(currentNode,it->first,it->second, color) );
                        debug && printf("Adding the edge (%d,%d,%f) to the open set\n",currentNode,it->first,it->second);
                    }

                    
                }
            }


        }
        
        //Find the next nearest node which is not in the closed set
        Edge minEdge;
        do{
            if(openSet.empty()){
                //There are no nodes to be visited; the graph is disconnected
                return -1;
            }
            minEdge = openSet.top();
            openSet.pop();
        }while(closedSet.find(minEdge.vertexPair.first) != closedSet.end() && closedSet.find(minEdge.vertexPair.second) != closedSet.end() );
        
        //the current node is the one not in closed set
        if( closedSet.find(minEdge.vertexPair.first) == closedSet.end() )
            currentNode = minEdge.vertexPair.first;
        else
            currentNode = minEdge.vertexPair.second;

        //Add edge to the mst graph
        mst->addEdge(minEdge.vertexPair.first,minEdge.vertexPair.second,minEdge.cost);
        debug && printf("Adding the edge (%d,%d,%f) to the min span tree\n",minEdge.vertexPair.first,minEdge.vertexPair.second,minEdge.cost);
        currentCost += minEdge.cost;
        
        //Add the new node to the closed set
        closedSet.insert(currentNode);


    }
    
    return currentCost;


}
