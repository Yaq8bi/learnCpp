#include <iostream>
#include <random>
#include <cstdlib>

constexpr int ROW{2}; // #define from c, but this is how its done in Cpp
constexpr int COLUMN{3};
constexpr int MAX_RANDOM_NUMBER{99};

int main()
{
    int mtrxArr[ROW][COLUMN];
    
    // int pointer array'yi, mtrxArr ile initialize yapiyorum, cunku mtrxArray '0' pozisyonuna isaret ediyor.
    //
    srand(time(nullptr));
    for (int(*rptr)[COLUMN] = mtrxArr; (rptr - mtrxArr) < ROW; rptr++)
    {
        for (int *cptr = *rptr; (cptr - *rptr) < COLUMN; cptr++)
        {

            // *cptr = dist6(rng);
            *cptr = std::rand() % (MAX_RANDOM_NUMBER + 1);
        }
    }

    printf("Column: 1-2-3\n       ========\n");

    for (int(*rptr)[COLUMN] = mtrxArr; (rptr - mtrxArr) < ROW; rptr++)
    {
        printf("Row %li: ", (rptr - mtrxArr));

        for (int *cptr = *rptr; (cptr - *rptr) < COLUMN; cptr++)
        {
            std::cout << *cptr;
            if ((cptr - *rptr) == COLUMN - 1)
            {
                break;
            }
            std::cout << "-";
        }
        std::cout << std::endl;
    }

    return 0;
}
