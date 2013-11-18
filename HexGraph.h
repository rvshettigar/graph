#include "Graph.h"
#include <vector>

enum VertexValue { EMPTY, RED, BLUE};


//Extends the regular graph to add a data field for each vertex
template <class vertexData>
class HexGraph: public Graph{
    //Vector to store arbitary data 
    vector<vertexData> *vertexValues;

    //Hex board size
    int hexBoardSize ;

    public:
        
        //Constructor
        HexGraph(int size, vertexData defaultValue):Graph(size*size+4){
        	hexBoardSize = size;
            vertexValues = new vector<vertexData>(size*size+4);
            //Initialize all the element in the vector to the default value
            for(int i=0 ;i< size*size ; i++){
                vertexValues->at(i) = defaultValue;
            }
            //Initialize the four virtual nodes
            vertexValues->at(size*size) = RED;
            vertexValues->at(size*size+1) = RED;
            vertexValues->at(size*size+2) = BLUE;
            vertexValues->at(size*size+3) = BLUE;

        }

        //Get the value for vertex specified by index
        inline vertexData getVertexValue(int index){
            return vertexValues->at(index) ;
        }

        //Set the value
        inline void setVertexValue(vertexData v,int index){
            vertexValues->at(index) = v;
        }

        //Get the hex board size
        inline int getHexBoardSize(){
        	return hexBoardSize;
        }

        

    

};