#ifndef GAME_INTERFACE_H
#define GAME_INTERFACE_H

#include <atomic>
#include <mutex>
#include "InputHandler.h"
#include "RenderHandler.h"

class GameInterface {
public:
    GameInterface();
    void start();
    void stop();
    ~GameInterface();

private:
    std::atomic<bool> running;
    std::mutex inputMutex;
    char directionInput;
    InputHandler* inputHandler;
    RenderHandler* renderHandler;
};

#endif // GAME_INTERFACE_H
