/*
Make a program to fill a 10-element int array with random numbers in the range of 0 and 99, then

print the array to the output.
sort the array ascending(from the smallest to the largest) and then
Print the sorted array to the output.
To fill, print and sort the array use only pointers.
*/

#include <iostream>
#include <random>

#define ARR_LEN 10

void printArr(int *arr);
void rndmArr(int *arr);
void ascendArr(int *arr);

int main()
{

    int numberArray[ARR_LEN];

    printf("\v");
    std::cout << "~~ The unsorted array ~~" << std::endl;
    rndmArr(numberArray);
    printArr(numberArray);
    printf("\v");
    std::cout << "~~ The sorted array ~~" << std::endl;
    ascendArr(numberArray);
    printArr(numberArray);

    return 0;
}

void rndmArr(int *arr)
{
    std::random_device dev;                                                // seed
    std::mt19937 rng(dev());                                               // takes the seed,
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 99); // type, minn and max val

    for (int i = 0; i < ARR_LEN; i++)
    {
        *(arr + i) = dist6(rng);
    }
}
void printArr(int *arr)
{

    for (int i = 0; i < ARR_LEN; i++)
    {
        if (i == (ARR_LEN - 1)) // quit the loop if its 1 digit less than the total elements(point is to not print a dash after the last char)
        {
            std::cout << arr[i];
            break;
        }
        std::cout << arr[i] << "-";
    }
    std::cout << std::endl; // \n ile ayni sey.
}
void ascendArr(int *arr)
{
    int temp = 0;
    bool swapped = false;

    for (int i = 0; i < ARR_LEN; i++)
    {
        swapped = false;
        for (int j = 0; j < ARR_LEN; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                swapped = true;
            }
        }

        if (!swapped)
        {
            std::cout << "\vAlready sorted" << std::endl;
            break;
        }
    }
}