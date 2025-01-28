
#include <iostream>
#include "fizzbuzz.h"

constexpr int RANGE_MIN = 1;
constexpr int RANGE_MAX = 255;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid number of arguments!" << std::endl;
        exit(1);
    }

    int number = std::stoi(argv[1]);

    if ((number < RANGE_MIN) || (number > RANGE_MAX))
    {
        std::cout << "The number shall be in the range of " << RANGE_MIN << " and " << RANGE_MAX << std::endl;
        exit(1);
    }

    for (int i = 1; i <= number; i++)
    {
        std::cout << fizz_buzz(i) << "\t";
    }

    std::cout << std::endl;

    return 0;
}