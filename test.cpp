#include <iostream>
#include <cstdlib>

constexpr int ROW{2}; // #define from c, but this is how its done in Cpp
constexpr int COLUMN{3};

int fun(int x, int y)
{
    if (y == 0)
        return x;
    else
    {
        return fun(x * x, --y);
    }
}

int main()
{
    // int mtrxArr[ROW][COLUMN];

    // for ( int(*rptr)[COLUMN] = mtrxArr; (rptr - mtrxArr) < ROW; rptr++)
    // {
    //     std::cout << *rptr << "\t" << std::endl;
    // }

    std::cout << fun(8, 2) << std::endl;

    return 0;
}