#include <thread>
#include <iostream>
#include <mutex>

static int count{0};
static std::mutex mtx; // Variable locker

void increment(void)
{
    mtx.lock(); // Lock lines below( Accessible to only single thread at a time.)
    for (int i = 0; i < 50000; i++)
    {
        count++; // There is a race condition on modifying count
    }
    mtx.unlock(); // Unlock( Let other threads access again ), Thread 1 lost its priviliges(LOL).
}

int main(void)
{
    std::thread t1{increment};
    std::thread t2{increment};
    std::thread t3{increment};
    std::thread t4{increment};
    std::thread t5{increment};

    t1.join(); // Join, simultanously run all joins in main( CPU speed dependent ), creates problem, fix is let each access alone( mutex.lock ).
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << "Count value:" << count << std::endl;

    return 0;
}