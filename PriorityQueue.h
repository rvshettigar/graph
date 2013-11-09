#include <vector>
#include <map>


using namespace std;

class Element{
    public:
        int vertex;
        double priority;

        Element(int v, double p){
            vertex = v;
            priority = p;
        }

};

class PriorityQueue{
    public:

        ~PriorityQueue(){
            //delete minQueue;
            //delete vertexCostMap;
        }

        vector<Element*>  minQueue;

        map<int,double> vertexCostMap;

        void changePriority( int vertex, double newPr);
        
        Element*  minPriority();
        

        bool contains(int vertex);

        void insertElem(int vertex, double priority);

        Element* top();

        inline int size(){ return minQueue.size(); }

        void bubbleUp(int index);

        void bubbleDown(int index);

        void swapElems( int i, int j);

        inline bool isEmpty(){return minQueue.empty(); }
};
