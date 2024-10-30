#include "Handler.h"

Handler::Handler(std::atomic<bool>& running, std::mutex& inputMutex, char& directionInput)
    : running(running), inputMutex(inputMutex), directionInput(directionInput) {}
