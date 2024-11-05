#include "GameInterface.h"
#include <thread>
#include <chrono>
#include "Game.h"
#include "Tetromino.h"
#include <iostream>



int main() {
    Game game;
    
    /*
    int cnt = 0;

    Tetromino block;

    //for testing
    game.setCurrentBlock(Tetromino());
    
    while (true) {    
        //if (newGame.isNewBlock())
        //    newGame.setCurrentBlock(Tetromino());
        game.printGrid();

        game.testFunc();
        game.deleteLine();
        //newGame.setNextBlock(Z);
        //newGame.printGrid();
    }
    */
    game.start();

    //std::this_thread::sleep_for(std::chrono::seconds(15));
    
    
    return 0;
}