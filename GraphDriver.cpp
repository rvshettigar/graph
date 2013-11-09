//#include "Graph.h"
#include "ShortestPath.h"
#include <iostream>


using namespace std;


int main(){
    double densities [] = {0.2, 0.4};
    int numVertices = 50;
    int range = 10;
    double sumGraphAvgPath,sumAvgPath,graphAvgPath,avgPath;
    int count,graphCount;

    for(int i =0; i< 2; i++){
        printf("Running 10000 simulations for graph of %d nodes having a density of %f \n", numVertices  ,densities[i]);
        sumAvgPath = 0;
        count = 0;
        for(int j =0; j< 10000; j++){

            Graph * g = new Graph( numVertices, range, densities[i] );
            //g->printGraph();
            sumGraphAvgPath = 0;
            graphCount = 0;
            for( int k=1; k<numVertices; k++){
                ShortestPath* spath = new ShortestPath();
                double sPathCost = spath->calculateShortestPath(g,0,k);

                if (sPathCost > 0 ){
                    sumGraphAvgPath += sPathCost;
                    graphCount++;
                }
                delete spath;
            }
            graphAvgPath = sumGraphAvgPath / graphCount;
            sumAvgPath += graphAvgPath;
            count ++;
            delete g;
        }
        avgPath = sumAvgPath/count;
        printf("Average of average path is %f\n", avgPath);

    }

    return 1;

}

