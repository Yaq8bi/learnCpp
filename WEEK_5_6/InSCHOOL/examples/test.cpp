#include <unity.h>
#include "fizzbuzz.h"

void setUp(void) {}
void tearDown(void) {}

void test_fizzbuzz_returns_nothing(void)
{
    TEST_ASSERT_EQUAL_STRING("", fizz_buzz(0));
}

void test_fizzbuzz_returns_number(void)
{
    TEST_ASSERT_EQUAL_STRING("2", fizz_buzz(2));
}

void test_fizzbuzz_returns_fizz(void)
{
    TEST_ASSERT_EQUAL_STRING("Fizz", fizz_buzz(3));
}

void test_fizzbuzz_returns_buzz(void)
{
    TEST_ASSERT_EQUAL_STRING("Buzz", fizz_buzz(5));
}

void test_fizzbuzz_returns_fizzbuzz(void)
{
    TEST_ASSERT_EQUAL_STRING("FizzBuzz", fizz_buzz(15));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_fizzbuzz_returns_nothing);
    RUN_TEST(test_fizzbuzz_returns_number);
    RUN_TEST(test_fizzbuzz_returns_fizz);
    RUN_TEST(test_fizzbuzz_returns_buzz);
    RUN_TEST(test_fizzbuzz_returns_fizzbuzz);

    return UNITY_END();
}