#include <iostream>
#include <cassert>

using namespace std;

class Rectangle
{

private:
    int length;
    int width;

public:
    Rectangle(int l, int w) : length{l}, width{w} {}

    // declare the function as a friend
    template <typename T>
    friend auto area(const T &_rect);
};
template <typename T>
auto area(const T &_rect)
{
    return _rect.length * _rect.width;
}

int main()
{
    Rectangle r(8, 4);
    // friend makes it accesible
    std::cout << area(r) << std::endl;

    return 0;
}