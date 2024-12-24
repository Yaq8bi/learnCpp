/*
Make a multiple instance stack using a fixed size array of type int.
The stack shall be tested using assertion and provide the following functions:
A function to create a stack.
A function to push a data element a stack.
A function to get number of the data elements stored in a stack.
A function to pop an element from a stack.

A function to clear a stack
A function to destroy a stack
*/
#include <iostream>
#include <cassert>
#include <thread>
#include <chrono>

constexpr int fixedSize{8};
int top{-1};

int *createTheStack() // create a pointer in the memeory that points to a set of array of fixed size.
{
    static int theStack[fixedSize];
    return theStack;
}

bool push(int *_stack, int _data)
{
    bool status = false;
    if (top < (fixedSize - 1))
    {
        top++;
        status = true;
        _stack[top] = _data;
        assert(_data == _stack[top]);
        printf("Assigned!\n");
        printf("in Stack: %i; Pos: %i; Status: %i;\v", _stack[top], top, status);
    }
    return status;
}

void pop(int *_stack)
{
    /*
    Example:
    [3]
    [2]
    [1]
    [0]
    -1(empty)
    */

    assert(top != -1); // return true to continue, else quit!
        if (top > -1) // because once we added something, top will be 0.
        {
            std::cout << "POPED: " << _stack[top] << std::endl;
            top--;

            std::this_thread::sleep_for(std::chrono::milliseconds(400));
        }
}

void printAmount()
{
    int loadingAnim[] = {'L', 'o', 'a', 'd', 'i', 'n', 'g', '.', '.', '.', '.', '.', '.', '.', '.', '.'};

    for (int i = 0; i < 16; i++)
    {
        printf("%c", loadingAnim[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    if (top == -1)
    {
        /* code */
        printf("\v\bThe stack is empty!");
    }

    printf("\nThere are %i amount of items in the stack.\n", top);
}

void clear(int *_stack)
{
    assert(top >= 0);
    for (int i = 0; i < fixedSize; i++)
    {
        _stack[top] = 0;
        top--;
    }
    printf("The stack has been cleared!");
}

int main()
{
    int *theStack = createTheStack(); // an integer pointer that points to the static pointer array that is returned from the function.
    int data{0};                      // initialize data with 0
    int items{0};

    for (size_t i = 0; i < fixedSize; i++)
    {
        std::cout << "\vWhat would you like to save?:" << std::endl;
        std::cin >> data;                                                               // take data from mr user
        printf("The push was %s ", push(theStack, data) ? "SUCCESS!\n" : "FAILURE!\n"); // This broke the code after a boolean was returned.
    }

    printAmount();
    pop(theStack); // print the LIFO(last in first out)!
    printAmount();
    clear(theStack);//if top is more than 0, clear. 

    return 0;
}