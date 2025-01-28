#include <unity.h>
#include "fizzbuzz.h"

void setUP(void) {}
void tearDown(void) {}
void test_fizzbuzz_returns_nothing(void)
{
    TEST_ASSERT_EQUAL_STRING("", fizz_buzz(0));
}
void test_fizzbuzz_returns_number(void)
{
    TEST_ASSERT_EQUAL_STRING("", fizz_buzz(0));
}

int main()
{
    UNITY_BEGIN();

    RUNT_TEST(/*name of the func*/ test_fizzbuzz_returns_nothing);
    RUNT_TEST(test_fizzbuzz_returns_number);
    RUNT_TEST(test_fizzbuzz_returns_fizz);
    RUNT_TEST(test_fizzbuzz_returns_buzz);
    RUNT_TEST(test_fizzbuzz_returns_fizzbuzz);

    return UNITY_END(); // returns 1 if program fails?
}

/*
The program is not aborted, rather unity testing returns the functions name.
*/