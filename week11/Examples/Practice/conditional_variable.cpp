#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::condition_variable cv;
std::mutex mtx;
long balance{0};

void moneyAdd(int money)
{                                        // lg is an instance of lock_guard, takes an <mutex> as an argument. lg locks mtx immediately.
    std::lock_guard<std::mutex> lg(mtx); // auto locks the mutex, and unlocks automatically when the function ends( to minimize the risks of deadlocks ).
    balance += money;
    std::cout << "Amount added to the account: " << balance << std::endl;
    cv.notify_one(); // to wake up another thread that is sleeping and waiting for a condition change.
}
void withdrawMoney(int money)
{
    std::unique_lock<std::mutex> ul(mtx); // Starts as locked(1 thread access at a time), Able to manually lock and unlock.

    cv.wait(ul, []
            { return (balance != 0) ? true : false; });
    if (balance >= money)
    {
        balance -= money;
        std::cout << "Money deducted from account: " << money << std::endl;
    }
    else
    {
        std::cout << "Balance is less than " << money << std::endl;
    }
    std::cout << "Current amount in balance: " << balance << std::endl;
}

int main()
{
    std::thread thread_add{moneyAdd, 800};
    std::thread thread_withdraw{withdrawMoney, 500};

    thread_add.join();
    thread_withdraw.join();

    return 0;
}