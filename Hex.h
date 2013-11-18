/*
 * Defines the Hex class for playing the game of Hex
 */


#include "ColoredMinSpanTree.h"
#include <vector>





class Hex{
    //Stores the Hex board as a graph
    HexGraph<VertexValue> *hexBoard;

    //Size of the board
    int boardSize;

    //Flag for game over
    bool gameOver;

    public:
        //Constructor for initializing the hex board
        Hex(int size);

        //Get the board size
        inline int getBoardSize(){
            return boardSize;
        }
        
        //Set the board size
        inline void setBoardSize(int size){
            this->boardSize = size;
        }
        
        //Get the vertex value string
        const char* getVertexValueString(VertexValue val){
            const char* stringValue;
            switch(val){
                case EMPTY:
                    stringValue = "." ;
                    break;
                case RED:
                    stringValue = "X";
                    break;
                case BLUE:
                    stringValue = "0";
                    break;
            }
            return stringValue;
        }

        //Get the mapping
        int getIndexMapping(int i, int j){
            return (i*boardSize +j) ;
        }

        //Print the Hex board
        void printHexBoard();

        //Make move and return if the move is valid
        bool makeMove(VertexValue val, int i, int j);

        //Check if game is over
        bool checkGameOver(){
            return gameOver;
        }

        //Check if there is a winner
        bool checkGameWinner(VertexValue color);


};
