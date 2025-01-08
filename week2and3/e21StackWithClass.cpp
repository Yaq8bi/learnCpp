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
 
 
constexpr int fixedSize{8};

class Stack
{
    int top{-1};
    int *stack;

public:
    Stack() : stack(new int[fixedSize]()) {}

    bool push(int _data)
    {
        bool status = false;
        if (top < (fixedSize - 1))
        {
            top++;
            status = true;
            stack[top] = _data;
            assert(_data == stack[top]);
            printf("Assigned!\n");
            printf("in Stack: %i; Pos: %i; Status: %i;\v", stack[top], top, status);
        }
        return status;
    }

    void pop()
    {
        if (top > -1)
        {
            std::cout << "POPED: " << stack[top] << std::endl;
            top--;
        }
    }

    void printAmount()
    {
        std::cout << "Amount of elements in the stack: " << top + 1 << std::endl;
    }

    bool isFull() const
    {
        return top == fixedSize - 1;
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    void clear()
    {
        if (top >= 0)
        {
            for (int i = 0; i < fixedSize; i++)
            {
                stack[top] = 0;
                top--;
            }
            top = -1;
            printf("\nThe stack has been reset!");
            std::cout.flush();
        }
        else
        {
            printf("\nCould not clear, stack is empty.");
            std::cout.flush();
        }
    }

    ~Stack()
    {
        if (stack)
        {
            delete[] stack;
            stack = nullptr;
            std::cout << "\nThe stack is destroyed!" << std::endl;
            std::cout.flush();
        }
        else
        {
            std::cout << "The stack does NOT EXIST!" << std::endl;
            std::cout.flush();
        }
    }
};

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);

    stack.printAmount();

    stack.pop();
    stack.printAmount();

    stack.clear();
 
     
    return 0;
}