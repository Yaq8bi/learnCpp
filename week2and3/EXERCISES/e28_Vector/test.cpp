#include <iostream>
#include "vector.hpp"

main()
{

    std::cout << isNonPrime(13) << std::endl; // 1 it IS a NONprimeNumber, 0 if it is a prime.

    std::srand(time(nullptr));

    std::vector<int> vecVar;

    for (int i = 0; i < NUM; i++)
    {
        vecVar.push_back(std::rand() % (RANGE_MAX - RANGE_MIN) + RANGE_MIN); // 1000 random numbers.
    }

    // delete non prime numbers, std::remove if, will remove anything in between that the func isNonPrime says true) vecVar.end will move them to end.
    vecVar.erase(std::remove_if(vecVar.begin(), vecVar.end(), isNonPrime), vecVar.end()); // moves all the nonprimenumbers from begining to the end in the vector.
    // Bydefault its ascending:
    std::sort(vecVar.begin(), vecVar.end()); // a new block of memeory is allocated and sorting happens.

    std::cout << "The amount of elements in the Vector: " << vecVar.size() << std::endl;//seet eh number of elems in the vector.

    std::for_each(vecVar.begin(), vecVar.end(), [](const auto &elem)
                  { std::cout << elem << std::endl; });

    return 0;
}