#include <iostream>
#include <random>
#include <cstdlib>

constexpr int ROW{2}; // #define from c, but this is how its done in Cpp
constexpr int COLUMN{3};

int main()
{

    int mtrxArr[ROW][COLUMN];

    std::random_device dev;                                                // seed
    std::mt19937 rng(dev());                                               // takes the seed,
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 99); // type, minn and max val

    // int pointer array'yi, mtrxArr ile initialize yapiyorum, cunku mtrxArray '0' pozisyonuna isaret ediyor.
    //
    for (int(*rptr)[COLUMN] = mtrxArr; (rptr - mtrxArr) < ROW; rptr++)
    {
        for (int *cptr = *rptr; (cptr - *rptr) < COLUMN; cptr++)
        {

            *cptr = dist6(rng);
        }
    }


    printf("Column: 1-2-3\n       ========\n");

    for (int (*rptr)[COLUMN] = mtrxArr; (rptr - mtrxArr) < ROW; rptr++)
    {
        printf("Row %i: ", (rptr - mtrxArr));

        for(int *cptr = *rptr; (cptr - *rptr) < COLUMN; cptr++)
        {
            std::cout << *cptr;
            if ( (cptr - *rptr) == COLUMN - 1)
            {
                break;
            }
            std::cout << "-";
        }
        std::cout << std::endl;
    }

    return 0;
}
