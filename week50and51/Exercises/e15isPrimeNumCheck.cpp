#include <iostream>

bool isPrime(int num)
{
    // number equal less than or equal to 1 is not prime.
    bool status{true};
    if (num <= 1)
    {
        status = false;
    }

    // number divisible to ANOTHER number than 1 or its self is not prime.
    for (int i = 2 /*to skip 0&1*/; i < num /*as long as its less than the number*/; ++i /*People are doing it this way in stack overflow, ask Faroch or Soufien why?*/)
    {
        if (num % i == 0)
        {
            status = false;
            break;
        }
    }
    return status;
}

int main(int argc, char *argv[])
{

    int number = std::stoi(argv[1]); // converts the argument to an int.

    std::string result = isPrime(number) ?/*true?*/ " is a prime number!" :/*else*/ " is not a prime number.";
    std::cout << "The number " << number << result << std::endl;

    return 0;
}