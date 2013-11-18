#include<iostream>
#include "Hex.h"



int main(){
    
    int size = 0;
    
    while(size <3){ 
        cout << "Please enter the size of the board(size>=3):";
        cin >> size ;
        cout <<endl ;
    }

    //Initializing a board of specified size
    Hex* h = new Hex(size);

    cout << "Initial Board layout" ;
    h->printHexBoard();

     
    //cout << "\nHuman Player moves first(X)\n";
    int numMoves = 1;
    while( !h->checkGameOver() ){

        int i=-1,j=-1;

        cout<< "Moves " << numMoves << " : Player 1(X)\n";
        //Ask player 1 for its move till the move is valid or game is valid
        do{
            cout<<"Enter your next move: ";
            cin >>i >> j;
            cout << endl;
        }while(!h->makeMove(RED, i , j) && !h->checkGameOver() );
        h->printHexBoard();
        numMoves++;

        //Check for winner
        if(h->checkGameWinner(RED)){
            //Player 1 is the winner
            cout<<"Player 1 wins\n" ;
            return 1;
        }

        cout<< "Moves " << numMoves << " : Player 2(0)\n";
        //Ask player 2 for its move till the move is valid or game is valid
        do{
            cout<<"Enter your next move: ";
            cin >>i >> j;
            cout << endl;
        }while(!h->makeMove(BLUE, i , j) && !h->checkGameOver() );
        h->printHexBoard();
        numMoves++;

        //Check for winner
        if(h->checkGameWinner(BLUE)){
            //Player 2 is the winner
            cout<<"Player 2 wins\n" ;
            return 1;
        }
    }

    return 1;
}

