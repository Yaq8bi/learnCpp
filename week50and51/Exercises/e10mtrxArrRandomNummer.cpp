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

    for (int(*rptr)[COLUMN] = mtrxArr; (rptr - mtrxArr) < ROW; rptr++)
    {
        printf("num: %i", rptr);
    }

    // for (int i = 0; i < ROW; i++)
    // {
    //     for (int j = 0; j < COLUMN; j++)
    //     {
    //         mtrxArr[i][j] = dist6(rng);
    //     }
    // }

    printf("Column: 1-2-3\n       ========\n");

    for (int i = 0; i < ROW; i++)
    {
        printf("Row %i: ", i + 1);
        for (int j = 0; j < COLUMN; j++)
        {
            // std::cout << "ROW: " << i << "Column: " << j << std::endl;

            std::cout << mtrxArr[i][j];
            if (j == COLUMN - 1)
            {
                break;
            }
            std::cout << "-";
        }
        std::cout << std::endl;
    }

    return 0;
}