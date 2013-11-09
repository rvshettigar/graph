#include "Graph.h"
#include <iostream>
#include <string>

using namespace std;


int main(){
    
    Graph* g = new Graph("mst_sample_graph.txt");
    
    g->printGraph();

    return 1;

}

