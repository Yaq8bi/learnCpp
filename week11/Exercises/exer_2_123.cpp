#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
// #include <atomic>
#include <chrono>

constexpr int FIRST{0};
constexpr int SECOND{1};
constexpr int THIRD{2}; // print third char, if flag is set to it.
constexpr int ITERATIONS{10};

static std::mutex mtx;
static std::condition_variable cv;
static volatile int FLAG = FIRST; // shared variable :goes between FIRST{0} and SECOND{1} AND THIRD{2}. [would prevent compiler optimizations that could cache FLAG in a register instead of reading from memory.]
// static std::atomic<int> FLAG = FIRST; // shared variable :goes between FIRST{0} and SECOND{1} AND THIRD{2}.

void printOne()
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        std::unique_lock<std::mutex> lock{mtx};

        cv.wait(lock, []
                { return (FLAG == FIRST); });
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "1 - ";
        FLAG = SECOND; // The indicator, almost like telling the code where to jump in a way.

        lock.unlock();   //
        cv.notify_all(); // notify 1 other thread.
    }
}
void printTwo()
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        std::unique_lock<std::mutex> lock{mtx};

        cv.wait(lock, []
                { return (FLAG == SECOND); }); 
        std::cout << "2 - ";
        FLAG = THIRD;

        lock.unlock();
        cv.notify_all();
    }
}
void printThree()
{
    for (int i = 0; i < ITERATIONS; i++)
    {
        std::unique_lock<std::mutex> lock{mtx};

        cv.wait(lock, []
                { return (FLAG == THIRD); }); 
        std::cout << "3" << std::endl;
        FLAG = FIRST;

        lock.unlock();
        cv.notify_all();
    }
}

int main()
{
    // The threads
    std::thread firstThread{printOne};
    std::thread secondThread{printTwo};
    std::thread thirdThread{printThree};
    // Wait on the threads to to finish their tasks.
    firstThread.join();
    secondThread.join();
    thirdThread.join();

    return 0;
}