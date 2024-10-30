#ifndef RENDER_HANDLER_H
#define RENDER_HANDLER_H

#include "Handler.h"

class RenderHandler : public Handler {
public:
    RenderHandler(std::atomic<bool>& running, std::mutex& inputMutex, char& directionInput);
    void start() override;
    void join() override;

private:
    void renderLoop();
};

#endif // RENDER_HANDLER_H
