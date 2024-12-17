/*
Make a program to fill a 2D array (2x3) of type int with random numbers in the range of 0 and 99
 and then print the array to the terminal.

To fill and print the array, use only pointers.
*/
#include <iostream>
#include <random>

#define COLUMN 2
#define ROW 3

void fillMtrxArr(int *_arr)
{
        // for (int j = 0; j < ROW; j++){// _arr[i][j] = dist6(rng);}
}

int main()
{
    std::random_device dev;                                                // seed
    std::mt19937 rng(dev());                                               // takes the seed,
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 99); // type, minn and max val

    int randomNumber = dist6(rng); // feed the time to rand.
    
    
    int mtrxArr[COLUMN][ROW];

    for (int i = 0; i < (COLUMN + ROW); i++)
    {
            *(_arr + i) = dist6(rng);

    }

    
    // fillMtrxArr(mtrxArr);

    return 0;
}