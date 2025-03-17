#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

template <typename T, size_t Size>
class ThreadSafeStack
{
public:
    ThreadSafeStack() : top(-1) {} // Initialize top at -1 (empty stack)

    // Delete copy constructor and copy assignment (uncopyable)
    ThreadSafeStack(const ThreadSafeStack &) = delete;
    ThreadSafeStack &operator=(const ThreadSafeStack &) = delete;

    // Push operation (blocks if stack is full)
    void push(const T &item)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cond_full.wait(lock, [this]
                       { return top < Size - 1; }); // Wait if full

        data[++top] = item;
        std::cout << "Pushed: " << item << std::endl;

        cond_empty.notify_one(); // Wake up a thread waiting on pop()
    }

    // Pop operation (blocks if stack is empty)
    T pop()
    {
        std::unique_lock<std::mutex> lock(mtx);
        cond_empty.wait(lock, [this]
                        { return top >= 0; }); // Wait if empty

        T item = data[top--];
        std::cout << "Popped: " << item << std::endl;

        cond_full.notify_one(); // Wake up a thread waiting on push()
        return item;
    }

private:
    T data[Size];                       // Fixed-size array for stack storage
    int top;                            // Stack pointer
    std::mutex mtx;                     // Mutex for thread safety
    std::condition_variable cond_empty; // Condition variable for empty stack
    std::condition_variable cond_full;  // Condition variable for full stack
};




// Example usage with multiple threads
void producer(ThreadSafeStack<int, 5> &stack)
{
    for (int i = 0; i < 10; ++i)
    {
        stack.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
    }
}

void consumer(ThreadSafeStack<int, 5> &stack)
{
    for (int i = 0; i < 10; ++i)
    {
        stack.pop();
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Simulate work
    }
}

int main()
{
    ThreadSafeStack<int, 5> stack; // Stack of size 5

    std::thread t1(producer, std::ref(stack));
    std::thread t2(consumer, std::ref(stack));

    t1.join();
    t2.join();

    return 0;
}
