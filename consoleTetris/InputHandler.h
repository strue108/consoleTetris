#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Handler.h"

class InputHandler : public Handler {
public:
    InputHandler(std::atomic<bool>& running, std::mutex& inputMutex, char& directionInput);
    void start() override;
    void join() override;

private:
    void inputLoop();
};

#endif // INPUT_HANDLER_H
