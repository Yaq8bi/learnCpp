/*
- Make a function to count number of digits of a given integer number using recursion.
For example: 456 has 3 digits

- Make a function to calculate XY using recursion. X and Y are two integers.
For example: 23 = 8.

recursion = functino calls it self until problem/desired outcome is reached.
*/

#include <iostream>

int recursiveDigitAmountCalc(int _number)
{
    int result{0};
    if (_number != 0)
    {

        result = 1 + recursiveDigitAmountCalc(_number / 10); // returns 1 +(PLUS) function, so its adding up 1(ONE) until functions stops.
    }

    return result;
}
int recursivePowerOf(int _x, int _y)
{
    return (_y == 0) ? 1 : _x * recursivePowerOf(_x, _y - 1);// DAMN!!
}

int main()
{
    int aNumber;
    int x, y;

    std::cout << "Enter a number for us to guess the digit amount:" << std::endl;
    std::cin >> aNumber;

    int digitAmountResult = recursiveDigitAmountCalc(aNumber);
    printf("\nAmount of digits: %i\v", digitAmountResult);

    std::cout << "Input the value for 'X' :\n X^y?";
    std::cin >> x;

    std::cout << "Input the value for 'y' :\n X^y?";
    std::cin >> y;

    std::cout << "The result is : " << recursivePowerOf(x, y) << std::endl;

    return 0;
}