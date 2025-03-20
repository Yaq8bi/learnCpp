#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

constexpr int PING{0};
constexpr int PONG{1};
constexpr int ITERATIONS{10};

static std::mutex mtx;
static std::condition_variable cv; // make it wait untill a condition is met.
static volatile int ping_pong = PING; // shared variable, lives in the RAM, not in register(CPU) :goes between PING{0} and PONG{1}

void ping(){
    for (int i = 0; i < ITERATIONS; i++)
    {
        std::unique_lock<std::mutex> lock{mtx};

        cv.wait(lock, []
                { return (ping_pong == PING); }); // wait until ping_pong is PING{0}

        std::cout << "Ping - ";
        ping_pong = PONG;

        lock.unlock(); // 
        cv.notify_one(); // notify 1 other thread.
    }
}
void pong(){
    for (int i = 0; i < ITERATIONS; i++)
    {
        std::unique_lock<std::mutex> lock{mtx};

        cv.wait(lock, []
                { return (ping_pong == PONG); });

        std::cout << "Pong" << std::endl;
        ping_pong = PING;

        lock.unlock();
        cv.notify_one();
    }
}

int main(){
    // The threads
    std::thread threadPing{ping};
    std::thread threadPong{pong};
    // Wait on the threads to to finish their tasks.
    threadPing.join();
    threadPong.join();

    return 0;
}