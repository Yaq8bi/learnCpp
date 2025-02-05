#include <iostream>
#include <cassert>
#include <cstring>
#include <fizzbuzz.h>
// should fail
void test_fizz_buzz_returns_nothing(void)
{
    assert(0 == std::strcmp("", fizz_buzz(0)));
    std::cout << "[Passed] test_fizz_returns_nothing" << std::endl;
}
// should fail
void test_fizz_buzz_returns_digits(void)
{
    assert(0 == std::strcmp("1", fizz_buzz(1)));
    std::cout << "[Passed] test_fizz_returns_nothing" << std::endl;
}

int main(void)
{
    test_fizz_buzz_returns_nothing();
    test_fizz_buzz_returns_digits();

    return 0;
}