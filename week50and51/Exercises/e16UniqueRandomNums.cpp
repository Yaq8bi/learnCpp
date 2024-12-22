/*
Make a function to fill an array of type int with unique random numbers in the range of 1 and 99.

Make another function to print the array to the output.

Example: An array filled with random numbers: {9, 3, 8, 13, 5, 2, 6, 7, 1, 4}
*/
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

constexpr int MAX{99};
constexpr int AMOUNT{9};

void fillWithUniqueRandomNumber(int *ptrArray)
{
    printf("Generating random numbers");
    for (int i = 0; i < AMOUNT; i++)
    {
        printf(".");
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        // *(ptrArray + i) = rand() % (MAX + 1); // But this line works flowlessly?
        // (*ptrArray)[i] = rand() % (MAX + 1); // why is this line wrong(compiler gives error and doesn't compile?) : This is a single integer not a pointr to an array.
        ptrArray[i] = rand() % (MAX + 1); // The Array that is being passed in as an argument.
    }
    printf("\nDONE!\v");
}
void printArray(int *ptrArray)
{
    printf("Printing the random numbers:\n");
    for (int i = 0; i < AMOUNT; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << *(ptrArray + i);
    }
    std::cout << "\vDone!" << std::endl;
}
void uniqueChecker(int *ptrArray)
{

    for (int i = 0; i < AMOUNT; i++)
    {
        for (int j = (i + 1); j < AMOUNT; j++)
        {
            if (ptrArray[i] == ptrArray[j])
            {
                int tempRandomNumber = rand() % (MAX + 1);
                printf("DUPLICATE FOUND!\v %i and %i was found and are a duplicate, swapping it with %i.", ptrArray[i], ptrArray[j], tempRandomNumber);
                ptrArray[i] = tempRandomNumber;
            }
            std::cout << "The i(" << i << ") has value: " << ptrArray[i] << " AND J(" << j << ") has value: " << ptrArray[j] << std::endl;
        }
    }
}

int main()
{
    srand(time(nullptr)); // seed the random
    int numArray[AMOUNT];

    fillWithUniqueRandomNumber(numArray);
    uniqueChecker(numArray);
    printArray(numArray);

    return 0;
}