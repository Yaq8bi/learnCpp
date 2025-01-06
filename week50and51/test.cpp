#include <iostream>
#include <cassert>
#include <vector>

constexpr int fixedSize{8};

int main()
{

    std::vector<int> emptyVector(5);        // create a vector with 5 elements
    std::vector<int> filledVector{1, 1, 1}; // create a vector with 5 elements, all initialized to 1

    int *elemVector2 = &filledVector[1]; // get the element at index 2
    *elemVector2 = 4;                    // set the element at index 2 to 4
    assert(filledVector[1] == 4);        // check if the element at index 2 is 4

    // for (size_t i = 0; i < filledVector.size(); i++)
    // {
    //     std::cout << "Element at index " << i + 1 << " is: " << filledVector[i] << std::endl;
    // }

    emptyVector.push_back(1); // add an element to the end of the vector
    emptyVector.push_back(2); // add an element to the end of the vector
    emptyVector.push_back(3); // add an element to the end of the vector
    emptyVector.push_back(4); // add an element to the end of the vector

    emptyVector.pop_back(); // remove the last element from the vector

    // for (size_t i = 0; i < emptyVector.size(); i++)
    // {
    //     std::cout << "Element at index " << i + 1 << " is: " << emptyVector[i] << std::endl;
    // }

    return 0;
}