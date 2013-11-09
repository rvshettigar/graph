#include "PriorityQueue.h"
#include <iostream>


using namespace std;


int main(){
    
    PriorityQueue* pr = new PriorityQueue();

    pr->insertElem(4,13);
    pr->insertElem(3,5);
    pr->insertElem(2,9);
    pr->insertElem(1,2);
    
    for(int i=0 ; i<pr->size() ;i++){
        
        printf("%d\n", pr->minQueue[i]->priority  );

    }


    
    if( pr->contains(4) ) {
        pr->changePriority(4,1);
    }

    while(!pr->isEmpty()){
        Element * elem = pr->minPriority();
        printf("(%d,%d)\n",elem->vertex,elem->priority);
    }

}
