#include <iostream>
#include <limits> // number check

int main()
{
    int number = -1;

    do
    {
        std::cin.clear();
        std::cin.fail();

        std::cout << "\vWhat number would you like to convert to binary(range:0-255)?: " << std::endl;
        while (!(std::cin >> number))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Please enter a valid number: ";
        }

        // std::cin >> number;

    } while (number < 0 || number > 255);

    if (number >= 0 && number <= 255)
    {
        std::cout << "\vBinary value: " << std::endl;
        for (int i = 7; i >= 0; --i)
        {
            std::cout << ((number >> i) & 1); // Shift right and mask with 1 to get the ith bit, whch is all the bits that makeup that particular number.
        }
        std::cout << "\n"
                  << std::endl;
    }

    // Print each bit of the number from the most significant to the least significant
    std::cout << std::endl; // Newline after binary representation

    return 0;
}

