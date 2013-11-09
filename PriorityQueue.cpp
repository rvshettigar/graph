#include "PriorityQueue.h"


using namespace std;


void PriorityQueue::swapElems(int i, int j){
    
    Element* temp = minQueue[i];
    minQueue[i] = minQueue[j];
    minQueue[j] = temp;

}

void PriorityQueue::insertElem(int vertex, double priority){

    Element * elem = new Element(vertex,priority);
    vertexCostMap.insert( pair<int,double>(vertex,priority) );
    
    minQueue.push_back(elem);
    int index = minQueue.size() - 1;

    bubbleUp(index);

}

void PriorityQueue::bubbleUp(int index){

    int parent = (index-1)/2;
    
    //Check if parent is greater than current element

    if(parent>=0 &&  minQueue[parent]->priority > minQueue[index]->priority){
        swapElems(index, parent);
        bubbleUp(parent);
    }

}

void PriorityQueue::bubbleDown(int index){
    bool debug = false;
    int child1 = 2*index + 1;
    int child2 = 2*index + 2;
    debug && printf("PART 0 - %d , %d , %d\n",index,child1,child2);
    //Check if both child are greater than the index the return
    if( child1< minQueue.size() && minQueue[child1]->priority >= minQueue[index]->priority && child2< minQueue.size() && minQueue[child2]->priority >= minQueue[index]->priority  ){
        debug && printf("PART 1 - %d , %d , %d\n",index,child1,child2);
        return;
    }
    
    if( child2< minQueue.size() ){

        debug && printf("PART 2 - %d , %d , %d\n",index,child1,child2);
        //Both child exist then check which child is the smaller
        if( minQueue[child1]->priority < minQueue[child2]->priority && minQueue[child1]->priority < minQueue[index]->priority  ){
            swapElems(index,child1);
            bubbleDown(child1);
        }else if( minQueue[child2]->priority < minQueue[index]->priority ){
            swapElems(index,child2);
            bubbleDown(child2);
        }
    }else if(child1 <minQueue.size() && minQueue[child1]->priority < minQueue[index]->priority  ){
        //Child
        debug && printf("PART 3 - %d , %d , %d\n",index,child1,child2);
        swapElems(index,child1);
        bubbleDown(child1);
    }


}

Element* PriorityQueue::top(){
    return minQueue.front() ;
}

Element* PriorityQueue::minPriority(){
    if(isEmpty())
        return NULL;

    Element * elem = top();
    //Remove the vertex from map

    vertexCostMap.erase(elem->vertex);

    //Remove it from the priority queue
    
    swapElems(0 , minQueue.size()-1);
    minQueue.pop_back();
    bubbleDown(0);
    return elem;

}

bool PriorityQueue::contains(int vertex ){
    //Check the map if it contains the element

    if(vertexCostMap.find(vertex) == vertexCostMap.end()){
        return false;
    }
    return true;

}

void PriorityQueue::changePriority(int vertex, double newPr ){
    //update the map
    vertexCostMap[vertex] = newPr;
    
    int index = -1;
    //FInd the index of the vertex in the minQueue 
    for(int i=0; i< minQueue.size();i++){
        if(minQueue[i]->vertex == vertex){
            index = i;
        }
    }
    if (index == -1){
        return;
    }

    //update the priority queue
    minQueue[index]->priority = newPr ;
    
    if( minQueue[(index-1)/2] > minQueue[index] ){
        bubbleUp(index);
    }

}
