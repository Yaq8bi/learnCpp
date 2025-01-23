#include <iostream>
#include <cassert>
#include "e27_Uncopyable_Template.hpp"

int main()
{
//Test starts here to check that These shouldn't work because of: Uncopyable & Unassignable.
    /*queue<int> q;
    queue<int> queue{q}; // this shouldn't work.

    queue = q;*/
    //test Ends here
    queue<int> q;
    assert(q.enqueue(10));
    assert(1 == q.leftNodes());

     int value;
    assert(q.dequeue(value));
    assert(0 == q.leftNodes());
    assert(10 == value);

    assert(q.enqueue(10));
    assert(1 == q.leftNodes());

    assert(q.enqueue(20));
    assert(2 == q.leftNodes());

    assert(q.dequeue(value));
    assert(1 == q.leftNodes());
    assert(10 == value);

    q.erase();
    assert(0 == q.leftNodes());
    assert(!q.dequeue(value));

    std::cout << "All tests passed!" << std::endl;

    return 0;
}