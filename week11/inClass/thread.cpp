#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// read the pdf document(examples in it)

int gloabalCounter{0};
std::mutex counterMutex;

void fiveThread(){
    for (int i = 0; i < 5; i++)
    {
        counterMutex.lock();
        gloabalCounter++;
        counterMutex.unlock();
        std::cout << "Updated by fiveThread function!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << std::this_thread::get_id() << std::endl;
    }
}

void tenThread(){
    for (int i = 0; i < 10; i++)
    {
        counterMutex.lock();
        gloabalCounter++;
        counterMutex.unlock();
        std::cout << "Updated from tenThread!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << std::this_thread::get_id() << std::endl;
    }
}

int main(){
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    // std::cout << std::this_thread::get_id() << std::endl; // print the id of the ID of the current thread.
    std::cout << "Starting thread ten..." << std::endl;
    std::thread thrdTen{tenThread};

    std::cout << "Running ten thread" << endl;
    std::thread thrdFive(fiveThread);

    tenThread.join();
    std::cout << "Ten Thread is done." << std::endl;
    fiveThread.join();
    std::cout << "Five Thread is done." << std::endl;

}
