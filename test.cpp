#include <iostream>
#include <cstdlib>

constexpr int ROW{2}; // #define from c, but this is how its done in Cpp
constexpr int COLUMN{3};

int main()
{
    int mtrxArr[ROW][COLUMN];

    for ( int(*rptr)[COLUMN] = mtrxArr; (rptr - mtrxArr) < ROW; rptr++)
    {
        std::cout << *rptr << "\t" << std::endl;
    }
 

    return 0;
}