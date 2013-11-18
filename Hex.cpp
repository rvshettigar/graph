#include<iostream>
#include "Hex.h"

using namespace std;

bool debug3 = false;
Hex::Hex(int size){
    //Initializing the variables
    gameOver = false;
    //Set the board size
    setBoardSize(size);
    
    debug3 && cout<< "Before initializing the HexGraph\n" ;

    //Initialize the hex graph
    hexBoard = new HexGraph<VertexValue>(size , EMPTY);
    
    debug3 && cout<< "After initializing the HexGraph\n" ;
    //Add the edges to the HexGraph
    
    for(int i=0; i < size ; i++){
        for(int j=0; j< size; j++){
            //Add the edges between left virtual node to vertices belonging to the column 0
            if(j==0){
                hexBoard->addEdge((size*size) , getIndexMapping(i,j) , 1.0);
            }
            //Add the edges between right virtual node to vertices belonging to the column size-1
            if(j==size-1){
                hexBoard->addEdge((size*size + 1) , getIndexMapping(i,j) , 1.0);
            }
            //Add the edges between top virtual node to vertices belonging to the row 0
            if(i==0){
                hexBoard->addEdge((size*size + 2) , getIndexMapping(i,j) , 1.0);
            }
            //Add the edges between bottom virtual node to vertices belonging to the row size-1
            if(i==size-1){
                hexBoard->addEdge((size*size + 3) , getIndexMapping(i,j) , 1.0);
            }


            //Go through each vertex in the board and add the valid edges

            for(int k = i-1 ; k<=i+1 ; k++){
                for(int l = j-1; l<= j+1 ; l++){

                    if( (k==i-1 && l==j-1) ||
                        (k==i+1 && l==j+1) ||
                        k <0 || k>=size ||
                        l <0 || l>=size ){

                        //Not a valid edge 
                        continue;
                    }else{

                        //Add the valid edge
                        int vertex1 = i*size + j;
                        int vertex2 = k*size + l;
                        debug3 && cout<< "Adding edge between (" << i <<", "<< j <<") and (" << k <<", "<< l <<")\n";    
                        hexBoard->addEdge(vertex1,vertex2,1.0);
                    }
                }
            }

        }
    }

}

void Hex::printHexBoard(){
   
    int size = getBoardSize();
    //Print the initial header
    printf("\n\n"); 
    printf(" ");
    for(int i=0; i< size; i++){
        printf(" %d",i);
    }
    printf("\n");
    
    for(int i=0; i< size; i++){
        //Print offset
        for(int k=0;k<=i;k++)
            printf(" ");
        printf("%d " , i) ;
        for(int j=0; j<size; j++){
            const char* vertexVal = getVertexValueString(hexBoard->getVertexValue(i*size+j));
            printf("%s ", vertexVal);
            
        }
        printf("%d\n",i);
    }
    //Print the offset for footer
    for(int k=0 ;k<=size;k++)
        printf(" ");
    printf("");
    //Print the footer
    for(int i=0; i< size; i++)
        printf(" %d",i);
    printf("\n");

    printf("\n\n"); 
}


bool Hex::makeMove(VertexValue val, int i, int j){

    //check if i and j are valid
    if( i<0 || i>=boardSize || j<0 || j>=boardSize ){
        return false;
    }

    //Check if the position is already taken by other player
    int index = getIndexMapping(i,j);

    //Make the move only if the position is empty
    if( !hexBoard->getVertexValue(index) == EMPTY){
        return false;
    }

    //Move is valid make the move

    hexBoard->setVertexValue(val , index);

    return true;

}

bool Hex::checkGameWinner(VertexValue color){

    //Initialize Min span tree
    ColoredMinSpanTree* cMST = new ColoredPrim();
    double cost = cMST->findMinSpanTree(hexBoard , color);

    if(cost != -1){
        gameOver = true;
        return true;
    }
    return false;


}
