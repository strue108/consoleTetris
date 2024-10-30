#include "InputHandler.h"
#include <iostream>

InputHandler::InputHandler(std::atomic<bool>& running, std::mutex& inputMutex, char& directionInput)
    : Handler(running, inputMutex, directionInput) {}

void InputHandler::start() {
    handlerThread = std::thread(&InputHandler::inputLoop, this);
}

void InputHandler::join() {
    handlerThread.join();
}

void InputHandler::inputLoop() {
    while (running) {
        char input;
        std::cin >> input;  // ����Ű �Է�
        {
            std::lock_guard<std::mutex> lock(inputMutex);
            directionInput = input;  // �Է°� ����


        }
    }
}
