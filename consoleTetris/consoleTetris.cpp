#include "GameInterface.h"
#include <thread>
#include <chrono>
#include "Game.h"
#include "Tetromino.h"
#include <iostream>



int main() {
    Game newGame;
    int cnt = 0;

    Tetromino block;
    newGame.setCurrentBlock(Tetromino());
    
    while (true) {    
        //if (newGame.isNewBlock())
        //    newGame.setCurrentBlock(Tetromino());
        newGame.printGrid();

        newGame.testFunc();
        newGame.deleteLine();
        //newGame.setNextBlock(Z);
        //newGame.printGrid();
    }
    
    return 0;
}