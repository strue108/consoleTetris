#include "GameInterface.h"
#include "GameInterface.h"

GameInterface::GameInterface() : running(true), directionInput(' ') {
    inputHandler = new InputHandler(running, inputMutex, directionInput);
    renderHandler = new RenderHandler(running, inputMutex, directionInput);
}

void GameInterface::start() {
    inputHandler->start();
    renderHandler->start();
}

void GameInterface::stop() {
    running = false;
    inputHandler->join();
    renderHandler->join();
}

GameInterface::~GameInterface() {
    delete inputHandler;
    delete renderHandler;
}
