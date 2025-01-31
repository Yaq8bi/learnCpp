#include <iostream>
#include <cassert>
#include "exam.hpp"

int main()
{
    cirBuffer<int, 4> cir;
    int numHolder{0};

    printf("DATA AMOUNT IN BUFFER: %i\n", cir.dataAmount());
    assert(cir.dataAmount() == 0);

    std::cout << "\t**Testing write and overwrite**" << std::endl;
    assert(cir.write(8) == true); // position 0
    assert(cir.write(5) == true); // position 1
    assert(cir.write(3) == true); // position 2
    assert(cir.write(7) == true); // position 3

    printf("DATA AMOUNT IN BUFFER: %i\n", cir.dataAmount());
    assert(cir.dataAmount() == 4);
    std::cout << "ELEMENTS IN THE BUFFERF: " << cir << std::endl;

    assert(cir.isFull() == true); // true, test passs

    std::cout << "ELEMENTS IN THE BUFFERF: " << cir << std::endl;
    cir.write(1); // overwrite the oldest data (8 -> replaced by 1)
    std::cout << "ELEMENTS IN THE BUFFERF: " << cir << std::endl;
    cir.write(2); // (5 -> replaced by 2)

    cir.read(numHolder);    // Head is at 3 now, because pos 0 and 1 is new. Oldest data now is pos 2.
    assert(numHolder == 3); // oldest data, after 2 overwrites, so the head moved twice so that it will not point to the newly written data.

    std::cout << "\vCLEANING THE BUFFER." << std::endl;
    cir.clear();                   // clear and empty the circular buffer.
    assert(!cir.isFull());         // circulat buffer is not full
    assert(cir.dataAmount() == 0); // circular buffer is empty
    std::cout << "**BUFFER CLEARED**" << std::endl;

    cir.write(5);   // pos 0
    cir.write(15);  // pos 1
    cir.write(99);  // pos 2
    cir.write(47);  // pos 3
    cir.write(100); // Overwirte pos 0 where tail will move to.
    std::cout << "\vELEMENTS IN THE BUFFER: " << cir << std::endl; // using the Operaotr overloading
    std::cout << "\vOPERATOR OVERLOADING WORKED" << std::endl;

    printf("\vDATA AMOUNT IN BUFFER: %i\n", cir.dataAmount());
    assert(cir.dataAmount() == 4);

    // ARITHMETIC
    cirBuffer<double, 4> arithBuff;
    arithBuff.write(2.4);
    arithBuff.write(8.9);
    arithBuff.write(3.7);
    arithBuff.write(9.2);

    double doubleHolder{0};
    arithBuff.read(doubleHolder);
    std::cout << doubleHolder << std::endl;
    assert(doubleHolder == 2.4);
    doubleHolder = arithBuff.averageBuff<double>();
    std::cout << "THE AVERAGE IS: " << doubleHolder << std::endl;

    std::cout << "\v***ALL TESTS PASSED***" << std::endl;

    return 0;
}