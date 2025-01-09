#include <iostream>
#include <cassert>
#include "e21_Stack.hpp"

int main()
{
    Stack stack;
    stack.push(1);
    assert(stack.push(1) == true);
    stack.push(2);
    assert(stack.push(2) == true);
    stack.push(3);
    assert(stack.push(3) == true);
    stack.push(4);
    assert(stack.push(4) == true);
    
    stack.printAmount();

    stack.pop();
    stack.printAmount();

    stack.clear();

    return 0;
}