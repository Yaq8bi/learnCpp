/*
Implement and test an uncopyable singleton stack class using an array of type int whose size is a compile-time constant.
The singleton class shall provide the following function:
A function to push a data element to the stack.
A function to get number of the data elements stored in the stack.
A function to pop an element from the stack.
A function to clear the stack
*/
#include <iostream>
#include <cassert>
#include "SingletonStack.hpp"

int main()
{
    SingletonStack &stack1 = SingletonStack::accessInstance(); // Creating an instance of the SingletonStack class.
    SingletonStack &stack2 = SingletonStack::accessInstance(); // Same instance as stack1.

    SingletonStack::printAmount();

    stack1.push(5);
    assert(stack1.push(5) == true);
    stack1.push(6);
    stack1.push(7);

    stack1.pop();
    assert(stack.pop() == true);
    stack1.pop();
    stack1.pop();

    stack1.clear();

    stack1.

    return 0;
}