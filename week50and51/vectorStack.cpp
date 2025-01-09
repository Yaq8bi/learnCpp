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

    std::vector<int> aStackVector;

    aStackVector.push_back(0);    // add an element to the end of the vector
    aStackVector.push_back(1);    // add an element to the end of the vector
    aStackVector.push_back(2);    // add an element to the end of the vector
    aStackVector.push_back(3);    // add an element to the end of the vector
    aStackVector.push_back(4);    // add an element to the end of the vector
    aStackVector.push_back(5);    // add an element to the end of the vector
    assert(aStackVector[0] == 0); // check if the element at index 1 is 0

    aStackVector.pop_back(); // Remove the last element from the vector, yani 5.
    aStackVector.erase(aStackVector.begin() + 1); // Remove the element at index 1, yani 1.  begin 0 dan başlar.

    for (size_t i = 0; i < aStackVector.size(); i++)
    {
        std::cout << "Element at index " << i << " is: " << aStackVector[i] << std::endl;
    }

    return 0;
}