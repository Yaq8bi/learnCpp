#ifndef E21_STACK_HPP
#define E21_STACK_HPP

#include <iostream>

class Stack
{
//no Need for private EXCEPT FOR FUNCTIONS INSIDE THE PRIVATE
//We move the PRIVATE TO BOTTOM, so that we can see the public functions
public:
    static constexpr int fixedSize{8};
    // Stack() : stack{} {} // constructor.
    
    bool push(int _data);
    bool pop();
    void printAmount() const;
    bool isFull() const;
    bool isEmpty() const;
    void clear();
    
    private:
    int top{-1};
    int stack[fixedSize];
};

#endif // E21_STACK_HPP