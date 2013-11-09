#include <vector>
#include <map>

using namespace std;

class Graph{
    
    int numVertices;
    int numEdges;

    //Data structure to hold the graph

    typedef map<int,double> edgeCostMap;

    vector<edgeCostMap*> *adjacencyList;
    
    public:
        //Contstructor
        Graph(int numV);

        //Constructor to initialize the graph randomly
        Graph(int numV, int range, double density);
        
        //Constructor to initialize the graph from a file
        Graph(const char* fileName);

        //Destructor
        ~Graph(){
            delete adjacencyList;
        }

        //Print the Adjacency list
        void printGraph();
        
        //Method to check if node x is adjacent to node y and return the cost
        double adjacent(int x, int y);
        
        
        //Method to list all nodes adjacent to x
        edgeCostMap* neighbors(int x);
       

        //Add a edge
        void addEdge(int x,int y, double cost);

        //Get a edge value
        void getEdgeValue(int x, int y);

        //Set a edge value
        void setEdgeValue(int x,int y, double cost);




};
