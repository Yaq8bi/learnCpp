/*
1) Make a function to fill an array of type int with random numbers int the range 0 and 99.

2) Make a function to print an array of type int to the output.

3) Make a function to swap values of two int variables.

4) Make a function to sort an array of type int. The function shall accept a function pointer of type compare_t to compare two values

    using compare_t = bool (*)(int, int);💀

void sort_array(size_t length, int *arr, compare_t compare);

    a) When you sort the array, the compare function shall be used to compare the elements

    b) To swap the elements, the swap function of step 3 shall be used.

    c) Implement two functions, compare_asc and compare_desc, to sort the array ascending and descending

bool compare_asc(int a, int b); and bool compare_desc(int a, int b);

    d) You shall be able to sort the array ascending and descending by calling sort_array with different compare functions



* To handle the arrays use only pointers
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>//swap function
#include <thread>//sleep
#include <chrono>//sleeps amount of mili/seconds

static constexpr int MAX{8};
static constexpr int MAX_RANDOM_NUMBER{99};

using compare_t = bool (*)(int, int);//Bu type'a ne tur dondurecegini belirliyorum.

bool cmpAsc(int x, int y);
bool cmpDesc(int x, int y);

void fillWithRandomNum(int *ptrArray);
void printAnArray(int *ptrArray);
void swapIntegers(int *numOne, int *numTwo);
void sort_array(int *arr, compare_t compare);



int main()
{
    srand(time(nullptr));
    int arrayOfNumbers[MAX];
    int x{8}, y{3};

    fillWithRandomNum(arrayOfNumbers);
    printAnArray(arrayOfNumbers);
    swapIntegers(&x,&y);
    printf("SWAPPED!\nX: %i\nY: %i\v", x, y);



// Sort in ascending order
    sort_array(arrayOfNumbers, cmpAsc);
    std::cout << "Ascending Order: ";
    for (int num : arrayOfNumbers) std::cout << num << " ";
    std::cout << std::endl;

     // Sort in descending order
    sort_array(arrayOfNumbers, cmpDesc);
    std::cout << "Descending Order: ";
    for (int num : arrayOfNumbers) std::cout << num << " ";
    std::cout << std::endl;


    return 0;
}


bool cmpAsc(int x, int y){
    return x > y;
}
bool cmpDesc(int x, int y){
    return x < y;
}
void sort_array(int *arr, compare_t compare) {
    for (size_t i = 0; i < MAX - 1; ++i) {
        for (size_t j = 0; j < MAX - i - 1; ++j) {
            if (compare(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void fillWithRandomNum(int *ptrArray)
{
    std::cout << "Randomizing numbers..." << std::endl;
    int i = 0;
    while (i < MAX)
    { //*(ptrArray + i) AND ptrArray[i] could be used interchangably in most situations, but ask Soufien to confirm.
        *(ptrArray + i) = rand() % (MAX_RANDOM_NUMBER + 1);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        i++;
    }
    printf("DONE!\n");
}
void printAnArray(int *ptrArray)
{
    std::cout << "Printing in progress..." << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        std::cout << *(ptrArray + i);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "\nDONE!\v" << std::endl;
}
void swapIntegers(int *numOne, int *numTwo){
    int temp{*numOne};
    *numOne = *numTwo;
    *numTwo = temp;
}
