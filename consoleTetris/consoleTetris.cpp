#include "GameInterface.h"
#include <thread>
#include <chrono>
#include "Game.h"
#include "Tetromino.h"
#include <iostream>



int main() {
    Game game;
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
 

    std::thread timerThread(&Game::timer, &game);
    std::thread inputThread(&Game::inputHandler, &game);
    std::thread blcokFallThread(&Game::blockFall, &game);

    game.run();

    timerThread.join();
    inputThread.join();
    blcokFallThread.join();

    return 0;
}