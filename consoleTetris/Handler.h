#ifndef HANDLER_H
#define HANDLER_H

#include <thread>
#include <atomic>
#include <mutex>

class Handler {
public:
    Handler(std::atomic<bool>& running, std::mutex& inputMutex, char& directionInput);
    virtual void start() = 0; // ���� ���� �Լ���, ���� Ŭ�������� ����
    virtual void join() = 0;  // ���� ���� �Լ���, ���� Ŭ�������� ����

protected:
    std::atomic<bool>& running;
    std::mutex& inputMutex;
    char& directionInput;
    std::thread handlerThread;
};

#endif // HANDLER_H
