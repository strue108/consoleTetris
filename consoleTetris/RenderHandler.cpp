#include "RenderHandler.h"
#include <iostream>

RenderHandler::RenderHandler(std::atomic<bool>& running, std::mutex& inputMutex, char& directionInput)
    : Handler(running, inputMutex, directionInput) {}

void RenderHandler::start() {
    handlerThread = std::thread(&RenderHandler::renderLoop, this);
}

void RenderHandler::join() {
    handlerThread.join();
}

void RenderHandler::renderLoop() {
    while (running) {
        {
            std::lock_guard<std::mutex> lock(inputMutex);
            std::cout << "Current direction: " << directionInput << std::endl;  // Ãâ·Â
        }
    }
}
