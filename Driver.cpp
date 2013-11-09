//#include "Graph.h"
#include "ShortestPath.h"
#include <iostream>


using namespace std;


int main(){
    /*
    int numVertices;
    cout << "Enter the number of vertices in the graph: " ;
    cin >> numVertices;
    cout << endl;
    */
    Graph * g = new Graph(50, 10, 0.2);
    
    /*
    //Test 1
    Graph * g= new Graph(5);
    g->addEdge(0,1,6);
    g->addEdge(0,2,1);
    g->addEdge(1,2,1);
    g->addEdge(1,3,4);
    g->addEdge(3,2,6);
    g->addEdge(3,4,6);
    g->addEdge(4,0,8);
    g->addEdge(4,2,1);

    */

    /*
    //Test 2
    Graph * g= new Graph(5);
    g->addEdge(2,1,7);
    g->addEdge(3,2,4);
    */
    
    //g->printGraph();
    

    ShortestPath* spath = new ShortestPath();
    int start=0 , end=49;
    /*
    printf ("Enter the starting point(0 - %d) : " , numVertices -1 )  ;
    cin >> start ;
    cout << endl;

    printf ("Enter the ending point(0 - %d) : " , numVertices -1 )  ;
    cin >> end;
    cout <<endl;
    */
    double sPathCost = spath->calculateShortestPath(g,start,end);
    cout <<"Shortest path cost is " <<sPathCost <<endl;
    spath->printShortestPath(start,end);


    return 1;

}

