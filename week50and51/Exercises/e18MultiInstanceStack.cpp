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
    // If new cannot allocate mem, it will return a nullptr, which i will use for checking
    return new (std::nothrow) int[fixedSize](); // allocate memory and initialize it to 0.
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

    if (top > -1) // because once we added something, top will be 0.
    {
        std::cout << "POPED: " << _stack[top] << std::endl;
        top--;

        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}

void printAmount(int *_stack)
{
    int loadingAnim[] = {'L', 'o', 'a', 'd', 'i', 'n', 'g', '.', '.', '.', '.', '.', '.'};

    for (int i = 0; i < 13; i++)
    {
        printf("%c", loadingAnim[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }

    if (!_stack)
    {
        printf("\nThe stack does not exist in memory!");
        std::cout.flush();
        return;
    }

    if (top >= 0 && top <= fixedSize)
    {
        printf("\nThere are %i amount of items in the stack.\n", top+1);
        std::cout.flush();
    }
    else
    {
        printf("\nThe stack is empty!");
        std::cout.flush();
    }
}

void clear(int *_stack)
{
    if (top >= 0)
    {
        for (int i = 0; i < fixedSize; i++)
        {
            _stack[top] = 0;
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

void destroyStack(int **_stack) // double pointer, because the stack in main(argument) is also a pointer from another function.
{
    if (*_stack) // single pointer to the pointer in main.
    {
        delete[] *_stack; // this delete is a C++ thing that deletes the memory allocated with new, but the brackets make it delete the array.
        *_stack = nullptr;
        std::cout << "\nThe stack is destroyed!" << std::endl;
        std::cout.flush();
    }
    else
    {
        std::cout << "The stack does NOT EXIST!" << std::endl;
        std::cout.flush();
    }
}

int main()
{
    int *theStack = createTheStack(); // an integer pointer that points to a dynamically allocated pointer of the amount of "fixedSize".
    int data{0};                      // initialize data with 0
    int items{0};

    for (size_t i = 0; i < fixedSize; i++)
    {
        std::cout << "\vWhat would you like to save?:" << std::endl;
        std::cin >> data;                                                                 // take data from mr user
        printf("\nThe push was %s ", push(theStack, data) ? "SUCCESS!\n" : "FAILURE!\n"); // This broke the code after a boolean was returned.
        std::cout.flush();
    }

    assert(top != -1); // return true to continue, else quit!
    printAmount(theStack);

    pop(theStack); // print the LIFO(last in first out)!

    assert(top != -1); // return true to continue, else quit! check if top is not -1(empty)
    printAmount(theStack);

    assert(top >= 0);
    clear(theStack); // if top is more than 0, clear.

    destroyStack(&theStack);
    assert(theStack == nullptr);

    printAmount(theStack);

    return 0;
}