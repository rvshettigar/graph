#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;
bool debug = false ;
bool debug1 = false;


Graph::Graph(int numV, int range, double density){
    
    numVertices = numV;
    
    adjacencyList = new vector<edgeCostMap*>(numV);

    //Randomly initialize the graph
    srand (time(NULL));

    //Iterate through each node and each possible edge
    for (int i=0; i< numV; i++ ){
        
        debug && printf ("Random Initialization Begin\n");

        for (int j=i+1; j < numV; j++){
            
            double randDensity = static_cast<double>(rand() % 1000) /1000;
            debug && printf ("Random density:%f\n",randDensity);
            
            //Create an edge if random density less than density
            if(randDensity < density){

                double randCost = static_cast<double> (rand() % (range*10)  )/10 + 1  ; 
                addEdge(i,j,randCost);
            
            }

        }

    }
       
}

Graph::Graph(int numV){
    numVertices = numV;
    adjacencyList = new vector<edgeCostMap*>(numV);
}


Graph::Graph(const char* fileName){
    //Open the file
    ifstream fileInput(fileName);
    if( !fileInput.is_open()  ){
        printf("Unable to open %s" , fileName);
        exit(-1);
    }
    
    if(!fileInput.eof()){
        //Extract the num vertices from the first line
        fileInput >> numVertices;
    }

    //Initialize the adjacency list
    adjacencyList = new vector<edgeCostMap*>(numVertices);
    
    //Extract the edges and their cost from remaining lines
    while(!fileInput.eof()){
        int vertex1,vertex2;
        double cost;

        fileInput >> vertex1 >> vertex2 >> cost ;

        //Perform some checks on the input
        if( (vertex1 < 0 || vertex1>= numVertices) || (vertex2 <0 || vertex2 >= numVertices) || cost <= 0 ){
            //Don't add this edge
            continue;
        }

        //Adding the edge to the graph
        addEdge(vertex1,vertex2,cost);
    }

}

void Graph::addEdge(int x, int y, double cost){
    //Dont want loops in the graph 
    if( x == y ) return;
    
    edgeCostMap* ecMap = dynamic_cast<edgeCostMap*>( adjacencyList->at(x));
    if( ecMap == NULL )
        ecMap = new edgeCostMap(); 
    
    edgeCostMap* ecMapAdj = dynamic_cast<edgeCostMap*>( adjacencyList->at(y));
    if( ecMapAdj == NULL )
        ecMapAdj = new edgeCostMap();
   

    //Create an edge if edge doesn't exist
    if( ecMap->find(y) != ecMap->end() || ecMapAdj->find(x) != ecMapAdj->end() ){
        return;
    }
    
    debug1 && printf ("Creating an edge (%d,%d) with cost %f\n",x,y,cost);
    //Creating an edge
    ecMap->insert(pair<int,double>(y , cost ));
    ecMapAdj->insert(pair<int,double>(x , cost ));

    adjacencyList->at(x) = ecMap;
    adjacencyList->at(y) = ecMapAdj;

}

double Graph::adjacent(int x, int y){
    //Check if an edge exists between the two vertices
    if ( adjacencyList->at(x)->find(y) != adjacencyList->at(x)->end() && adjacencyList->at(y)->find(x) != adjacencyList->at(y)->end()){
        return adjacencyList->at(x)->find(y)->second;
    }
    return -1;
 

}


map<int,double>* Graph::neighbors(int vertex){
    
    if(adjacencyList->at(vertex) != NULL){
        return adjacencyList->at(vertex);
    }
    return NULL;

}

void Graph::printGraph(){
    
   for(int i=0 ; i < numVertices ; i++){
        
    //printf("hello");
        printf( "Vertex %d: ",i );
        edgeCostMap * ecMap = adjacencyList->at(i);

        if(ecMap == NULL){
            continue;
        }
        

        for( edgeCostMap::iterator ecI = ecMap->begin() ; ecI != ecMap->end() ; ecI++){
        
            printf( "( %d, %f )\t", ecI->first,ecI->second);
            

        }
        cout << endl;
   }

}


