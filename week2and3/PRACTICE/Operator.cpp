#include <iostream>

class Point
{
    int x, y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    Point operator+(const Point &p)
    {
        return Point(x + p.x, y + p.y);
    }

    void print()
    {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
};


main()
{
    Point p1(1, 2), p2(3, 4);

    Point p3 = p1 + p2;
    p3.print();

    return 0;
}