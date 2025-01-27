/*
Implement and test an uncopyable, but movable template stack class using an array whose size is specified during creation(size shall be greater than three)
The class shall provide the following function:
A function to get size of a stack.
A function to push a data element to a stack.
A function to get number of the data elements stored in a stack.
A function to pop an element from a stack.
A function to clear a stack
Use exception handling, test the class using assertions, ensure that the dynamic memory is managed properly and the class is movable.
*/
// #ifndef //STACK_H
// #define  //STACK_H

#include <cstdef>
#include <cstexcept>

template<typename T>

class theStack
{
private:
    int top{-1};
    int size{0};
    T *array{nullptr};
    static constexpr int SIZE_MIN{4};
public:
    theStack();
    ~theStack();
};

theStack::theStack(/* args */)
{
}

theStack::~theStack()
{
}



// #endif // STACK_H