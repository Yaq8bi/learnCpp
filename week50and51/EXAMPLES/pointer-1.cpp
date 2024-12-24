#include <cstdio>
#include <cstdint>
#include <iostream>

static void func1(int x) { x = 5; }

static void func2(int *x) { *x = 20; }

int main(void)
{
    uint8_t value = 42;
    uint8_t *iptr = &value;

    // Writing information about value
    (void)printf("Value of value is %d and the address of value is %p\n", value, &value);

    // Writing information about the iptr pointer
    std::cout << "Value of iptr is " << iptr << ", the value, iptr is pointing to is " << iptr
              << " and the address of iptr is" << &iptr << std::endl;
    (void)printf("The size of value is %ld byte and size of iptr is %ld bytes\n", sizeof(value), sizeof(iptr));

    int var = 2;

    func1(var);                                // Call by value. A copy of var is passed to func1
    (void)printf("Value of var is %d\n", var); // var is still 2

    func2(&var);                               // Call by reference. The address of var is passed to func2
    (void)printf("Value of var is %d\n", var); // var 20

    // Example of an uninitialized pointer (will give any random value); is known as a wild pointer
    int32_t *wild_ptr;

    (void)printf("Value of the un-initialized pointer: %d\n\n", *wild_ptr);

    // Using pointer for arrays
    uint8_t buffer[4] = {2, 4, 8, 16};
    uint8_t *bptr = buffer;

    if (buffer[2] == *(buffer + 2))
    {
        // Will print this if the values are equal (they are pointing to the same location)
        (void)printf("It is true!\n\n");
    }

    // Iterate thru an array using pointer arithmatic
    for (int i = 0; i < sizeof(buffer) / sizeof(buffer[0]); ++i)
    {
        (void)printf("Data in index %d is: %d\n", i, *bptr);
        bptr++;
    }

    // Find the position in an array that a pointer is pointing to.
    bptr = &buffer[2];
    int index = static_cast<int>(bptr - buffer);

    (void)printf("%p - %p\n", bptr, buffer);
    (void)printf("\nThe index set was: %d\n", index);

    return 0;
}
