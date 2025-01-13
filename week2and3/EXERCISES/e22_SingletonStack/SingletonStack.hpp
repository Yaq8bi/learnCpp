#ifndef SINGLETONSTACK_HPP
#define SINGLETONSTACK_HPP

#include <iostream>

class SingletonStack
{
public:
    static SingletonStack &accessInstance(); /*Returning*/
    bool push(int _data);
    void printAmount();
    bool pop(int &_int);
    bool clear();

private:
    int top{-1};
    static constexpr int compileConst{8};
    static int singleStack[compileConst];

    SingletonStack() = default;                      // Constructor
    SingletonStack(const SingletonStack &) = delete; // Deleting the copy constructor.

    //GPT
    SingletonStack &operator=(const SingletonStack &) = delete;
};

#endif // SINGLETONSTACK_HPP