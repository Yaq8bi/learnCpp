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
 #ifndef STACK_H
 #define  STACK_H

#include <cstddef>
#include <stdexcept>

template <typename T>

class theStack
{
private:
    int top{-1};
    int size{0};
    T *array{nullptr};
    static constexpr int MIN{4};

public:
    theStack(const theStack &) = delete;            // uncopyable
    theStack &operator=(const theStack &) = delete; // unnasignable

    theStack(int _size) : size{_size} // constructor
    {

        if (size < MIN)
        {
            throw std::invalid_argument{"Invalid Size"};
        }
        array = new T[size]{};
    }
    // stack  will not own the resources.
    // no exccept meaning do not return an exception.
    theStack(theStack &&_stack) noexcept : top{_stack.top}, size{_stack.size}, array{_stack.array}
    {
        _stack.array = nullptr;
        _stack.top = -1;
        _stack.size = 0;
    }

    theStack &operator=(theStack &&_stack) noexcept
    {
        if (this != &_stack)
        {
            delete array; // Realease resources

            // moving ownership back
            top = _stack.top;
            size = _stack.size;
            array = _stack.array;

            // queue will  not own the resources
            _stack.top = -1;
            _stack.size = 0;
            _stack.array = nullptr;
        }
        return *this;
    }

    bool push(const T &_data) noexcept
    {
        bool status{false};
        if (top < (size - 1))
        {
            top++;
            status = true;
            array[top] = _data;
        }
        return status;
    }

    bool pop(T &_data) noexcept
    {
        bool status{false};
        if (top > -1)
        {
            _data = array[top];
            status = true;
            top--;
        }
        return status;
    }

    int capacity(void) noexcept
    {
        return size;
    }

    int available(void) noexcept
    {
        return (top + 1);
    }

    void clear(void) noexcept
    {
        top = -1;
    }

    ~theStack()
    {
        delete array;
    }
};

 #endif // STACK_H