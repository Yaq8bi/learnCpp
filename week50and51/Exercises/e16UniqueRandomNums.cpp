/*
Make a function to fill an array of type int with unique random numbers in the range of 1 and 99.

Make another function to print the array to the output.

Example: An array filled with random numbers: {9, 3, 8, 13, 5, 2, 6, 7, 1, 4}
*/
#include <iostream>
#include <cstdlib>

constexpr int MAX{99};
constexpr int AMOUNT{9};

void fillWithUniqueRandomNumber(int *ptrArray)
{
    for (int i = 0; i < AMOUNT; i++)
    {
        *(ptrArray + i) = rand() % (MAX + 1); // But this line works flowlessly?
        (*ptrArray)[i] = rand() % (MAX + 1); // why is this line wrong(compiler gives error and doesn't compile?)
    }
}
void printArray(int *ptrArray){
    for (int i = 0; i < AMOUNT; i++)
    {
        std::cout << *(ptrArray + i);
    }
    std::cout << std::endl;
}

int main()
{
    srand(time(nullptr));
    int numArray[AMOUNT];

    fillWithUniqueRandomNumber(numArray);
    printArray(numArray);

    return 0;
}