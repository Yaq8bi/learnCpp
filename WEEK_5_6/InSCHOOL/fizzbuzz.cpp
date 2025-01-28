#include <cstdio>
#include <cstring>
#include "fizzbuzz.h"
//the TDD way of coding:
#define FIZZBUZZ "FizzBuzz"
#define FIZZ "Fizz"
#define BUZZ "Buzz"

constexpr int FIZZ_DIV{3};
constexpr int BUZZ_DIV{FIZZ_DIV * BUZZ_DIV};



static char output[sizeof(FIZZBUZZ)];

char *fizz_buzz(int num)
{
    if (num < 1)
        std::strcpy(output, "");
    else if (num % FIZZBUZZ_DIV == 0)
        std::strcpy(output, "Fizz");
    else if (num % FIZZ_DIV == 0)
    {

        std::strcpy(output, BUZZ);
    }
    else
    {
        std::sprintf(output, "%d", num);
    }

    return output;
}