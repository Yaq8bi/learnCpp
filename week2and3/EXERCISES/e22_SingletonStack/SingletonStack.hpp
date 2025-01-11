#ifndef SINGLETONSTACK_HPP
#define SINGLETONSTACK_HPP

#include <iostream>

class SingletonStack
{
public:
    static SingletonStack &accessInstance(); /*Returning*/
    bool push(int _data);
    void printAmount();
    bool pop();
    bool clear();

private:
    int top{-1};
    static constexpr int compileConst{8};
    int singleStack[compileConst];

    SingletonStack(const SingletonStack &) = delete; // Deleting the copy constructor.
    SingletonStack() = default;                      // Constructor
};

#endif // SINGLETONSTACK_HPP