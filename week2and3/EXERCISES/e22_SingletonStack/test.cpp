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
#include <thread>
#include <chrono>

#include "SingletonStack.hpp"

//  int SingletonStack::singleStack[];

int main()
{
    int temp{0};
    // Creating an instance of the SingletonStack class.
    SingletonStack &stack1 = SingletonStack::accessInstance();
    // Same instance as stack1.
    SingletonStack &stack2 = SingletonStack::accessInstance();
    assert(&stack1 == &stack2);//to check both is refereing to the same instance.

    stack1.printAmount();
    assert(stack2.push(1) == true);
    assert(stack1.push(2) == true);
    stack1.push(3);

    stack1.printAmount();
    std::cout << "\vStarting the popping now!\v" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));

    stack2.pop(temp);
    assert(temp == 3);
    stack1.pop(temp);
    assert(temp == 2);
    stack1.pop(temp);
    assert(temp == 1);

    stack1.clear();

    stack1.printAmount();

    return 0;
}

