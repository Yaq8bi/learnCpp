#include <iostream>
#include <cassert>
#include "exam.hpp"

int main()
{
    cirBuffer<int, 4> cir;

    int numHolder{0};

    cir.write(7);
    cir.write(9);
    cir.write(8);
    cir.write(2);
    assert(cir.isFull());
    cir.write(7);
    cir.write(9);

    cir.read(numHolder);
    cir.read(numHolder);

    std::cout << "Number of elements stored in buffer: " << cir.dataAmount() << std::endl;
    cir.clear();
    
    // std::cout << cir;

    assert(!cir.isFull());
    std::cout << "all tests passed\v" << std::endl;

    return 0;
}