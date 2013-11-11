#include "MinSpanTree.h"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[]){

    if(argc < 2){
        printf("Usage: %s <filename>\n", argv[0]);
        exit(0);
    }
    
    Graph* g = new Graph(argv[1]);
    
    //g->printGraph();

    MinSpanTree* mst = new Prim();
    double cost = mst->findMinSpanTree(g);

    printf("Cost of MST is %f\n", cost);

    if(cost != -1){
        mst->printMST();
    }

    return 1;

}

