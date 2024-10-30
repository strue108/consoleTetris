#ifndef HANDLER_H
#define HANDLER_H

#include <thread>
#include <atomic>
#include <mutex>

class Handler {
public:
    Handler(std::atomic<bool>& running, std::mutex& inputMutex, char& directionInput);
    virtual void start() = 0; // 순수 가상 함수로, 서브 클래스에서 구현
    virtual void join() = 0;  // 순수 가상 함수로, 서브 클래스에서 구현

protected:
    std::atomic<bool>& running;
    std::mutex& inputMutex;
    char& directionInput;
    std::thread handlerThread;
};

#endif // HANDLER_H
