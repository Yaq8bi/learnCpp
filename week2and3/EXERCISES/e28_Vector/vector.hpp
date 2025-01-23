/*
1. Generate and store 1000 random numbers in the range of 100 and 100000 in a vector.
2. Remove the non-prime numbers from the vector.
3. Sort the vector using std::sort in ascending order (from smallest to largest)
4. Usinng an iterator print the elements in the vector to the terminal.
*/
#ifndef  VECTOR.HPP
#define VECTOR.HPP

#include <iostream>
// vector and Ascend
#include <vector>
#include <algorithm>
// Rand
#include <ctime>
#include <cmath> //for getting square root of a num.

constexpr int NUM{1000};
constexpr int FIRST_PRIME{2};
constexpr int RANGE_MIN{100};
constexpr int RANGE_MAX{100000};

static bool isNonPrime(int num)
{
    bool status{true}; // by deafault, assume the num is not prime.
    if (num >= FIRST_PRIME)
    {
        status = false; // num could be a prime.
        if (num > FIRST_PRIME)
        {
            status = true; // non prime

            // Prime divisble byitself and 1
            const int max_num{static_cast<int>(std::sqrt(num)) + 1}; // sqrt of 23 = 4.

            for (int i = FIRST_PRIME; i <= max_num; i++)
            {
                if (num % i == 0) // if num is divisible(returns 0) by by the i(getting incremented)
                {
                    status = false; // is divisible by the current i.
                    std::cout << "This is a prime number: " << num << std::endl;
                    break;
                }
            }
        }
    }

    // auto vector

    return status;
}

#endif  //VECTOR.HPP