#include <iostream>
#include <cassert>
#include "SingletonStack.hpp"

/*When inside the sourcefile, i must write the class name(lives in header file), and then the members.*/
    static SingletonStack::SingletonStack &accessInstance() //Returns a reference to the instance. Pointer would need a arrow when called in main.
    {
        static SingletonStack instance;
        return instance;
    }

    bool SingletonStack::push(int _data)
    {
        bool status = false;          // failed
        if (top < (compileConst - 1)) // minus one becasue of the null at the end of the array.
        {
            top++;
            singleStack[top] = _data;
            status = true; // success

            std::cout << "Pos " << top << ": " << singleStack[top] << std::endl;
        }
        return status;
    };

    void SingletonStack::printAmount()
    {
        std::cout << "Total number of DATA stored in the stack: " << top + 1 << std::endl;
    }

    bool SingletonStack::pop()
    {
        bool status = false;
        if (top >= 0)
        {
            std::cout << "Popped: " << singleStack[top] << std::endl;
            status = true;
            top--;
        }
        return status;
    }

    bool SingletonStack::clear()
    {
        bool status = false;
        for (int i = 0; i < top; i++)
        {
            singleStack[top] = 0;
            status = true;
            top--;
        }
        return status;
    }