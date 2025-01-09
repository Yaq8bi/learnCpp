/*
Implement and test a stack class using an array of type int whose size is a compile-time constant.
The class shall provide the following function:
A function to push a data element to a stack.
A function to get number of the data elements stored in a stack.
A function to pop an element from a stack.
A function to check if a stack is full or not.
A function to check if a stack is empty or not
A function to clear a stack
*/
#include <iostream>
#include <cassert>
#include "e21_Stack.hpp"


bool Stack::push(int _data)
{
    bool status = false;
    if (top < (fixedSize - 1))
    {
        top++;
        status = true;
        stack[top] = _data;
        std::cout << "Stacked: " << stack[top] << "\n"
                  << "Rank: " << top << "\n"
                  << "Status: " << status << std::endl;
    }
    return status;
}

bool Stack::pop()
{
    bool status = false;
    if (top >= 0)
    {
        std::cout << "Popped: " << stack[top] << std::endl;
        status = true;
        top--;
    }
    return status;
}

void Stack::printAmount() const
{
    std::cout << "Total amount: " << top + 1 << std::endl;
}

bool Stack::isFull() const // Marking it as const ensures the compiler enforces this "read-only" behavior. If you accidentally tried to modify top or stack inside isFull(), the compiler would throw an error.
{
    return top == fixedSize - 1;
}

bool Stack::isEmpty() const
{
    return top == -1;
}

void Stack::clear()
{
    if (top >= 0)
    {
        for (int i = 0; i < fixedSize; i++)
        {
            stack[top] = 0;
            top--;
        } // clearing the stack.

        top = -1;
        printf("\nThe stack reset!");
        std::cout.flush();
    }
    else
    {
        std::cout << "\nCould not clear, stack is empty.";
        std::cout.flush();
    }
}

// ~Stack(){} // Destructor.