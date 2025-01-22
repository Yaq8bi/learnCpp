#include <iostream>

void func()
{
    throw 1.0f;
}
int main(){
    try{//error detection.
        func();
        std::cout << "....." << std::endl;
    }
    catch(float exp/*The exception is an int*/)//can have multiple catch, for a single try.
    {
        std::cout << exp << std::endl;
    }
    return 0;
}