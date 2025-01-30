#include <iostream>
#include <cassert>
#include "exam.hpp"

int main()
{
    cirBuffer<int, 4> cir;

    int numHolder{0};

    std::cout << "Testing write and overwrite behavior..." << std::endl;
    assert(cir.write(7) == true);

    cir.write(9);
    cir.write(8);
    cir.write(2);

    assert(cir.isFull()); // true, test passs
    assert(cir.dataAmount() == 4); //true, 4 item in buffer

    cir.write(10); // overwrite the oldest data (7 -> replaced by 10)
    cir.write(20); // (9 -> replaced by 20)

    cir.read(numHolder);
    assert(numHolder == 8); // oldest data, after 2 overwrite, so the head moved twice so that it will not point to the newly written data.
    cir.read(numHolder);
    assert(numHolder == 2);

    std::cout << "Write and overwrite tests passed." << std::endl;
    std::cout << "Buffer contents: " << cir << std::endl;

    std::cout << "Testing clear() functionality..." << std::endl;
    cir.clear();
    assert(!cir.isFull());
    assert(cir.dataAmount() == 0);
    bool status = cir.read(numHolder);

    std::cout << "Clear tests passed." << std::endl;

    std::cout << "Testing operator<<..." << std::endl;
    cir.write(5);
    cir.write(15);
    cir.write(25);
    std::cout << "Buffer contents: " << cir << std::endl;
    std::cout << "Operator<< tests passed." << std::endl;

    std::cout << "All tests passed!" << std::endl;

    return 0;
}