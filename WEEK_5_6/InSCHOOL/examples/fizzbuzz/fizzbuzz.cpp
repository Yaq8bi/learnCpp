#include <cstdio>
#include <cstring>
#include "fizzbuzz.h"

#define FIZZ "Fizz"
constexpr int FIZZ_DIV{3};

#define BUZZ "Buzz"
constexpr int BUZZ_DIV{5};

#define FIZZBUZZ "FizzBuzz"
constexpr int FIZZBUZZ_DIV{FIZZ_DIV * BUZZ_DIV};

static char output[sizeof(FIZZBUZZ)];

char *fizz_buzz(int num)
{
    if (num < 1)
    {
        std::strcpy(output, "");
    }
    else if (num % FIZZBUZZ_DIV == 0)
    {
        std::strcpy(output, FIZZBUZZ);
    }
    else if (num % FIZZ_DIV == 0)
    {
        std::strcpy(output, FIZZ);
    }
    else if (num % BUZZ_DIV == 0)
    {
        std::strcpy(output, BUZZ);
    }
    else
    {
        std::sprintf(output, "%d", num);
    }

    return output;
}