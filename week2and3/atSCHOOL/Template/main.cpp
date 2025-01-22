#include <iostream>
#include <array>

template <typename T>//Always implement them in the header file!
void print(T x)
{
    std::cout << x << std::endl;
}

int main()
{
    print(12);
    print("now");
    // std::aray<int, 5> array{1, 2, 3, 4, 5};

    return 0;
}