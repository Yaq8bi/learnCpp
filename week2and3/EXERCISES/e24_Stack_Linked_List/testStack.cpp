#include <iostream>
#include "stackWpointer.hpp"
#include <cassert>

int main(void)
{
    int value;
    Stack stck;

    assert(stck.push(10));
    assert(1 == stck.availableElements());

    assert(stck.push(20));
    assert(2 == stck.availableElements());

    std::cout << "Stack contents: " << stck << std::endl; // Print the stack contents

    assert(stck.pop(value));
    assert(1 == stck.availableElements());
    assert(20 == value);

    assert(stck.pop(value));
    assert(0 == stck.availableElements());
    assert(10 == value);

    stck.clear();

    assert(!stck.pop(value));
    assert(0 == stck.availableElements());

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

