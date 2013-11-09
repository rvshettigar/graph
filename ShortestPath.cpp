#include "ShortestPath.h"
#include <iostream>
#include <stack>

using namespace std;
bool debug2 = false; 

double ShortestPath::calculateShortestPath(Graph* g ,int start, int end){
    if(start == end)
        return 0;

    int currentNode = start;
    double currentCost = 0.0;
    backLinkMap.insert( pair<int,int>(start, -1) );

    do{
        //Get the neighbors of current node
        map<int,double>* ecMap = g->neighbors(currentNode);
        if(ecMap == NULL){
            continue;
        }
        debug2 && printf("PART 0 : (%d,%f) \n", currentNode,currentCost);
        for( map<int,double>::iterator it= ecMap->begin(); it!= ecMap->end(); it++  ){
            
            if( closedMap.find(it->first) == closedMap.end()){
                //This neighbor has not been visited yet
                
                //Check if the neighbor is in the open set

                if (!openSet.contains(it->first) ){
                    
                    openSet.insertElem(it->first, (currentCost + it->second) );
                    backLinkMap.insert(pair<int,int>(it->first , currentNode));
                    debug2 && printf("Open Set Does not Contain : (%d,%f) \n", it->first, (currentCost + it->second) );
    
                }else{
                    //Neighbor is in the open set, now compare the cost of the vertex in open set
                    
                    if( openSet.vertexCostMap[it->first] > (currentCost + it->second) ){
                        debug2 && printf("Open Set Contains & Greater : (%d,%f)  Greater value in open set is %f \n", it->first, (currentCost + it->second), openSet.vertexCostMap[it->first] );
                        //Update the neighbor with the new cost in open set
                        openSet.changePriority(it->first , (currentCost + it->second) );

                        //update the backlink
                        backLinkMap.erase(it->first);
                        backLinkMap.insert(pair<int,int>(it->first , currentNode));


                    }else{

                        debug2 && printf("Open Set Contains & Less : (%d,%f) Lesser value in open set is %f \n", it->first, (currentCost + it->second), openSet.vertexCostMap[it->first] );
                    }

                }

            }

        }

        // Add the current node to the closed set
        closedMap.insert(pair<int,double>(currentNode,currentCost));

        //Get the element with the least cost from the min queue
        Element * nextNode = openSet.minPriority();
        if(nextNode == NULL ) break;
        currentNode = nextNode->vertex;
        currentCost = nextNode->priority;

        

    }while( closedMap.find(end) ==closedMap.end()  );

    if( closedMap.find(end)!=closedMap.end() )
        return closedMap[end] ;
    else
        return -1;


}

void ShortestPath::printShortestPath(int start, int end){
    if(start == end){
        printf("Shortest path from %d to %d is \n%d\t%d\n",start,end,start,end);
    }

    if( closedMap.find(end) == closedMap.end() )
        return;
    
    stack<int> path;
    path.push(end);

    int currentNode = end;
    printf("Shortest path from %d to %d\n",start,end);
    while(backLinkMap.find(currentNode)!=backLinkMap.end() &&  backLinkMap[currentNode] != -1){
        path.push(backLinkMap[currentNode]);
        currentNode = backLinkMap[currentNode];
    }

    while( !path.empty() ){
        printf("%d\t" , path.top());
        path.pop();
    }
    cout<<endl;

}
